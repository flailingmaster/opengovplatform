<?php

/**
 * @file
 * Download count provided default views.
 */

/**
 * Implementation of hook_views_default_views().
 */
function download_count_views_default_views() {
  /*
   * View 'download_count_file_downloads'
   */
  $view = new view;
  $view->name = 'download_count_file_downloads';
  $view->description = 'A basic download count view using the file download table (provided by the download_count module).';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'download_count';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'fid' => array(
      'label' => 'File',
      'required' => 0,
      'id' => 'fid',
      'table' => 'download_count',
      'field' => 'fid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'counter' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'counter_start' => '1',
      'exclude' => 0,
      'id' => 'counter',
      'table' => 'views',
      'field' => 'counter',
      'relationship' => 'none',
    ),
    'filename' => array(
      'label' => 'File Name',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_file' => 0,
      'exclude' => 0,
      'id' => 'filename',
      'table' => 'files',
      'field' => 'filename',
      'relationship' => 'fid',
    ),
    'filepath' => array(
      'label' => 'Path',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_file' => 1,
      'exclude' => 0,
      'id' => 'filepath',
      'table' => 'files',
      'field' => 'filepath',
      'relationship' => 'fid',
    ),
    'filemime' => array(
      'label' => 'Mime type',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_file' => 0,
      'exclude' => 0,
      'id' => 'filemime',
      'table' => 'files',
      'field' => 'filemime',
      'relationship' => 'fid',
    ),
    'filesize' => array(
      'label' => 'Size',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'file_size_display' => 'formatted',
      'exclude' => 0,
      'id' => 'filesize',
      'table' => 'files',
      'field' => 'filesize',
      'relationship' => 'fid',
    ),
    'ip_address' => array(
      'label' => 'IP address',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'ip_address',
      'table' => 'download_count',
      'field' => 'ip_address',
      'relationship' => 'none',
    ),
    'referrer' => array(
      'label' => 'Referrer',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'display_as_link' => 1,
      'exclude' => 0,
      'id' => 'referrer',
      'table' => 'download_count',
      'field' => 'referrer',
      'relationship' => 'none',
    ),
    'timestamp_1' => array(
      'label' => 'Download datetime',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'small',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'timestamp_1',
      'table' => 'download_count',
      'field' => 'timestamp',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'downloads' => array(
      'order' => 'DESC',
      'id' => 'downloads',
      'table' => 'files',
      'field' => 'downloads',
      'relationship' => 'fid',
    ),
  ));
  $handler->override_option('filters', array(
    'downloads' => array(
      'operator' => '>',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'downloads',
      'table' => 'files',
      'field' => 'downloads',
      'relationship' => 'fid',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Individual File Downloads');
  $handler->override_option('items_per_page', 25);
  $handler->override_option('use_pager', '1');
  $handler->override_option('distinct', 0);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'counter' => 'counter',
      'filename' => 'filename',
      'filepath' => 'filepath',
      'filemime' => 'filemime',
      'filesize' => 'filesize',
      'timestamp_1' => 'timestamp_1',
      'ip_address' => 'ip_address',
      'referrer' => 'referrer',
    ),
    'info' => array(
      'counter' => array(
        'separator' => '',
      ),
      'filename' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'filepath' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'filemime' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'filesize' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'timestamp_1' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'ip_address' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'referrer' => array(
        'sortable' => 1,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'individual_file_downloads');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Individual File Downloads',
    'description' => '',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $views[$view->name] = $view;

  /*
   * View 'download_count_files'
   */
  $view = new view;
  $view->name = 'download_count_files';
  $view->description = 'A basic download count view using the files table.';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'files';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'counter' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'counter_start' => '1',
      'exclude' => 0,
      'id' => 'counter',
      'table' => 'views',
      'field' => 'counter',
      'relationship' => 'none',
    ),
    'filename' => array(
      'label' => 'File Name',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_file' => 0,
      'exclude' => 0,
      'id' => 'filename',
      'table' => 'files',
      'field' => 'filename',
      'relationship' => 'none',
    ),
    'filepath' => array(
      'label' => 'Path',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_file' => 1,
      'exclude' => 0,
      'id' => 'filepath',
      'table' => 'files',
      'field' => 'filepath',
      'relationship' => 'none',
    ),
    'filemime' => array(
      'label' => 'Mime type',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_file' => 0,
      'exclude' => 0,
      'id' => 'filemime',
      'table' => 'files',
      'field' => 'filemime',
      'relationship' => 'none',
    ),
    'filesize' => array(
      'label' => 'Size',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'file_size_display' => 'formatted',
      'exclude' => 0,
      'id' => 'filesize',
      'table' => 'files',
      'field' => 'filesize',
      'relationship' => 'none',
    ),
    'timestamp' => array(
      'label' => 'Upload date',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'small',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'timestamp',
      'table' => 'files',
      'field' => 'timestamp',
      'relationship' => 'none',
    ),
    'downloads' => array(
      'label' => 'Download count',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'set_precision' => FALSE,
      'precision' => 0,
      'decimal' => '.',
      'separator' => ',',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'downloads',
      'table' => 'files',
      'field' => 'downloads',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'downloads' => array(
      'order' => 'DESC',
      'id' => 'downloads',
      'table' => 'files',
      'field' => 'downloads',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'downloads' => array(
      'operator' => '>',
      'value' => array(
        'value' => '0',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'downloads',
      'table' => 'files',
      'field' => 'downloads',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'File Downloads');
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'filename' => 'filename',
      'filepath' => 'filepath',
      'filemime' => 'filemime',
      'filesize' => 'filesize',
      'timestamp' => 'timestamp',
      'downloads' => 'downloads',
    ),
    'info' => array(
      'filename' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'filepath' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'filemime' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'filesize' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'timestamp' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'downloads' => array(
        'sortable' => 1,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('path', 'file_downloads');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'File Downloads',
    'description' => '',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $views[$view->name] = $view;

  return $views;
}
