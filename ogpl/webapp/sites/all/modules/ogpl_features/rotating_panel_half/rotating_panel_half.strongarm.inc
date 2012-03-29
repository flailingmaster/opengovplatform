<?php

/**
 * Implementation of hook_strongarm().
 */
function rotating_panel_half_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_rotating_panel_half';
  $strongarm->value = '0';
  $export['comment_anonymous_rotating_panel_half'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_rotating_panel_half';
  $strongarm->value = '3';
  $export['comment_controls_rotating_panel_half'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_rotating_panel_half';
  $strongarm->value = '4';
  $export['comment_default_mode_rotating_panel_half'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_rotating_panel_half';
  $strongarm->value = '1';
  $export['comment_default_order_rotating_panel_half'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_rotating_panel_half';
  $strongarm->value = '50';
  $export['comment_default_per_page_rotating_panel_half'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_rotating_panel_half';
  $strongarm->value = '0';
  $export['comment_form_location_rotating_panel_half'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_rotating_panel_half';
  $strongarm->value = '1';
  $export['comment_preview_rotating_panel_half'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_rotating_panel_half';
  $strongarm->value = '2';
  $export['comment_rotating_panel_half'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_rotating_panel_half';
  $strongarm->value = '1';
  $export['comment_subject_field_rotating_panel_half'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_rotating_panel_half';
  $strongarm->value = array(
    'detailed_question' => '2',
    'title' => '-5',
    'body_field' => '0',
    'revision_information' => '4',
    'author' => '3',
    'options' => '5',
    'comment_settings' => '6',
    'menu' => '-1',
    'path' => '7',
    'attachments' => '8',
    'workflow' => '1',
  );
  $export['content_extra_weights_rotating_panel_half'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_rotating_panel_half';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_rotating_panel_half'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_rotating_panel_half';
  $strongarm->value = '1';
  $export['upload_rotating_panel_half'] = $strongarm;

  return $export;
}
