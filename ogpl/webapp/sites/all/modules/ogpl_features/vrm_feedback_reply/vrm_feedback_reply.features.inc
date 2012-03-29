<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function vrm_feedback_reply_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function vrm_feedback_reply_node_info() {
  $items = array(
    'feedback_reply' => array(
      'name' => t('Feedback Reply'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Subject'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
