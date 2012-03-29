<?php

/**
 * Implementation of hook_default_fe_block_boxes().
 */
function node_expiry_alert_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Block to display messages if content is due for review';
  $fe_block_boxes->format = '3';
  $fe_block_boxes->machine_name = 'cms_notification_alert';
  $fe_block_boxes->body = '<?php
$view = views_get_view_result(\'list_of_expired_contents\');
$count=sizeof($view);
if($count>1)
echo\'There are \'.$count .\' published contents due for review.Click <a href="expiredcontents">here</a> for more details.\';
if($count==1)
echo\'There is only \'.$count .\' published content due for review.Click <a href="expiredcontents">here</a> for more details.\';
?>';

  $export['cms_notification_alert'] = $fe_block_boxes;

  return $export;
}
