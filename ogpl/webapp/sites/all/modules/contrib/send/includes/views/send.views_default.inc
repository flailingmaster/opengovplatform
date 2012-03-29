<?php
/**
 * Implementation of hook_views_default_views().
 */
function send_views_default_views() {
  /* TODO this view is horribly broken (http://drupal.org/node/911936) and
     publicly available (http://drupal.org/node/480844).  I rule!

     Commenting out until this can be fixed correctly.
  */
  return;

  $view = new view;
  $view->name = 'send';
  $view->description = 'Default views provided by the Send module';
  $view->tag = 'send';
  $view->view_php = '';
  $view->base_table = 'send';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'uid' => array(
      'label' => 'Sender',
      'required' => 1,
      'id' => 'uid',
      'table' => 'send',
      'field' => 'uid',
      'relationship' => 'none',
    ),
    'rid' => array(
      'label' => 'Recipient',
      'required' => 0,
      'id' => 'rid',
      'table' => 'send_recipient',
      'field' => 'rid',
      'relationship' => 'none',
    ),
    'nid' => array(
      'label' => 'Node',
      'required' => 0,
      'id' => 'nid',
      'table' => 'send_recipient',
      'field' => 'nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'nid',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('distinct', 0);
  $handler->override_option('style_options', array(
    'grouping' => '',
  ));
  $handler = $view->new_display('page', 'Send node history', 'page_1');
  $handler->override_option('fields', array(
    'timestamp' => array(
      'label' => 'Timestamp',
      'date_format' => 'small',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'timestamp',
      'table' => 'send',
      'field' => 'timestamp',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'name' => array(
      'label' => 'Sender',
      'link_to_user' => 1,
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'relationship' => 'uid',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'name_1' => array(
      'label' => 'Recipient',
      'link_to_user' => 1,
      'exclude' => 0,
      'id' => 'name_1',
      'table' => 'users',
      'field' => 'name',
      'relationship' => 'rid',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'subject' => array(
      'label' => 'Subject',
      'exclude' => 0,
      'id' => 'subject',
      'table' => 'send',
      'field' => 'subject',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'message' => array(
      'label' => 'Message',
      'exclude' => 0,
      'id' => 'message',
      'table' => 'send',
      'field' => 'message',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'module' => array(
      'label' => 'Module',
      'exclude' => 0,
      'id' => 'module',
      'table' => 'send',
      'field' => 'module',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'timestamp' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'timestamp',
      'table' => 'send',
      'field' => 'timestamp',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'default_argument_type' => 'node',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'ignore',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'nid',
      'override' => array(
        'button' => 'Use default',
      ),
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'event' => 0,
        'image' => 0,
        'news' => 0,
        'page' => 0,
        'portfolio' => 0,
        'profile' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        '2' => 0,
        '1' => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'view send statistics',
  ));
  $handler->override_option('title', 'Email history');
  $handler->override_option('use_ajax', TRUE);
  $handler->override_option('items_per_page', 20);
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'columns' => array(
      'timestamp' => 'timestamp',
      'name' => 'name',
      'name_1' => 'name_1',
      'subject' => 'subject',
      'message' => 'message',
      'module' => 'module',
    ),
    'info' => array(
      'timestamp' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'name_1' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'subject' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'message' => array(
        'separator' => '',
      ),
      'module' => array(
        'sortable' => 1,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler->override_option('path', 'node/%/send');
  $handler->override_option('menu', array(
    'type' => 'tab',
    'title' => 'Email history',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'weight' => '0',
  ));
  $handler = $view->new_display('block', 'Most emailed', 'block_1');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'nid',
    ),
    'send_count' => array(
      'label' => 'Recipients',
      'exclude' => 1,
      'id' => 'send_count',
      'table' => 'send',
      'field' => 'send_count',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'count_type' => 'send_count',
    ),
  ));
  $handler->override_option('sorts', array(
    'send_count' => array(
      'order' => 'DESC',
      'group_by_node' => 1,
      'count_type' => 'send_count',
      'id' => 'send_count',
      'table' => 'send',
      'field' => 'send_count',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Most emailed');
  $handler->override_option('use_more', 1);
  $handler->override_option('style_plugin', 'list');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'type' => 'ol',
  ));
  $handler->override_option('block_description', 'Most emailed');
  $handler->override_option('block_caching', -1);
  $handler = $view->new_display('block', 'Recently emailed', 'block_2');
  $handler->override_option('sorts', array(
    'timestamp' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'group_by_node' => 1,
      'id' => 'timestamp',
      'table' => 'send',
      'field' => 'timestamp',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Recently emailed');
  $handler->override_option('use_more', 1);
  $handler->override_option('block_description', 'Recently emailed');
  $handler->override_option('block_caching', -1);
  $views[$view->name] = $view;

  return $views;
}
