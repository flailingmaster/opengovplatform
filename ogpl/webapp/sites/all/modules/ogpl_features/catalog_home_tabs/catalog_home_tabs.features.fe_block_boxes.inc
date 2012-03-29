<?php

/**
 * Implementation of hook_default_fe_block_boxes().
 */
function catalog_home_tabs_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'embed Popular_Apps_Catalog';
  $fe_block_boxes->format = '4';
  $fe_block_boxes->machine_name = 'popular_apps_catalog';
  $fe_block_boxes->body = 'Popular_Apps_Catalog';

  $export['popular_apps_catalog'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'embed Popular_Dataset_Catalog';
  $fe_block_boxes->format = '4';
  $fe_block_boxes->machine_name = 'popular_dataset_catalog';
  $fe_block_boxes->body = 'Popular_Dataset_Catalog';

  $export['popular_dataset_catalog'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'embed Popular_Document_Catalog';
  $fe_block_boxes->format = '4';
  $fe_block_boxes->machine_name = 'popular_document_catalog';
  $fe_block_boxes->body = 'Popular_Document_Catalog';

  $export['popular_document_catalog'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'embed Recent_Apps_Catalog';
  $fe_block_boxes->format = '4';
  $fe_block_boxes->machine_name = 'recent_apps_catalog';
  $fe_block_boxes->body = 'Recent_Apps_Catalog';

  $export['recent_apps_catalog'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'embed Recent_Dataset_Catalog';
  $fe_block_boxes->format = '4';
  $fe_block_boxes->machine_name = 'recent_dataset_catalog';
  $fe_block_boxes->body = 'Recent_Dataset_Catalog';

  $export['recent_dataset_catalog'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'embed Recent_Document_Catalog';
  $fe_block_boxes->format = '4';
  $fe_block_boxes->machine_name = 'recent_document_catalog';
  $fe_block_boxes->body = 'Recent_Document_Catalog';

  $export['recent_document_catalog'] = $fe_block_boxes;

  return $export;
}
