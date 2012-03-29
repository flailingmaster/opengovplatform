<?php
/**
 * @file
 * Provide views data and handler information for dms_customizations.module.
 */

/**
 * Implements hook_views_data_alter().
 */
function dms_customizations_views_data() {
  $data = array();

  // Provide a list of allowed operations on the node.
  $data['node']['dms_allowed_operations'] = array(
    'title' => t('DMS Allowed operations'),
    'field' => array(
      'help' => t('Provide a list of allowed operations on the node.'),
      'handler' => 'views_handler_field_allowed_node_operation',
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_handlers().
 */
function dms_customizations_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'dms_customizations') . '/views',
    ),
    'handlers' => array(
      // field handlers
      'views_handler_field_allowed_node_operation' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
