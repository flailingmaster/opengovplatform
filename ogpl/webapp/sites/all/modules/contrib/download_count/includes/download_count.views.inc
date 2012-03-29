<?php

/**
 * @file
 * Provide views data for the download_count.module.
 */

/**
 * Implementation of hook_views_handlers().
 */
function download_count_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'download_count') . '/includes',
    ),
    'handlers' => array(
      'download_count_views_handler_field_file' => array(
        'parent' => 'views_handler_field_file',
      ),
      'download_count_views_handler_field_count' => array(
        'parent' => 'views_handler_field_numeric',
      ),
      'download_count_views_handler_sort_count' => array(
        'parent' => 'views_handler_sort',
      ),
      'download_count_views_handler_filter_count' => array(
        'parent' => 'views_handler_filter_numeric',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data().
 */
function download_count_views_data() {

  //base table info
  $data['download_count']['table']['group']  = t('Download count');
  $data['download_count']['table']['base'] = array(
    'field' => 'dcid',
    'title' => t('File download'),
    'help' => t("Download history for files handled by the core upload and contributed filefield modules."),
  );

  //joins
  $data['download_count']['table']['join'] = array(
    'files' => array(
      'left_field' => 'fid',
      'field' => 'fid',
    ),
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
    'node_revisions' => array(
      'left_field' => 'vid',
      'field' => 'vid',
    ),
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  //standard fields
  $data['download_count']['dcid'] = array(
    'title' => t('Download count id'),
    'help' => t('The unique id of the download.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['download_count']['ip_address'] = array(
    'title' => t('IP address'),
    'help' => t('IP address of the downloading user.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['download_count']['referrer'] = array(
    'title' => t('Referrer'),
    'help' => t('Referrer URI.'),
    'field' => array(
      'handler' => 'views_handler_field_url',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['download_count']['timestamp'] = array(
    'title' => t('Timestamp'),
    'help' => t('The date & time the file was downloaded.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  //virtual fields
  $data['files']['downloads'] = array(
    'title' => t('Download count'),
    'help' => t('The number of times the file has been downloaded.'),
    'field' => array(
      'handler' => 'download_count_views_handler_field_count',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'download_count_views_handler_filter_count',
    ),
    'sort' => array(
      'handler' => 'download_count_views_handler_sort_count',
    ),
  );

  //relationships
  $data['download_count']['fid'] = array(
    'title' => t('File'),
    'help' => t('Relate the download to the file.'),
    'relationship' => array(
      'base' => 'files',
      'base field' => 'fid',
      'handler' => 'views_handler_relationship',
      'label' => t('File'),
    ),
  );

  $data['download_count']['nid'] = array(
    'title' => t('Node'),
    'help' => t('Relate the download to the node to which it was attacahed when downloaded.'),
    'relationship' => array(
      'base' => 'node',
      'base field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Node'),
    ),
  );

  $data['download_count']['vid'] = array(
    'title' => t('Node Revision'),
    'help' => t('Relate the download to the node revision to which it was attacahed when downloaded.'),
    'relationship' => array(
      'base' => 'node_revisions',
      'base field' => 'vid',
      'handler' => 'views_handler_relationship',
      'label' => t('Node Revision'),
    ),
  );

  $data['download_count']['uid'] = array(
    'title' => t('User'),
    'help' => t("Relate the download to the user that downloaded it."),
    'relationship' => array(
      'base' => 'users',
      'base field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('User'),
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_data_alter().
 *
 * Replaces default views file field link formatters with download_count formatter.
 */
function download_count_views_data_alter(&$data) {
  foreach ($data as $module => $m) {
    foreach ($m as $column => $c) {
      foreach ($c as $property => $p) {
        if ($property == 'field' && !empty($p['handler'])) {
          switch ($p['handler']) {
            case 'views_handler_field_file':
              $data[$module][$column][$property]['handler'] = 'download_count_views_handler_field_file';
              break;
          }
        }
      }
    }
  }
}
