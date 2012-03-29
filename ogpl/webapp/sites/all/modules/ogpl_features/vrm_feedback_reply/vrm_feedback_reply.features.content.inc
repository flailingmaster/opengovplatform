<?php

/**
 * Implementation of hook_content_default_fields().
 */
function vrm_feedback_reply_content_default_fields() {
  $fields = array();

  // Exported field: field_feedback_id
  $fields['feedback_reply-field_feedback_id'] = array(
    'field_name' => 'field_feedback_id',
    'type_name' => 'feedback_reply',
    'display_settings' => array(
      'weight' => '4',
      'parent' => '',
      '5' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'feedback' => 'feedback',
      'agency' => 0,
      'block' => 0,
      'chart' => 0,
      'country_data' => 0,
      'catalog_type_data_apps' => 0,
      'catalog_type_data_service' => 0,
      'catalog_type_data_tools' => 0,
      'dataset' => 0,
      'catalog_type_document' => 0,
      'access_type_downloadable' => 0,
      'access_type_embed_link' => 0,
      'access_type_execute_upon_access' => 0,
      'faq' => 0,
      'imageflow' => 0,
      'feedback_reply' => 0,
      'flags' => 0,
      'geospatial_metadata' => 0,
      'page' => 0,
      'profile' => 0,
      'catalog_type_raw_data' => 0,
      'rotating_panel' => 0,
      'sector' => 0,
      'state_data_site' => 0,
      'statistical_metadata' => 0,
      'story' => 0,
      'sub_agency' => 0,
      'subject_keyword' => 0,
      'policy_program_data_quality' => 0,
      'policy_program_open_government' => 0,
      'policy_program_privacy' => 0,
      'upload_docs' => 0,
      'webform' => 0,
      'whats_new' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Feedback Id',
      'weight' => '4',
      'description' => '',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_feedback_reply_body
  $fields['feedback_reply-field_feedback_reply_body'] = array(
    'field_name' => 'field_feedback_reply_body',
    'type_name' => 'feedback_reply',
    'display_settings' => array(
      'weight' => '9',
      'parent' => '',
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_feedback_reply_body][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Comments',
      'weight' => '9',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_reply_cc
  $fields['feedback_reply-field_reply_cc'] = array(
    'field_name' => 'field_reply_cc',
    'type_name' => 'feedback_reply',
    'display_settings' => array(
      'weight' => '7',
      'parent' => '',
      '5' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_reply_cc][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'CC',
      'weight' => '6',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_reply_to
  $fields['feedback_reply-field_reply_to'] = array(
    'field_name' => 'field_reply_to',
    'type_name' => 'feedback_reply',
    'display_settings' => array(
      'weight' => '6',
      'parent' => '',
      '5' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_reply_to][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Mail to',
      'weight' => '5',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('CC');
  t('Comments');
  t('Feedback Id');
  t('Mail to');

  return $fields;
}
