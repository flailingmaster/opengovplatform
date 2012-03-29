<?php

/**
 * Implementation of hook_default_fe_taxonomy_vocabulary().
 */
function vrm_workflow_states_description_default_fe_taxonomy_vocabulary() {
  $export = array();

  $fe_taxonomy_vocabulary = new stdClass;
  $fe_taxonomy_vocabulary->name = 'VRM workflow states';
  $fe_taxonomy_vocabulary->description = '';
  $fe_taxonomy_vocabulary->help = '';
  $fe_taxonomy_vocabulary->relations = '1';
  $fe_taxonomy_vocabulary->hierarchy = '1';
  $fe_taxonomy_vocabulary->multiple = '0';
  $fe_taxonomy_vocabulary->required = '0';
  $fe_taxonomy_vocabulary->tags = '0';
  $fe_taxonomy_vocabulary->module = 'taxonomy';
  $fe_taxonomy_vocabulary->weight = '0';
  $fe_taxonomy_vocabulary->nodes = array();
  $fe_taxonomy_vocabulary->machine_name = 'vrm_workflow_states';

  $export['vrm_workflow_states'] = $fe_taxonomy_vocabulary;

  return $export;
}

/**
 * Implementation of hook_views_api().
 */
function vrm_workflow_states_description_views_api() {
  return array(
    'api' => '2',
  );
}
