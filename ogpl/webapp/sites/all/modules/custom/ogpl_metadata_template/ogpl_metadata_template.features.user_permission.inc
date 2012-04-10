<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function ogpl_metadata_template_user_default_permissions() {
  $permissions = array();

  // Exported permission: edit field_agency_name
  $permissions['edit field_agency_name'] = array(
    'name' => 'edit field_agency_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'CMS Administrator',
      '2' => 'Moderator',
      '3' => 'PMO',
      '4' => 'Publisher',
    ),
  );

  // Exported permission: edit field_agency_short_name
  $permissions['edit field_agency_short_name'] = array(
    'name' => 'edit field_agency_short_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'CMS Administrator',
      '2' => 'Moderator',
      '3' => 'PMO',
      '4' => 'Publisher',
    ),
  );

  // Exported permission: edit field_atd_access_point
  $permissions['edit field_atd_access_point'] = array(
    'name' => 'edit field_atd_access_point',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_atd_compressed_format
  $permissions['edit field_atd_compressed_format'] = array(
    'name' => 'edit field_atd_compressed_format',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_atd_file_format
  $permissions['edit field_atd_file_format'] = array(
    'name' => 'edit field_atd_file_format',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_atd_file_size
  $permissions['edit field_atd_file_size'] = array(
    'name' => 'edit field_atd_file_size',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctd_catalog_location
  $permissions['edit field_ctd_catalog_location'] = array(
    'name' => 'edit field_ctd_catalog_location',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Publisher',
      '2' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctd_classification
  $permissions['edit field_ctd_classification'] = array(
    'name' => 'edit field_ctd_classification',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctd_dataset_group_name
  $permissions['edit field_ctd_dataset_group_name'] = array(
    'name' => 'edit field_ctd_dataset_group_name',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctd_frequency
  $permissions['edit field_ctd_frequency'] = array(
    'name' => 'edit field_ctd_frequency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctd_language
  $permissions['edit field_ctd_language'] = array(
    'name' => 'edit field_ctd_language',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctd_target_audience_nr
  $permissions['edit field_ctd_target_audience_nr'] = array(
    'name' => 'edit field_ctd_target_audience_nr',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctd_validity_date
  $permissions['edit field_ctd_validity_date'] = array(
    'name' => 'edit field_ctd_validity_date',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctda_app_type
  $permissions['edit field_ctda_app_type'] = array(
    'name' => 'edit field_ctda_app_type',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctda_catalog_location
  $permissions['edit field_ctda_catalog_location'] = array(
    'name' => 'edit field_ctda_catalog_location',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctda_datasets_used
  $permissions['edit field_ctda_datasets_used'] = array(
    'name' => 'edit field_ctda_datasets_used',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctda_language
  $permissions['edit field_ctda_language'] = array(
    'name' => 'edit field_ctda_language',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctda_target_audience_nr
  $permissions['edit field_ctda_target_audience_nr'] = array(
    'name' => 'edit field_ctda_target_audience_nr',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctds_access_type
  $permissions['edit field_ctds_access_type'] = array(
    'name' => 'edit field_ctds_access_type',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctds_datasets_used
  $permissions['edit field_ctds_datasets_used'] = array(
    'name' => 'edit field_ctds_datasets_used',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctds_language
  $permissions['edit field_ctds_language'] = array(
    'name' => 'edit field_ctds_language',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctds_service_category
  $permissions['edit field_ctds_service_category'] = array(
    'name' => 'edit field_ctds_service_category',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctds_service_maturity
  $permissions['edit field_ctds_service_maturity'] = array(
    'name' => 'edit field_ctds_service_maturity',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctds_target_audience_nr
  $permissions['edit field_ctds_target_audience_nr'] = array(
    'name' => 'edit field_ctds_target_audience_nr',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctdt_datasets_used
  $permissions['edit field_ctdt_datasets_used'] = array(
    'name' => 'edit field_ctdt_datasets_used',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctdt_extraction_formats
  $permissions['edit field_ctdt_extraction_formats'] = array(
    'name' => 'edit field_ctdt_extraction_formats',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctdt_language
  $permissions['edit field_ctdt_language'] = array(
    'name' => 'edit field_ctdt_language',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctdt_tool_location
  $permissions['edit field_ctdt_tool_location'] = array(
    'name' => 'edit field_ctdt_tool_location',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctdt_tool_type
  $permissions['edit field_ctdt_tool_type'] = array(
    'name' => 'edit field_ctdt_tool_type',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctrd_bibliography_citation
  $permissions['edit field_ctrd_bibliography_citation'] = array(
    'name' => 'edit field_ctrd_bibliography_citation',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctrd_catalog_location
  $permissions['edit field_ctrd_catalog_location'] = array(
    'name' => 'edit field_ctrd_catalog_location',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctrd_category_designation
  $permissions['edit field_ctrd_category_designation'] = array(
    'name' => 'edit field_ctrd_category_designation',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctrd_dataset_group_name
  $permissions['edit field_ctrd_dataset_group_name'] = array(
    'name' => 'edit field_ctrd_dataset_group_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ctrd_frequency
  $permissions['edit field_ctrd_frequency'] = array(
    'name' => 'edit field_ctrd_frequency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_access_method
  $permissions['edit field_ds_access_method'] = array(
    'name' => 'edit field_ds_access_method',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_access_url
  $permissions['edit field_ds_access_url'] = array(
    'name' => 'edit field_ds_access_url',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_agency_generated_id
  $permissions['edit field_ds_agency_generated_id'] = array(
    'name' => 'edit field_ds_agency_generated_id',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_agency_name
  $permissions['edit field_ds_agency_name'] = array(
    'name' => 'edit field_ds_agency_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'CMS Administrator',
      '2' => 'Content Creator',
      '3' => 'Moderator',
      '4' => 'PMO',
      '5' => 'Publisher',
      '6' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_asset_jurisdiction
  $permissions['edit field_ds_asset_jurisdiction'] = array(
    'name' => 'edit field_ds_asset_jurisdiction',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_catlog_type
  $permissions['edit field_ds_catlog_type'] = array(
    'name' => 'edit field_ds_catlog_type',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_contact_name
  $permissions['edit field_ds_contact_name'] = array(
    'name' => 'edit field_ds_contact_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_contact_phone_number
  $permissions['edit field_ds_contact_phone_number'] = array(
    'name' => 'edit field_ds_contact_phone_number',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_contact_title
  $permissions['edit field_ds_contact_title'] = array(
    'name' => 'edit field_ds_contact_title',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_datafile
  $permissions['edit field_ds_datafile'] = array(
    'name' => 'edit field_ds_datafile',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_dataset_license
  $permissions['edit field_ds_dataset_license'] = array(
    'name' => 'edit field_ds_dataset_license',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_dataset_license_url
  $permissions['edit field_ds_dataset_license_url'] = array(
    'name' => 'edit field_ds_dataset_license_url',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_date_released
  $permissions['edit field_ds_date_released'] = array(
    'name' => 'edit field_ds_date_released',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_date_submitted
  $permissions['edit field_ds_date_submitted'] = array(
    'name' => 'edit field_ds_date_submitted',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
    ),
  );

  // Exported permission: edit field_ds_description
  $permissions['edit field_ds_description'] = array(
    'name' => 'edit field_ds_description',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_email_address
  $permissions['edit field_ds_email_address'] = array(
    'name' => 'edit field_ds_email_address',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_fax_number
  $permissions['edit field_ds_fax_number'] = array(
    'name' => 'edit field_ds_fax_number',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_file
  $permissions['edit field_ds_file'] = array(
    'name' => 'edit field_ds_file',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_keywords
  $permissions['edit field_ds_keywords'] = array(
    'name' => 'edit field_ds_keywords',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_office_address
  $permissions['edit field_ds_office_address'] = array(
    'name' => 'edit field_ds_office_address',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_policy_program_goal
  $permissions['edit field_ds_policy_program_goal'] = array(
    'name' => 'edit field_ds_policy_program_goal',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_reference_url
  $permissions['edit field_ds_reference_url'] = array(
    'name' => 'edit field_ds_reference_url',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_sector
  $permissions['edit field_ds_sector'] = array(
    'name' => 'edit field_ds_sector',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'CMS Administrator',
      '2' => 'Content Creator',
      '3' => 'Moderator',
      '4' => 'Publisher',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_sub_agency
  $permissions['edit field_ds_sub_agency'] = array(
    'name' => 'edit field_ds_sub_agency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'CMS Administrator',
      '2' => 'Content Creator',
      '3' => 'Moderator',
      '4' => 'Publisher',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_sub_sector_nr
  $permissions['edit field_ds_sub_sector_nr'] = array(
    'name' => 'edit field_ds_sub_sector_nr',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_title
  $permissions['edit field_ds_title'] = array(
    'name' => 'edit field_ds_title',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'CMS Administrator',
      '2' => 'Content Creator',
      '3' => 'Moderator',
      '4' => 'Publisher',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ds_unique_id
  $permissions['edit field_ds_unique_id'] = array(
    'name' => 'edit field_ds_unique_id',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
    ),
  );

  // Exported permission: edit field_geo_field_1
  $permissions['edit field_geo_field_1'] = array(
    'name' => 'edit field_geo_field_1',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_geo_field_2
  $permissions['edit field_geo_field_2'] = array(
    'name' => 'edit field_geo_field_2',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ppdq_policy_goal_id
  $permissions['edit field_ppdq_policy_goal_id'] = array(
    'name' => 'edit field_ppdq_policy_goal_id',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ppdq_policy_goal_title
  $permissions['edit field_ppdq_policy_goal_title'] = array(
    'name' => 'edit field_ppdq_policy_goal_title',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ppdq_responsible_agency
  $permissions['edit field_ppdq_responsible_agency'] = array(
    'name' => 'edit field_ppdq_responsible_agency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ppog_dgib_submissions
  $permissions['edit field_ppog_dgib_submissions'] = array(
    'name' => 'edit field_ppog_dgib_submissions',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ppog_high_value_dataset
  $permissions['edit field_ppog_high_value_dataset'] = array(
    'name' => 'edit field_ppog_high_value_dataset',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ppog_high_value_reason
  $permissions['edit field_ppog_high_value_reason'] = array(
    'name' => 'edit field_ppog_high_value_reason',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ppog_new_data
  $permissions['edit field_ppog_new_data'] = array(
    'name' => 'edit field_ppog_new_data',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ppog_open_government_plan
  $permissions['edit field_ppog_open_government_plan'] = array(
    'name' => 'edit field_ppog_open_government_plan',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ppog_policy_goal_id
  $permissions['edit field_ppog_policy_goal_id'] = array(
    'name' => 'edit field_ppog_policy_goal_id',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ppog_policy_goal_title
  $permissions['edit field_ppog_policy_goal_title'] = array(
    'name' => 'edit field_ppog_policy_goal_title',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ppp_policy_goal_id
  $permissions['edit field_ppp_policy_goal_id'] = array(
    'name' => 'edit field_ppp_policy_goal_id',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ppp_policy_goal_title
  $permissions['edit field_ppp_policy_goal_title'] = array(
    'name' => 'edit field_ppp_policy_goal_title',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_ppp_responsible_agency
  $permissions['edit field_ppp_responsible_agency'] = array(
    'name' => 'edit field_ppp_responsible_agency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_prof_agency
  $permissions['edit field_prof_agency'] = array(
    'name' => 'edit field_prof_agency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_prof_name
  $permissions['edit field_prof_name'] = array(
    'name' => 'edit field_prof_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Data Steward',
      '2' => 'Manager',
      '3' => 'Moderator',
      '4' => 'Organization POC',
      '5' => 'PMO',
      '6' => 'Publisher',
      '7' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_prof_phone
  $permissions['edit field_prof_phone'] = array(
    'name' => 'edit field_prof_phone',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Data Steward',
      '2' => 'Manager',
      '3' => 'Moderator',
      '4' => 'Organization POC',
      '5' => 'PMO',
      '6' => 'Publisher',
      '7' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_prof_sub_agency
  $permissions['edit field_prof_sub_agency'] = array(
    'name' => 'edit field_prof_sub_agency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Data Steward',
      '2' => 'Manager',
      '3' => 'Moderator',
      '4' => 'Organization POC',
      '5' => 'PMO',
      '6' => 'Publisher',
      '7' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_request_type
  $permissions['edit field_request_type'] = array(
    'name' => 'edit field_request_type',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
    ),
  );

  // Exported permission: edit field_sa_subagency_agency
  $permissions['edit field_sa_subagency_agency'] = array(
    'name' => 'edit field_sa_subagency_agency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
    ),
  );

  // Exported permission: edit field_sa_subagency_name
  $permissions['edit field_sa_subagency_name'] = array(
    'name' => 'edit field_sa_subagency_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
    ),
  );

  // Exported permission: edit field_sa_subagency_short_name
  $permissions['edit field_sa_subagency_short_name'] = array(
    'name' => 'edit field_sa_subagency_short_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
    ),
  );

  // Exported permission: edit field_sector_nr
  $permissions['edit field_sector_nr'] = array(
    'name' => 'edit field_sector_nr',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_sector_title
  $permissions['edit field_sector_title'] = array(
    'name' => 'edit field_sector_title',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
    ),
  );

  // Exported permission: edit field_st_data_quality
  $permissions['edit field_st_data_quality'] = array(
    'name' => 'edit field_st_data_quality',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_st_disclosure_avoidance
  $permissions['edit field_st_disclosure_avoidance'] = array(
    'name' => 'edit field_st_disclosure_avoidance',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_st_estimation
  $permissions['edit field_st_estimation'] = array(
    'name' => 'edit field_st_estimation',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_st_non_response_adjustment
  $permissions['edit field_st_non_response_adjustment'] = array(
    'name' => 'edit field_st_non_response_adjustment',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_st_questionnaire_design
  $permissions['edit field_st_questionnaire_design'] = array(
    'name' => 'edit field_st_questionnaire_design',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_st_sampling
  $permissions['edit field_st_sampling'] = array(
    'name' => 'edit field_st_sampling',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_st_seasonal_adjustment
  $permissions['edit field_st_seasonal_adjustment'] = array(
    'name' => 'edit field_st_seasonal_adjustment',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_st_series_breaks
  $permissions['edit field_st_series_breaks'] = array(
    'name' => 'edit field_st_series_breaks',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_st_statistical_methodology
  $permissions['edit field_st_statistical_methodology'] = array(
    'name' => 'edit field_st_statistical_methodology',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_st_weighting
  $permissions['edit field_st_weighting'] = array(
    'name' => 'edit field_st_weighting',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'authenticated user',
    ),
  );

  // Exported permission: edit field_sub_sector_title
  $permissions['edit field_sub_sector_title'] = array(
    'name' => 'edit field_sub_sector_title',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'CMS Administrator',
      '2' => 'Moderator',
      '3' => 'Publisher',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_agency_name
  $permissions['view field_agency_name'] = array(
    'name' => 'view field_agency_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
      '4' => 'anonymous user',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: view field_agency_short_name
  $permissions['view field_agency_short_name'] = array(
    'name' => 'view field_agency_short_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
      '4' => 'anonymous user',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: view field_atd_access_point
  $permissions['view field_atd_access_point'] = array(
    'name' => 'view field_atd_access_point',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_atd_compressed_format
  $permissions['view field_atd_compressed_format'] = array(
    'name' => 'view field_atd_compressed_format',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'VRM Admin',
      '4' => 'anonymous user',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: view field_atd_file_format
  $permissions['view field_atd_file_format'] = array(
    'name' => 'view field_atd_file_format',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'VRM Admin',
      '4' => 'anonymous user',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: view field_atd_file_size
  $permissions['view field_atd_file_size'] = array(
    'name' => 'view field_atd_file_size',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'VRM Admin',
      '4' => 'anonymous user',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctd_catalog_location
  $permissions['view field_ctd_catalog_location'] = array(
    'name' => 'view field_ctd_catalog_location',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctd_classification
  $permissions['view field_ctd_classification'] = array(
    'name' => 'view field_ctd_classification',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctd_dataset_group_name
  $permissions['view field_ctd_dataset_group_name'] = array(
    'name' => 'view field_ctd_dataset_group_name',
    'roles' => array(
      '0' => 'anonymous user',
    ),
  );

  // Exported permission: view field_ctd_frequency
  $permissions['view field_ctd_frequency'] = array(
    'name' => 'view field_ctd_frequency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctd_language
  $permissions['view field_ctd_language'] = array(
    'name' => 'view field_ctd_language',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctd_target_audience_nr
  $permissions['view field_ctd_target_audience_nr'] = array(
    'name' => 'view field_ctd_target_audience_nr',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctd_validity_date
  $permissions['view field_ctd_validity_date'] = array(
    'name' => 'view field_ctd_validity_date',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctda_app_type
  $permissions['view field_ctda_app_type'] = array(
    'name' => 'view field_ctda_app_type',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctda_catalog_location
  $permissions['view field_ctda_catalog_location'] = array(
    'name' => 'view field_ctda_catalog_location',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctda_datasets_used
  $permissions['view field_ctda_datasets_used'] = array(
    'name' => 'view field_ctda_datasets_used',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctda_language
  $permissions['view field_ctda_language'] = array(
    'name' => 'view field_ctda_language',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctda_target_audience_nr
  $permissions['view field_ctda_target_audience_nr'] = array(
    'name' => 'view field_ctda_target_audience_nr',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctds_access_type
  $permissions['view field_ctds_access_type'] = array(
    'name' => 'view field_ctds_access_type',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctds_datasets_used
  $permissions['view field_ctds_datasets_used'] = array(
    'name' => 'view field_ctds_datasets_used',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctds_language
  $permissions['view field_ctds_language'] = array(
    'name' => 'view field_ctds_language',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctds_service_category
  $permissions['view field_ctds_service_category'] = array(
    'name' => 'view field_ctds_service_category',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctds_service_maturity
  $permissions['view field_ctds_service_maturity'] = array(
    'name' => 'view field_ctds_service_maturity',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctds_target_audience_nr
  $permissions['view field_ctds_target_audience_nr'] = array(
    'name' => 'view field_ctds_target_audience_nr',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctdt_datasets_used
  $permissions['view field_ctdt_datasets_used'] = array(
    'name' => 'view field_ctdt_datasets_used',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctdt_extraction_formats
  $permissions['view field_ctdt_extraction_formats'] = array(
    'name' => 'view field_ctdt_extraction_formats',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctdt_language
  $permissions['view field_ctdt_language'] = array(
    'name' => 'view field_ctdt_language',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctdt_tool_location
  $permissions['view field_ctdt_tool_location'] = array(
    'name' => 'view field_ctdt_tool_location',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctdt_tool_type
  $permissions['view field_ctdt_tool_type'] = array(
    'name' => 'view field_ctdt_tool_type',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctrd_bibliography_citation
  $permissions['view field_ctrd_bibliography_citation'] = array(
    'name' => 'view field_ctrd_bibliography_citation',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctrd_catalog_location
  $permissions['view field_ctrd_catalog_location'] = array(
    'name' => 'view field_ctrd_catalog_location',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctrd_category_designation
  $permissions['view field_ctrd_category_designation'] = array(
    'name' => 'view field_ctrd_category_designation',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctrd_dataset_group_name
  $permissions['view field_ctrd_dataset_group_name'] = array(
    'name' => 'view field_ctrd_dataset_group_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ctrd_frequency
  $permissions['view field_ctrd_frequency'] = array(
    'name' => 'view field_ctrd_frequency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_access_method
  $permissions['view field_ds_access_method'] = array(
    'name' => 'view field_ds_access_method',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_access_url
  $permissions['view field_ds_access_url'] = array(
    'name' => 'view field_ds_access_url',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_agency_generated_id
  $permissions['view field_ds_agency_generated_id'] = array(
    'name' => 'view field_ds_agency_generated_id',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
      '4' => 'anonymous user',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_agency_name
  $permissions['view field_ds_agency_name'] = array(
    'name' => 'view field_ds_agency_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
      '4' => 'anonymous user',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_asset_jurisdiction
  $permissions['view field_ds_asset_jurisdiction'] = array(
    'name' => 'view field_ds_asset_jurisdiction',
    'roles' => array(),
  );

  // Exported permission: view field_ds_catlog_type
  $permissions['view field_ds_catlog_type'] = array(
    'name' => 'view field_ds_catlog_type',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_contact_name
  $permissions['view field_ds_contact_name'] = array(
    'name' => 'view field_ds_contact_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_contact_phone_number
  $permissions['view field_ds_contact_phone_number'] = array(
    'name' => 'view field_ds_contact_phone_number',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_contact_title
  $permissions['view field_ds_contact_title'] = array(
    'name' => 'view field_ds_contact_title',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_datafile
  $permissions['view field_ds_datafile'] = array(
    'name' => 'view field_ds_datafile',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_dataset_license
  $permissions['view field_ds_dataset_license'] = array(
    'name' => 'view field_ds_dataset_license',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_dataset_license_url
  $permissions['view field_ds_dataset_license_url'] = array(
    'name' => 'view field_ds_dataset_license_url',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_date_released
  $permissions['view field_ds_date_released'] = array(
    'name' => 'view field_ds_date_released',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_date_submitted
  $permissions['view field_ds_date_submitted'] = array(
    'name' => 'view field_ds_date_submitted',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_description
  $permissions['view field_ds_description'] = array(
    'name' => 'view field_ds_description',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_email_address
  $permissions['view field_ds_email_address'] = array(
    'name' => 'view field_ds_email_address',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_fax_number
  $permissions['view field_ds_fax_number'] = array(
    'name' => 'view field_ds_fax_number',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_file
  $permissions['view field_ds_file'] = array(
    'name' => 'view field_ds_file',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'VRM Admin',
      '4' => 'anonymous user',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_keywords
  $permissions['view field_ds_keywords'] = array(
    'name' => 'view field_ds_keywords',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_office_address
  $permissions['view field_ds_office_address'] = array(
    'name' => 'view field_ds_office_address',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_policy_program_goal
  $permissions['view field_ds_policy_program_goal'] = array(
    'name' => 'view field_ds_policy_program_goal',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_reference_url
  $permissions['view field_ds_reference_url'] = array(
    'name' => 'view field_ds_reference_url',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_sector
  $permissions['view field_ds_sector'] = array(
    'name' => 'view field_ds_sector',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_sub_agency
  $permissions['view field_ds_sub_agency'] = array(
    'name' => 'view field_ds_sub_agency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_sub_sector_nr
  $permissions['view field_ds_sub_sector_nr'] = array(
    'name' => 'view field_ds_sub_sector_nr',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_title
  $permissions['view field_ds_title'] = array(
    'name' => 'view field_ds_title',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ds_unique_id
  $permissions['view field_ds_unique_id'] = array(
    'name' => 'view field_ds_unique_id',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Manager',
      '2' => 'Moderator',
      '3' => 'PMO',
      '4' => 'Publisher',
      '5' => 'anonymous user',
    ),
  );

  // Exported permission: view field_geo_field_1
  $permissions['view field_geo_field_1'] = array(
    'name' => 'view field_geo_field_1',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_geo_field_2
  $permissions['view field_geo_field_2'] = array(
    'name' => 'view field_geo_field_2',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ppdq_policy_goal_id
  $permissions['view field_ppdq_policy_goal_id'] = array(
    'name' => 'view field_ppdq_policy_goal_id',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ppdq_policy_goal_title
  $permissions['view field_ppdq_policy_goal_title'] = array(
    'name' => 'view field_ppdq_policy_goal_title',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ppdq_responsible_agency
  $permissions['view field_ppdq_responsible_agency'] = array(
    'name' => 'view field_ppdq_responsible_agency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
      '4' => 'anonymous user',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ppog_dgib_submissions
  $permissions['view field_ppog_dgib_submissions'] = array(
    'name' => 'view field_ppog_dgib_submissions',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ppog_high_value_dataset
  $permissions['view field_ppog_high_value_dataset'] = array(
    'name' => 'view field_ppog_high_value_dataset',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ppog_high_value_reason
  $permissions['view field_ppog_high_value_reason'] = array(
    'name' => 'view field_ppog_high_value_reason',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ppog_new_data
  $permissions['view field_ppog_new_data'] = array(
    'name' => 'view field_ppog_new_data',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ppog_open_government_plan
  $permissions['view field_ppog_open_government_plan'] = array(
    'name' => 'view field_ppog_open_government_plan',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ppog_policy_goal_id
  $permissions['view field_ppog_policy_goal_id'] = array(
    'name' => 'view field_ppog_policy_goal_id',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ppog_policy_goal_title
  $permissions['view field_ppog_policy_goal_title'] = array(
    'name' => 'view field_ppog_policy_goal_title',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ppp_policy_goal_id
  $permissions['view field_ppp_policy_goal_id'] = array(
    'name' => 'view field_ppp_policy_goal_id',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ppp_policy_goal_title
  $permissions['view field_ppp_policy_goal_title'] = array(
    'name' => 'view field_ppp_policy_goal_title',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_ppp_responsible_agency
  $permissions['view field_ppp_responsible_agency'] = array(
    'name' => 'view field_ppp_responsible_agency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
      '4' => 'anonymous user',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: view field_prof_agency
  $permissions['view field_prof_agency'] = array(
    'name' => 'view field_prof_agency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Data Steward',
      '2' => 'Manager',
      '3' => 'Moderator',
      '4' => 'Organization POC',
      '5' => 'PMO',
      '6' => 'Publisher',
      '7' => 'anonymous user',
      '8' => 'authenticated user',
    ),
  );

  // Exported permission: view field_prof_name
  $permissions['view field_prof_name'] = array(
    'name' => 'view field_prof_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Data Steward',
      '2' => 'Manager',
      '3' => 'Moderator',
      '4' => 'Organization POC',
      '5' => 'PMO',
      '6' => 'Publisher',
      '7' => 'anonymous user',
      '8' => 'authenticated user',
    ),
  );

  // Exported permission: view field_prof_phone
  $permissions['view field_prof_phone'] = array(
    'name' => 'view field_prof_phone',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Data Steward',
      '2' => 'Manager',
      '3' => 'Moderator',
      '4' => 'Organization POC',
      '5' => 'PMO',
      '6' => 'Publisher',
      '7' => 'anonymous user',
      '8' => 'authenticated user',
    ),
  );

  // Exported permission: view field_prof_sub_agency
  $permissions['view field_prof_sub_agency'] = array(
    'name' => 'view field_prof_sub_agency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Data Steward',
      '2' => 'Manager',
      '3' => 'Moderator',
      '4' => 'Organization POC',
      '5' => 'PMO',
      '6' => 'Publisher',
      '7' => 'anonymous user',
      '8' => 'authenticated user',
    ),
  );

  // Exported permission: view field_request_type
  $permissions['view field_request_type'] = array(
    'name' => 'view field_request_type',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_sa_subagency_agency
  $permissions['view field_sa_subagency_agency'] = array(
    'name' => 'view field_sa_subagency_agency',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
      '4' => 'anonymous user',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: view field_sa_subagency_name
  $permissions['view field_sa_subagency_name'] = array(
    'name' => 'view field_sa_subagency_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
      '4' => 'anonymous user',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: view field_sa_subagency_short_name
  $permissions['view field_sa_subagency_short_name'] = array(
    'name' => 'view field_sa_subagency_short_name',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
      '4' => 'anonymous user',
      '5' => 'authenticated user',
    ),
  );

  // Exported permission: view field_sector_nr
  $permissions['view field_sector_nr'] = array(
    'name' => 'view field_sector_nr',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'PMO',
      '3' => 'Publisher',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_sector_title
  $permissions['view field_sector_title'] = array(
    'name' => 'view field_sector_title',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_st_data_quality
  $permissions['view field_st_data_quality'] = array(
    'name' => 'view field_st_data_quality',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_st_disclosure_avoidance
  $permissions['view field_st_disclosure_avoidance'] = array(
    'name' => 'view field_st_disclosure_avoidance',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_st_estimation
  $permissions['view field_st_estimation'] = array(
    'name' => 'view field_st_estimation',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_st_non_response_adjustment
  $permissions['view field_st_non_response_adjustment'] = array(
    'name' => 'view field_st_non_response_adjustment',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_st_questionnaire_design
  $permissions['view field_st_questionnaire_design'] = array(
    'name' => 'view field_st_questionnaire_design',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_st_sampling
  $permissions['view field_st_sampling'] = array(
    'name' => 'view field_st_sampling',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_st_seasonal_adjustment
  $permissions['view field_st_seasonal_adjustment'] = array(
    'name' => 'view field_st_seasonal_adjustment',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_st_series_breaks
  $permissions['view field_st_series_breaks'] = array(
    'name' => 'view field_st_series_breaks',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_st_statistical_methodology
  $permissions['view field_st_statistical_methodology'] = array(
    'name' => 'view field_st_statistical_methodology',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_st_weighting
  $permissions['view field_st_weighting'] = array(
    'name' => 'view field_st_weighting',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'Moderator',
      '2' => 'Publisher',
      '3' => 'anonymous user',
      '4' => 'authenticated user',
    ),
  );

  // Exported permission: view field_sub_sector_title
  $permissions['view field_sub_sector_title'] = array(
    'name' => 'view field_sub_sector_title',
    'roles' => array(
      '0' => 'Administrator',
      '1' => 'CMS Administrator',
      '2' => 'Moderator',
      '3' => 'Publisher',
      '4' => 'anonymous user',
      '5' => 'authenticated user',
    ),
  );

  return $permissions;
}
