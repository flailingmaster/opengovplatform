<?php

/**
 * Implementation of hook_fieldgroup_default_groups().
 */
function ogpl_metadata_template_fieldgroup_default_groups() {
  $groups = array();

  // Exported group: group_ds_access_type
  $groups['dataset-group_ds_access_type'] = array(
    'group_type' => 'standard',
    'type_name' => 'dataset',
    'group_name' => 'group_ds_access_type',
    'label' => 'Access Type',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => 'Access Method links Data Asset Core Metadata and [Access Method]-specific Metadata.',
      ),
      'display' => array(
        'weight' => '6',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'simple',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'description' => '',
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
      'multistep' => array(
        'step' => '2',
        'block' => 1,
      ),
    ),
    'weight' => '6',
    'fields' => array(
      '0' => 'field_ds_access_method',
    ),
  );

  // Exported group: group_ds_all_datasets
  $groups['dataset-group_ds_all_datasets'] = array(
    'group_type' => 'standard',
    'type_name' => 'dataset',
    'group_name' => 'group_ds_all_datasets',
    'label' => 'Core metadata',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => 'CORE:  Data Asset Core Metadata (metadata relevant to any data asset)',
      ),
      'display' => array(
        'weight' => '5',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'simple',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'simple',
          'exclude' => 0,
        ),
        'description' => 'CORE:  Data Asset Core Metadata (metadata relevant to any data asset)',
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
      'multistep' => array(
        'step' => '1',
        'block' => 0,
      ),
    ),
    'weight' => '5',
    'fields' => array(
      '0' => 'field_ds_agency_generated_id',
      '1' => 'field_ds_title',
      '2' => 'field_ds_description',
      '3' => 'field_ds_agency_name',
      '4' => 'field_ds_sub_agency',
      '5' => 'field_ds_contact_name',
      '6' => 'field_ds_contact_title',
      '7' => 'field_ds_office_address',
      '8' => 'field_ds_contact_phone_number',
      '9' => 'field_ds_email_address',
      '10' => 'field_ds_fax_number',
      '11' => 'field_ds_sector',
      '12' => 'field_ds_sub_sector_nr',
      '13' => 'field_ds_keywords',
      '14' => 'field_ds_date_released',
      '15' => 'field_ds_access_url',
      '16' => 'field_ds_reference_url',
      '17' => 'field_ds_asset_jurisdiction',
      '18' => 'field_ds_dataset_license',
      '19' => 'field_ds_dataset_license_url',
    ),
  );

  // Exported group: group_ds_catalog_type
  $groups['dataset-group_ds_catalog_type'] = array(
    'group_type' => 'standard',
    'type_name' => 'dataset',
    'group_name' => 'group_ds_catalog_type',
    'label' => 'Catalog Type',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '8',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'simple',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'description' => '',
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'flexifield_dataset' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
      'multistep' => array(
        'step' => '3',
        'block' => 1,
      ),
    ),
    'weight' => '8',
    'fields' => array(
      '0' => 'field_ds_catlog_type',
    ),
  );

  // Exported group: group_ds_data_store
  $groups['dataset-group_ds_data_store'] = array(
    'group_type' => 'standard',
    'type_name' => 'dataset',
    'group_name' => 'group_ds_data_store',
    'label' => 'Data File',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '7',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'simple',
          'exclude' => 0,
        ),
        'description' => '',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '5' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
      'multistep' => array(
        'step' => '2',
        'block' => 0,
      ),
    ),
    'weight' => '7',
    'fields' => array(
      '0' => 'field_ds_datafile',
    ),
  );

  // Exported group: group_ds_policy_program_goal
  $groups['dataset-group_ds_policy_program_goal'] = array(
    'group_type' => 'standard',
    'type_name' => 'dataset',
    'group_name' => 'group_ds_policy_program_goal',
    'label' => 'Policy/Program Goal',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => 'Identify the policies and/or programs the data asset is required to comply with or is intended to advance.',
      ),
      'display' => array(
        'weight' => '9',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'simple',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'description' => '',
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
      'multistep' => array(
        'step' => '4',
        'block' => 1,
      ),
    ),
    'weight' => '9',
    'fields' => array(
      '0' => 'field_ds_policy_program_goal',
    ),
  );

  // Exported group: group_ds_profile
  $groups['dataset-group_ds_profile'] = array(
    'group_type' => 'standard',
    'type_name' => 'dataset',
    'group_name' => 'group_ds_profile',
    'label' => 'Core metadata',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => 'CORE: Administration-specific Metadata (can be considered part of Data Asset Core Metadata)',
      ),
      'display' => array(
        'weight' => '4',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'simple',
          'exclude' => 0,
        ),
        'description' => 'CORE: Administration-specific Metadata (can be considered part of Data Asset Core Metadata)',
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
      'multistep' => array(
        'step' => '1',
        'block' => 1,
      ),
    ),
    'weight' => '4',
    'fields' => array(
      '0' => 'field_ds_unique_id',
      '1' => 'field_ds_date_submitted',
      '2' => 'field_request_type',
    ),
  );

  // Exported group: group_ds_upload
  $groups['dataset-group_ds_upload'] = array(
    'group_type' => 'standard',
    'type_name' => 'dataset',
    'group_name' => 'group_ds_upload',
    'label' => 'Upload',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset_collapsible',
        'description' => '',
      ),
      'display' => array(
        'weight' => '3',
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'simple',
          'exclude' => 0,
        ),
        'description' => '',
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'flexifield_dataset' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
      'multistep' => array(
        'step' => '1',
        'block' => 0,
      ),
    ),
    'weight' => '3',
    'fields' => array(
      '0' => 'field_ds_file',
    ),
  );

  // Exported group: group_ds_workflow
  $groups['dataset-group_ds_workflow'] = array(
    'group_type' => 'standard',
    'type_name' => 'dataset',
    'group_name' => 'group_ds_workflow',
    'label' => 'Workflow Submission',
    'settings' => array(
      'form' => array(
        'style' => 'fieldset',
        'description' => '',
      ),
      'display' => array(
        'weight' => '11',
        'label' => 'above',
        'teaser' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'full' => array(
          'format' => 'simple',
          'exclude' => 0,
        ),
        '4' => array(
          'format' => 'fieldset',
          'exclude' => 1,
        ),
        'description' => '',
        '2' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        '3' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
        'token' => array(
          'format' => 'fieldset',
          'exclude' => 0,
        ),
      ),
      'multistep' => array(
        'step' => '5',
        'block' => 1,
      ),
    ),
    'weight' => '11',
    'fields' => array(),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Access Type');
  t('Catalog Type');
  t('Core metadata');
  t('Data File');
  t('Policy/Program Goal');
  t('Upload');
  t('Workflow Submission');

  return $groups;
}
