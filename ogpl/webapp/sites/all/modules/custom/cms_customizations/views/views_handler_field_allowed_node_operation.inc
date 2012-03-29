<?php

/**
 * @file
 * Provide views field handler for dms_customizations.module.
 */

/**
 * Field handler to present a link to the node.
 */
class views_handler_field_allowed_node_operation extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['preview_link_text'] = array(
      '#type' => 'textfield',
      '#description' => 'Leave blank to not show this link.',
      '#title' => t('Preview link text'),
      '#default_value' => $this->options['preview_link_text'],
    );
    $form['download_link_text'] = array(
      '#type' => 'textfield',
      '#description' => 'Leave blank to not show this link.',
      '#title' => t('Download link text'),
      '#default_value' => $this->options['download_link_text'],
    );
    $form['approve_link_text'] = array(
      '#type' => 'textfield',
      '#description' => 'Leave blank to not show this link.',
      '#title' => t('Approve link text'),
      '#default_value' => $this->options['approve_link_text'],
    );
    $form['sendback_link_text'] = array(
      '#type' => 'textfield',
      '#description' => 'Leave blank to not show this link.',
      '#title' => t('Send back link text'),
      '#default_value' => $this->options['sendback_link_text'],
    );
    $form['publish_link_text'] = array(
      '#type' => 'textfield',
      '#description' => 'Leave blank to not show this link.',
      '#title' => t('Publish link text'),
      '#default_value' => $this->options['publish_link_text'],
    );
    $form['submit_link_text'] = array(
      '#type' => 'textfield',
      '#description' => 'Leave blank to not show this link.',
      '#title' => t('Submit link text'),
      '#default_value' => $this->options['submit_link_text'],
    );
    $form['edit_link_text'] = array(
      '#type' => 'textfield',
      '#description' => 'Leave blank to not show this link.',
      '#title' => t('Edit link text'),
      '#default_value' => $this->options['edit_link_text'],
    );
    $form['delete_link_text'] = array(
      '#type' => 'textfield',
      '#description' => 'Leave blank to not show this link.',
      '#title' => t('Delete link text'),
      '#default_value' => $this->options['delete_link_text'],
    );
    $form['update_request_link_text'] = array(
      '#type' => 'textfield',
      '#description' => 'Leave blank to not show this link.',
      '#title' => t('Update request link text'),
      '#default_value' => $this->options['update_request_link_text'],
    );  
    $form['delete_request_link_text'] = array(
      '#type' => 'textfield',
      '#description' => 'Leave blank to not show this link.',
      '#title' => t('Delete request link text'),
      '#default_value' => $this->options['delete_request_link_text'],
    );

    $form['display_workflow_state'] = array(
      '#type' => 'checkbox',
      '#description' => 'Enable to show current workflow state.',
      '#title' => t('Show current workflow state'),
      '#options' => array(0 => t('Hide'), 1 => t('Show')),
      '#default_value' => $this->options['display_workflow_state'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function possible_workflow_transitions($node) {
    $wid = workflow_get_workflow_for_type($node->type);
    $published_state = variable_get("workflow_node_revision_published_state_$wid", 19);
    $actions = array();

    $choices = workflow_field_choices($node);

    if (!is_array($choices)) {
      return $actions;
    }

    if ($system_state = array_search('Create/Edit Content', $choices)) {
      unset($choices[$system_state]);
    }

    $choice_keys = array_keys($choices);

    $current_state = workflow_node_current_state($node);
    $current_state_key = array_search($current_state, $choice_keys);

    $current_state_name = workflow_get_state_name($current_state);
    $actions['current_state_name'] = $current_state_name;

    if (($current_state_key - 1) >= 0 ) {
      $actions['sendback'] = $choice_keys[$current_state_key - 1];
    }

    if (($current_state_key + 1) < count($choice_keys) && $current_state_key != 0) {
      $actions['approve'] = $choice_keys[$current_state_key + 1];
    }

    if ($current_state_key == 0 && ($current_state_key + 1) < count($choice_keys)) {
      $actions['submit'] = $choice_keys[$current_state_key + 1];
    }

    if (!empty($choices[$published_state]) && $current_state != $published_state) {
      $actions['publish'] = $published_state;
    }
   
    if ($current_state == $published_state) {
      $actions['update_and_delete_request'] = $published_state;
    }
 
    return $actions;
  }

  function render($values) {
    global $user;
    $links = '';

    $nid = $values->{$this->aliases['nid']};
    $node = node_load($nid);
    $actions = $this->possible_workflow_transitions($node);

    if ($this->options['display_workflow_state']) {
      $links.= $actions['current_state_name'] . '<br>';
    }

    if (isset($actions['approve']) && !empty($this->options['approve_link_text'])) {
      $attributes = array('attributes' => array('class' => 'approve-link', 'title' => 'Approve this record for next approval step'));
      $text = $this->options['approve_link_text'];
      $links .= l($text, url("node/$nid/workflow", array('query' => 'workflow_state=' . $actions['approve'] . '&destination=', 'absolute' => TRUE)), $attributes);
    }

    if (isset($actions['submit']) && !empty($this->options['submit_link_text'])) {
      $attributes = array('attributes' => array('class' => 'submit-link', 'title' => 'Submit this record for approval'));
      $text = $this->options['submit_link_text'];
      $links .= l($text, url("node/$nid/workflow", array('query' => 'workflow_state=' . $actions['submit'] . '&destination=', 'absolute' => TRUE)), $attributes);
    }

    if (isset($actions['publish']) && !empty($this->options['publish_link_text'])) {
      $attributes = array('attributes' => array('class' => 'publish-link', 'title' => 'Publish this record to the main website'));
      $text = $this->options['publish_link_text'];
      $links .= l($text, url("node/$nid/workflow", array('query' => 'workflow_state=' . $actions['publish'] . '&destination=', 'absolute' => TRUE)), $attributes);
    }

    if (isset($actions['sendback']) && !empty($this->options['sendback_link_text'])) {
      $attributes = array('attributes' => array('class' => 'sendback-link', 'title' => 'Send this record back in workflow'));
      $text =$this->options['sendback_link_text'];
      $links .= l($text, url("node/$nid/workflow", array('query' => 'workflow_state=' . $actions['sendback'] . '&destination=', 'absolute' => TRUE)), $attributes);
    }

    if (node_access('grant_update', $node) && !empty($this->options['edit_link_text'])) {
      $attributes = array('attributes' => array('class' => 'edit-link', 'title' => 'Edit this record'));
      $text = $this->options['edit_link_text'];
      $links .= l($text, url("node/$nid/edit", array('query' => 'destination=', 'absolute' => TRUE)), $attributes);
    }
   if (node_access('grant_view', $node) && !empty($this->options['preview_link_text'])) {
      $attributes = array('attributes' => array('class' => 'preview-link', 'title' => 'Preview this record'));
      $text = $this->options['preview_link_text'];
      $links .= l($text, url("node/$nid", array('query' => 'destination=', 'absolute' => TRUE)), $attributes);
    }

    if (node_access('view', $node) && !empty($this->options['download_link_text'])) {
      $attributes = array('attributes' => array('class' => 'download-csv-link', 'title' => 'Download this record in CSV format'));
      $text = $this->options['download_link_text'];
      $links .= l($text, url("node/$nid/view/csv", array('query' => 'destination=', 'absolute' => TRUE)), $attributes);
    }

    return $links;
  }
}
