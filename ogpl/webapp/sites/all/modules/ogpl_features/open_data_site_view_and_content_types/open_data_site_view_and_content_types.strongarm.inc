<?php

/**
 * Implementation of hook_strongarm().
 */
function open_data_site_view_and_content_types_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_country_data';
  $strongarm->value = '0';
  $export['comment_anonymous_country_data'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_state_data_site';
  $strongarm->value = '0';
  $export['comment_anonymous_state_data_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_country_data';
  $strongarm->value = '3';
  $export['comment_controls_country_data'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_state_data_site';
  $strongarm->value = '3';
  $export['comment_controls_state_data_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_country_data';
  $strongarm->value = '0';
  $export['comment_country_data'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_country_data';
  $strongarm->value = '4';
  $export['comment_default_mode_country_data'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_state_data_site';
  $strongarm->value = '4';
  $export['comment_default_mode_state_data_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_country_data';
  $strongarm->value = '1';
  $export['comment_default_order_country_data'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_state_data_site';
  $strongarm->value = '1';
  $export['comment_default_order_state_data_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_country_data';
  $strongarm->value = '50';
  $export['comment_default_per_page_country_data'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_state_data_site';
  $strongarm->value = '50';
  $export['comment_default_per_page_state_data_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_country_data';
  $strongarm->value = '0';
  $export['comment_form_location_country_data'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_state_data_site';
  $strongarm->value = '0';
  $export['comment_form_location_state_data_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_country_data';
  $strongarm->value = '1';
  $export['comment_preview_country_data'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_state_data_site';
  $strongarm->value = '1';
  $export['comment_preview_state_data_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_state_data_site';
  $strongarm->value = '0';
  $export['comment_state_data_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_country_data';
  $strongarm->value = '1';
  $export['comment_subject_field_country_data'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_state_data_site';
  $strongarm->value = '0';
  $export['comment_subject_field_state_data_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_country_data';
  $strongarm->value = array(
    'detailed_question' => '9',
    'print' => '16',
    'title' => '-5',
    'revision_information' => '11',
    'author' => '10',
    'options' => '12',
    'comment_settings' => '15',
    'menu' => '6',
    'path' => '13',
    'attachments' => '14',
    'workflow' => '7',
    'nodewords' => '8',
  );
  $export['content_extra_weights_country_data'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_state_data_site';
  $strongarm->value = array(
    'title' => '4',
    'body_field' => '6',
    'revision_information' => '10',
    'author' => '11',
    'options' => '12',
    'comment_settings' => '16',
    'menu' => '5',
    'path' => '15',
    'attachments' => '14',
    'detailed_question' => '9',
    'workflow' => '7',
    'print' => '13',
    'nodewords' => '8',
  );
  $export['content_extra_weights_state_data_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_country_data';
  $strongarm->value = '0';
  $export['language_content_type_country_data'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_state_data_site';
  $strongarm->value = '0';
  $export['language_content_type_state_data_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_country_data';
  $strongarm->value = array(
    0 => 'revision',
    1 => 'revision_moderation',
  );
  $export['node_options_country_data'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_state_data_site';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_state_data_site'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_country_data';
  $strongarm->value = '1';
  $export['upload_country_data'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_state_data_site';
  $strongarm->value = '1';
  $export['upload_state_data_site'] = $strongarm;

  return $export;
}
