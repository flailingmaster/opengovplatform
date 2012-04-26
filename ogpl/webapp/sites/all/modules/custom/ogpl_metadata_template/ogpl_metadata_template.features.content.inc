<?php

/**
 * Implementation of hook_content_default_fields().
 */
function ogpl_metadata_template_content_default_fields() {
  $fields = array();

  // Exported field: field_atd_access_point
  $fields['access_type_downloadable-field_atd_access_point'] = array(
    'field_name' => 'field_atd_access_point',
    'type_name' => 'access_type_downloadable',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'link',
    'required' => '1',
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
      'label' => 'Access point',
      'weight' => '4',
      'description' => 'If the data set is downloadable, enter the URL for instant access to the downloadable data file.  This is the URL for access to the data set via a "one-click download".  Please enter  a URL only.',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_atd_compressed_format
  $fields['access_type_downloadable-field_atd_compressed_format'] = array(
    'field_name' => 'field_atd_compressed_format',
    'type_name' => 'access_type_downloadable',
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
    'allowed_values' => 'Please Select
Yes
No',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Compressed Format',
      'weight' => '5',
      'description' => 'Compressed file then "yes" or "no".',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_atd_file_format
  $fields['access_type_downloadable-field_atd_file_format'] = array(
    'field_name' => 'field_atd_file_format',
    'type_name' => 'access_type_downloadable',
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
    'allowed_values' => 'Please select
XML
CSV
XLS
KML/KMZ
Shapefile
Map',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'File format',
      'weight' => '7',
      'description' => 'If downloadable, enter the format in which file may be downloaded.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_atd_file_size
  $fields['access_type_downloadable-field_atd_file_size'] = array(
    'field_name' => 'field_atd_file_size',
    'type_name' => 'access_type_downloadable',
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
          '_error_element' => 'default_value_widget][field_atd_file_size][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'File size',
      'weight' => '6',
      'description' => 'If downloadable, please enter the size of file in MB.',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_agency_name
  $fields['agency-field_agency_name'] = array(
    'field_name' => 'field_agency_name',
    'type_name' => 'agency',
    'display_settings' => array(
      'weight' => '31',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'plain',
        'exclude' => 0,
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
          '_error_element' => 'default_value_widget][field_agency_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Agency Name',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_agency_short_name
  $fields['agency-field_agency_short_name'] = array(
    'field_name' => 'field_agency_short_name',
    'type_name' => 'agency',
    'display_settings' => array(
      'weight' => '32',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'plain',
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
          '_error_element' => 'default_value_widget][field_agency_short_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Agency Short Name',
      'weight' => '-3',
      'description' => 'Acronym or short name corresponding to the Agency name.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ctda_app_type
  $fields['catalog_type_data_apps-field_ctda_app_type'] = array(
    'field_name' => 'field_ctda_app_type',
    'type_name' => 'catalog_type_data_apps',
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
    'allowed_values' => 'Please select
Web APPs
Web Service
Mobile APP
MapService
RSS
Data Site
APIs',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'App Type',
      'weight' => '31',
      'description' => 'Select the appropriate APP Type that this submission should be listed (i.e. Web APPs, Web Service, Mobile APP, MapService, RSS, Data Site, APIs, etc).',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ctda_catalog_location
  $fields['catalog_type_data_apps-field_ctda_catalog_location'] = array(
    'field_name' => 'field_ctda_catalog_location',
    'type_name' => 'catalog_type_data_apps',
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
    'allowed_values' => 'Please select
Internal
External',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Catalog Location',
      'weight' => '33',
      'description' => 'Data could be internal or external.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ctda_datasets_used
  $fields['catalog_type_data_apps-field_ctda_datasets_used'] = array(
    'field_name' => 'field_ctda_datasets_used',
    'type_name' => 'catalog_type_data_apps',
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
          '_error_element' => 'default_value_widget][field_ctda_datasets_used][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Dataset(s) Used',
      'weight' => '32',
      'description' => 'Datasets used to develop this app or This APP would provide data analysis for which data sets.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ctda_language
  $fields['catalog_type_data_apps-field_ctda_language'] = array(
    'field_name' => 'field_ctda_language',
    'type_name' => 'catalog_type_data_apps',
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
          '_error_element' => 'default_value_widget][field_ctda_language][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Language',
      'weight' => '34',
      'description' => 'Language of the data set.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ctda_target_audience_nr
  $fields['catalog_type_data_apps-field_ctda_target_audience_nr'] = array(
    'field_name' => 'field_ctda_target_audience_nr',
    'type_name' => 'catalog_type_data_apps',
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'target_audience' => 'target_audience',
      'agency' => 0,
      'block' => 0,
      'country_data' => 0,
      'catalog_type_data_apps' => 0,
      'catalog_type_data_service' => 0,
      'catalog_type_data_tools' => 0,
      'dataset' => 0,
      'catalog_type_document' => 0,
      'access_type_downloadable' => 0,
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
      'state_data_site' => 0,
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
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Target Audience',
      'weight' => '36',
      'description' => 'Target Audience of the data asset.',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_ctds_access_type
  $fields['catalog_type_data_service-field_ctds_access_type'] = array(
    'field_name' => 'field_ctds_access_type',
    'type_name' => 'catalog_type_data_service',
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
    'allowed_values' => 'Open Access
Authenticated Access',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Access Type',
      'weight' => '12',
      'description' => 'Open Access, Authenticated Access, etc.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ctds_datasets_used
  $fields['catalog_type_data_service-field_ctds_datasets_used'] = array(
    'field_name' => 'field_ctds_datasets_used',
    'type_name' => 'catalog_type_data_service',
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
          '_error_element' => 'default_value_widget][field_ctds_datasets_used][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Dataset(s) Used',
      'weight' => '8',
      'description' => 'Data asset(s) "served" to user.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ctds_language
  $fields['catalog_type_data_service-field_ctds_language'] = array(
    'field_name' => 'field_ctds_language',
    'type_name' => 'catalog_type_data_service',
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
          '_error_element' => 'default_value_widget][field_ctds_language][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Language',
      'weight' => '11',
      'description' => 'Language of the data set.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ctds_service_category
  $fields['catalog_type_data_service-field_ctds_service_category'] = array(
    'field_name' => 'field_ctds_service_category',
    'type_name' => 'catalog_type_data_service',
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
    'allowed_values' => 'Please select
Apply
Check
Track
Obtain',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Service Category',
      'weight' => '7',
      'description' => 'Apply, Check, Track, Obtain, etc.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ctds_service_maturity
  $fields['catalog_type_data_service-field_ctds_service_maturity'] = array(
    'field_name' => 'field_ctds_service_maturity',
    'type_name' => 'catalog_type_data_service',
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
    'allowed_values' => 'Please select
Information
Partially Online
Fully Online ',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Service Maturity',
      'weight' => '6',
      'description' => 'Information, Partially Online, Fully Online.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ctds_target_audience_nr
  $fields['catalog_type_data_service-field_ctds_target_audience_nr'] = array(
    'field_name' => 'field_ctds_target_audience_nr',
    'type_name' => 'catalog_type_data_service',
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'target_audience' => 'target_audience',
      'agency' => 0,
      'block' => 0,
      'country_data' => 0,
      'catalog_type_data_apps' => 0,
      'catalog_type_data_service' => 0,
      'catalog_type_data_tools' => 0,
      'dataset' => 0,
      'catalog_type_document' => 0,
      'access_type_downloadable' => 0,
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
      'state_data_site' => 0,
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
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Target Audience',
      'weight' => '9',
      'description' => '	Target Audience of the data asset.',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_ctdt_datasets_used
  $fields['catalog_type_data_tools-field_ctdt_datasets_used'] = array(
    'field_name' => 'field_ctdt_datasets_used',
    'type_name' => 'catalog_type_data_tools',
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
          '_error_element' => 'default_value_widget][field_ctdt_datasets_used][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Dataset(s) Used',
      'weight' => '32',
      'description' => 'Datasets used to develop this tool that would provide data analysis for which data sets.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ctdt_extraction_formats
  $fields['catalog_type_data_tools-field_ctdt_extraction_formats'] = array(
    'field_name' => 'field_ctdt_extraction_formats',
    'type_name' => 'catalog_type_data_tools',
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
    'allowed_values' => 'Please select
XML
CSV
XLS
KML/KMZ
Shapefile
Map',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Extraction Formats',
      'weight' => '34',
      'description' => 'Select dataset formats in which the tool can extract.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ctdt_language
  $fields['catalog_type_data_tools-field_ctdt_language'] = array(
    'field_name' => 'field_ctdt_language',
    'type_name' => 'catalog_type_data_tools',
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
          '_error_element' => 'default_value_widget][field_ctdt_language][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Language',
      'weight' => '35',
      'description' => 'Language of the data set.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ctdt_tool_location
  $fields['catalog_type_data_tools-field_ctdt_tool_location'] = array(
    'field_name' => 'field_ctdt_tool_location',
    'type_name' => 'catalog_type_data_tools',
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
    'allowed_values' => 'Please select
Internal
External',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Tool Location',
      'weight' => '33',
      'description' => 'Tool could be internal or external.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ctdt_tool_type
  $fields['catalog_type_data_tools-field_ctdt_tool_type'] = array(
    'field_name' => 'field_ctdt_tool_type',
    'type_name' => 'catalog_type_data_tools',
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
    'allowed_values' => 'Please select
Extraction
Interpretation',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Tool Type',
      'weight' => '31',
      'description' => 'Select the appropriate data extraction/interpretation Tool.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ctd_catalog_location
  $fields['catalog_type_document-field_ctd_catalog_location'] = array(
    'field_name' => 'field_ctd_catalog_location',
    'type_name' => 'catalog_type_document',
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
    'allowed_values' => 'Please select
Internal
External',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Catalog Location',
      'weight' => '-3',
      'description' => 'Document  could be internal or external.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ctd_classification
  $fields['catalog_type_document-field_ctd_classification'] = array(
    'field_name' => 'field_ctd_classification',
    'type_name' => 'catalog_type_document',
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
    'allowed_values' => 'Please select
Form
Proforma
Scheme
Act
Rule
Annual Report
Survey Report
Budget Document
Citizen Charter',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Document Classification',
      'weight' => '-2',
      'description' => 'Please select from the list of document classifications (controlled vocabulary) viz. Form, Proforma, Scheme, Act, Rule, Annual Report, Survey Report, Budget Document, Citizen Charter, etc.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ctd_dataset_group_name
  $fields['catalog_type_document-field_ctd_dataset_group_name'] = array(
    'field_name' => 'field_ctd_dataset_group_name',
    'type_name' => 'catalog_type_document',
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
          '_error_element' => 'default_value_widget][field_ctd_dataset_group_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Dataset Group Name',
      'weight' => '-1',
      'description' => 'This field allows agencies to provide a Group Name to a set of documents in order to show that they may be presented as a group or a set.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ctd_frequency
  $fields['catalog_type_document-field_ctd_frequency'] = array(
    'field_name' => 'field_ctd_frequency',
    'type_name' => 'catalog_type_document',
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
          '_error_element' => 'default_value_widget][field_ctd_frequency][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Frequency',
      'weight' => '5',
      'description' => 'Frequency of document Release ( annual, monthly etc.).',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ctd_language
  $fields['catalog_type_document-field_ctd_language'] = array(
    'field_name' => 'field_ctd_language',
    'type_name' => 'catalog_type_document',
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
          '_error_element' => 'default_value_widget][field_ctd_language][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Language',
      'weight' => '6',
      'description' => 'Language of the document.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ctd_target_audience_nr
  $fields['catalog_type_document-field_ctd_target_audience_nr'] = array(
    'field_name' => 'field_ctd_target_audience_nr',
    'type_name' => 'catalog_type_document',
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'target_audience' => 'target_audience',
      'agency' => 0,
      'block' => 0,
      'country_data' => 0,
      'catalog_type_data_apps' => 0,
      'catalog_type_data_service' => 0,
      'catalog_type_data_tools' => 0,
      'dataset' => 0,
      'catalog_type_document' => 0,
      'access_type_downloadable' => 0,
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
      'state_data_site' => 0,
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
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Target Audience',
      'weight' => '3',
      'description' => 'Target Audience of the data asset.',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_ctd_validity_date
  $fields['catalog_type_document-field_ctd_validity_date'] = array(
    'field_name' => 'field_ctd_validity_date',
    'type_name' => 'catalog_type_document',
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
    'type' => 'datestamp',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'm/d/Y - H:i',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-10:+10',
      'label_position' => 'above',
      'label' => 'Validity Date',
      'weight' => '4',
      'description' => 'Date up to which the document would be valid.',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_ctrd_bibliography_citation
  $fields['catalog_type_raw_data-field_ctrd_bibliography_citation'] = array(
    'field_name' => 'field_ctrd_bibliography_citation',
    'type_name' => 'catalog_type_raw_data',
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
          '_error_element' => 'default_value_widget][field_ctrd_bibliography_citation][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Bibliographic Citation',
      'weight' => '35',
      'description' => 'This field may be used when others make reference to the data, as in a bibliographic citation or source reference.  If the agency does not have a standard reference for this dataset, simply provide the URL for the dataset.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ctrd_catalog_location
  $fields['catalog_type_raw_data-field_ctrd_catalog_location'] = array(
    'field_name' => 'field_ctrd_catalog_location',
    'type_name' => 'catalog_type_raw_data',
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
    'allowed_values' => 'Please Select
Internal
External',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Catalog Location',
      'weight' => '31',
      'description' => 'Data could be internal or external.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ctrd_category_designation
  $fields['catalog_type_raw_data-field_ctrd_category_designation'] = array(
    'field_name' => 'field_ctrd_category_designation',
    'type_name' => 'catalog_type_raw_data',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'flexifield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'flexifield',
    'active' => '1',
    'item_types' => array(
      'geospatial_metadata' => 'geospatial_metadata',
      'statistical_metadata' => 'statistical_metadata',
      'agency' => 0,
      'data_tool' => 0,
      'data_catalog' => 0,
      'dataset' => 0,
      'access_type_downloadable' => 0,
      'access_type_embed_link' => 0,
      'access_type_execute_upon_access' => 0,
      'catalog_type_raw_data' => 0,
      'page' => 0,
      'profile' => 0,
      'story' => 0,
      'sub_agency' => 0,
      'subject_keyword' => 0,
      'webform' => 0,
      'catalog_type_data_apps' => FALSE,
      'catalog_type_data_service' => FALSE,
      'catalog_type_data_tools' => FALSE,
      'catalog_type_document' => FALSE,
      'policy_program_data_quality' => FALSE,
      'policy_program_open_government' => FALSE,
      'policy_program_privacy' => FALSE,
    ),
    'widget' => array(
      'disable_tabledrag' => 0,
      'disable_tabledrag_children' => NULL,
      'default_value' => array(
        '0' => '',
      ),
      'default_value_php' => NULL,
      'label' => 'Specialized Data Category Designation',
      'weight' => '33',
      'description' => 'Identify the type of dataset (i.e. statistical, geospatial, surveillance or research).  Please choose the category that best fits the dataset.',
      'type' => 'flexifield_default_widget',
      'module' => 'flexifield',
    ),
  );

  // Exported field: field_ctrd_dataset_group_name
  $fields['catalog_type_raw_data-field_ctrd_dataset_group_name'] = array(
    'field_name' => 'field_ctrd_dataset_group_name',
    'type_name' => 'catalog_type_raw_data',
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
          '_error_element' => 'default_value_widget][field_ctrd_dataset_group_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Dataset Group Name',
      'weight' => '32',
      'description' => 'This field allows agencies to provide a Group Name to multiple datasets and/or tools in order to show that they may be presented as a group or a set.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ctrd_frequency
  $fields['catalog_type_raw_data-field_ctrd_frequency'] = array(
    'field_name' => 'field_ctrd_frequency',
    'type_name' => 'catalog_type_raw_data',
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
          '_error_element' => 'default_value_widget][field_ctrd_frequency][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Frequency',
      'weight' => '34',
      'description' => 'Frequency of data collection (one-time, annual, hourly, etc.).',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ds_access_method
  $fields['dataset-field_ds_access_method'] = array(
    'field_name' => 'field_ds_access_method',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '22',
      'parent' => 'group_ds_access_type',
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
        'exclude' => 1,
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
    'type' => 'flexifield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'flexifield',
    'active' => '1',
    'item_types' => array(
      'access_type_downloadable' => 'access_type_downloadable',
      'agency' => 0,
      'block' => 0,
      'chart' => 0,
      'country_data' => 0,
      'catalog_type_data_apps' => 0,
      'catalog_type_data_service' => 0,
      'catalog_type_data_tools' => 0,
      'dataset' => 0,
      'catalog_type_document' => 0,
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
      'state_data_site' => 0,
      'statistical_metadata' => 0,
      'story' => 0,
      'sub_agency' => 0,
      'subject_keyword' => 0,
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
        '0' => array(
          'type' => '',
          'value' => array(),
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Access Method',
      'weight' => '22',
      'description' => '',
      'type' => 'flexifield_default_widget',
      'module' => 'flexifield',
    ),
  );

  // Exported field: field_ds_access_url
  $fields['dataset-field_ds_access_url'] = array(
    'field_name' => 'field_ds_access_url',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '22',
      'parent' => 'group_ds_all_datasets',
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
        'exclude' => 1,
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
    'type' => 'link',
    'required' => '1',
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
      'multistep' => NULL,
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Access URL',
      'weight' => '22',
      'description' => 'URL to the high level repository in which this dataset or tool resides at the agency (e.g., the HTML page that displays the link to the dataset.)',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_ds_agency_generated_id
  $fields['dataset-field_ds_agency_generated_id'] = array(
    'field_name' => 'field_ds_agency_generated_id',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '6',
      'parent' => 'group_ds_all_datasets',
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
        'exclude' => 1,
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
          '_error_element' => 'default_value_widget][field_ds_agency_generated_id][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Agency Generated ID',
      'weight' => '6',
      'description' => 'This field may be used by the agency to track the submissions on their internal systems.  The field is optional as it will not typically be used by the system and will not be published on the catalog.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ds_agency_name
  $fields['dataset-field_ds_agency_name'] = array(
    'field_name' => 'field_ds_agency_name',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '9',
      'parent' => 'group_ds_all_datasets',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'agency' => 'agency',
      'catalog_type_data_apps' => 0,
      'catalog_type_data_service' => 0,
      'catalog_type_data_tools' => 0,
      'dataset' => 0,
      'catalog_type_document' => 0,
      'access_type_downloadable' => 0,
      'access_type_embed_link' => 0,
      'access_type_execute_upon_access' => 0,
      'geospatial_metadata' => 0,
      'page' => 0,
      'profile' => 0,
      'catalog_type_raw_data' => 0,
      'sector' => 0,
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
      'size' => 60,
      'default_value' => NULL,
      'default_value_php' => 'global $user;
// check if content_profile module is enabled
if (module_exists(\'content_profile\')) {
  $profile =  content_profile_load(\'profile\', $user->uid);
  return array(array(\'nid\' => $profile->field_prof_agency[0][\'nid\']));  
}
return array(array(\'value\' => 0));',
      'label' => 'Agency Name',
      'weight' => '9',
      'description' => 'Department or Independent Agency name.',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_ds_asset_jurisdiction
  $fields['dataset-field_ds_asset_jurisdiction'] = array(
    'field_name' => 'field_ds_asset_jurisdiction',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '24',
      'parent' => 'group_ds_all_datasets',
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
      'rows' => 5,
      'size' => '60',
      'multistep' => '0',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_ds_asset_jurisdiction][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Asset Jurisdiction',
      'weight' => '24',
      'description' => 'The exact location or area to which the asset caters to viz. state/province, district, city etc.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ds_catlog_type
  $fields['dataset-field_ds_catlog_type'] = array(
    'field_name' => 'field_ds_catlog_type',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '58',
      'parent' => 'group_ds_catalog_type',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'flexifield',
    'required' => '1',
    'multiple' => '0',
    'module' => 'flexifield',
    'active' => '1',
    'item_types' => array(
      'catalog_type_data_apps' => 'catalog_type_data_apps',
      'catalog_type_data_service' => 'catalog_type_data_service',
      'catalog_type_data_tools' => 'catalog_type_data_tools',
      'catalog_type_document' => 'catalog_type_document',
      'catalog_type_raw_data' => 'catalog_type_raw_data',
      'agency' => 0,
      'data_tool' => 0,
      'data_catalog' => 0,
      'dataset' => 0,
      'access_type_downloadable' => 0,
      'access_type_embed_link' => 0,
      'access_type_execute_upon_access' => 0,
      'geospatial_metadata' => 0,
      'page' => 0,
      'profile' => 0,
      'statistical_metadata' => 0,
      'story' => 0,
      'sub_agency' => 0,
      'subject_keyword' => 0,
      'webform' => 0,
      'policy_program_data_quality' => FALSE,
      'policy_program_open_government' => FALSE,
      'policy_program_privacy' => FALSE,
    ),
    'widget' => array(
      'disable_tabledrag' => 0,
      'disable_tabledrag_children' => NULL,
      'default_value' => array(
        '0' => array(
          'type' => '',
          'value' => array(),
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Catalog type',
      'weight' => '58',
      'description' => '',
      'type' => 'flexifield_default_widget',
      'module' => 'flexifield',
    ),
  );

  // Exported field: field_ds_contact_name
  $fields['dataset-field_ds_contact_name'] = array(
    'field_name' => 'field_ds_contact_name',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '11',
      'parent' => 'group_ds_all_datasets',
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
        'exclude' => 1,
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
          '_error_element' => 'default_value_widget][field_ds_contact_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Contact Person (Name)',
      'weight' => '11',
      'description' => 'Contact person\'s name (first, then last) where questions from the  PMO should be sent.. ** Note that these "contact" elements (6 to 6.5) need not be published on the DGIB website but may receive public email comments made specifically about this dataset or tool.**',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ds_contact_phone_number
  $fields['dataset-field_ds_contact_phone_number'] = array(
    'field_name' => 'field_ds_contact_phone_number',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '14',
      'parent' => 'group_ds_all_datasets',
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
        'exclude' => 1,
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
          '_error_element' => 'default_value_widget][field_ds_contact_phone_number][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Contact Person Phone Number',
      'weight' => '14',
      'description' => 'Contact person\'s phone number.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ds_contact_title
  $fields['dataset-field_ds_contact_title'] = array(
    'field_name' => 'field_ds_contact_title',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '12',
      'parent' => 'group_ds_all_datasets',
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
        'exclude' => 1,
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_ds_contact_title][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Contact Person Title',
      'weight' => '12',
      'description' => 'Contact person\'s Address for correspondence.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ds_datafile
  $fields['dataset-field_ds_datafile'] = array(
    'field_name' => 'field_ds_datafile',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '23',
      'parent' => 'group_ds_data_store',
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
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'txt pdf doc docx xls xlsx',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'multistep' => NULL,
      'label' => 'Datafile',
      'weight' => '23',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_ds_dataset_license
  $fields['dataset-field_ds_dataset_license'] = array(
    'field_name' => 'field_ds_dataset_license',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '25',
      'parent' => 'group_ds_all_datasets',
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
        'exclude' => 1,
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
    'allowed_values' => 'Please select
Yes
No',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Data asset use requires a license agreement',
      'weight' => '25',
      'description' => 'This is a required field to ensure that license agreements are not bypassed during the one-click download interface on the website.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ds_dataset_license_url
  $fields['dataset-field_ds_dataset_license_url'] = array(
    'field_name' => 'field_ds_dataset_license_url',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '26',
      'parent' => 'group_ds_all_datasets',
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
        'exclude' => 1,
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
          '_error_element' => 'default_value_widget][field_ds_dataset_license_url][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Data asset license agreement URL',
      'weight' => '26',
      'description' => 'URL to the license agreement page for the dataset or tool.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ds_date_released
  $fields['dataset-field_ds_date_released'] = array(
    'field_name' => 'field_ds_date_released',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '20',
      'parent' => 'group_ds_all_datasets',
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
        'exclude' => 1,
      ),
    ),
    'widget_active' => '1',
    'type' => 'datestamp',
    'required' => '1',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
    ),
    'timezone_db' => '',
    'tz_handling' => 'none',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'm/d/Y - H:i',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date Released',
      'weight' => '20',
      'description' => 'Date when the dataset was first made available to the public . This date should not be confused with when the data is being entered into Data.gov as it could have already been published on your website.',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_ds_date_submitted
  $fields['dataset-field_ds_date_submitted'] = array(
    'field_name' => 'field_ds_date_submitted',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '5',
      'parent' => 'group_ds_profile',
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
        'exclude' => 1,
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
    'type' => 'datestamp',
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
    'tz_handling' => 'site',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'd.m.Y - H:i',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Date Submitted',
      'weight' => '5',
      'description' => 'Date data asset record entered into the System',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_ds_description
  $fields['dataset-field_ds_description'] = array(
    'field_name' => 'field_ds_description',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '8',
      'parent' => 'group_ds_all_datasets',
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
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '1',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '1',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          'format' => '3',
          '_error_element' => 'default_value_widget][field_ds_description][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Description',
      'weight' => '8',
      'description' => 'Please provide a detailed description of the dataset or tool (e.g., an abstract) such that the user would be able to determine the nature and purpose of the data.',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_ds_email_address
  $fields['dataset-field_ds_email_address'] = array(
    'field_name' => 'field_ds_email_address',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '15',
      'parent' => 'group_ds_all_datasets',
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
        'exclude' => 1,
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
    'type' => 'email',
    'required' => '1',
    'multiple' => '0',
    'module' => 'email',
    'active' => '1',
    'widget' => array(
      'size' => '60',
      'multistep' => NULL,
      'default_value' => array(
        '0' => array(
          'email' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Contact Person Email Address',
      'weight' => '15',
      'description' => 'Contact person\'s email address.',
      'type' => 'email_textfield',
      'module' => 'email',
    ),
  );

  // Exported field: field_ds_fax_number
  $fields['dataset-field_ds_fax_number'] = array(
    'field_name' => 'field_ds_fax_number',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '16',
      'parent' => 'group_ds_all_datasets',
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
        'exclude' => 1,
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
          '_error_element' => 'default_value_widget][field_ds_fax_number][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Contact Person Fax No.',
      'weight' => '16',
      'description' => 'Contact person\'s Fax.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ds_file
  $fields['dataset-field_ds_file'] = array(
    'field_name' => 'field_ds_file',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '59',
      'parent' => 'group_ds_upload',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'download_count',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 1,
      ),
      'token' => array(
        'format' => 'default',
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
      'file_extensions' => 'csv xml xls xlsx',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'label' => 'File',
      'weight' => '59',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_ds_keywords
  $fields['dataset-field_ds_keywords'] = array(
    'field_name' => 'field_ds_keywords',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '19',
      'parent' => 'group_ds_all_datasets',
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
        'exclude' => 1,
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
      'rows' => '3',
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_ds_keywords][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Keywords',
      'weight' => '19',
      'description' => 'Searchable keywords help users discover your datasets from different perspectives.  They also provide ways of identifying other datasets that are similar to yours.  Please include terms that would be used by both technical and non-technical users.  If the item being described is a \'data mining and/or extraction tool," then please provide keywords that describe the underlying dataset.   Agencies are encouraged to include as many keywords as possible.  Please use commas to separate keywords.',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_ds_office_address
  $fields['dataset-field_ds_office_address'] = array(
    'field_name' => 'field_ds_office_address',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '13',
      'parent' => 'group_ds_all_datasets',
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
        'exclude' => 1,
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
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_ds_office_address][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Contact Person Office Address',
      'weight' => '13',
      'description' => 'Contact person\'s Address for correspondence.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ds_policy_program_goal
  $fields['dataset-field_ds_policy_program_goal'] = array(
    'field_name' => 'field_ds_policy_program_goal',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '13',
      'parent' => 'group_ds_policy_program_goal',
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
        'exclude' => 1,
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
    'type' => 'flexifield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'flexifield',
    'active' => '1',
    'item_types' => array(
      'policy_program_data_quality' => 'policy_program_data_quality',
      'policy_program_open_government' => 'policy_program_open_government',
      'policy_program_privacy' => 'policy_program_privacy',
      'agency' => 0,
      'catalog_type_data_apps' => 0,
      'catalog_type_data_service' => 0,
      'catalog_type_data_tools' => 0,
      'dataset' => 0,
      'catalog_type_document' => 0,
      'access_type_downloadable' => 0,
      'access_type_embed_link' => 0,
      'access_type_execute_upon_access' => 0,
      'geospatial_metadata' => 0,
      'page' => 0,
      'profile' => 0,
      'catalog_type_raw_data' => 0,
      'sector' => 0,
      'statistical_metadata' => 0,
      'story' => 0,
      'sub_agency' => 0,
      'subject_keyword' => 0,
      'upload_docs' => 0,
      'webform' => 0,
      'whats_new' => 0,
    ),
    'widget' => array(
      'disable_tabledrag' => 0,
      'disable_tabledrag_children' => NULL,
      'default_value' => array(
        '0' => array(
          'type' => '',
          'value' => array(),
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Policy/Program Goal',
      'weight' => '13',
      'description' => '',
      'type' => 'flexifield_default_widget',
      'module' => 'flexifield',
    ),
  );

  // Exported field: field_ds_reference_url
  $fields['dataset-field_ds_reference_url'] = array(
    'field_name' => 'field_ds_reference_url',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '23',
      'parent' => 'group_ds_all_datasets',
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
        'exclude' => 1,
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
    'type' => 'link',
    'required' => '1',
    'multiple' => '1',
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
      'multistep' => NULL,
      'default_value' => array(
        '0' => array(
          'url' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Reference URL',
      'weight' => '23',
      'description' => 'URL or bibliographic citation for the technical documentation for this dataset.  This may include description to the study design, instrumentation, implementation, limitations, and appropriate use of the dataset or tool. In the case of multiple documents or URLs, please delimit with commas.',
      'type' => 'link',
      'module' => 'link',
    ),
  );

  // Exported field: field_ds_sector
  $fields['dataset-field_ds_sector'] = array(
    'field_name' => 'field_ds_sector',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '17',
      'parent' => 'group_ds_all_datasets',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 1,
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
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'sector' => 'sector',
      'agency' => 0,
      'catalog_type_data_apps' => 0,
      'catalog_type_data_service' => 0,
      'catalog_type_data_tools' => 0,
      'dataset' => 0,
      'catalog_type_document' => 0,
      'access_type_downloadable' => 0,
      'access_type_embed_link' => 0,
      'access_type_execute_upon_access' => 0,
      'geospatial_metadata' => 0,
      'page' => 0,
      'profile' => 0,
      'catalog_type_raw_data' => 0,
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
      'size' => 60,
      'multistep' => '0',
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sector',
      'weight' => '17',
      'description' => 'Choose the category(ies) that most closely apply(ies) to your data asset.',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_ds_sub_agency
  $fields['dataset-field_ds_sub_agency'] = array(
    'field_name' => 'field_ds_sub_agency',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '10',
      'parent' => 'group_ds_all_datasets',
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'sub_agency' => 'sub_agency',
      'agency' => 0,
      'block' => 0,
      'country_data' => 0,
      'catalog_type_data_apps' => 0,
      'catalog_type_data_service' => 0,
      'catalog_type_data_tools' => 0,
      'dataset' => 0,
      'catalog_type_document' => 0,
      'access_type_downloadable' => 0,
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
      'state_data_site' => 0,
      'statistical_metadata' => 0,
      'story' => 0,
      'subject_keyword' => 0,
      'theme_file_uploader' => 0,
      'policy_program_data_quality' => 0,
      'policy_program_open_government' => 0,
      'policy_program_privacy' => 0,
      'webform' => 0,
      'whats_new' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'multistep' => '0',
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sub Agency Name',
      'weight' => '10',
      'description' => 'Bureau or Sub-Agency or operating unit name.',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_ds_sub_sector_nr
  $fields['dataset-field_ds_sub_sector_nr'] = array(
    'field_name' => 'field_ds_sub_sector_nr',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '18',
      'parent' => 'group_ds_all_datasets',
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'sub_sector' => 'sub_sector',
      'agency' => 0,
      'block' => 0,
      'country_data' => 0,
      'catalog_type_data_apps' => 0,
      'catalog_type_data_service' => 0,
      'catalog_type_data_tools' => 0,
      'dataset' => 0,
      'catalog_type_document' => 0,
      'access_type_downloadable' => 0,
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
      'state_data_site' => 0,
      'statistical_metadata' => 0,
      'story' => 0,
      'sub_agency' => 0,
      'subject_keyword' => 0,
      'target_audience' => 0,
      'test_date' => 0,
      'theme_file_uploader' => 0,
      'policy_program_data_quality' => 0,
      'policy_program_open_government' => 0,
      'policy_program_privacy' => 0,
      'webform' => 0,
      'whats_new' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'multistep' => '0',
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sub-Sector',
      'weight' => '18',
      'description' => 'Sub category of Sector.',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_ds_title
  $fields['dataset-field_ds_title'] = array(
    'field_name' => 'field_ds_title',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '7',
      'parent' => 'group_ds_all_datasets',
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
        'exclude' => 1,
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
          '_error_element' => 'default_value_widget][field_ds_title][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Title',
      'weight' => '7',
      'description' => 'Unique name of the dataset or Tool. (e.g., Current Population Survey, Consumer Price Index, FBI Ten Most Wanted Widget).  This field will be used to populate the data catalog; the catalog will be sorted on this field.  Note: if the title is not unique within the entire catalog, you will be asked to change it.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ds_unique_id
  $fields['dataset-field_ds_unique_id'] = array(
    'field_name' => 'field_ds_unique_id',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '4',
      'parent' => 'group_ds_profile',
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
        'exclude' => 1,
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
          '_error_element' => 'default_value_widget][field_ds_unique_id][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Unique Id',
      'weight' => '4',
      'description' => 'For DataGov PMO Use Only - will be generated when placed in catalog',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_request_type
  $fields['dataset-field_request_type'] = array(
    'field_name' => 'field_request_type',
    'type_name' => 'dataset',
    'display_settings' => array(
      'weight' => '6',
      'parent' => 'group_ds_profile',
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
        'exclude' => 1,
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
    'allowed_values' => 'Create
Update
Delete',
    'allowed_values_php' => '',
    'widget' => array(
      'multistep' => '0',
      'default_value' => array(
        '0' => array(
          'value' => 'Create',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Request Type',
      'weight' => '6',
      'description' => 'This is not a part of the template and used only for internal purpose.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_geo_field_1
  $fields['geospatial_metadata-field_geo_field_1'] = array(
    'field_name' => 'field_geo_field_1',
    'type_name' => 'geospatial_metadata',
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
          '_error_element' => 'default_value_widget][field_geo_field_1][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Field 1',
      'weight' => '31',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_geo_field_2
  $fields['geospatial_metadata-field_geo_field_2'] = array(
    'field_name' => 'field_geo_field_2',
    'type_name' => 'geospatial_metadata',
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
          '_error_element' => 'default_value_widget][field_geo_field_2][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Field 2',
      'weight' => '32',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ppdq_policy_goal_id
  $fields['policy_program_data_quality-field_ppdq_policy_goal_id'] = array(
    'field_name' => 'field_ppdq_policy_goal_id',
    'type_name' => 'policy_program_data_quality',
    'display_settings' => array(
      'weight' => '5',
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
      'flexifield_dataset' => array(
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
          '_error_element' => 'default_value_widget][field_ppdq_policy_goal_id][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Policy/Goal ID',
      'weight' => '5',
      'description' => 'UID',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ppdq_policy_goal_title
  $fields['policy_program_data_quality-field_ppdq_policy_goal_title'] = array(
    'field_name' => 'field_ppdq_policy_goal_title',
    'type_name' => 'policy_program_data_quality',
    'display_settings' => array(
      'weight' => '6',
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
      'flexifield_dataset' => array(
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
          '_error_element' => 'default_value_widget][field_ppdq_policy_goal_title][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Policy/Goal Title',
      'weight' => '6',
      'description' => 'Official Title.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ppdq_responsible_agency
  $fields['policy_program_data_quality-field_ppdq_responsible_agency'] = array(
    'field_name' => 'field_ppdq_responsible_agency',
    'type_name' => 'policy_program_data_quality',
    'display_settings' => array(
      'weight' => '7',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      'flexifield_dataset' => array(
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'agency' => 'agency',
      'block' => 0,
      'country_data' => 0,
      'catalog_type_data_apps' => 0,
      'catalog_type_data_service' => 0,
      'catalog_type_data_tools' => 0,
      'dataset' => 0,
      'catalog_type_document' => 0,
      'access_type_downloadable' => 0,
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
      'state_data_site' => 0,
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
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => NULL,
      'default_value_php' => 'global $user;
// check if content_profile module is enabled
if (module_exists(\'content_profile\')) {
  $profile =  content_profile_load(\'profile\', $user->uid);
  return array(array(\'nid\' => $profile->field_prof_agency[0][\'nid\']));  
}
return array(array(\'value\' => 0));',
      'label' => 'Agency Responsible for Information Quality',
      'weight' => '7',
      'description' => 'Enter the Agency name corresponding to the applicable Information Quality Guidelines for the dataset.  In some cases, this may be a parent organization, such as a Department.',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_ppog_dgib_submissions
  $fields['policy_program_open_government-field_ppog_dgib_submissions'] = array(
    'field_name' => 'field_ppog_dgib_submissions',
    'type_name' => 'policy_program_open_government',
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
    'allowed_values' => 'Please select
Yes
No',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Is this record a part of DGIB submissions',
      'weight' => '40',
      'description' => 'Answer yes/no to indicate if this dataset submission is in response to the DGIB announcement.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ppog_high_value_dataset
  $fields['policy_program_open_government-field_ppog_high_value_dataset'] = array(
    'field_name' => 'field_ppog_high_value_dataset',
    'type_name' => 'policy_program_open_government',
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
    'allowed_values' => 'Please select
Yes
No',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Is this a high value dataset',
      'weight' => '42',
      'description' => 'Answer yes/no to indicate if this dataset submission is considered "high value".',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ppog_high_value_reason
  $fields['policy_program_open_government-field_ppog_high_value_reason'] = array(
    'field_name' => 'field_ppog_high_value_reason',
    'type_name' => 'policy_program_open_government',
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
          '_error_element' => 'default_value_widget][field_ppog_high_value_reason][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'What makes this a high value dataset',
      'weight' => '43',
      'description' => 'Make a selection that best describes your validation for defining the dataset as "high value".',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ppog_new_data
  $fields['policy_program_open_government-field_ppog_new_data'] = array(
    'field_name' => 'field_ppog_new_data',
    'type_name' => 'policy_program_open_government',
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
          '_error_element' => 'default_value_widget][field_ppog_new_data][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'How is this new',
      'weight' => '44',
      'description' => 'Please provide a brief explination how this data is new. Please provide a brief explanation why this dataset is considered new.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ppog_open_government_plan
  $fields['policy_program_open_government-field_ppog_open_government_plan'] = array(
    'field_name' => 'field_ppog_open_government_plan',
    'type_name' => 'policy_program_open_government',
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
    'allowed_values' => 'Please select
Yes
No',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Is this record listed in your agency open government plan',
      'weight' => '41',
      'description' => 'Answer yes/no to indicate if this dataset submission is listed in your Agency\'s Open Governemtn plan.',
      'type' => 'optionwidgets_select',
      'module' => 'optionwidgets',
    ),
  );

  // Exported field: field_ppog_policy_goal_id
  $fields['policy_program_open_government-field_ppog_policy_goal_id'] = array(
    'field_name' => 'field_ppog_policy_goal_id',
    'type_name' => 'policy_program_open_government',
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
          '_error_element' => 'default_value_widget][field_ppog_policy_goal_id][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Policy/Goal ID',
      'weight' => '38',
      'description' => 'UID',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ppog_policy_goal_title
  $fields['policy_program_open_government-field_ppog_policy_goal_title'] = array(
    'field_name' => 'field_ppog_policy_goal_title',
    'type_name' => 'policy_program_open_government',
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
          '_error_element' => 'default_value_widget][field_ppog_policy_goal_title][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Policy/Goal Title',
      'weight' => '39',
      'description' => 'Official Title.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ppp_policy_goal_id
  $fields['policy_program_privacy-field_ppp_policy_goal_id'] = array(
    'field_name' => 'field_ppp_policy_goal_id',
    'type_name' => 'policy_program_privacy',
    'display_settings' => array(
      'weight' => '31',
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
          '_error_element' => 'default_value_widget][field_ppp_policy_goal_id][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Policy/Goal ID',
      'weight' => '31',
      'description' => 'UID',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ppp_policy_goal_title
  $fields['policy_program_privacy-field_ppp_policy_goal_title'] = array(
    'field_name' => 'field_ppp_policy_goal_title',
    'type_name' => 'policy_program_privacy',
    'display_settings' => array(
      'weight' => '32',
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
          '_error_element' => 'default_value_widget][field_ppp_policy_goal_title][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Policy/Goal Title',
      'weight' => '32',
      'description' => 'Official Title.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_ppp_responsible_agency
  $fields['policy_program_privacy-field_ppp_responsible_agency'] = array(
    'field_name' => 'field_ppp_responsible_agency',
    'type_name' => 'policy_program_privacy',
    'display_settings' => array(
      'weight' => '33',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'plain',
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'agency' => 'agency',
      'block' => 0,
      'country_data' => 0,
      'catalog_type_data_apps' => 0,
      'catalog_type_data_service' => 0,
      'catalog_type_data_tools' => 0,
      'dataset' => 0,
      'catalog_type_document' => 0,
      'access_type_downloadable' => 0,
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
      'state_data_site' => 0,
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
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => NULL,
      'default_value_php' => 'global $user;
// check if content_profile module is enabled
if (module_exists(\'content_profile\')) {
  $profile =  content_profile_load(\'profile\', $user->uid);
  return array(array(\'nid\' => $profile->field_prof_agency[0][\'nid\']));  
}
return array(array(\'value\' => 0));',
      'label' => 'Agency responsible for PII',
      'weight' => '33',
      'description' => 'Enter the Agency name corresponding to the applicable Personally Identifiable Information Guidelines for the dataset.  In some cases, this may be a parent organization, such as a Department.',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_prof_agency
  $fields['profile-field_prof_agency'] = array(
    'field_name' => 'field_prof_agency',
    'type_name' => 'profile',
    'display_settings' => array(
      'weight' => '-2',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
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
      'agency' => 'agency',
      'admin_link' => 0,
      'block' => 0,
      'chart' => 0,
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
      'flags' => 0,
      'geospatial_metadata' => 0,
      'open_data_sites' => 0,
      'page' => 0,
      'profile' => 0,
      'catalog_type_raw_data' => 0,
      'rotating_panel' => 0,
      'sector' => 0,
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
      'size' => 60,
      'default_value' => NULL,
      'default_value_php' => 'return array(
  0 => array(\'nid\' => 0),
);',
      'label' => 'Agency',
      'weight' => '-2',
      'description' => '',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_prof_name
  $fields['profile-field_prof_name'] = array(
    'field_name' => 'field_prof_name',
    'type_name' => 'profile',
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
          '_error_element' => 'default_value_widget][field_prof_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Name',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_prof_phone
  $fields['profile-field_prof_phone'] = array(
    'field_name' => 'field_prof_phone',
    'type_name' => 'profile',
    'display_settings' => array(
      'weight' => '-3',
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
          '_error_element' => 'default_value_widget][field_prof_phone][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Phone Number',
      'weight' => '-3',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_prof_sub_agency
  $fields['profile-field_prof_sub_agency'] = array(
    'field_name' => 'field_prof_sub_agency',
    'type_name' => 'profile',
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'sub_agency' => 'sub_agency',
      'agency' => 0,
      'block' => 0,
      'country_data' => 0,
      'catalog_type_data_apps' => 0,
      'catalog_type_data_service' => 0,
      'catalog_type_data_tools' => 0,
      'dataset' => 0,
      'catalog_type_document' => 0,
      'access_type_downloadable' => 0,
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
      'state_data_site' => 0,
      'statistical_metadata' => 0,
      'story' => 0,
      'subject_keyword' => 0,
      'theme_file_uploader' => 0,
      'policy_program_data_quality' => 0,
      'policy_program_open_government' => 0,
      'policy_program_privacy' => 0,
      'webform' => 0,
      'whats_new' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sub Agency',
      'weight' => '-1',
      'description' => 'Bureau or Sub-Agency or operating unit name.',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_sector_title
  $fields['sector-field_sector_title'] = array(
    'field_name' => 'field_sector_title',
    'type_name' => 'sector',
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
          '_error_element' => 'default_value_widget][field_sector_title][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sector Title',
      'weight' => '31',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_st_data_quality
  $fields['statistical_metadata-field_st_data_quality'] = array(
    'field_name' => 'field_st_data_quality',
    'type_name' => 'statistical_metadata',
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
          '_error_element' => 'default_value_widget][field_st_data_quality][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Data quality (variances, CVs, CIs, etc)',
      'weight' => '12',
      'description' => 'Description or URL of resource containing more detailed information.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_st_disclosure_avoidance
  $fields['statistical_metadata-field_st_disclosure_avoidance'] = array(
    'field_name' => 'field_st_disclosure_avoidance',
    'type_name' => 'statistical_metadata',
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
          '_error_element' => 'default_value_widget][field_st_disclosure_avoidance][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Disclosure avoidance',
      'weight' => '7',
      'description' => 'Description or URL of resource containing more detailed information.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_st_estimation
  $fields['statistical_metadata-field_st_estimation'] = array(
    'field_name' => 'field_st_estimation',
    'type_name' => 'statistical_metadata',
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
          '_error_element' => 'default_value_widget][field_st_estimation][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Estimation',
      'weight' => '5',
      'description' => 'Description or URL of resource containing more detailed information.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_st_non_response_adjustment
  $fields['statistical_metadata-field_st_non_response_adjustment'] = array(
    'field_name' => 'field_st_non_response_adjustment',
    'type_name' => 'statistical_metadata',
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
          '_error_element' => 'default_value_widget][field_st_non_response_adjustment][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Non-response adjustment',
      'weight' => '10',
      'description' => 'Description or URL of resource containing more detailed information.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_st_questionnaire_design
  $fields['statistical_metadata-field_st_questionnaire_design'] = array(
    'field_name' => 'field_st_questionnaire_design',
    'type_name' => 'statistical_metadata',
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
          '_error_element' => 'default_value_widget][field_st_questionnaire_design][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Questionnaire design',
      'weight' => '8',
      'description' => 'Description or URL of resource containing more detailed information.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_st_sampling
  $fields['statistical_metadata-field_st_sampling'] = array(
    'field_name' => 'field_st_sampling',
    'type_name' => 'statistical_metadata',
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
          '_error_element' => 'default_value_widget][field_st_sampling][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sampling',
      'weight' => '4',
      'description' => 'Description or URL of resource containing more detailed information.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_st_seasonal_adjustment
  $fields['statistical_metadata-field_st_seasonal_adjustment'] = array(
    'field_name' => 'field_st_seasonal_adjustment',
    'type_name' => 'statistical_metadata',
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
          '_error_element' => 'default_value_widget][field_st_seasonal_adjustment][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Seasonal adjustment',
      'weight' => '11',
      'description' => 'Description or URL of resource containing more detailed information.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_st_series_breaks
  $fields['statistical_metadata-field_st_series_breaks'] = array(
    'field_name' => 'field_st_series_breaks',
    'type_name' => 'statistical_metadata',
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
          '_error_element' => 'default_value_widget][field_st_series_breaks][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Series breaks',
      'weight' => '9',
      'description' => 'Description or URL of resource containing more detailed information.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_st_statistical_methodology
  $fields['statistical_metadata-field_st_statistical_methodology'] = array(
    'field_name' => 'field_st_statistical_methodology',
    'type_name' => 'statistical_metadata',
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
          '_error_element' => 'default_value_widget][field_st_statistical_methodology][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Statistical methodology ',
      'weight' => '3',
      'description' => 'Components identifying statistical information/properties of data.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_st_weighting
  $fields['statistical_metadata-field_st_weighting'] = array(
    'field_name' => 'field_st_weighting',
    'type_name' => 'statistical_metadata',
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
          '_error_element' => 'default_value_widget][field_st_weighting][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Weighting',
      'weight' => '6',
      'description' => 'Description or URL of resource containing more detailed information.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_sa_subagency_agency
  $fields['sub_agency-field_sa_subagency_agency'] = array(
    'field_name' => 'field_sa_subagency_agency',
    'type_name' => 'sub_agency',
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
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'agency' => 'agency',
      'agency_subagency' => 0,
      'data_tool' => 0,
      'data_catalog' => 0,
      'dataset' => 0,
      'geospatial_metadata' => 0,
      'page' => 0,
      'profile' => 0,
      'statistical_metadata' => 0,
      'story' => 0,
      'sub_agency' => 0,
      'subject_keyword' => 0,
      'webform' => 0,
      'catalog_type_data_apps' => FALSE,
      'catalog_type_data_service' => FALSE,
      'catalog_type_data_tools' => FALSE,
      'catalog_type_document' => FALSE,
      'access_type_downloadable' => FALSE,
      'access_type_embed_link' => FALSE,
      'access_type_execute_upon_access' => FALSE,
      'catalog_type_raw_data' => FALSE,
      'policy_program_data_quality' => FALSE,
      'policy_program_open_government' => FALSE,
      'policy_program_privacy' => FALSE,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Agency',
      'weight' => '34',
      'description' => '',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_sa_subagency_name
  $fields['sub_agency-field_sa_subagency_name'] = array(
    'field_name' => 'field_sa_subagency_name',
    'type_name' => 'sub_agency',
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
          '_error_element' => 'default_value_widget][field_sa_subagency_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sub-Agency Name',
      'weight' => '31',
      'description' => 'Bureau or Sub-Agency or operating unit name.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_sa_subagency_short_name
  $fields['sub_agency-field_sa_subagency_short_name'] = array(
    'field_name' => 'field_sa_subagency_short_name',
    'type_name' => 'sub_agency',
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
          '_error_element' => 'default_value_widget][field_sa_subagency_short_name][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sub-Agency Short Name',
      'weight' => '33',
      'description' => 'Acronym or short name corresponding to the Sub-Agency name.',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_sector_nr
  $fields['sub_sector-field_sector_nr'] = array(
    'field_name' => 'field_sector_nr',
    'type_name' => 'sub_sector',
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'sector' => 'sector',
      'agency' => 0,
      'block' => 0,
      'country_data' => 0,
      'catalog_type_data_apps' => 0,
      'catalog_type_data_service' => 0,
      'catalog_type_data_tools' => 0,
      'dataset' => 0,
      'catalog_type_document' => 0,
      'access_type_downloadable' => 0,
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
      'state_data_site' => 0,
      'statistical_metadata' => 0,
      'story' => 0,
      'sub_agency' => 0,
      'sub_sector' => 0,
      'subject_keyword' => 0,
      'target_audience' => 0,
      'test_date' => 0,
      'theme_file_uploader' => 0,
      'policy_program_data_quality' => 0,
      'policy_program_open_government' => 0,
      'policy_program_privacy' => 0,
      'webform' => 0,
      'whats_new' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sector',
      'weight' => '-3',
      'description' => 'Choose the category(ies) that most closely applies. ',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_sub_sector_title
  $fields['sub_sector-field_sub_sector_title'] = array(
    'field_name' => 'field_sub_sector_title',
    'type_name' => 'sub_sector',
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
          '_error_element' => 'default_value_widget][field_sub_sector_title][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Sub Sector Title',
      'weight' => '-4',
      'description' => 'Title of Sub category of Sector',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Method');
  t('Access Type');
  t('Access URL');
  t('Access point');
  t('Agency');
  t('Agency Generated ID');
  t('Agency Name');
  t('Agency Responsible for Information Quality');
  t('Agency Short Name');
  t('Agency responsible for PII');
  t('App Type');
  t('Asset Jurisdiction');
  t('Bibliographic Citation');
  t('Catalog Location');
  t('Catalog type');
  t('Compressed Format');
  t('Contact Person (Name)');
  t('Contact Person Email Address');
  t('Contact Person Fax No.');
  t('Contact Person Office Address');
  t('Contact Person Phone Number');
  t('Contact Person Title');
  t('Data asset license agreement URL');
  t('Data asset use requires a license agreement');
  t('Data quality (variances, CVs, CIs, etc)');
  t('Datafile');
  t('Dataset Group Name');
  t('Dataset(s) Used');
  t('Date Released');
  t('Date Submitted');
  t('Description');
  t('Disclosure avoidance');
  t('Document Classification');
  t('Estimation');
  t('Extraction Formats');
  t('Field 1');
  t('Field 2');
  t('File');
  t('File format');
  t('File size');
  t('Frequency');
  t('How is this new');
  t('Is this a high value dataset');
  t('Is this record a part of DGIB submissions');
  t('Is this record listed in your agency open government plan');
  t('Keywords');
  t('Language');
  t('Name');
  t('Non-response adjustment');
  t('Phone Number');
  t('Policy/Goal ID');
  t('Policy/Goal Title');
  t('Policy/Program Goal');
  t('Questionnaire design');
  t('Reference URL');
  t('Request Type');
  t('Sampling');
  t('Seasonal adjustment');
  t('Sector');
  t('Sector Title');
  t('Series breaks');
  t('Service Category');
  t('Service Maturity');
  t('Specialized Data Category Designation');
  t('Statistical methodology ');
  t('Sub Agency');
  t('Sub Agency Name');
  t('Sub Sector Title');
  t('Sub-Agency Name');
  t('Sub-Agency Short Name');
  t('Sub-Sector');
  t('Target Audience');
  t('Title');
  t('Tool Location');
  t('Tool Type');
  t('Unique Id');
  t('Validity Date');
  t('Weighting');
  t('What makes this a high value dataset');

  return $fields;
}
