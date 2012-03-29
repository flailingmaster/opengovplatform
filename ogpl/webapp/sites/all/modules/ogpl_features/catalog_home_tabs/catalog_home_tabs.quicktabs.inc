<?php

/**
 * Implementation of hook_quicktabs_default_quicktabs().
 */
function catalog_home_tabs_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass;
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'catalog_tab';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = 0;
  $quicktabs->default_tab = FALSE;
  $quicktabs->title = 'Front End Home Page Rotating Tabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'Most_Recent_Catalog',
      'display' => 'block_1',
      'args' => '',
      'get_displays' => 'vdisp_0',
      'title' => 'Recent Catalogs',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'Most_Popular_Catalog',
      'display' => 'block_1',
      'args' => '',
      'get_displays' => 'vdisp_1',
      'title' => 'Popular Catalogs',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'bid' => 'web_feed_aggregator_delta_0',
      'hide_title' => 1,
      'title' => 'Major Events',
      'weight' => '-98',
      'type' => 'block',
    ),
  );
  $quicktabs->style = 'Zen';
  $export['catalog_tab'] = $quicktabs;

  return $export;
}
