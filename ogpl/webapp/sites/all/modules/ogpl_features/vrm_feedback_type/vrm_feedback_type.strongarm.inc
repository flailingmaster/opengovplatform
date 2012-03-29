<?php

/**
 * Implementation of hook_strongarm().
 */
function vrm_feedback_type_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_feedback';
  $strongarm->value = '0';
  $export['comment_anonymous_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_feedback';
  $strongarm->value = '3';
  $export['comment_controls_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_feedback';
  $strongarm->value = '4';
  $export['comment_default_mode_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_feedback';
  $strongarm->value = '1';
  $export['comment_default_order_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_feedback';
  $strongarm->value = '50';
  $export['comment_default_per_page_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_feedback';
  $strongarm->value = '2';
  $export['comment_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_feedback';
  $strongarm->value = '0';
  $export['comment_form_location_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_feedback';
  $strongarm->value = '0';
  $export['comment_preview_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_feedback';
  $strongarm->value = '1';
  $export['comment_subject_field_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_feedback';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '11',
    'author' => '12',
    'options' => '13',
    'comment_settings' => '14',
    'menu' => '7',
    'taxonomy' => '-2',
    'path' => '15',
    'detailed_question' => '9',
    'workflow' => '8',
    'print' => '16',
    'nodewords' => '10',
  );
  $export['content_extra_weights_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_feedback';
  $strongarm->value = '0';
  $export['language_content_type_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_feedback';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_feedback';
  $strongarm->value = '0';
  $export['upload_feedback'] = $strongarm;

  return $export;
}
