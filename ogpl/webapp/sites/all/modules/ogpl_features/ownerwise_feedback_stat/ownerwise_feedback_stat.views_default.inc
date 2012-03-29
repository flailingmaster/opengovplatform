<?php

/**
 * Implementation of hook_views_default_views().
 */
function ownerwise_feedback_stat_views_default_views() {
  $views = array();

  // Exported view: ownerwise_feedback_stat
  $view = new view;
  $view->name = 'ownerwise_feedback_stat';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'feedback';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'owner_id' => array(
      'label' => 'owner_id',
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
      'id' => 'owner_id',
      'table' => 'feedback',
      'field' => 'owner_id',
      'relationship' => 'none',
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
$res=db_query("select users.name as name  from users where users.uid=\'$row->owner_id\'");
$result=db_fetch_object($res);
print $result->name;
?>',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php',
      'table' => 'views',
      'field' => 'php',
      'relationship' => 'none',
    ),
    'php_1' => array(
      'label' => 'Total Feedbacks',
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

if(!empty($from)){
$month_year=explode("/",$from);
$starttime = mktime(0, 0, 0, $month_year[0], 1, $month_year[1]);
$startdate=date(\'Y-m-d\', $starttime);
}
if(!empty($to)){
$month_year=explode("/",$to);
$num = cal_days_in_month(CAL_GREGORIAN, $month_year[0], $month_year[1]);
$endtime = mktime(0, 0, 0, $month_year[0], $num, $month_year[1]);
$enddate=date(\'Y-m-d\', $endtime);
}
if(empty($from) && empty($to))
{
$res=db_query("select count(feedback.feedback_id) as total from feedback where feedback.owner_id=\'$row->owner_id\'");
$result=db_fetch_object($res);
print $result->total;
}
else{
$res=db_query("select count(feedback.feedback_id) as total from feedback where feedback.owner_id=\'$row->owner_id\' and feedback.feedback_date>=\'$startdate\' and feedback.feedback_date<=\'$enddate\' ");
$result=db_fetch_object($res);
print $result->total;
}

?>',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_1',
      'table' => 'views',
      'field' => 'php',
      'relationship' => 'none',
    ),
    'php_2' => array(
      'label' => 'Assigned',
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

if(!empty($from)){
$month_year=explode("/",$from);
$starttime = mktime(0, 0, 0, $month_year[0], 1, $month_year[1]);
$startdate=date(\'Y-m-d\', $starttime);
}
if(!empty($to)){
$month_year=explode("/",$to);
$num = cal_days_in_month(CAL_GREGORIAN, $month_year[0], $month_year[1]);
$endtime = mktime(0, 0, 0, $month_year[0], $num, $month_year[1]);
$enddate=date(\'Y-m-d\', $endtime);
}
if(empty($from) && empty($to))
{
$res=db_query("select count(feedback.feedback_id) total from feedback where feedback.owner_id=\'$row->owner_id\' and feedback.status_id=\'2\'");
$result=db_fetch_object($res);
print $result->total;
}
else{
$res=db_query("select count(feedback.feedback_id) total from feedback where feedback.owner_id=\'$row->owner_id\' and feedback.status_id=\'2\' and feedback.feedback_date>=\'$startdate\' and feedback.feedback_date<=\'$enddate\' ");
$result=db_fetch_object($res);
print $result->total;
}

?>',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_2',
      'table' => 'views',
      'field' => 'php',
      'relationship' => 'none',
    ),
    'php_3' => array(
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

if(!empty($from)){
$month_year=explode("/",$from);
$starttime = mktime(0, 0, 0, $month_year[0], 1, $month_year[1]);
$startdate=date(\'Y-m-d\', $starttime);
}
if(!empty($to)){
$month_year=explode("/",$to);
$num = cal_days_in_month(CAL_GREGORIAN, $month_year[0], $month_year[1]);
$endtime = mktime(0, 0, 0, $month_year[0], $num, $month_year[1]);
$enddate=date(\'Y-m-d\', $endtime);
}
if(empty($from) && empty($to))
{
$res=db_query("select count(feedback.feedback_id) total from feedback where feedback.owner_id=\'$row->owner_id\' and feedback.status_id=\'4\'");
$result=db_fetch_object($res);
print $result->total;
}
else{
$res=db_query("select count(feedback.feedback_id) total from feedback where feedback.owner_id=\'$row->owner_id\' and feedback.status_id=\'4\' and feedback.feedback_date>=\'$startdate\' and feedback.feedback_date<=\'$enddate\' ");
$result=db_fetch_object($res);
print $result->total;
}
?>',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_3',
      'table' => 'views',
      'field' => 'php',
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

if(!empty($from)){
$month_year=explode("/",$from);
$starttime = mktime(0, 0, 0, $month_year[0], 1, $month_year[1]);
$startdate=date(\'Y-m-d\', $starttime);
}
if(!empty($to)){
$month_year=explode("/",$to);
$num = cal_days_in_month(CAL_GREGORIAN, $month_year[0], $month_year[1]);
$endtime = mktime(0, 0, 0, $month_year[0], $num, $month_year[1]);
$enddate=date(\'Y-m-d\', $endtime);
}
if(empty($from) && empty($to))
{
$res=db_query("select count(feedback.feedback_id) total from feedback where feedback.owner_id=\'$row->owner_id\' and feedback.status_id=\'5\'");
$result=db_fetch_object($res);
print $result->total;
}
else
{
$res=db_query("select count(feedback.feedback_id) total from feedback where feedback.owner_id=\'$row->owner_id\' and feedback.status_id=\'5\' and feedback.feedback_date>=\'$startdate\' and feedback.feedback_date<=\'$enddate\' ");
$result=db_fetch_object($res);
print $result->total;
}
?>',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_4',
      'table' => 'views',
      'field' => 'php',
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

if(!empty($from)){
$month_year=explode("/",$from);
$starttime = mktime(0, 0, 0, $month_year[0], 1, $month_year[1]);
$startdate=date(\'Y-m-d\', $starttime);
}
if(!empty($to)){
$month_year=explode("/",$to);
$num = cal_days_in_month(CAL_GREGORIAN, $month_year[0], $month_year[1]);
$endtime = mktime(0, 0, 0, $month_year[0], $num, $month_year[1]);
$enddate=date(\'Y-m-d\', $endtime);
}
if(empty($from) && empty($to))
{
$res=db_query("select count(feedback.feedback_id) total from feedback where feedback.owner_id=\'$row->owner_id\' and feedback.status_id=\'6\'");
$result=db_fetch_object($res);
print $result->total;
}
else{
$res=db_query("select count(feedback.feedback_id) total from feedback where feedback.owner_id=\'$row->owner_id\' and feedback.status_id=\'6\' and feedback.feedback_date>=\'$startdate\' and feedback.feedback_date<=\'$enddate\' ");
$result=db_fetch_object($res);
print $result->total;
}



?>',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_5',
      'table' => 'views',
      'field' => 'php',
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

if(!empty($from)){
$month_year=explode("/",$from);
$starttime = mktime(0, 0, 0, $month_year[0], 1, $month_year[1]);
$startdate=date(\'Y-m-d\', $starttime);
}
if(!empty($to)){
$month_year=explode("/",$to);
$num = cal_days_in_month(CAL_GREGORIAN, $month_year[0], $month_year[1]);
$endtime = mktime(0, 0, 0, $month_year[0], $num, $month_year[1]);
$enddate=date(\'Y-m-d\', $endtime);
}
if(empty($from) && empty($to))
{
$res=db_query("select count(feedback.feedback_id) total from feedback where feedback.owner_id=\'$row->owner_id\' and feedback.status_id=\'7\'");
$result=db_fetch_object($res);
print $result->total;
}
else{
$res=db_query("select count(feedback.feedback_id) total from feedback where feedback.owner_id=\'$row->owner_id\' and feedback.status_id=\'7\' and feedback.feedback_date>=\'$startdate\' and feedback.feedback_date<=\'$enddate\' ");
$result=db_fetch_object($res);
print $result->total;
}
?>',
      'use_php_click_sortable' => '0',
      'php_click_sortable' => '',
      'exclude' => 0,
      'id' => 'php_6',
      'table' => 'views',
      'field' => 'php',
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
      'owner_id' => 'owner_id',
    ),
    'info' => array(
      'owner_id' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));

  $views[$view->name] = $view;

  return $views;
}
