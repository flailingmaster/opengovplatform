<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function rotating_panel_half_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function rotating_panel_half_imagecache_default_presets() {
  $items = array(
    'rotating_images_home_half' => array(
      'presetname' => 'rotating_images_home_half',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_resize',
          'data' => array(
            'width' => '661',
            'height' => '255',
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function rotating_panel_half_views_api() {
  return array(
    'api' => '2',
  );
}
