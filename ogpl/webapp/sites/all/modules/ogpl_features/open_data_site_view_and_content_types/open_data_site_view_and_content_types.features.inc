<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function open_data_site_view_and_content_types_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function open_data_site_view_and_content_types_node_info() {
  $items = array(
    'country_data' => array(
      'name' => t('Country Data'),
      'module' => 'features',
      'description' => t('Contains data to be shown on header page (Flags and government name) and open data sites'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'state_data_site' => array(
      'name' => t('State Data Site'),
      'module' => 'features',
      'description' => t('Contains state data site details'),
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
function open_data_site_view_and_content_types_views_api() {
  return array(
    'api' => '2',
  );
}
