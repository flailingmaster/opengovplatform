<?php

/**
 * Implementation of hook_strongarm().
 */
function vrm_feedback_reply_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_feedback_reply';
  $strongarm->value = '0';
  $export['comment_anonymous_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_feedback_reply';
  $strongarm->value = '3';
  $export['comment_controls_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_feedback_reply';
  $strongarm->value = '4';
  $export['comment_default_mode_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_feedback_reply';
  $strongarm->value = '1';
  $export['comment_default_order_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_feedback_reply';
  $strongarm->value = '50';
  $export['comment_default_per_page_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_feedback_reply';
  $strongarm->value = '0';
  $export['comment_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_feedback_reply';
  $strongarm->value = '0';
  $export['comment_form_location_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_feedback_reply';
  $strongarm->value = '1';
  $export['comment_preview_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_feedback_reply';
  $strongarm->value = '1';
  $export['comment_subject_field_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_feedback_reply';
  $strongarm->value = array(
    'title' => '8',
    'body_field' => '7',
    'revision_information' => '15',
    'author' => '14',
    'options' => '16',
    'comment_settings' => '17',
    'menu' => '10',
    'path' => '20',
    'attachments' => '19',
    'detailed_question' => '12',
    'workflow' => '13',
    'print' => '18',
    'nodewords' => '11',
  );
  $export['content_extra_weights_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_feedback_reply';
  $strongarm->value = '0';
  $export['language_content_type_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_feedback_reply';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_feedback_reply';
  $strongarm->value = '1';
  $export['upload_feedback_reply'] = $strongarm;

  return $export;
}
