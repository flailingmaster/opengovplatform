<?php

/**
 * @file
 * Provides additional rules support for petreference fields.
 */

/**
 * Implementation of hook_rules_action_info().
 */
function petreference_rules_action_info() {
  $info = array();
  $info['petreference_rules_action_load'] = array(
    'label' => t('Load a referenced pet template'),
    'arguments' => array(
      'pet' => array(
        'type' => 'pet',
        'label' => t('Content containing the PET Reference field'),
      ),
    ),
    'new variables' => array(
      'referenced_pet' => array(
        'type' => 'pet',
        'label' => t('Referenced content'),
      ),
    ),
    'module' => 'CCK',
    'help' => t('Note that if the field has multiple values, only the first pet template will be loaded.'),
  );
  return $info;
}

function petreference_rules_action_load($node, $settings) {
  if ($pid = $node->{$settings['field']}[0]['pid']) {
    return array('referenced_pet' => pet_load(array('nid' => $nid)));
  }
}

function petreference_rules_action_load_form($settings, &$form) {
  $settings += array('field' => '');
  $options = content_rules_get_field_names_by_type('petreference');
  $form['settings']['field'] = array(
    '#type' => 'select',
    '#title' => t('Field'),
    '#default_value' => $settings['field'],
    '#options' => $options,
    '#required' => TRUE,
    '#disabled' => empty($options),
    '#description' => empty($options) ? t('There are no petreference fields defined.') : '',
  );
}
