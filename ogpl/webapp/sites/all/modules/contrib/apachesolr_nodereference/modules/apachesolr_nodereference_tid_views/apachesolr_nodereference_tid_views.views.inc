<?php
/**
 * Implementation of hook_views_handlers().
 */
function apachesolr_nodereference_tid_views_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'apachesolr_nodereference_tid_views') . '/handlers',
    ),
    'handlers' => array(
      'apachesolr_views_handler_argument_nodereference_tid' => array(
        'parent' => 'apachesolr_views_handler_argument_nodereference',
      )
    )
  );
}

/**
 * Implementation of hook_views_data_alter().
 */
function apachesolr_nodereference_tid_views_views_data_alter(&$data) {
  foreach (module_invoke_all('apachesolr_entities') as $base_table => $definition) {
    // provide CCK mappings filters
    foreach (apachesolr_cck_fields() as $name => $field) {
      if ($field['type'] == 'nodereference') {
        foreach ($field['referenceable_types'] as $type) {
          if (!empty($type)) {
            $result = db_query("SELECT vid FROM {vocabulary_node_types} WHERE type = '%s'", $type);

            while ($obj = db_fetch_object($result)) {
              $vocab = taxonomy_vocabulary_load($obj->vid);
              
              $data['apachesolr_' . $base_table]['im_noderef_' . $type . '_vid_' . $obj->vid] = array(
                'title' => t($field['widget']['label'] . ' - ' . $vocab->name),
                'help' => t('@vocab taxonomy mapping for CCK nodereference @fieldname', array('@vocab' => $vocab->name, '@fieldname' => $field['field_name'])),
                'argument' => array(
                  'handler' => 'apachesolr_views_handler_argument_nodereference_tid',
                  'cck_field' => $field,
                  'vid' => $vocab->vid
                ),
              );
            }
          }
        }
      }
    }
  }
}