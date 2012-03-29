<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function vrm_feedback_type_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function vrm_feedback_type_node_info() {
  $items = array(
    'feedback' => array(
      'name' => t('Feedback'),
      'module' => 'features',
      'description' => t('Feedback used for Visitors Review Management'),
      'has_title' => '1',
      'title_label' => t('Sender Name'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
