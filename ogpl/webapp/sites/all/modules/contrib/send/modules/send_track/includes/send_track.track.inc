<?php // $Id$

/**
 * Menu callback for a tracking activity.
 */
function send_track_page($op, $send_recipient) {
  $args = func_get_args();
  $path = join('/', array_slice($args, 2));

  // Call the API function that manages tracking activities.
  send_track($op, NULL, $send_recipient, $path);

  // The rest of the path is presumably a URL to redirect to.
  drupal_goto($path);
}

/**
 * Schema alter code for the send_recipient table.
 * Handlers can optionally create additional fields for tracking purposes.
 */
function _send_track_schema_alter(&$schema) {
  // The table doesn't exist at all.
  $table = 'send_recipient';
  $new = !db_table_exists($table);

  foreach (module_invoke_all('send_track_handler_info') as $info) {
    if (isset($info['database columns'])) {

      $indexes = array();
      if (isset($info['database indexes'])) {
        $indexes = array('indexes' => $info['database indexes']);
        $schema[$table]['indexes'] = array_merge($schema[$table]['indexes'], $info['database indexes']);
      }

      foreach ($info['database columns'] as $name => $spec) {
        // Add this column to the schema array.
        $schema[$table]['fields'][$name] = $spec;

        // Add the column to the database if it does not already exist.
        if (!$new && !db_column_exists($table, $name)) {
          db_add_field($ret, $table, $name, $spec, $indexes);
          $indexes = array();
        }
      }
    }
  }
}

function send_track($op, $value = 1, $send_recipient = NULL, $path = NULL) {
  if (!$send_recipient) {
    // Look for send_recipient info that was previously set in the session.
    if (isset($_SESSION['send_recipient'])) {
      $send_recipient = send_recipient_load($_SESSION['send_recipient']);
    }
    // Look for a send_hash cookie.
    elseif (isset($_COOKIES['send_hash'])) {
      $send_recipient = send_hash_load($_COOKIES['send_hash']);
    }
  }
  if (!$send_recipient) {
    // This activity has nothing to do with any send activity.  Abort!
    return FALSE;
  }

  if (!$path) $path = $_GET['q'];
  
  // Make sure this is a valid activity.
  $handlers = module_invoke_all('send_track_handler_info');
  if (!isset($handlers[$op])) return FALSE;
  $info = $handlers[$op];
  
  // Limit the number of times we'll be tracking this.
  if (isset($info['count once']) && $info['count once']) {
    if ($send_recipient->$op) return FALSE;
  }

  // Store the activity in the send tracking table.
  $send_track = (object) array(
    'srid' => $send_recipient->srid,
    'activity' => check_plain($op),
    'timestamp' => time(),
    'hostname' => ip_address(),
    'path' => filter_xss($path),
  );
  drupal_write_record('send_track', $send_track);
  
  // Let the predefined callback respond to this.
  if (isset($info['callback']) && function_exists($func = $info['callback'])) {
    $func($send_track);
  }

  // Let other modules react to this.
  module_invoke_all('send_track', $op, $send_track, $path);

  return $send_track;
}

/**
 * Implementation of my own hook_send_track_handler_info().
 */
function send_track_send_track_handler_info() {
  return array(
    'open' => array(
      'title' => t('Open rate'),
      'description' => t('An open-rate tracker.'),
      'callback' => 'send_track_open',
      'count once' => TRUE,
      'database columns' => array(
        'open' => array('type' => 'int', 'size' => 'tiny', 'not null' => TRUE, 'default' => 0),
      ),
    ),
    'click' => array(
      'title' => t('Click-through'),
      'description' => t('Track the number of times an embedded URL is clicked.'),
      'callback' => 'send_track_click',
      'count once' => FALSE,
      'database columns' => array(
        'click' => array('type' => 'int', 'unsigned' => TRUE, 'not null' => TRUE, 'default' => 0),
      ),
    )
  );
}

/**
 * Implementation of Send module's hook_message_alter().
 */
function _send_track_send_message_alter(&$message, $profile, $r, $nids, $mode) {
  if ($mode == 'mail' || $mode == 'mlm') { // TODO eliminate mlm and handle elsewhere.
    global $base_url;
    $body = $message['body'];

    // Open:  We'll only replace one src image to avoid overrunnig the server.
    $open_path  = 'send/o/'. $r->hash .'/';
    $pattern = '@(src=")('. $base_url .')?('. base_path() .')(.*q=)?([^"]+)@mi';
    $body = preg_replace($pattern, '\1\2\3\4'.$open_path.'\5', $body, 1);

    // Click-through
    $click_path  = 'send/c/'. $r->hash .'/';
    $pattern = '@(href=")('. $base_url .')?('. base_path() .')(.*q=)?([^"]+)@mi';
    $body = preg_replace($pattern, '\1\2\3\4'.$click_path.'\5', $body);
    
    // TODO: Add tracking for fully-qualified links to remote URLs.
    //$click_full = url('send/c/'. $r->hash, array('absolute' => TRUE));
    $message['body'] = $body;
  }
}

/**
 * Custom behavior for the "click" activity.
 */
function send_track_click($send_track) {
  // Store the event in the session:  It may be retrieved for, say, a purchase.
  $_SESSION['send_recipient'] = $send_track->srid;
}
