<?php

/**
 * Implementation of hook_content_default_fields().
 */
function featured_gallery_content_default_fields() {
  $fields = array();

  // Exported field: field_imag
  $fields['imageflow-field_imag'] = array(
    'field_name' => 'field_imag',
    'type_name' => 'imageflow',
    'display_settings' => array(
      'weight' => '7',
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
      '5' => array(
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
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 1,
      'title' => '',
      'custom_title' => 1,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'image',
      'weight' => '7',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Exported field: field_instructions
  $fields['imageflow-field_instructions'] = array(
    'field_name' => 'field_instructions',
    'type_name' => 'imageflow',
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

  // Exported field: field_reference_dataset
  $fields['imageflow-field_reference_dataset'] = array(
    'field_name' => 'field_reference_dataset',
    'type_name' => 'imageflow',
    'display_settings' => array(
      'weight' => '8',
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
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'agency' => 0,
      'diymap' => 0,
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
      'openlayers_test_type' => 0,
      'page' => 0,
      'profile' => 0,
      'catalog_type_raw_data' => 0,
      'rotating_panel_half' => 0,
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
      'geo_data' => 0,
    ),
    'advanced_view' => 'list_datasets',
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
      'label' => 'High Value Datasets',
      'weight' => '8',
      'description' => '',
      'type' => 'nodereference_buttons',
      'module' => 'nodereference',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('High Value Datasets');
  t('Instructions');
  t('image');

  return $fields;
}
