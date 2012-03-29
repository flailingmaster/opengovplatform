<?php

/**
 * @file
 * Functions that are only called on the admin pages.
 */

/**
 * Overriding system settings form.
 */
function superfish_system_settings_form($form) {
  $form['buttons']['submit'] = array('#type' => 'submit', '#value' => t('Save configuration') );
  if (!empty($_POST) && form_get_errors()) {
    drupal_set_message(t('The settings have not been saved because of the errors.'), 'error');
  }
  $form['#submit'][] = 'system_settings_form_submit';
  $form['#theme'] = 'system_settings_form';
  return $form;
}

/**
 * Module settings form.
 */
function superfish_menu_settings() {
  $form['superfish_number'] = array(
    '#type' => 'select',
    '#title' => t('Number of blocks'),
    '#multiple' => FALSE,
    '#options' => drupal_map_assoc(range(1, 50)),
    '#description' => t('The number of Superfish menu blocks.'),
    '#default_value' => variable_get('superfish_number', 4),
  );
  $form['superfish_slp'] = array(
    '#type' => 'textarea',
    '#title' => t('Path to Superfish library'),
    '#description' => t('Edit only if you are sure of what you are doing.'),
    '#default_value' => variable_get('superfish_slp',
      libraries_get_path('superfish') ."/jquery.hoverIntent.minified.js\n".
      libraries_get_path('superfish') ."/jquery.bgiframe.min.js\n".
      libraries_get_path('superfish') ."/superfish.js\n".
      libraries_get_path('superfish') ."/supersubs.js\n".
      libraries_get_path('superfish') ."/supposition.js\n".
      libraries_get_path('superfish') ."/sftouchscreen.js"),
    '#rows' => 7,
  );
  return superfish_system_settings_form($form);
}

/**
 * Implements hook_validate().
 */
function superfish_menu_settings_validate($form, &$form_state) {
  $error = array();
  // Trimming blank lines and such.
  $sf_library = preg_replace("/(^[\r\n]*|[\r\n]+)[\s\t]*[\r\n]+/", "\n", trim($form_state['values']['superfish_slp']));
  $sf_library = explode("\n", $sf_library);
  // Crystal clear.
  foreach ($sf_library as $s) {
    if (!file_exists($s)) {
      $error[] = $s;
    }
  }
  if (!empty($error)) {
    $error_message = '';
    if (count($error) > 1) {
      foreach ($error as $e) {
        $error_message .= '<li>'. $e .'</li>';
      }
      $error_message = t('Files not found') .': <ul>'. $error_message .'</ul>';
    }
    else {
      $error_message = t('File not found') .': '. $error[0];
    }
    form_set_error('superfish_slp', $error_message);
  }
}