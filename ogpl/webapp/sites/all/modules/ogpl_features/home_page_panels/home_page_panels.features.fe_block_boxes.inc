<?php

/**
 * Implementation of hook_default_fe_block_boxes().
 */
function home_page_panels_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->machine_name = 'apps_block_content';
  $fe_block_boxes->body = NULL;

  $export['apps_block_content'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->machine_name = 'apps_block_header';
  $fe_block_boxes->body = NULL;

  $export['apps_block_header'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->machine_name = 'communities_content';
  $fe_block_boxes->body = NULL;

  $export['communities_content'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->machine_name = 'communities_header';
  $fe_block_boxes->body = NULL;

  $export['communities_header'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->machine_name = 'dataset_block_content';
  $fe_block_boxes->body = NULL;

  $export['dataset_block_content'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->machine_name = 'dataset_block_header';
  $fe_block_boxes->body = NULL;

  $export['dataset_block_header'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Front End Gallery Content Home Page';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'gallery_content';
  $fe_block_boxes->body = '<h2>OGPL Offerings</h2><!--learn --><div class="galleryBlocks alpha"><h3>Learn</h3><img alt="Learn" src="/drupal_svn/sites/all/themes/nic/images/img-learn.png" title="Learn" /><p>Are you a teacher, professor, or student? Young people across America are learning about Data.gov and we want you to be part of getting data into the classroom.</p></div><!--learn --><!--developers corner --><div class="galleryBlocks"><h3>Developers Corner</h3><img alt="Developers Corner" src="/drupal_svn/sites/all/themes/nic/images/img-developers.png" title="Developers Corner" /><p>Are you interested in sharing your mashups, apps, and ideas? Do you want to learn how to create app and mashups with some of the data hosted here on Data.gov</p></div><!--developers corner --><!--linked data --><div class="galleryBlocks"><h3>Linked Data</h3><img alt="Linked Data" src="/drupal_svn/sites/all/themes/nic/images/img-linked-data.png" title="Linked Data" /><p>Linked data is data in which real-world things are given addresses on the web (URIs), and data is published about them in machine-readable formats at those locations.</p></div><!--linked data -->';

  $export['gallery_content'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Front End Gallery Header Home Page';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'gallery_header';
  $fe_block_boxes->body = '<h1>OGPL Offerings</h1>';

  $export['gallery_header'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->machine_name = 'welcome_block_content';
  $fe_block_boxes->body = '<h1>OGPL Offerings</h1>';

  $export['welcome_block_content'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Front End Welcome Header Home Page';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'welcome_block_header';
  $fe_block_boxes->body = '';

  $export['welcome_block_header'] = $fe_block_boxes;

  return $export;
}
