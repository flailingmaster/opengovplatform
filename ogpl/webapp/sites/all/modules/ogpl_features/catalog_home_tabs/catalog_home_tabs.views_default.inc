<?php

/**
 * Implementation of hook_views_default_views().
 */
function catalog_home_tabs_views_default_views() {
  $views = array();

  // Exported view: Most_Popular_Catalog
  $view = new view;
  $view->name = 'Most_Popular_Catalog';
  $view->description = 'Most Popular Catalog';
  $view->tag = '';
  $view->base_table = 'blocks';
  $view->core = 0;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'body' => array(
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
      'exclude' => 1,
      'id' => 'body',
      'table' => 'boxes',
      'field' => 'body',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'phpcode' => array(
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
      'value' => '<?php echo  views_embed_view(trim($data->boxes_body));',
      'exclude' => 0,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('filters', array(
    'title' => array(
      'operator' => '=',
      'value' => 'Most Popular Catalog',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'case' => 1,
      'id' => 'title',
      'table' => 'blocks',
      'field' => 'title',
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
      'table' => 'blocks',
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
  $handler->override_option('style_plugin', 'slideshow');
  $handler->override_option('style_options', array(
    'type' => 'ul',
    'mode' => 'views_slideshow_singleframe',
    'views_slideshow_singleframe-prefix' => '',
    'views_slideshow_singleframe' => array(
      'timeout' => '5000',
      'delay' => '0',
      'speed' => '700',
      'start_paused' => 0,
      'fixed_height' => '1',
      'random' => '0',
      'pause' => '1',
      'pause_on_click' => '0',
      'pause_when_hidden' => 0,
      'pause_when_hidden_type' => 'full',
      'amount_allowed_visible' => '',
      'remember_slide' => 0,
      'remember_slide_days' => '1',
      'controls' => '0',
      'pager' => '0',
      'pager_type' => 'Numbered',
      'pager_hover' => '2',
      'pager_click_to_page' => 0,
      'image_count' => '0',
      'items_per_slide' => '1',
      'effect' => 'fade',
      'sync' => '1',
      'nowrap' => '0',
      'advanced' => '',
      'ie' => array(
        'cleartype' => 'true',
        'cleartypenobg' => 'false',
      ),
    ),
    'views_slideshow_thumbnailhover-prefix' => '',
    'views_slideshow_thumbnailhover' => array(
      'main_fields' => array(
        'phpcode' => 0,
      ),
      'breakout_fields' => array(
        'phpcode' => 0,
      ),
      'teasers_last' => 1,
      'timeout' => '5000',
      'delay' => '0',
      'speed' => '300',
      'start_paused' => 0,
      'fixed_height' => '1',
      'random' => '0',
      'pause' => '1',
      'pause_on_click' => '0',
      'pause_when_hidden' => 0,
      'pause_when_hidden_type' => 'full',
      'amount_allowed_visible' => '',
      'remember_slide' => 0,
      'remember_slide_days' => '1',
      'pager_event' => 'mouseover',
      'controls' => '0',
      'image_count' => '0',
      'effect' => 'fade',
      'sync' => '1',
      'nowrap' => '1',
      'advanced' => '',
      'ie' => array(
        'cleartype' => 'true',
        'cleartypenobg' => 'false',
      ),
    ),
    'views_slideshow_imageflow-prefix' => '',
    'views_slideshow_imageflow' => array(
      'aspect_ratio' => '1.964',
      'images_height' => '0.67',
      'image_cursor' => 'pointer',
      'slider' => 1,
      'slider_cursor' => 'pointer',
      'start' => 'middle',
      'captions' => 1,
      'imageFocusM' => '1.0',
      'scrollbarP' => '0.6',
      'imageFocusMax' => '4',
      'onClick' => 'function() { document.location = this.url; }',
    ),
  ));
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  // Exported view: Most_Recent_Catalog
  $view = new view;
  $view->name = 'Most_Recent_Catalog';
  $view->description = 'Most Recent Catalog';
  $view->tag = '';
  $view->base_table = 'blocks';
  $view->core = 0;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'body' => array(
      'label' => '',
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
      'exclude' => 1,
      'id' => 'body',
      'table' => 'boxes',
      'field' => 'body',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'phpcode' => array(
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
      'value' => '<?php echo  views_embed_view(trim($data->boxes_body));',
      'exclude' => 0,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('filters', array(
    'title' => array(
      'operator' => '=',
      'value' => 'Most Recent Catalog',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'case' => 1,
      'id' => 'title',
      'table' => 'blocks',
      'field' => 'title',
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
      'table' => 'blocks',
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
  $handler->override_option('style_plugin', 'slideshow');
  $handler->override_option('style_options', array(
    'type' => 'ul',
    'mode' => 'views_slideshow_singleframe',
    'views_slideshow_imageflow-prefix' => '',
    'views_slideshow_imageflow' => array(
      'aspect_ratio' => '1.964',
      'images_height' => '0.67',
      'image_cursor' => 'pointer',
      'slider' => 1,
      'slider_cursor' => 'pointer',
      'start' => 'middle',
      'captions' => 1,
      'imageFocusM' => '1.0',
      'scrollbarP' => '0.6',
      'imageFocusMax' => '4',
      'onClick' => 'function() { document.location = this.url; }',
      'buttons' => 0,
      'circular' => 0,
    ),
    'views_slideshow_singleframe-prefix' => '',
    'views_slideshow_singleframe' => array(
      'timeout' => '5000',
      'delay' => '0',
      'speed' => '700',
      'start_paused' => 0,
      'fixed_height' => '1',
      'random' => '0',
      'pause' => '1',
      'pause_on_click' => '0',
      'pause_when_hidden' => 0,
      'pause_when_hidden_type' => 'full',
      'amount_allowed_visible' => '',
      'remember_slide' => 0,
      'remember_slide_days' => '1',
      'controls' => '0',
      'pager' => '0',
      'pager_type' => 'Numbered',
      'pager_hover' => '2',
      'pager_click_to_page' => 0,
      'image_count' => '0',
      'items_per_slide' => '1',
      'effect' => 'fade',
      'sync' => '1',
      'nowrap' => '0',
      'advanced' => '',
      'ie' => array(
        'cleartype' => 'true',
        'cleartypenobg' => 'false',
      ),
    ),
    'views_slideshow_thumbnailhover-prefix' => '',
    'views_slideshow_thumbnailhover' => array(
      'main_fields' => array(
        'phpcode' => 0,
      ),
      'breakout_fields' => array(
        'phpcode' => 0,
      ),
      'teasers_last' => 1,
      'timeout' => '5000',
      'delay' => '0',
      'speed' => '300',
      'start_paused' => 0,
      'fixed_height' => '1',
      'random' => '0',
      'pause' => '1',
      'pause_on_click' => '0',
      'pause_when_hidden' => 0,
      'pause_when_hidden_type' => 'full',
      'amount_allowed_visible' => '',
      'remember_slide' => 0,
      'remember_slide_days' => '1',
      'pager_event' => 'mouseover',
      'controls' => '0',
      'image_count' => '0',
      'effect' => 'fade',
      'sync' => '1',
      'nowrap' => '1',
      'advanced' => '',
      'ie' => array(
        'cleartype' => 'true',
        'cleartypenobg' => 'false',
      ),
    ),
  ));
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  // Exported view: Popular_Apps_Catalog
  $view = new view;
  $view->name = 'Popular_Apps_Catalog';
  $view->description = 'Popular Apps Catalog';
  $view->tag = 'popular recent catalogs';
  $view->base_table = 'node';
  $view->core = 0;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '[title] ',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '40',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 1,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
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
    'field_ds_catlog_type_item_id' => array(
      'operator' => '=',
      'value' => array(
        'value' => 'catalog_type_data_apps',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'field_ds_catlog_type_item_id',
      'table' => 'node_data_field_ds_catlog_type',
      'field' => 'field_ds_catlog_type_item_id',
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
  $handler->override_option('items_per_page', 5);

  $views[$view->name] = $view;

  // Exported view: Popular_Dataset_Catalog
  $view = new view;
  $view->name = 'Popular_Dataset_Catalog';
  $view->description = 'Popular Dataset Catalog';
  $view->tag = 'popular recent catalogs';
  $view->base_table = 'node';
  $view->core = 0;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '[title] ',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '40',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 1,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
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
    'field_ds_catlog_type_item_id' => array(
      'operator' => '=',
      'value' => array(
        'value' => 'catalog_type_raw_data',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'field_ds_catlog_type_item_id',
      'table' => 'node_data_field_ds_catlog_type',
      'field' => 'field_ds_catlog_type_item_id',
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
  $handler->override_option('items_per_page', 5);

  $views[$view->name] = $view;

  // Exported view: Popular_Document_Catalog
  $view = new view;
  $view->name = 'Popular_Document_Catalog';
  $view->description = 'Popular Document Catalog';
  $view->tag = 'popular recent catalogs';
  $view->base_table = 'node';
  $view->core = 0;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '[title]  ',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '40',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 1,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
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
    'field_ds_catlog_type_item_id' => array(
      'operator' => '=',
      'value' => array(
        'value' => 'catalog_type_document',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'field_ds_catlog_type_item_id',
      'table' => 'node_data_field_ds_catlog_type',
      'field' => 'field_ds_catlog_type_item_id',
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
  $handler->override_option('items_per_page', 5);

  $views[$view->name] = $view;

  // Exported view: Recent_Apps_Catalog
  $view = new view;
  $view->name = 'Recent_Apps_Catalog';
  $view->description = 'Recent Apps Catalog';
  $view->tag = 'popular recent catalogs';
  $view->base_table = 'node';
  $view->core = 0;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '[title] ',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '40',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 1,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
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
    'field_ds_catlog_type_item_id' => array(
      'operator' => '=',
      'value' => array(
        'value' => 'catalog_type_data_apps',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'field_ds_catlog_type_item_id',
      'table' => 'node_data_field_ds_catlog_type',
      'field' => 'field_ds_catlog_type_item_id',
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
  $handler->override_option('items_per_page', 5);

  $views[$view->name] = $view;

  // Exported view: Recent_Dataset_Catalog
  $view = new view;
  $view->name = 'Recent_Dataset_Catalog';
  $view->description = 'Recent Dataset Catalog';
  $view->tag = 'popular recent catalogs';
  $view->base_table = 'node';
  $view->core = 0;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '[title] ',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '40',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 1,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
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
    'field_ds_catlog_type_item_id' => array(
      'operator' => '=',
      'value' => array(
        'value' => 'catalog_type_raw_data',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'field_ds_catlog_type_item_id',
      'table' => 'node_data_field_ds_catlog_type',
      'field' => 'field_ds_catlog_type_item_id',
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
  $handler->override_option('items_per_page', 5);

  $views[$view->name] = $view;

  // Exported view: Recent_Document_Catalog
  $view = new view;
  $view->name = 'Recent_Document_Catalog';
  $view->description = 'Recent Document Catalog';
  $view->tag = 'popular recent catalogs';
  $view->base_table = 'node';
  $view->core = 0;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '[title] ',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '40',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 1,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'created' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'created',
      'table' => 'node',
      'field' => 'created',
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
    'field_ds_catlog_type_item_id' => array(
      'operator' => '=',
      'value' => array(
        'value' => 'catalog_type_document',
        'min' => '',
        'max' => '',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'field_ds_catlog_type_item_id',
      'table' => 'node_data_field_ds_catlog_type',
      'field' => 'field_ds_catlog_type_item_id',
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
  $handler->override_option('items_per_page', 5);

  $views[$view->name] = $view;

  return $views;
}
