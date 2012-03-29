<?php

/**
 * Implementation of hook_default_fe_block_boxes().
 */
function front_end_major_events_tab_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->machine_name = 'front_end_major_events_block';
  $fe_block_boxes->body = NULL;

  $export['front_end_major_events_block'] = $fe_block_boxes;

  return $export;
}
