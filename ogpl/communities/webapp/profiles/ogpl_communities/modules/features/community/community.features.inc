<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function community_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function community_node_info() {
  $items = array(
    'community_home' => array(
      'name' => t('Community Home'),
      'module' => 'features',
      'description' => t('A home for communities'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function community_views_api() {
  return array(
    'api' => '2',
  );
}
