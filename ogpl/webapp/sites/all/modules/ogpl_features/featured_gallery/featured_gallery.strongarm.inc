<?php

/**
 * Implementation of hook_strongarm().
 */
function featured_gallery_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_imageflow';
  $strongarm->value = '0';
  $export['comment_anonymous_imageflow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_imageflow';
  $strongarm->value = '3';
  $export['comment_controls_imageflow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_imageflow';
  $strongarm->value = '4';
  $export['comment_default_mode_imageflow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_imageflow';
  $strongarm->value = '1';
  $export['comment_default_order_imageflow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_imageflow';
  $strongarm->value = '50';
  $export['comment_default_per_page_imageflow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_imageflow';
  $strongarm->value = '0';
  $export['comment_form_location_imageflow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_imageflow';
  $strongarm->value = '0';
  $export['comment_imageflow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_imageflow';
  $strongarm->value = '1';
  $export['comment_preview_imageflow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_imageflow';
  $strongarm->value = '1';
  $export['comment_subject_field_imageflow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_imageflow';
  $strongarm->value = array(
    'detailed_question' => '0',
    'print' => '13',
    'title' => '-5',
    'revision_information' => '1',
    'author' => '2',
    'options' => '3',
    'comment_settings' => '6',
    'menu' => '-3',
    'path' => '4',
    'attachments' => '5',
    'workflow' => '-2',
    'nodewords' => '-1',
  );
  $export['content_extra_weights_imageflow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_imageflow';
  $strongarm->value = '0';
  $export['language_content_type_imageflow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_imageflow';
  $strongarm->value = array(
    0 => 'revision',
    1 => 'revision_moderation',
  );
  $export['node_options_imageflow'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_imageflow';
  $strongarm->value = '1';
  $export['upload_imageflow'] = $strongarm;

  return $export;
}
