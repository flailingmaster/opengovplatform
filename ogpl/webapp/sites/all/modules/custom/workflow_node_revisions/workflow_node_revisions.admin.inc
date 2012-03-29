<?php

/**
 * @file
 * Administrative pages for configuring workflow based revisions.
 */

/**
 * Menu callback. Create the main workflow based revisions configuration page, which gives an overview
 * of workflow based revisioning configurations.
 */
function workflow_node_revisions_overview_form() {
  $workflows = workflow_get_all();
  $states = array();
  $form = array();
  $fields = array_keys(content_fields());
  $field_options = array_combine($fields, $fields);
  $role_options = user_roles();

  $form['revision_permissions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Provide roles permitted to update and delete published datasets.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['revision_permissions']['workflow_node_revision_role_permissions'] = array(
    '#type' => 'checkboxes',
    '#options' => $role_options,
    '#title' => t('Select roles'),
    '#default_value' => variable_get('workflow_node_revision_role_permissions', array(3 => 3, 4 => 4, 6 => 6, 10 => 10)),
  );

  $form['request_type'] = array(
    '#type' => 'fieldset',
    '#title' => t('Provide a field for storing update and delete request status.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['request_type']["workflow_node_revision_request_type"] = array(
    '#type' => 'select',
    '#options' => $field_options,
    '#title' => t('Request type field'),
    '#default_value' => variable_get("workflow_node_revision_request_type", 'field_request_type'),
  );

  $form['workflow'] = array(
    '#type' => 'fieldset',
    '#title' => t('For each workflow listed below, select the states where a node is considered published, deleted or archived. You have to select a field with unique values to keep track of content revisions.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  foreach ($workflows as $wid => $name) {
    $form['workflow'][$name] = array(
      '#type' => 'item',
      '#value' => t(check_plain( 'Workflow: ' . $name)),
    );

    $states = workflow_get_states($wid);

    $form['workflow']["workflow_node_revision_published_state_$wid"] = array(
      '#type' => 'select',
      '#options' => $states,
      '#title' => t('Workflow published state:'),
      '#default_value' => variable_get("workflow_node_revision_published_state_$wid", '10'),
    );

    $form['workflow']["workflow_node_revision_deleted_state_$wid"] = array(
      '#type' => 'select',
      '#options' => $states,
      '#title' => t('Workflow deleted state:'),
      '#default_value' => variable_get("workflow_node_revision_deleted_state_$wid", '11'),
    );

    $form['workflow']["workflow_node_revision_archived_state_$wid"] = array(
      '#type' => 'select',
      '#options' => $states,
      '#title' => t('Workflow archived state:'),
      '#default_value' => variable_get("workflow_node_revision_archived_state_$wid", '12'),
    );

    $form['workflow']["workflow_node_revision_unique_field_$wid"] = array(
      '#type' => 'select',
      '#options' => $field_options,
      '#title' => t('Workflow unique field:'),
      '#default_value' => variable_get("workflow_node_revision_unique_field_$wid", 'field_ds_unique_id'),
    );
  }

  return system_settings_form($form);
}
