<?php
/**
 * @file
 * Provide views data and handler information for vrm_customization.module.
 */

/**
 * Implements hook_views_data_alter().
 */
function vrm_customization_views_data() {
  $data = array();

  // Provide a list of allowed operations on the node.
  $data['node']['vrm_allowed_operations'] = array(
    'title' => t('VRM Allowed operations'),
    'field' => array(
      'help' => t('Provide a list of allowed operations on the node.'),
      'handler' => 'vrm_views_handler_field_allowed_node_operation',
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function vrm_customization_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'vrm_customization') . '/views',
    ),
    'handlers' => array(
      // field handlers
      'vrm_views_handler_field_allowed_node_operation' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
