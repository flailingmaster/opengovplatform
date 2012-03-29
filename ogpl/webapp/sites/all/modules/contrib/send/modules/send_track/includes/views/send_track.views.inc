<?php // $Id$

/**
 * Implementation of hook_views_data().
 */
function send_track_views_data() {
  $data['send_track']['table']['group'] = t('Send');

  // Form a relationship to the send_recipient table.
  $data['send_track']['srid'] = array(
  );

  // Filter / field handler for the activity type.
  // Todo write a "where in" handler.
  $data['send_track']['activity'] = array(
  );

  // Hostname
  $data['send_track']['hostname'] = array(
  );

  // Timestamp
  $data['send_track']['hostname'] = array(
  );

  // TODO the "path" item is really only interesting to e.g. "click" functionality

  // Add our columns to the send_recipient table.
  foreach (module_invoke_all('send_track_handler_info') as $name => $info) {
    if (isset($info['database columns'])) {
// TODO making assumptions about column layout - should go into the hook?
      $data['send_recipient'][$name] = array(
        'title' => $info['title'],
        'help' => $info['description'],
        'field' => array(
          'handler' => 'views_handler_field_numeric', 
          'click sortable' => TRUE,
        ),
        'filter' => array(
          'handler' => 'send_views_handler_filter',
          'options callback' => 'send_profile_names',
        ),
        'sort' => array(
          'handler' => 'views_handler_sort',
        ),
      );
    }
  }
  return $data;
}
