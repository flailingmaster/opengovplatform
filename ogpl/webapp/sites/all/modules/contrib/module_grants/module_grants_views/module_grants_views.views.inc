<?php

/**
 * @file
 * Provides Module Grants enhancements for the Views module.
 */

/**
 * Implementation of hook_views_handlers().
 */
function module_grants_views_views_handlers() {
  return array(
  'info' => array(
    'path' => drupal_get_path('module', 'module_grants_views'),
    ),
    'handlers' => array(
      'module_grants_views_handler_field_node_link_edit' => array(
        'parent' => 'views_handler_field_node_link',
      ),
      'module_grants_views_handler_field_node_link_delete' => array(
        'parent' => 'views_handler_field_node_link',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data_alter().
 */
function module_grants_views_views_data_alter(&$data) {
  $data['node']['module_grants_views_node_link_edit'] = array(
    'group' => t('Module Grants'),
    'title' => t('Edit link'),
    'help' => t('Provide node edit link based on Module Grants access.'),
    'real field' => 'nid',
    'field' => array(
      'handler' => 'module_grants_views_handler_field_node_link_edit',
    ),
  );
  $data['node']['module_grants_views_node_link_delete'] = array(
    'group' => t('Module Grants'),
    'title' => t('Delete link'),
    'help' => t('Provide node delete link based on Module Grants access.'),
    'real field' => 'nid',
    'field' => array(
      'handler' => 'module_grants_views_handler_field_node_link_delete',
    ),
  );
}
