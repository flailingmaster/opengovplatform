<?php

/**
 * Implementation of hook_views_default_views().
 */
function dms_dataset_management_view_views_default_views() {
  $views = array();

  // Exported view: dataset_management
  $view = new view;
  $view->name = 'dataset_management';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->core = 0;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'field_ds_agency_name_nid' => array(
      'label' => 'Agency Name',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_ds_agency_name_nid',
      'table' => 'node_data_field_ds_agency_name',
      'field' => 'field_ds_agency_name_nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'nid' => array(
      'label' => 'Nid',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 1,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'title_1' => array(
      'label' => 'Title Only',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 1,
      ),
      'empty' => 'Untitled',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 1,
      'id' => 'title_1',
      'table' => 'node',
      'field' => 'title',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => 'Title and Description',
      'alter' => array(
        'alter_text' => 1,
        'text' => '<strong>[title_1]</strong>',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'field_agency_name_value' => array(
      'label' => 'Agency Name',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_agency_name_value',
      'table' => 'node_data_field_agency_name',
      'field' => 'field_agency_name_value',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'field_ds_agency_name_nid',
    ),
    'field_ds_description_value' => array(
      'label' => 'Description',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '500',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 1,
      ),
      'empty' => '(no description entered)',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_ds_description_value',
      'table' => 'node_data_field_ds_description',
      'field' => 'field_ds_description_value',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'changed' => array(
      'label' => 'Updated Date',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'small',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'changed',
      'table' => 'node',
      'field' => 'changed',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'field_request_type_value' => array(
      'id' => 'field_request_type_value',
      'table' => 'node_data_field_request_type',
      'field' => 'field_request_type_value',
    ),
    'dms_allowed_operations' => array(
      'label' => 'Operations',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'text' => '',
      'exclude' => 0,
      'id' => 'dms_allowed_operations',
      'table' => 'node',
      'field' => 'dms_allowed_operations',
      'relationship' => 'none',
      'preview_link_text' => 'Preview',
      'download_link_text' => 'Download',
      'approve_link_text' => 'Approve',
      'sendback_link_text' => 'Send back',
      'publish_link_text' => 'Publish',
      'submit_link_text' => 'Submit',
      'edit_link_text' => 'Edit',
      'delete_link_text' => 'Delete',
      'override' => array(
        'button' => 'Override',
      ),
      'display_workflow_state' => 1,
      'update_request_link_text' => 'Update request',
      'delete_request_link_text' => 'Delete request',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'dataset' => 'dataset',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'sid' => array(
      'operator' => 'in',
      'value' => array(
        5 => '5',
        6 => '6',
        7 => '7',
        10 => '10',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'sid_op',
        'identifier' => 'sid',
        'label' => 'Workflow step',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 0,
        'reduce' => 1,
        'bef_select_all_none' => 1,
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'field_request_type_value_many_to_one' => array(
      'operator' => 'or',
      'value' => array(
        'Create' => 'Create',
        'Update' => 'Update',
        'Delete' => 'Delete',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'field_request_type_value_many_to_one_op',
        'identifier' => 'field_request_type_value_many_to_one',
        'label' => 'Request Type Filter',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 0,
        'reduce' => 1,
        'bef_select_all_none' => 1,
      ),
      'id' => 'field_request_type_value_many_to_one',
      'table' => 'node_data_field_request_type',
      'field' => 'field_request_type_value_many_to_one',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Dataset Management Summary');
  $handler->override_option('header_format', '1');
  $handler->override_option('header_empty', 0);
  $handler->override_option('empty', 'There are no items to display.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('use_pager', 'mini');
  $handler->override_option('style_plugin', 'bulk');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'desc',
    'summary' => '',
    'columns' => array(
      'nid' => 'nid',
      'title_1' => 'title_1',
      'title' => 'title',
      'field_agency_name_value' => 'field_agency_name_value',
      'field_ds_description_value' => 'title',
      'changed' => 'changed',
      'field_request_type_value' => 'title',
      'dms_allowed_operations' => 'dms_allowed_operations',
    ),
    'info' => array(
      'nid' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'title_1' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'title' => array(
        'sortable' => 1,
        'separator' => '<br>',
      ),
      'field_agency_name_value' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'field_ds_description_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'changed' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'field_request_type_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'dms_allowed_operations' => array(
        'separator' => '',
      ),
    ),
    'default' => 'changed',
    'execution_type' => '1',
    'max_performance' => 0,
    'display_type' => '0',
    'hide_selector' => 0,
    'preserve_selection' => 1,
    'display_result' => 0,
    'merge_single_action' => 1,
    'operations' => array(
      'workflow_customizations_approve_action' => array(
        'selected' => 1,
        'skip_confirmation' => 1,
        'label' => '',
      ),
      'node_assign_owner_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'workflow_select_given_state_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => 'Change Workflow State',
      ),
      'workflow_select_next_state_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => 'Approve/Submit',
      ),
      'workflow_customizations_delete_action' => array(
        'selected' => 1,
        'skip_confirmation' => 1,
        'label' => '',
      ),
      'views_bulk_operations_delete_node_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => 'Delete',
      ),
      'node_mass_update-a27b9efabcd054685a549378b174ad11' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'system_message_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'token_actions_message_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'dms_ds_upload_download_node_csv_action' => array(
        'selected' => 1,
        'skip_confirmation' => 1,
        'label' => 'Download',
      ),
      'views_bulk_operations_ruleset_action_rules_set_1' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'views_bulk_operations_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'views_bulk_operations_script_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'node_make_sticky_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'node_make_unsticky_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'node_mass_update-c4d3b28efb86fd703619a50b74d43794' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'views_bulk_operations_fields_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
        'settings' => array(
          'php_code' => 0,
          'show_tokens' => 0,
          'display_fields' => array(
            '_all_' => '_all_',
          ),
        ),
      ),
      'views_bulk_operations_taxonomy_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'views_bulk_operations_argument_selector_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'node_promote_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'node_mass_update-14de7d028b4bffdf2b4a266562ca18ac' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'node_mass_update-9c585624b9b3af0b4687d5f97f35e047' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'node_publish_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'token_actions_goto_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'system_goto_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'node_unpromote_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'node_mass_update-8ce21b08bb8e773d10018b484fe4815e' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'node_save_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'system_send_email_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'token_actions_send_email_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'token_actions_send_email_action-c62e847fcee4353039a2d8e9191ffbf0' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'workflow_customizations_sendback_action' => array(
        'selected' => 1,
        'skip_confirmation' => 1,
        'label' => '',
      ),
      'node_mass_update-0ccad85c1ebe4c9ceada1aa64293b080' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'node_unpublish_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'node_unpublish_by_keyword_action' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'auto_nodetitle_operations_update' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => '',
      ),
      'pathauto_node_update_alias_multiple-620e193b20ba9caa374fea9ca0ad38f0' => array(
        'selected' => 0,
        'skip_confirmation' => 0,
        'label' => 'hello',
      ),
    ),
  ));
  $handler = $view->new_display('block_path', 'Dataset Management Summary', 'block_1');
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'dataset' => 'dataset',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'sid' => array(
      'operator' => 'in',
      'value' => array(
        5 => '5',
        6 => '6',
        7 => '7',
        10 => '10',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'sid_op',
        'identifier' => 'sid',
        'label' => 'Workflow step',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 0,
        'reduce' => 1,
        'bef_select_all_none' => 1,
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'field_request_type_value_many_to_one' => array(
      'operator' => 'or',
      'value' => array(
        'Create' => 'Create',
        'Update' => 'Update',
        'Delete' => 'Delete',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'field_request_type_value_many_to_one_op',
        'identifier' => 'field_request_type_value_many_to_one',
        'label' => 'Request Type Filter',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 0,
        'reduce' => 1,
        'bef_select_all_none' => 1,
      ),
      'id' => 'field_request_type_value_many_to_one',
      'table' => 'node_data_field_request_type',
      'field' => 'field_request_type_value_many_to_one',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
  ));
  $handler->override_option('title', 'Dataset Summary');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $handler->override_option('path', '');
  $handler = $view->new_display('block_path', 'Data Steward Summary', 'block_2');
  $handler->override_option('arguments', array(
    'field_ds_agency_name_nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
      'default_argument_type' => 'php',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'field_ds_agency_name_nid',
      'table' => 'node_data_field_ds_agency_name',
      'field' => 'field_ds_agency_name_nid',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        2 => 0,
        10 => 0,
        3 => 0,
        9 => 0,
        4 => 0,
        6 => 0,
      ),
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => 'global $user;
$profile = content_profile_load(\'profile\', $user->uid);

if(isset($profile->field_prof_agency[0][\'nid\']))
     return $profile->field_prof_agency[0][\'nid\'];
else
     return 0;',
      'validate_argument_node_type' => array(
        'access_type_downloadable' => 0,
        'access_type_embed_link' => 0,
        'access_type_execute_upon_access' => 0,
        'agency' => 0,
        'catalog_type_data_apps' => 0,
        'catalog_type_data_service' => 0,
        'catalog_type_data_tools' => 0,
        'catalog_type_document' => 0,
        'catalog_type_raw_data' => 0,
        'dataset' => 0,
        'geospatial_metadata' => 0,
        'page' => 0,
        'policy_program_data_quality' => 0,
        'policy_program_open_government' => 0,
        'policy_program_privacy' => 0,
        'profile' => 0,
        'sector' => 0,
        'statistical_metadata' => 0,
        'story' => 0,
        'subject_keyword' => 0,
        'sub_agency' => 0,
        'upload_docs' => 0,
        'webform' => 0,
        'whats_new' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('title', 'Dataset Summary');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $handler->override_option('path', '');
  $handler = $view->new_display('block_path', 'Organization Summary', 'block_3');
  $handler->override_option('arguments', array(
    'field_ds_agency_name_nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
      'default_argument_type' => 'php',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'field_ds_agency_name_nid',
      'table' => 'node_data_field_ds_agency_name',
      'field' => 'field_ds_agency_name_nid',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        2 => 0,
        3 => 0,
        9 => 0,
        4 => 0,
        6 => 0,
      ),
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_fixed' => '',
      'default_argument_user' => 0,
      'default_argument_php' => 'global $user;
$profile = content_profile_load(\'profile\', $user->uid);

if(isset($profile->field_prof_agency[0][\'nid\']))
     return $profile->field_prof_agency[0][\'nid\'];
else
     return 0;',
      'validate_argument_node_type' => array(
        'agency' => 0,
        'dataset' => 0,
        'data_catalog' => 0,
        'data_tool' => 0,
        'geospatial_metadata' => 0,
        'page' => 0,
        'profile' => 0,
        'statistical_metadata' => 0,
        'story' => 0,
        'subject_keyword' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'dataset' => 'dataset',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'sid' => array(
      'operator' => 'in',
      'value' => array(
        5 => '5',
        6 => '6',
        7 => '7',
        10 => '10',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'sid_op',
        'identifier' => 'sid',
        'label' => 'Workflow step',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 0,
        'reduce' => 1,
        'bef_select_all_none' => 1,
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'field_request_type_value_many_to_one' => array(
      'operator' => 'or',
      'value' => array(
        'Create' => 'Create',
        'Update' => 'Update',
        'Delete' => 'Delete',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'field_request_type_value_many_to_one_op',
        'identifier' => 'field_request_type_value_many_to_one',
        'label' => 'Request Type Filter',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 0,
        'reduce' => 1,
        'bef_select_all_none' => 1,
      ),
      'id' => 'field_request_type_value_many_to_one',
      'table' => 'node_data_field_request_type',
      'field' => 'field_request_type_value_many_to_one',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
  ));
  $handler->override_option('title', 'Dataset Summary');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $handler->override_option('path', '');
  $handler = $view->new_display('block_path', 'PMO Summary', 'block_4');
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'dataset' => 'dataset',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'sid' => array(
      'operator' => 'in',
      'value' => array(
        5 => '5',
        6 => '6',
        7 => '7',
        10 => '10',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'sid_op',
        'identifier' => 'sid',
        'label' => 'Workflow step',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 0,
        'reduce' => 1,
        'bef_select_all_none' => 1,
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'field_request_type_value_many_to_one' => array(
      'operator' => 'or',
      'value' => array(
        'Create' => 'Create',
        'Update' => 'Update',
        'Delete' => 'Delete',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'field_request_type_value_many_to_one_op',
        'identifier' => 'field_request_type_value_many_to_one',
        'label' => 'Request Type Filter',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 0,
        'reduce' => 1,
        'bef_select_all_none' => 1,
      ),
      'id' => 'field_request_type_value_many_to_one',
      'table' => 'node_data_field_request_type',
      'field' => 'field_request_type_value_many_to_one',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    ),
  ));
  $handler->override_option('title', 'Dataset Summary');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $handler->override_option('path', '');

  $views[$view->name] = $view;

  return $views;
}
