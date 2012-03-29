<?php

/**
 * Implementation of hook_views_default_views().
 */
function assigneewise_feedback_listing_urm_views_default_views() {
  $views = array();

  // Exported view: ownerwise_feedback_listing
  $view = new view;
  $view->name = 'ownerwise_feedback_listing';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'content_type_feedback';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'field_assigned_to_uid' => array(
      'label' => 'field_assigned_to_uid',
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
      'id' => 'field_assigned_to_uid',
      'table' => 'content_type_feedback',
      'field' => 'field_assigned_to_uid',
      'relationship' => 'none',
    ),
    'php' => array(
      'id' => 'php',
      'table' => 'views',
      'field' => 'php',
    ),
  ));
  $handler->override_option('filters', array(
    'field_assigned_to_uid' => array(
      'operator' => '=',
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
      'id' => 'field_assigned_to_uid',
      'table' => 'content_type_feedback',
      'field' => 'field_assigned_to_uid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('distinct', 0);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'summary' => '',
    'columns' => array(
      'field_assigned_to_uid' => 'field_assigned_to_uid',
    ),
    'info' => array(
      'field_assigned_to_uid' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('page', 'assignee_wise_VRM_listing', 'page_1');
  $handler->override_option('fields', array(
    'field_assigned_to_uid' => array(
      'label' => 'field_assigned_to_uid',
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
      'exclude' => 1,
      'id' => 'field_assigned_to_uid',
      'table' => 'content_type_feedback',
      'field' => 'field_assigned_to_uid',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'php' => array(
      'label' => 'Assignee',
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
      'use_php_setup' => 0,
      'php_setup' => '',
      'php_value' => '',
      'php_output' => '<?php
$res=db_query("select name from users where uid=$row->field_assigned_to_uid");
$res1=db_fetch_object($res);
print $res1->name;
?> ',
      'use_php_click_sortable' => '2',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'php_3' => array(
      'label' => 'Total Feedback',
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
      'use_php_setup' => 0,
      'php_setup' => '',
      'php_value' => '',
      'php_output' => '<?php
$from=$_GET[\'from\'];
$to=$_GET[\'to\'];
if(empty($from) && empty($to))
$date_condition="1";
else{
$start_time=$from." 00:00:00";
$end_time=$to." 23:59:59";
$date_condition="FROM_UNIXTIME(node.created) >= \'$start_time\' and FROM_UNIXTIME(node.created) <= \'$end_time\'";
}
$res=db_query("select count(content_type_feedback.nid) as cnt
from workflow_node,content_type_feedback,node  
where  workflow_node.nid=content_type_feedback.nid
and content_type_feedback.nid=node.nid and
content_type_feedback.`field_assigned_to_uid`=$row->field_assigned_to_uid and $date_condition");
$res1=db_fetch_object($res);
print $res1->cnt;
?>',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_3',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'php_1' => array(
      'label' => ' Assigned',
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
      'use_php_setup' => 0,
      'php_setup' => '',
      'php_value' => '',
      'php_output' => '<?php
$from=$_GET[\'from\'];
$to=$_GET[\'to\'];

if(empty($from) && empty($to))
$date_condition="1";
else{
$start_time=$from." 00:00:00";
$end_time=$to." 23:59:59";
$date_condition="FROM_UNIXTIME(node.created) >= \'$start_time\' and FROM_UNIXTIME(node.created) <= \'$end_time\'";

}
$res=db_query("select count(content_type_feedback.nid) as cnt
from workflow_node,content_type_feedback ,node 
where workflow_node.sid=27 and workflow_node.nid=content_type_feedback.nid
and content_type_feedback.nid=node.nid and
content_type_feedback.`field_assigned_to_uid`=$row->field_assigned_to_uid and $date_condition");
$res1=db_fetch_object($res);
print $res1->cnt;
?>',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_1',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'php_2' => array(
      'label' => 'Replied',
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
      'use_php_setup' => 0,
      'php_setup' => '',
      'php_value' => '',
      'php_output' => '<?php
$from=$_GET[\'from\'];
$to=$_GET[\'to\'];

if(empty($from) && empty($to))
$date_condition="1";
else{
$start_time=$from." 00:00:00";
$end_time=$to." 23:59:59";
$date_condition="FROM_UNIXTIME(node.created) >= \'$start_time\' and FROM_UNIXTIME(node.created) <= \'$end_time\'";

}
$res=db_query("select count(content_type_feedback.nid) as cnt
from workflow_node,content_type_feedback ,node 
where workflow_node.sid=28 and workflow_node.nid=content_type_feedback.nid
and content_type_feedback.nid=node.nid and
content_type_feedback.`field_assigned_to_uid`=$row->field_assigned_to_uid and $date_condition");
$res1=db_fetch_object($res);
print $res1->cnt;
?>',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_2',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'php_4' => array(
      'label' => 'Reviewed',
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
      'use_php_setup' => 0,
      'php_setup' => '',
      'php_value' => '',
      'php_output' => '<?php
$from=$_GET[\'from\'];
$to=$_GET[\'to\'];

if(empty($from) && empty($to))
$date_condition="1";
else{
$start_time=$from." 00:00:00";
$end_time=$to." 23:59:59";
$date_condition="FROM_UNIXTIME(node.created) >= \'$start_time\' and FROM_UNIXTIME(node.created) <= \'$end_time\'";

}
$res=db_query("select count(content_type_feedback.nid) as cnt
from workflow_node,content_type_feedback,node  
where workflow_node.sid=29 and workflow_node.nid=content_type_feedback.nid
and content_type_feedback.nid=node.nid and
content_type_feedback.`field_assigned_to_uid`=$row->field_assigned_to_uid and $date_condition");
$res1=db_fetch_object($res);
print $res1->cnt;
?>',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_4',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'php_5' => array(
      'label' => 'Closed',
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
      'use_php_setup' => 0,
      'php_setup' => '',
      'php_value' => '',
      'php_output' => '<?php
$from=$_GET[\'from\'];
$to=$_GET[\'to\'];

if(empty($from) && empty($to))
$date_condition="1";
else{
$start_time=$from." 00:00:00";
$end_time=$to." 23:59:59";
$date_condition="FROM_UNIXTIME(node.created) >= \'$start_time\' and FROM_UNIXTIME(node.created) <= \'$end_time\'";

}
$res=db_query("select count(content_type_feedback.nid) as cnt
from workflow_node,content_type_feedback ,node 
where workflow_node.sid=33 and workflow_node.nid=content_type_feedback.nid
and content_type_feedback.nid=node.nid and
content_type_feedback.`field_assigned_to_uid`=$row->field_assigned_to_uid and $date_condition");
$res1=db_fetch_object($res);
print $res1->cnt;
?>',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_5',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'php_6' => array(
      'label' => 'Archived',
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
      'use_php_setup' => 0,
      'php_setup' => '',
      'php_value' => '',
      'php_output' => '<?php
$from=$_GET[\'from\'];
$to=$_GET[\'to\'];

if(empty($from) && empty($to))
$date_condition="1";
else{
$start_time=$from." 00:00:00";
$end_time=$to." 23:59:59";
$date_condition="FROM_UNIXTIME(node.created) >= \'$start_time\' and FROM_UNIXTIME(node.created) <= \'$end_time\'";

}
$res=db_query("select count(content_type_feedback.nid) as cnt
from workflow_node,content_type_feedback,node  
where workflow_node.sid=32 and workflow_node.nid=content_type_feedback.nid
and content_type_feedback.nid=node.nid and
content_type_feedback.`field_assigned_to_uid`=$row->field_assigned_to_uid and $date_condition");
$res1=db_fetch_object($res);
print $res1->cnt;
?>',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_6',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'field_assigned_to_uid' => array(
      'operator' => '!=',
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
      'id' => 'field_assigned_to_uid',
      'table' => 'content_type_feedback',
      'field' => 'field_assigned_to_uid',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'role',
    'role' => array(
      18 => 18,
      6 => 6,
      15 => 15,
    ),
  ));
  $handler->override_option('title', 'Assignee Wise VRM Listing');
  $handler->override_option('empty', '<div class="chart-error">No data found </div>');
  $handler->override_option('empty_format', '2');
  $handler->override_option('items_per_page', 0);
  $handler->override_option('distinct', 1);
  $handler->override_option('path', 'assigneewise-vrm-listing');
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
