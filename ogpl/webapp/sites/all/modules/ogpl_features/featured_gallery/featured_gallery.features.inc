<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function featured_gallery_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function featured_gallery_node_info() {
  $items = array(
    'imageflow' => array(
      'name' => t('Featured Gallery'),
      'module' => 'features',
      'description' => t('Gallery displaying images as a slide show.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function featured_gallery_views_api() {
  return array(
    'api' => '2',
  );
}
