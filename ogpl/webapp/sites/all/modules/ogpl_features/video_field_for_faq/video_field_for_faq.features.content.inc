<?php

/**
 * Implementation of hook_content_default_fields().
 */
function video_field_for_faq_content_default_fields() {
  $fields = array();

  // Exported field: field_video
  $fields['faq-field_video'] = array(
    'field_name' => 'field_video',
    'type_name' => 'faq',
    'display_settings' => array(
      'weight' => '31',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp4 mpeg avi mpg wmv flv mov',
      'file_path' => 'videos',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'default_video_thumb' => NULL,
      'default_dimensions' => '176x144',
      'default_player_dimensions' => '176x144',
      'autoconversion' => 1,
      'autothumbnail' => 'no',
      'label' => 'Video',
      'weight' => '31',
      'description' => '',
      'type' => 'uploadfield_widget',
      'module' => 'uploadfield',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Video');

  return $fields;
}
