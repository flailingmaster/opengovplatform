<?php

/**
 * Implementation of hook_views_default_views().
 */
function list_of_datasets_views_default_views() {
  $views = array();

  // Exported view: list_datasets
  $view = new view;
  $view->name = 'list_datasets';
  $view->description = 'list_datasets';
  $view->tag = '';
  $view->base_table = 'node';
  $view->core = 0;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'field_ds_policy_program_goal_item_id' => array(
      'label' => 'Policy/Program Goal',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_ds_policy_program_goal_item_id',
      'table' => 'node_data_field_ds_policy_program_goal',
      'field' => 'field_ds_policy_program_goal_item_id',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'title' => array(
      'label' => '',
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
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'dataset' => 'dataset',
        'policy_program_data_quality' => 'policy_program_data_quality',
        'policy_program_open_government' => 'policy_program_open_government',
        'policy_program_privacy' => 'policy_program_privacy',
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
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'sid' => array(
      'operator' => 'in',
      'value' => array(
        10 => '10',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'relationship' => 'none',
    ),
    'field_ppog_high_value_dataset_value_many_to_one' => array(
      'operator' => 'or',
      'value' => array(
        'Yes' => 'Yes',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'field_ppog_high_value_dataset_value_many_to_one',
      'table' => 'node_data_field_ppog_high_value_dataset',
      'field' => 'field_ppog_high_value_dataset_value_many_to_one',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'field_ds_policy_program_goal_item_id',
      'reduce_duplicates' => 0,
    ),
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('items_per_page', 0);
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);

  $views[$view->name] = $view;

  return $views;
}
