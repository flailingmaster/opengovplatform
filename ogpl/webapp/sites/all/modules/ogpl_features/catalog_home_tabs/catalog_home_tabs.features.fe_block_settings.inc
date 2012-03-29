<?php

/**
 * Implementation of hook_default_fe_block_settings().
 */
function catalog_home_tabs_default_fe_block_settings() {
  $export = array();

  // dms
  $theme = array();

  $theme['aggregator-feed-1'] = array(
    'module' => 'aggregator',
    'delta' => 'feed-1',
    'theme' => 'dms',
    'status' => 0,
    'weight' => '-73',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['block-popular_apps_catalog'] = array(
    'module' => 'block',
    'theme' => 'dms',
    'status' => 0,
    'weight' => '49',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Most Popular Catalog',
    'cache' => '-1',
    'machine_name' => 'popular_apps_catalog',
  );

  $theme['block-popular_dataset_catalog'] = array(
    'module' => 'block',
    'theme' => 'dms',
    'status' => 0,
    'weight' => '50',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Most Popular Catalog',
    'cache' => '-1',
    'machine_name' => 'popular_dataset_catalog',
  );

  $theme['block-popular_document_catalog'] = array(
    'module' => 'block',
    'theme' => 'dms',
    'status' => 0,
    'weight' => '51',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Most Popular Catalog',
    'cache' => '-1',
    'machine_name' => 'popular_document_catalog',
  );

  $theme['block-recent_apps_catalog'] = array(
    'module' => 'block',
    'theme' => 'dms',
    'status' => 0,
    'weight' => '52',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Most Recent Catalog',
    'cache' => '-1',
    'machine_name' => 'recent_apps_catalog',
  );

  $theme['block-recent_dataset_catalog'] = array(
    'module' => 'block',
    'theme' => 'dms',
    'status' => 0,
    'weight' => '53',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Most Recent Catalog',
    'cache' => '-1',
    'machine_name' => 'recent_dataset_catalog',
  );

  $theme['block-recent_document_catalog'] = array(
    'module' => 'block',
    'theme' => 'dms',
    'status' => 0,
    'weight' => '54',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => 'Most Recent Catalog',
    'cache' => '-1',
    'machine_name' => 'recent_document_catalog',
  );

  $theme['quicktabs-catalog_tab'] = array(
    'module' => 'quicktabs',
    'delta' => 'catalog_tab',
    'theme' => 'dms',
    'status' => 0,
    'weight' => '-27',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['views-Most_Popular_Catalog-block_1'] = array(
    'module' => 'views',
    'delta' => 'Most_Popular_Catalog-block_1',
    'theme' => 'dms',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-Most_Recent_Catalog-block_1'] = array(
    'module' => 'views',
    'delta' => 'Most_Recent_Catalog-block_1',
    'theme' => 'dms',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $export['dms'] = $theme;

  // ogpl_css3
  $theme = array();

  $theme['aggregator-feed-1'] = array(
    'module' => 'aggregator',
    'delta' => 'feed-1',
    'theme' => 'ogpl_css3',
    'status' => 0,
    'weight' => '-82',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '1',
  );

  $theme['block-popular_apps_catalog'] = array(
    'module' => 'block',
    'theme' => 'ogpl_css3',
    'status' => '1',
    'weight' => '-70',
    'region' => 'hidden_content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'popular_apps_catalog',
  );

  $theme['block-popular_dataset_catalog'] = array(
    'module' => 'block',
    'theme' => 'ogpl_css3',
    'status' => '1',
    'weight' => '-71',
    'region' => 'hidden_content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'popular_dataset_catalog',
  );

  $theme['block-popular_document_catalog'] = array(
    'module' => 'block',
    'theme' => 'ogpl_css3',
    'status' => '1',
    'weight' => '-71',
    'region' => 'hidden_content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'popular_document_catalog',
  );

  $theme['block-recent_apps_catalog'] = array(
    'module' => 'block',
    'theme' => 'ogpl_css3',
    'status' => '1',
    'weight' => '-71',
    'region' => 'hidden_content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'recent_apps_catalog',
  );

  $theme['block-recent_dataset_catalog'] = array(
    'module' => 'block',
    'theme' => 'ogpl_css3',
    'status' => '1',
    'weight' => '-71',
    'region' => 'hidden_content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'recent_dataset_catalog',
  );

  $theme['block-recent_document_catalog'] = array(
    'module' => 'block',
    'theme' => 'ogpl_css3',
    'status' => '1',
    'weight' => '26',
    'region' => 'hidden_content',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
    'machine_name' => 'recent_document_catalog',
  );

  $theme['quicktabs-catalog_tab'] = array(
    'module' => 'quicktabs',
    'delta' => 'catalog_tab',
    'theme' => 'ogpl_css3',
    'status' => '1',
    'weight' => '-103',
    'region' => 'banner_right',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '1',
    'pages' => '<front>',
    'title' => '<none>',
    'cache' => '-1',
  );

  $theme['views-Most_Popular_Catalog-block_1'] = array(
    'module' => 'views',
    'delta' => 'Most_Popular_Catalog-block_1',
    'theme' => 'ogpl_css3',
    'status' => 0,
    'weight' => '3',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => '-1',
  );

  $theme['views-Most_Recent_Catalog-block_1'] = array(
    'module' => 'views',
    'delta' => 'Most_Recent_Catalog-block_1',
    'theme' => 'ogpl_css3',
    'status' => 0,
    'weight' => '4',
    'region' => '',
    'custom' => '0',
    'throttle' => '0',
    'visibility' => '0',
    'pages' => '',
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
