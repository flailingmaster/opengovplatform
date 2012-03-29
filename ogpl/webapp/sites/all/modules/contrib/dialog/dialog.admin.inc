<?php
// $Id$

/**
 * @file
 * Administration settings for Dialog API
 */

/**
 * Administration settings form.
 */
function dialog_admin_settings() {
  $form = array();

  $form['dialog_attributes'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Dialog default attributes'),
  );

  $form['dialog_attributes']['dialog_default_height'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Height'),
    '#default_value' => variable_get('dialog_default_height', 'auto'),
    '#description'   => t('The CSS value for dialog height'),
  );

  $form['dialog_attributes']['dialog_default_width'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Width'),
    '#default_value' => variable_get('dialog_default_width', '600px'),
    '#description'   => t('The CSS value for dialog width'),
  );

  return system_settings_form($form);
}
