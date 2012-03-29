<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function rotating_panel_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function rotating_panel_imagecache_default_presets() {
  $items = array(
    'rotating_images_home' => array(
      'presetname' => 'rotating_images_home',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_resize',
          'data' => array(
            'width' => '987',
            'height' => '255',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function rotating_panel_node_info() {
  $items = array(
    'rotating_panel' => array(
      'name' => t('Rotating Panel'),
      'module' => 'features',
      'description' => t('Panel displaying images in a rotating manner displayed on the home page'),
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
function rotating_panel_views_api() {
  return array(
    'api' => '2',
  );
}
