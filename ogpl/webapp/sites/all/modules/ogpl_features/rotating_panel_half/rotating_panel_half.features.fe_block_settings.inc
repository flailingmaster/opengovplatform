<?php

/**
 * Implementation of hook_default_fe_block_settings().
 */
function rotating_panel_half_default_fe_block_settings() {
  $export = array();

  // dms
  $theme = array();

  $theme['views-Rotating_Panel_Half-block_1'] = array(
    'module' => 'views',
    'delta' => 'Rotating_Panel_Half-block_1',
    'theme' => 'dms',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $export['dms'] = $theme;

  // ogpl_css3
  $theme = array();

  $theme['views-Rotating_Panel_Half-block_1'] = array(
    'module' => 'views',
    'delta' => 'Rotating_Panel_Half-block_1',
    'theme' => 'ogpl_css3',
    'status' => '1',
    'weight' => '0',
    'region' => 'banner_left',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '',
    'cache' => '-1',
  );

  $export['ogpl_css3'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}
