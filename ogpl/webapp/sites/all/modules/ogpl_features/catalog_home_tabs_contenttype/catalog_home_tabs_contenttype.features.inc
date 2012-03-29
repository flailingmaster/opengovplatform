<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function catalog_home_tabs_contenttype_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function catalog_home_tabs_contenttype_node_info() {
  $items = array(
    'apps_catalog' => array(
      'name' => t('Apps Catalog'),
      'module' => 'features',
      'description' => t('Apps catalog pages for tabs'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'dataset_catalog' => array(
      'name' => t('Dataset Catalog'),
      'module' => 'features',
      'description' => t('Dataset catalog pages for tabs'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'document_catalog' => array(
      'name' => t('Document Catalog'),
      'module' => 'features',
      'description' => t('Document catalog pages for tabs'),
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
