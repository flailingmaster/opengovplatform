<?php

/**
 * @file
 * A node revisioning module based on workflow states defined by the workflow module. Page callbacks for workflow node revisions module.
 */


/**
 *  Menu callback for creating revisions of published content
 */
function workflow_node_revisions_create_revision($original_node, $action) {
  $request_type = array(
    'update_request' => 'Update',
    'delete_request' => 'Delete',
  );

  return drupal_get_form('workflow_node_revisions_confirm_revision', $original_node, $request_type[$action]);
}

/**
 *  form builder: prompt the user to confirm the operation
 */
function workflow_node_revisions_confirm_revision($form_state, $node, $action) {
  $form['nid'] = array('#type' => 'value', '#value' => $node->nid);
  $form['request_type'] = array('#type' => 'value', '#value' => $action);

  $confirm_form = confirm_form($form,
    t('Are you sure you want to %action %title?', array('%title' =>  $node->title, '%action' => $action)), 
    'node/'. $node->nid, '<p>'. 
    t('This action will create a new '. $action .  ' request. You will then be redirected to the edit page for the new request.') .'</p>',
    t($action),
    t('Cancel'));

  return $confirm_form;
}

/**
 *  Handle confirm form submission
 */
function workflow_node_revisions_confirm_revision_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $new_nid = workflow_node_revisions_save_revision($form_state['values']['nid'], $form_state['values']['request_type']);
  }
  $form_state['redirect'] = 'node/'. $new_nid .'/edit';
}

/**
 *  Clones a node by directly saving it.
 */
function workflow_node_revisions_save_revision($nid, $action) {
  if (is_numeric($nid)) {
    global $user;

    $node = node_load($nid);
    if (isset($node->nid)) {
      $original_node = drupal_clone($node);

      $node->nid = NULL;
      $node->vid = NULL;
      $node->tnid = NULL;
      $node->name = $user->name;
      $node->uid = $user->uid;
      $node->created = NULL;
      $node->changed = NULL;
      $node->path = NULL;
      $node->files = array();
      $node->title = t('!action request: !title', array('!title' => $node->title, '!action' => $action));
      $node->_workflow = NULL;
      $node->status = 1;

      // Add an extra property as a flag.
      $node->request_from_original_nid = $original_node->nid;

      // Add the request type
      $request_type_field = variable_get("workflow_node_revision_request_type", 'field_request_type');
      $node->$request_type_field = array('0' => array('value' => ucfirst($action)));

      $node_options = variable_get('node_options_'. $node->type, array('status', 'promote'));
      // Fill in the default values.
      foreach (array('status', 'moderate', 'promote', 'sticky', 'revision') as $key) {
        $node->$key = in_array($key, $node_options);
      }

      node_save($node);
      return $node->nid;
    }
  }
}
