<?php
// $Id: multistep.rules.inc,v 1.1.2.1 2010/07/28 01:23:06 vkareh Exp $

/**
 * Implementation of hook_rules_condition_info().
 */
function multistep_rules_condition_info() {
  return array(
  'multistep_condition_content_is_complete' => array(
    'label' => t('Content is complete'),
    'arguments' => array(
      'node' => array(
        'type' => 'node',
        'label' => t('Content'),
      ),
    ),
    'module' => 'Multistep',
  ),
  'multistep_condition_content_will_complete' => array(
    'label' => t('Content will complete'),
    'arguments' => array(
      'node' => array(
        'type' => 'node',
        'label' => t('Content'),
      ),
    ),
    'module' => 'Multistep',
    ),
  );
}

/**
 * Check to see if the node is complete.
 */
function multistep_condition_content_is_complete($node) {
  $steps = variable_get('multistep_steps_' . $node->type, 0);
  // Look for a step that is not complete.
  for ($step = 1; $step <= $steps; $step++) {
    if (_multistep_get_status($node->nid, $step) != 'submitted') {
      return FALSE;
    }
  }
  return TRUE;
}

/**
 * Check to see if the node is will complete. This should only
 * ever happen once. At least that is the idea anyway.
 */
function multistep_condition_content_will_complete($node) {
  $steps = variable_get('multistep_steps_' . $node->type, 0);
  $current_step = _multistep_get_current_step($node->type);
  $unsubmitted = array();
  // Get all the incomplete steps
  for ($step = 1; $step <= $steps; $step++) {
    if (_multistep_get_status($node->nid, $step) != 'submitted') {
      $unsubmitted[$step] = $step;
    }
  }
  if (count($unsubmitted) == 1 && $unsubmitted[$current_step] == $current_step) {
    // Submitting the last unsubmitted step will complete the content
	  return TRUE;
  }
  return FALSE;
}
