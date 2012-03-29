<?php // $Id: send.module,v 1.33 2007/12/07 19:45:24 vauxia Exp

/**
 * @file
 *
 */

/**
 * Load callback for a sent message.
 */
function send_message_load($id) {
  if (is_numeric($id)) {
    $send = db_fetch_object(db_query("SELECT * FROM {send} 
      WHERE sid = %d", $id));
  }
  else {
    $recipient = send_hash_load($id);
    $send = send_message_load($recipient->sid);
    $send->recipient = $recipient;
  }
  return $send;
}

/**
 * Load callback for send_recipients, using a unique hash.
 */
function send_hash_load($hash) {
  // There's a small possibility of collision here, use the most recent hash.
  $res = db_query("SELECT * FROM {send_recipient} WHERE hash = '%s'
    ORDER BY srid LIMIT 1", $hash);
  return db_fetch_object($res);
}

/**
 * Load callback for send_recipients, using an id.
 */
function send_recipient_load($srid) {
  $res = db_query("SELECT * FROM {send_recipient} WHERE srid = %d", $srid);
  return db_fetch_object($res);
}

/**
 * API Function: Common defaults for any element that appears on a send form. 
 */
function send_element_defaults() {
  return array(
    '#input' => TRUE,
    '#process' => array('send_process'),
    '#theme' => 'send_element',
    '#tree' => TRUE,
  ); 
}

/**
 * Load a handler for send profiles, etc.
 */
function send_handler_load($name = 'send') {
  static $loaded;
  static $profiles;

  if (!isset($loaded)) {
    $profiles = send_profiles();
    require dirname(__FILE__) .'/handlers/send.inc';
    $loaded = array('send' => $profiles['send']);
  }

  if ($handler = $profiles[$name]) {
    if (isset($loaded[$name]))  return $loaded[$name];

    if ($parent = $handler['parent']) send_handler_load($parent);
    if (isset($handler['file'])) {
      $file = isset($handler['path']) ? $handler['path'] .'/' : '';
      $file .= $handler['file'];

      // Require the file, if it exists.
      if (is_file($file)) {
        require $file;
        $loaded[$name] = $handler;
      }
    }
    else {
      $loaded[$name] = $handler;
    }

    return $loaded[$name];
  }
}

/**
 * List all available sending profiles for the site.
 */
function send_profiles($profile_name = NULL, $options = array()) {
  static $profiles;
  if ($profile_name || !$profiles) {
    $profiles = module_invoke_all('send_profile_info', $profile_name, $options);

    foreach ($profiles as $name => $info) {
      // Set the profile name.
      $info['name'] = $name;

      if(!isset($info['handler'])) $info['handler'] = $name;
      if(!isset($info['class'])) $info['class'] = 'sendProfile';

      // Set default values.  TODO this is hard-coded in a way that should
      // likely be supplanted by something cleaner.
      // TODO hard-coded default template!
      if(!isset($info['template'])) $info['template'] = 1;

      $profiles[$name] = $info;
    }
  }

  return $profiles;
}

/**
 * List all available sending profiles for the site in a name => value array.
 */
function send_profile_names() {
  static $list;
  if (!isset($list)) {
    $list = array();
    foreach (send_profiles() as $name => $info) {
      $list[$name] = $info['title'];
    }
  }
  return $list;
}

/**
 * Load callback for send_profiles.
 */
function send_profile_load($values = NULL, $options = array()) {
  if (is_scalar($values)) {
    $id  = $values;

    // Look for the profile in the database.
    $query = (is_numeric($id)) ? "spid = %d" : "name = '%s'";
    if (!$values = db_fetch_array(db_query("SELECT * FROM {send_profile}
      WHERE $query", $id))) {

      // Look for it in the array populated by hook_send_profile_info().
      $profiles = send_profiles($id);
      if (!$values = $profiles[$id]) return FALSE;
    }
  }
  $values  = array_merge((array) $values, $options);
  $handler = isset($values['handler']) ? $values['handler'] : $values['name'];
  if ($info = send_handler_load($handler)) {
    $class = isset($info['class']) ? $info['class'] : $handler;
    return New $class($values);
  }
}

/**
 * Save function for a send profile.
 */
function send_profile_save(&$profile) {
  if (method_exists($profile, 'save')) $profile->save();
}

/**
 * Save function for a send profile.
 */
function send_profile_delete(&$profile) {
  if (!is_object($profile)) $profile = send_profile_load($profile);
  if (method_exists($profile, 'delete')) $profile->delete();
}

/**
 * Create a duplicate instance of a send profile.  This is useful when
 * extending a global profile for an individual node, etc.
 */
function send_profile_copy($name, $new_name) {
  if ($profile = send_profile_load($name)) {
    unset($profile->spid);
    $profile->parent = $name;
    $profile->setName($new_name);
    return $profile;
  }
}

/**
 * An API function to list any message templates that exist.
 */
function send_templates($profile = NULL, $active_only = TRUE) {
  module_load_include('inc', 'send.template', 'includes/send');
  return send_template_list($profile, $active_only);
}

/**
 * The main send processing function.
 */
function send($profile, $recipients, $nids = array(), $message = array()) {
  $profile = send_profile_load($profile);
  $profile->setRecipients($recipients);
  $profile->nids = $nids;
  $profile->setMessage($message);
  return $profile->send();
}

/**
 * Generate a unique send contact entry for anonymous and authenticated send
 * contacts, based on the send method and a unique identifier ( e.g. mail )
 */
function send_contact($mode, $contact) {
  $contact = (object) $contact;
  if (isset($contact->scid)) return $contact;

  $contact->mode = $mode;

  // Where supplementary contact data may be stored.
  $table = 'send_contact_'. check_plain($mode);
  if (!db_table_exists($table)) $table = '';

  // See if the entry already exists.
  if (isset($contact->uid) && $contact->uid) {
    // Only one uid + mode combination allowed, so search by uid if possible.
    if ($row = db_fetch_object(db_query("SELECT * FROM {send_contact} 
      WHERE uid = %d AND mode = '%s'", $contact->uid, $mode))) {

      $contact->scid = $row->scid;

      if ($table) {
        if ($row = db_fetch_array(db_query('SELECT * FROM {' . $table . '}
          WHERE scid = %d', $row->scid))) {

          foreach ($row as $key => $val) $contact->key = $contact->val;
        }
      }
    }
  }
  elseif ($table) {
    // Search the table for a unique value.
    $schema = drupal_get_schema($table);
    $query = array();
    if (isset($schema['unique keys'])) {
      foreach ($schema['unique keys'] as $keys) {
        foreach ($keys as $key) {
          $place = db_type_placeholder($schema['fields'][$key]['type']);
          $query[] = "$key = $place";
          $values[] = $contact->$key;
        }
      }
      if ($row = db_fetch_array(db_query('SELECT * FROM {' . $table . '}
        WHERE '. join(' AND ', $query), $values))) {

        foreach ($row as $key => $val) $contact->$key = $val;
      }
    }
  }

  // Save a new entry if we didn't just load one.
  if (!$contact->scid) {
    drupal_write_record('send_contact', $contact);
    if ($table) {
      drupal_write_record($table, $contact);
    }
  }

  // Allow modules to save and/or alter the contact entry before we return it.
  drupal_alter('send_contact', $contact);

  return $contact;
}

/**
 * Delivery callback for Send module's built-in delivery mode of "mail".
 */
function send_deliver_mail($profile, $contact, $nids, &$message, $mode) {
  $sender = $message['sender'];

  if (module_exists('mimemail')) {
    // Use mimemail if available, to support HTML messages.
    return mimemail($sender, $contact, $message['subject'], $message['body']);
  }
  else {
    // TODO populate this.
    return drupal_mail();
  }
}
