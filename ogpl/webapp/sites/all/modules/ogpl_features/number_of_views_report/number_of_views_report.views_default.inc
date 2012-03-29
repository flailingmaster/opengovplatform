<?php

/**
 * Implementation of hook_views_default_views().
 */
function number_of_views_report_views_default_views() {
  $views = array();

  // Exported view: views_by_agency
  $view = new view;
  $view->name = 'views_by_agency';
  $view->description = 'Views By Agency';
  $view->tag = 'View By Agency and Category';
  $view->base_table = 'node';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'field_ds_agency_name_nid' => array(
      'label' => 'Agency Name',
      'required' => 1,
      'delta' => -1,
      'id' => 'field_ds_agency_name_nid',
      'table' => 'node_data_field_ds_agency_name',
      'field' => 'field_ds_agency_name_nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'field_agency_name_value' => array(
      'label' => 'Agency',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
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
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_agency_name_value',
      'table' => 'node_data_field_agency_name',
      'field' => 'field_agency_name_value',
      'relationship' => 'field_ds_agency_name_nid',
    ),
    'totalcount' => array(
      'label' => 'Total views',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
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
      'format_plural' => 0,
      'format_plural_singular' => '1',
      'format_plural_plural' => '@count',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'totalcount',
      'table' => 'node_counter',
      'field' => 'totalcount',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'totalcount' => array(
      'order' => 'DESC',
      'id' => 'totalcount',
      'table' => 'node_counter',
      'field' => 'totalcount',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'dataset' => 'dataset',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'sid' => array(
      'operator' => 'in',
      'value' => array(
        10 => '10',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Views By Agency');
  $handler->override_option('empty', 'There are no items to display.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'summary' => '',
    'columns' => array(
      'field_agency_name_value' => 'field_agency_name_value',
      'totalcount' => 'totalcount',
    ),
    'info' => array(
      'field_agency_name_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'totalcount' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => 'field_agency_name_value',
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('header', '<?php
global $base_url;

print \'<h1 class="metrics-visitorstats-table-heading fLeft"> Views by Agency</h1>\';

print \'<div title="CSV Download" class="download-report" style="padding-right:0px;">Download report as: <a class="hyperlink" href="\'.$base_url.\'/visitorstats/viewsbyagency/csv?itemcount=200"><img alt="CSV" src="[token global site-url]sites/all/themes/ogpl_css3/images/csv.png" /></a> \' ;

print \'<a title="XLS Download" class="hyperlink"  href="\'.$base_url.\'/visitorstats/viewsbyagency/xls?itemcount=200"><img alt="XLS" src="[token global site-url]sites/all/themes/ogpl_css3/images/xls.png" /></a>\';

print \'<a style="padding-left:3px;" title="PDF Download" class="hyperlink" href="\'.$base_url.\'/printpdf/visitorstats/viewsbyagency/pdf?itemcount=200"><img alt="PDF" src="[token global site-url]sites/all/themes/ogpl_css3/images/pdf.png" /></a></div>\';

?>
');
  $handler->override_option('header_format', '3');
  $handler->override_option('header_empty', 0);
  $handler->override_option('items_per_page', 10);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'desc',
    'summary' => '',
    'columns' => array(
      'field_agency_name_value' => 'field_agency_name_value',
      'totalcount' => 'totalcount',
    ),
    'info' => array(
      'field_agency_name_value' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'totalcount' => array(
        'sortable' => 1,
        'separator' => '',
      ),
    ),
    'default' => 'totalcount',
  ));
  $handler->override_option('path', 'visitorstats/viewsbyagency');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler = $view->new_display('views_data_export', 'CSV', 'views_data_export_1');
  $handler->override_option('items_per_page', '0');
  $handler->override_option('style_plugin', 'views_data_export_csv');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
    'attach_text' => 'CSV',
    'provide_file' => 1,
    'filename' => '%view--%timestamp-full.csv',
    'help' => '',
    'parent_sort' => 0,
    'separator' => ',',
    'quote' => 1,
    'trim' => 0,
    'replace_newlines' => 0,
    'newline_replacement' => ', ',
    'header' => 1,
    'encoding' => '',
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('path', 'visitorstats/viewsbyagency/csv');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'primary-links',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array());
  $handler->override_option('sitename_title', FALSE);
  $handler->override_option('use_batch', '0');
  $handler = $view->new_display('views_data_export', 'XLS', 'views_data_export_2');
  $handler->override_option('items_per_page', '0');
  $handler->override_option('style_plugin', 'views_data_export_xls');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
    'attach_text' => 'XLS',
    'provide_file' => 1,
    'filename' => '%view--%timestamp-full.xls',
    'help' => '',
    'parent_sort' => 0,
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('path', 'visitorstats/viewsbyagency/xls');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'primary-links',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array());
  $handler->override_option('sitename_title', FALSE);
  $handler->override_option('use_batch', '0');
  $handler = $view->new_display('page', 'PDF', 'page_2');
  $handler->override_option('header_format', '3');
  $handler->override_option('header_empty', 0);
  $handler->override_option('items_per_page', 10);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'desc',
    'summary' => '',
    'columns' => array(
      'field_agency_name_value' => 'field_agency_name_value',
      'totalcount' => 'totalcount',
    ),
    'info' => array(
      'field_agency_name_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'totalcount' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => 'totalcount',
  ));
  $handler->override_option('path', 'visitorstats/viewsbyagency/pdf');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
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

  // Exported view: views_by_category
  $view = new view;
  $view->name = 'views_by_category';
  $view->description = 'Views By Category';
  $view->tag = 'View By Agency and Category';
  $view->base_table = 'node';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'field_ds_sector_nid' => array(
      'label' => 'Sector',
      'required' => 1,
      'delta' => '-1',
      'id' => 'field_ds_sector_nid',
      'table' => 'node_data_field_ds_sector',
      'field' => 'field_ds_sector_nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'field_sector_title_value' => array(
      'label' => 'Category',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
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
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_sector_title_value',
      'table' => 'node_data_field_sector_title',
      'field' => 'field_sector_title_value',
      'relationship' => 'field_ds_sector_nid',
    ),
    'totalcount' => array(
      'label' => 'Total views',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
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
      'format_plural' => 0,
      'format_plural_singular' => '1',
      'format_plural_plural' => '@count',
      'prefix' => '',
      'suffix' => '',
      'exclude' => 0,
      'id' => 'totalcount',
      'table' => 'node_counter',
      'field' => 'totalcount',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'totalcount' => array(
      'order' => 'DESC',
      'id' => 'totalcount',
      'table' => 'node_counter',
      'field' => 'totalcount',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'dataset' => 'dataset',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'sid' => array(
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
    ),
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Views By Category');
  $handler->override_option('empty', 'There are no items to display.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'desc',
    'summary' => '',
    'columns' => array(
      'field_sector_title_value' => 'field_sector_title_value',
      'totalcount' => 'totalcount',
    ),
    'info' => array(
      'field_sector_title_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'totalcount' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => 'totalcount',
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'dataset' => 'dataset',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'sid' => array(
      'operator' => 'in',
      'value' => array(),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('header', '<?php
global $base_url;

print \'<h1 class="metrics-visitorstats-table-heading fLeft">Views by Category</h1>\';

print \'<div class="download-report" style="padding-right:0px;">Download report as: <a title="CSV Download" class="hyperlink" href="\'.$base_url.\'/visitorstats/viewsbycategory/csv?itemcount=200"><img alt="CSV" src="[token global site-url]sites/all/themes/ogpl_css3/images/csv.png" /></a> \' ;

print \'<a title="XLS Download" class="hyperlink"  href="\'.$base_url.\'/visitorstats/viewsbycategory/xls?itemcount=200"><img alt="XLS" src="[token global site-url]sites/all/themes/ogpl_css3/images/xls.png" /></a>\';

print \'<a style="padding-left:3px;" title="PDF Download"  class="hyperlink"  href="\'.$base_url.\'/printpdf/visitorstats/viewsbycategory/pdf?itemcount=200"><img alt="PDF" src="[token global site-url]sites/all/themes/ogpl_css3/images/pdf.png" /></a></div>\';

?>
');
  $handler->override_option('header_format', '3');
  $handler->override_option('header_empty', 0);
  $handler->override_option('items_per_page', 10);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'desc',
    'summary' => '',
    'columns' => array(
      'field_sector_title_value' => 'field_sector_title_value',
      'totalcount' => 'totalcount',
    ),
    'info' => array(
      'field_sector_title_value' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'totalcount' => array(
        'sortable' => 1,
        'separator' => '',
      ),
    ),
    'default' => 'totalcount',
  ));
  $handler->override_option('path', 'visitorstats/viewsbycategory');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler = $view->new_display('views_data_export', 'CSV', 'views_data_export_1');
  $handler->override_option('items_per_page', '0');
  $handler->override_option('style_plugin', 'views_data_export_csv');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
    'attach_text' => 'CSV',
    'provide_file' => 1,
    'filename' => '%view--%timestamp-full.csv',
    'help' => '',
    'parent_sort' => 0,
    'separator' => ',',
    'quote' => 1,
    'trim' => 0,
    'replace_newlines' => 0,
    'newline_replacement' => ', ',
    'header' => 1,
    'encoding' => '',
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('path', 'visitorstats/viewsbycategory/csv');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'primary-links',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array());
  $handler->override_option('sitename_title', FALSE);
  $handler->override_option('use_batch', '0');
  $handler = $view->new_display('views_data_export', 'XLS', 'views_data_export_2');
  $handler->override_option('items_per_page', '0');
  $handler->override_option('style_plugin', 'views_data_export_xls');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
    'attach_text' => 'XLS',
    'provide_file' => 1,
    'filename' => '%view--%timestamp-full.xls',
    'help' => '',
    'parent_sort' => 0,
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('path', 'visitorstats/viewsbycategory/xls');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'primary-links',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array());
  $handler->override_option('sitename_title', FALSE);
  $handler->override_option('use_batch', '0');
  $handler = $view->new_display('page', 'PDF', 'page_2');
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'dataset' => 'dataset',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'sid' => array(
      'operator' => 'in',
      'value' => array(),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('header_format', '3');
  $handler->override_option('header_empty', 0);
  $handler->override_option('items_per_page', 10);
  $handler->override_option('use_pager', '1');
  $handler->override_option('path', 'visitorstats/viewsbycategory/pdf');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
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
