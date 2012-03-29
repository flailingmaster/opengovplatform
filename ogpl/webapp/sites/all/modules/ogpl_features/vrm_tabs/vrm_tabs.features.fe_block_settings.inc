<?php

/**
 * Implementation of hook_default_fe_block_settings().
 */
function vrm_tabs_default_fe_block_settings() {
  $export = array();

  // dms
  $theme = array();

  $theme['quicktabs-vrm_admin_tabs'] = array(
    'module' => 'quicktabs',
    'delta' => 'vrm_admin_tabs',
    'theme' => 'dms',
    'status' => '1',
    'weight' => '-94',
    'region' => 'content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'vrm_dashboard',
    'title' => ' ',
    'cache' => '-1',
  );

  $theme['quicktabs-vrm_admin_tabs_list'] = array(
    'module' => 'quicktabs',
    'delta' => 'vrm_admin_tabs_list',
    'theme' => 'dms',
    'status' => 0,
    'weight' => '28',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-vrm_pmo_tabs_list'] = array(
    'module' => 'quicktabs',
    'delta' => 'vrm_pmo_tabs_list',
    'theme' => 'dms',
    'status' => 0,
    'weight' => '-95',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'vrm_dashboard',
    'title' => '  ',
    'cache' => '-1',
  );

  $theme['quicktabs-vrm_poc_tabs_list'] = array(
    'module' => 'quicktabs',
    'delta' => 'vrm_poc_tabs_list',
    'theme' => 'dms',
    'status' => 0,
    'weight' => '-94',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'vrm_dashboard',
    'title' => ' ',
    'cache' => '-1',
  );

  $export['dms'] = $theme;

  // ogpl_css3
  $theme = array();

  $theme['quicktabs-vrm_admin_tabs'] = array(
    'module' => 'quicktabs',
    'delta' => 'vrm_admin_tabs',
    'theme' => 'ogpl_css3',
    'status' => 0,
    'weight' => '-37',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'vrm_dashboard',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-vrm_admin_tabs_list'] = array(
    'module' => 'quicktabs',
    'delta' => 'vrm_admin_tabs_list',
    'theme' => 'ogpl_css3',
    'status' => 0,
    'weight' => '-36',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['quicktabs-vrm_pmo_tabs_list'] = array(
    'module' => 'quicktabs',
    'delta' => 'vrm_pmo_tabs_list',
    'theme' => 'ogpl_css3',
    'status' => 0,
    'weight' => '-35',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'vrm_dashboard',
    'title' => '  ',
    'cache' => '-1',
  );

  $theme['quicktabs-vrm_poc_tabs_list'] = array(
    'module' => 'quicktabs',
    'delta' => 'vrm_poc_tabs_list',
    'theme' => 'ogpl_css3',
    'status' => 0,
    'weight' => '-34',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => 'vrm_dashboard',
    'title' => ' ',
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
