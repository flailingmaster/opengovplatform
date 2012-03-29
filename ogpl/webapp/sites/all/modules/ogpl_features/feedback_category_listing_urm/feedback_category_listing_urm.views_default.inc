<?php

/**
 * Implementation of hook_views_default_views().
 */
function feedback_category_listing_urm_views_default_views() {
  $views = array();

  // Exported view: feedback_category_listing
  $view = new view;
  $view->name = 'feedback_category_listing';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'term_data';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'name' => array(
      'label' => 'Term',
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
      'link_to_taxonomy' => 0,
      'exclude' => 0,
      'id' => 'name',
      'table' => 'term_data',
      'field' => 'name',
      'relationship' => 'none',
    ),
    'tid' => array(
      'label' => 'Term ID',
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
      'id' => 'tid',
      'table' => 'term_data',
      'field' => 'tid',
      'relationship' => 'none',
    ),
    'php' => array(
      'label' => 'Total Feedback Assigned',
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
$res=db_query("select count(node.nid) as cnt
from node,workflow_node,term_data,term_node  
where workflow_node.sid=26 and workflow_node.nid=node.nid
and 
term_node.nid=node.nid and term_data.tid=$row->tid and term_node.tid=term_data.tid");
$res1=db_fetch_object($res);
print $res1->cnt;
?>
',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php',
      'table' => 'views',
      'field' => 'php',
      'relationship' => 'none',
    ),
    'php_1' => array(
      'label' => 'Total Feedback Replied',
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
$res=db_query("select count(node.nid) as cnt
from node,workflow_node,term_data,term_node  
where workflow_node.sid=27 and workflow_node.nid=node.nid
and 
term_node.nid=node.nid and term_data.tid=$row->tid and term_node.tid=term_data.tid");
$res1=db_fetch_object($res);
print $res1->cnt;
?>
',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_1',
      'table' => 'views',
      'field' => 'php',
      'relationship' => 'none',
    ),
    'php_2' => array(
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
$start_date=explode("/",$from);
$starttime = mktime(0, 0, 0, $start_date[0], $start_date[1], $start_date[2]);
$end_date=explode("/",$to);
$endtime = mktime(11, 59, 59, $end_date[0], $end_date[1], $end_date[2]);
$date_condition="workflow_node.stamp>=$starttime and workflow_node.stamp<=$endtime";


//$date_condition="DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')>=\'".$from."\' and DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')<=\'".$to."\'";
}

$res=db_query("select count(node.nid) as cnt
from node,workflow_node,term_data,term_node  
where workflow_node.sid=29 and workflow_node.nid=node.nid
and 
term_node.nid=node.nid and term_data.tid=$row->tid and term_node.tid=term_data.tid
and
$date_condition");
$res1=db_fetch_object($res);

print $res1->cnt;

?>
',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_2',
      'table' => 'views',
      'field' => 'php',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'vid' => array(
      'operator' => 'in',
      'value' => array(
        1 => '1',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'vid',
      'table' => 'term_data',
      'field' => 'vid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'summary' => '',
    'columns' => array(
      'name' => 'name',
      'tid' => 'tid',
    ),
    'info' => array(
      'name' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'tid' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('page', 'VRM Category Metrics', 'page_1');
  $handler->override_option('fields', array(
    'name' => array(
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
      'link_to_taxonomy' => 0,
      'exclude' => 0,
      'id' => 'name',
      'table' => 'term_data',
      'field' => 'name',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'tid' => array(
      'label' => 'Term ID',
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
      'id' => 'tid',
      'table' => 'term_data',
      'field' => 'tid',
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

//$date_condition="DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')>=\'".$from."\' and DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')<=\'".$to."\'";
}

$res=db_query("select count(node.nid) as cnt
from node,workflow_node,term_data,term_node  
where workflow_node.sid=32 and workflow_node.nid=node.nid
and 
term_node.nid=node.nid and term_data.tid=$row->tid and term_node.tid=term_data.tid
and
$date_condition");
$res1=db_fetch_object($res);

print $res1->cnt;

?>
',
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
    'php' => array(
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


//$date_condition="DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')>=\'".$from."\' and DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')<=\'".$to."\'";
}

$res=db_query("select count(node.nid) as cnt
from node,workflow_node,term_data, content_field_category 
where workflow_node.sid=27 and workflow_node.nid=node.nid
and 
content_field_category.nid=node.nid and term_data.tid=$row->tid and content_field_category.field_category_value=term_data.tid
and
$date_condition");
$res1=db_fetch_object($res);

print $res1->cnt;

?>
',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php',
      'table' => 'views',
      'field' => 'php',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'php_7' => array(
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


//$date_condition="DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')>=\'".$from."\' and DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')<=\'".$to."\'";
}

$res=db_query("select count(node.nid) as cnt
from node,workflow_node,term_data,term_node  
where workflow_node.sid=33 and workflow_node.nid=node.nid
and 
term_node.nid=node.nid and term_data.tid=$row->tid and term_node.tid=term_data.tid
and
$date_condition");
$res1=db_fetch_object($res);

print $res1->cnt;

?>
',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_7',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'php_8' => array(
      'label' => 'Irrelevant',
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


//$date_condition="DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')>=\'".$from."\' and DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')<=\'".$to."\'";
}

$res=db_query("select count(node.nid) as cnt
from node,workflow_node,term_data,term_node  
where workflow_node.sid=34 and workflow_node.nid=node.nid
and 
term_node.nid=node.nid and term_data.tid=$row->tid and term_node.tid=term_data.tid
and
$date_condition");
$res1=db_fetch_object($res);

print $res1->cnt;

?>
',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_8',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'php_4' => array(
      'label' => 'Opened',
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


//$date_condition="DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')>=\'".$from."\' and DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')<=\'".$to."\'";
}

$res=db_query("select count(node.nid) as cnt
from node,workflow_node,term_data,term_node  
where workflow_node.sid=26 and workflow_node.nid=node.nid
and 
term_node.nid=node.nid and term_data.tid=$row->tid and term_node.tid=term_data.tid
and
$date_condition");
$res1=db_fetch_object($res);

print $res1->cnt;

?>
',
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
    'php_1' => array(
      'label' => ' Replied',
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
$res=db_query("select count(node.nid) as cnt
from node,workflow_node,term_data,content_field_category
where workflow_node.sid=28 and workflow_node.nid=node.nid
and 
content_field_category.nid=node.nid and term_data.tid=$row->tid and content_field_category.field_category_value=term_data.tid
and
$date_condition");
$res1=db_fetch_object($res);
print $res1->cnt;
?>
',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_1',
      'table' => 'views',
      'field' => 'php',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'php_3' => array(
      'label' => 'Reverted',
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


//$date_condition="DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')>=\'".$from."\' and DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')<=\'".$to."\'";
}

$res=db_query("select count(node.nid) as cnt
from node,workflow_node,term_data,term_node  
where workflow_node.sid=30 and workflow_node.nid=node.nid
and 
term_node.nid=node.nid and term_data.tid=$row->tid and term_node.tid=term_data.tid
and
$date_condition");
$res1=db_fetch_object($res);

print $res1->cnt;

?>
',
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
    'php_2' => array(
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


//$date_condition="DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')>=\'".$from."\' and DATE_FORMAT(FROM_UNIXTIME(workflow_node.stamp), \'%m/%d/%Y\')<=\'".$to."\'";
}

$res=db_query("select count(node.nid) as cnt
from node,workflow_node,term_data,term_node  
where workflow_node.sid=29 and workflow_node.nid=node.nid
and 
term_node.nid=node.nid and term_data.tid=$row->tid and term_node.tid=term_data.tid
and
$date_condition");
$res1=db_fetch_object($res);

print $res1->cnt;

?>
',
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
  ));
  $handler->override_option('filters', array(
    'vid' => array(
      'operator' => 'in',
      'value' => array(
        2 => '2',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'vid',
      'table' => 'term_data',
      'field' => 'vid',
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
  $handler->override_option('title', 'VRM Category Metrics');
  $handler->override_option('path', 'vrm-category-metrics');
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
