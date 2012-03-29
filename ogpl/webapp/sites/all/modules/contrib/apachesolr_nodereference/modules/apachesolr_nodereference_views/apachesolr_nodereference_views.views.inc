<?php
/**
 * Implementation of hook_views_handlers().
 */
function apachesolr_nodereference_views_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'apachesolr_nodereference_views') . '/handlers',
    ),
    'handlers' => array(
      'apachesolr_views_handler_field_nodereference' => array(
        'parent' => 'views_handler_field',
      ),
      'apachesolr_views_handler_filter_nodereference' => array(
        'parent' => 'content_handler_filter_many_to_one',
      ),
      'apachesolr_views_handler_argument_nodereference' => array(
        'parent' => 'content_handler_argument_many_to_one',
      )
    )
  );
}

/**
 * Implementation of hook_views_data_alter().
 */
function apachesolr_nodereference_views_views_data_alter(&$data) {
  foreach (module_invoke_all('apachesolr_entities') as $base_table => $definition) {
    // provide CCK mappings filters
    foreach (apachesolr_cck_fields() as $name => $field) {
      if ($field['type'] == 'nodereference') {
        $data['apachesolr_' . $base_table][apachesolr_index_key($field)] = array(
          'title' => t($field['widget']['label']),
          'help' => t('CCK Mapping for @fieldname', array('@fieldname' => $field['field_name'])),
          'field' => array(
            'handler' => 'apachesolr_views_handler_field_nodereference',
          ),
          'filter' => array(
            'handler' => 'apachesolr_views_handler_filter_nodereference',
            'cck_field' => $field,
          ),
          'argument' => array(
            'handler' => 'apachesolr_views_handler_argument_nodereference',
            'cck_field' => $field,
          ),
        );
      }
    }
  }
}