<?php

/**
 * Implementation of hook_content_default_fields().
 */
function open_data_site_view_and_content_types_content_default_fields() {
  $fields = array();

  // Exported field: field_content_creator
  $fields['country_data-field_content_creator'] = array(
    'field_name' => 'field_content_creator',
    'type_name' => 'country_data',
    'display_settings' => array(
      'weight' => '17',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
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
    'type' => 'userreference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'userreference',
    'active' => '1',
    'referenceable_roles' => array(
      '11' => 11,
      '2' => 0,
      '10' => 0,
      '18' => 0,
      '3' => 0,
      '9' => 0,
      '12' => 0,
      '4' => 0,
      '6' => 0,
      '14' => 0,
      '13' => 0,
      '15' => 0,
    ),
    'referenceable_status' => '1',
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'reverse_link' => 0,
      'default_value' => array(
        '0' => array(
          'uid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Select A Content Creator',
      'weight' => '17',
      'description' => 'Select One Of the Content creators from the list',
      'type' => 'userreference_select',
      'module' => 'userreference',
    ),
  );

  // Exported field: field_country_dataset_link
  $fields['country_data-field_country_dataset_link'] = array(
    'field_name' => 'field_country_dataset_link',
    'type_name' => 'country_data',
    'display_settings' => array(
      'weight' => '2',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'none',
    'title_value' => '',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Dataset Link',
      'weight' => '2',
      'description' => 'Provide country dataset link here',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_country_latitude
  $fields['country_data-field_country_latitude'] = array(
    'field_name' => 'field_country_latitude',
    'type_name' => 'country_data',
    'display_settings' => array(
      'weight' => '3',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_float',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_country_latitude][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Latitude',
      'weight' => '3',
      'description' => 'Provide latitude of region e.g. 34.45',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_country_longitude
  $fields['country_data-field_country_longitude'] = array(
    'field_name' => 'field_country_longitude',
    'type_name' => 'country_data',
    'display_settings' => array(
      'weight' => '4',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_float',
    'required' => '1',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_country_longitude][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Longitude',
      'weight' => '4',
      'description' => 'Provide longitude of region e.g. 45.50',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_country_portal_url
  $fields['country_data-field_country_portal_url'] = array(
    'field_name' => 'field_country_portal_url',
    'type_name' => 'country_data',
    'display_settings' => array(
      'weight' => '1',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'none',
    'title_value' => '',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'National /Country Portal',
      'weight' => '1',
      'description' => 'Provide National/Country portal link',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_expiry_date
  $fields['country_data-field_expiry_date'] = array(
    'field_name' => 'field_expiry_date',
    'type_name' => 'country_data',
    'display_settings' => array(
      'weight' => '19',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'short',
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
    'type' => 'datetime',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'utc',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'j M Y',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Enter the Expiry Date',
      'weight' => '19',
      'description' => 'Enter The Date Of Expiry',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_instructions
  $fields['country_data-field_instructions'] = array(
    'field_name' => 'field_instructions',
    'type_name' => 'country_data',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
      '5' => array(
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
    'required' => '0',
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
          '_error_element' => 'default_value_widget][field_instructions][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Instructions',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_moderator
  $fields['country_data-field_moderator'] = array(
    'field_name' => 'field_moderator',
    'type_name' => 'country_data',
    'display_settings' => array(
      'weight' => '18',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
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
    'type' => 'userreference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'userreference',
    'active' => '1',
    'referenceable_roles' => array(
      '12' => 12,
      '2' => 0,
      '10' => 0,
      '18' => 0,
      '11' => 0,
      '3' => 0,
      '9' => 0,
      '4' => 0,
      '6' => 0,
      '14' => 0,
      '13' => 0,
      '15' => 0,
    ),
    'referenceable_status' => '1',
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'reverse_link' => 0,
      'default_value' => array(
        '0' => array(
          'uid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Select A Moderator',
      'weight' => '18',
      'description' => 'Select A Moderator From The List',
      'type' => 'userreference_select',
      'module' => 'userreference',
    ),
  );

  // Exported field: field_no_ofdays
  $fields['country_data-field_no_ofdays'] = array(
    'field_name' => 'field_no_ofdays',
    'type_name' => 'country_data',
    'display_settings' => array(
      'weight' => '20',
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '30',
          '_error_element' => 'default_value_widget][field_no_ofdays][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Notify Before (Days)',
      'weight' => '20',
      'description' => 'Enter the Number of Days here. ',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_open_data_site_image
  $fields['country_data-field_open_data_site_image'] = array(
    'field_name' => 'field_open_data_site_image',
    'type_name' => 'country_data',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'WW Data Site Image',
      'weight' => '-1',
      'description' => 'For better resolution upload image of dimension 157X105',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_site_flag_image
  $fields['country_data-field_site_flag_image'] = array(
    'field_name' => 'field_site_flag_image',
    'type_name' => 'country_data',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
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
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Flag Image',
      'weight' => '-2',
      'description' => 'For better resolution upload image of dimension 22X23',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_state_data
  $fields['country_data-field_state_data'] = array(
    'field_name' => 'field_state_data',
    'type_name' => 'country_data',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'flexifield',
    'required' => '0',
    'multiple' => '1',
    'module' => 'flexifield',
    'active' => '1',
    'item_types' => array(
      'state_data_site' => 'state_data_site',
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
      'feedback' => 0,
      'feedback_reply' => 0,
      'feedback_review' => 0,
      'geospatial_metadata' => 0,
      'page' => 0,
      'profile' => 0,
      'catalog_type_raw_data' => 0,
      'upload_docs' => 0,
      'rotating_panel' => 0,
      'sector' => 0,
      'statistical_metadata' => 0,
      'story' => 0,
      'sub_agency' => 0,
      'subject_keyword' => 0,
      'theme_file_uploader' => 0,
      'policy_program_data_quality' => 0,
      'policy_program_open_government' => 0,
      'policy_program_privacy' => 0,
      'webform' => 0,
      'whats_new' => 0,
    ),
    'widget' => array(
      'disable_tabledrag' => 0,
      'disable_tabledrag_children' => NULL,
      'default_value' => array(
        '1' => array(
          'value' => array(
            'field_region_type' => array(
              '0' => array(
                'value' => '',
              ),
            ),
            'field_state_name' => array(
              '0' => array(
                'value' => '',
                '_error_element' => 'default_value_widget][field_state_data][1][value][field_state_name][0][value',
              ),
            ),
            'field_sub_region' => array(
              '0' => array(
                'value' => '',
                '_error_element' => 'default_value_widget][field_state_data][1][value][field_sub_region][0][value',
              ),
            ),
            'field_state_portal_link' => array(
              '0' => array(
                'url' => '',
              ),
            ),
            'field_state_dataset_link' => array(
              '0' => array(
                'url' => '',
              ),
            ),
            'field_state_latitude' => array(
              '0' => array(
                'value' => '',
                '_error_element' => 'default_value_widget][field_state_data][1][value][field_state_latitude][0][value',
              ),
            ),
            'field_state_longitude' => array(
              '0' => array(
                'value' => '',
                '_error_element' => 'default_value_widget][field_state_data][1][value][field_state_longitude][0][value',
              ),
            ),
          ),
          '_weight' => '1',
          'type' => 'state_data_site',
        ),
        '0' => array(
          'value' => array(
            'field_region_type' => array(
              '0' => array(
                'value' => '',
              ),
            ),
            'field_state_name' => array(
              '0' => array(
                'value' => '',
                '_error_element' => 'default_value_widget][field_state_data][0][value][field_state_name][0][value',
              ),
            ),
            'field_sub_region' => array(
              '0' => array(
                'value' => '',
                '_error_element' => 'default_value_widget][field_state_data][0][value][field_sub_region][0][value',
              ),
            ),
            'field_state_portal_link' => array(
              '0' => array(
                'url' => '',
              ),
            ),
            'field_state_dataset_link' => array(
              '0' => array(
                'url' => '',
              ),
            ),
            'field_state_latitude' => array(
              '0' => array(
                'value' => '',
                '_error_element' => 'default_value_widget][field_state_data][0][value][field_state_latitude][0][value',
              ),
            ),
            'field_state_longitude' => array(
              '0' => array(
                'value' => '',
                '_error_element' => 'default_value_widget][field_state_data][0][value][field_state_longitude][0][value',
              ),
            ),
          ),
          '_weight' => '0',
          'type' => 'state_data_site',
        ),
        'field_state_data_add_more' => 'Add another item',
      ),
      'default_value_php' => NULL,
      'label' => 'State/City/Agency Data',
      'weight' => '5',
      'description' => '',
      'type' => 'flexifield_default_widget',
      'module' => 'flexifield',
    ),
  );

  // Exported field: field_union_govt_name
  $fields['country_data-field_union_govt_name'] = array(
    'field_name' => 'field_union_govt_name',
    'type_name' => 'country_data',
    'display_settings' => array(
      'weight' => 0,
      'parent' => '',
      'label' => array(
        'format' => 'above',
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
      '5' => array(
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_union_govt_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Union Government Name',
      'weight' => 0,
      'description' => 'Union Government Name e.g. Government Of India',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_website_header_image
  $fields['country_data-field_website_header_image'] = array(
    'field_name' => 'field_website_header_image',
    'type_name' => 'country_data',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '5' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Site Header Image',
      'weight' => '-3',
      'description' => 'For better resolution, upload image of dimension 38X24',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_region_type
  $fields['state_data_site-field_region_type'] = array(
    'field_name' => 'field_region_type',
    'type_name' => 'state_data_site',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
      '5' => array(
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
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => 'Agency|Agency
City|City
Municipality|Municipality
State|State
Sub-agency|Sub-agency',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Region Type',
      'weight' => '-3',
      'description' => 'Region type e.g. state, city etc',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_state_dataset_link
  $fields['state_data_site-field_state_dataset_link'] = array(
    'field_name' => 'field_state_dataset_link',
    'type_name' => 'state_data_site',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'none',
    'title_value' => '',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'title' => '',
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Dataset URL',
      'weight' => '1',
      'description' => 'Dataset link of region',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_state_latitude
  $fields['state_data_site-field_state_latitude'] = array(
    'field_name' => 'field_state_latitude',
    'type_name' => 'state_data_site',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_float',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_state_latitude][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Latitude',
      'weight' => '2',
      'description' => 'Provide latitude of region e.g. 34.45',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_state_longitude
  $fields['state_data_site-field_state_longitude'] = array(
    'field_name' => 'field_state_longitude',
    'type_name' => 'state_data_site',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_float',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_state_longitude][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Longitude',
      'weight' => '3',
      'description' => 'Provide longitude of region e.g. 34.45',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_state_name
  $fields['state_data_site-field_state_name'] = array(
    'field_name' => 'field_state_name',
    'type_name' => 'state_data_site',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
      '5' => array(
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
          '_error_element' => 'default_value_widget][field_state_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'State/Agency',
      'weight' => '-2',
      'description' => 'State/Agency  name',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_state_portal_link
  $fields['state_data_site-field_state_portal_link'] = array(
    'field_name' => 'field_state_portal_link',
    'type_name' => 'state_data_site',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '0',
    'multiple' => '0',
    'module' => 'link',
    'active' => '1',
    'attributes' => array(
      'target' => 'default',
      'rel' => '',
      'class' => '',
      'title' => '',
    ),
    'display' => array(
      'url_cutoff' => '80',
    ),
    'url' => 0,
    'title' => 'none',
    'title_value' => '',
    'enable_tokens' => 0,
    'validate_url' => 1,
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Portal URL',
      'weight' => 0,
      'description' => 'Portal link of region',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_sub_region
  $fields['state_data_site-field_sub_region'] = array(
    'field_name' => 'field_sub_region',
    'type_name' => 'state_data_site',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
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
      '5' => array(
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
          '_error_element' => 'default_value_widget][field_sub_region][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'City/Sub-agency',
      'weight' => '-1',
      'description' => 'City/Municipality/Sub-agency name',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('City/Sub-agency');
  t('Dataset Link');
  t('Dataset URL');
  t('Enter the Expiry Date');
  t('Flag Image');
  t('Instructions');
  t('Latitude');
  t('Longitude');
  t('National /Country Portal');
  t('Notify Before (Days)');
  t('Portal URL');
  t('Region Type');
  t('Select A Content Creator');
  t('Select A Moderator');
  t('Site Header Image');
  t('State/Agency');
  t('State/City/Agency Data');
  t('Union Government Name');
  t('WW Data Site Image');

  return $fields;
}
