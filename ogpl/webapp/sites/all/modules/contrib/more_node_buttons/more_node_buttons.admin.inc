<?php
// $Id: more_node_buttons.admin.inc,v 1.1.2.9 2010/11/04 15:08:23 quiptime Exp $

/* 
 * @file
 * Function file to administer the More node buttons module settings.
 */

/**
 * Display an overview table contains the More node buttons mappings.
 *
 * @return
 *   The form array.
 */
function more_node_buttons_admin() {
  $mappings = more_node_buttons_get_mappings();
  $mnb_values = more_node_buttons_get_values();

  $form = array(
    '#theme' => 'more_node_buttons_all_form',
    '#mappings' => $mappings,
    '#cache' => TRUE,
    '#weight' => 0,
  );

  foreach ($mappings as $type => $v) {
    // It makes no sense to use the Mnb module with the content type panel.
    if ($type == 'panel') {
      continue;
    }

    // Provide "Cancel" button settings.
    $form['node_buttons'][$type]['more_node_buttons_cancel_'. $type] = array(
      '#type' => 'select',
      '#options' => array(
        0 => t('None'),
        1 => t('Left'),
        2 => t('Right'),
      ),
      '#default_value' => variable_get('more_node_buttons_cancel_'. $type, 0),
    );
    // Provide the "Cancel referer redirect" option.
    $form['node_buttons'][$type]['more_node_buttons_cancel_referer_redirect_'. $type] = array(
      '#type' => 'checkbox',
      '#default_value' => variable_get('more_node_buttons_cancel_referer_redirect_'. $type, 0),
    );
    // Provide "Save and continue" button settings.
    $form['node_buttons'][$type]['more_node_buttons_sac_'. $type] = array(
      '#type' => 'select',
      '#options' => _more_node_buttons_save_and_options(),
      '#default_value' => variable_get('more_node_buttons_sac_'. $type, 0),
    );
    // Provide "Save and create new" button settings.
    $form['node_buttons'][$type]['more_node_buttons_sacn_'. $type] = array(
      '#type' => 'select',
      '#options' => _more_node_buttons_save_and_options(),
      '#default_value' => variable_get('more_node_buttons_sacn_'. $type, 0),
    );
    // Provide the "Create new" tab option.
    $form['node_buttons'][$type]['more_node_buttons_tabcn_'. $type] = array(
      '#type' => 'checkbox',
      '#default_value' => variable_get('more_node_buttons_tabcn_'. $type, 0),
    );
  }

  // Provide customizable button and tab values.
  // Don't make default value strings translatable here!
  $form['values'] = array(
    '#type' => 'fieldset',
    '#title' => t('Button and tab values'),
    '#description' => t('Use your own names for the buttons and the tab. These names are translatable with the translation interface. Do not enter translated texts here.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['values']['more_node_buttons_value_cancel'] = array(
    '#type' => 'textfield',
    '#title' => t('Cancel button'),
    '#size' => 20,
    '#maxlength' => 50,
    '#default_value' => $mnb_values['cancel'] ? check_plain($mnb_values['cancel']) : 'Cancel',
    '#prefix' => '<div class="mnb-values-first">',
  );
  $form['values']['more_node_buttons_value_sac'] = array(
    '#type' => 'textfield',
    '#title' => t('Save and continue button'),
    '#size' => 20,
    '#maxlength' => 50,
    '#default_value' => $mnb_values['sac'] ? check_plain($mnb_values['sac']) : 'Save and continue',
    '#suffix' => '</div>',
  );
  $form['values']['more_node_buttons_value_sacn'] = array(
    '#type' => 'textfield',
    '#title' => t('Save and create new button'),
    '#size' => 20,
    '#maxlength' => 50,
    '#default_value' => $mnb_values['sacn'] ? check_plain($mnb_values['sacn']) : 'Save and create new',
    '#prefix' => '<div class="mnb-values-last">',
  );
  $form['values']['more_node_buttons_value_tabcn'] = array(
    '#type' => 'textfield',
    '#title' => t('Create new tab'),
    '#size' => 20,
    '#maxlength' => 50,
    '#default_value' => $mnb_values['tabcn'] ? check_plain($mnb_values['tabcn']) : 'Create new',
    '#suffix' => '</div>',
  );

  $form['submit']['save'] = array(
    '#type' => 'submit',
    '#name' => 'save',
    '#value' => t('Save'),
  );
  $form['submit']['reset'] = array(
    '#type' => 'submit',
    '#name' => 'reset',
    '#value' => t('Reset to defaults'),
  );

  return $form;
}

/**
 * Display a central Mnb settings form.
 *
 * @return
 *   The complete HTML formatted administer page.
 */
function theme_more_node_buttons_all_form($form) {
  drupal_add_css(drupal_get_path('module', 'more_node_buttons') .'/more_node_buttons_admin.css');
  
  $mappings = $form['#mappings'];
  $output  = '';
  $extra_info = '';

  $output  = '<h3>' .t('Settings'). '</h3>';
  $output .= '<p>'. t('Which @module functions are used by the content types.', array('@module' => t('More node buttons'))) .'</p>';

  $header = array(t('Cancel'), t('- referer redirection'), t('Save and continue'), t('Save and create new'), t('Create new tab'),);

  $i = 1;
  foreach ($mappings as $type => $maps) {
    // It makes no sense to use the Mnb module with the content type panel.
    if ($type == 'panel') {
      // Define an additional information.
      $extra_info = '<p>'. t('For the content type %type no settings can be made.', array('%type' => t($mappings['panel']['name']))) .'</p>';
      continue;
    }

    // Convert underscores in the machine redeable type names to hyphen for right path building.
    $parsed_type = str_replace('_', '-', $type);

    // Provide own odd/even functionality.
    $evenodd = $i % 2 ? 'odd-mnb' : 'even-mnb';
    $evenodd = $i & 1 ? 'odd-mnb' : 'even-mnb';

    $type_link = 'admin/content/node-type/'. $parsed_type;
    $link = l($maps['name'], $type_link, array('query' => array('destination' => 'admin/settings/more-node-buttons'), 'fragment' => 'more-node-buttons-on-content-type', 'attributes' => array('title' => t('Edit this content type'))));

    // The node type row; Include an link to directly edit the mnb settings in the node type.
    $rows[] = array('data' => array('data' => array('data' => $link, 'colspan' => 5)), 'class' => $evenodd .' '. $evenodd .'-type');
    // The row contains the form elements.
    $rows[] = array(
      'data' => array(
        drupal_render($form['node_buttons'][$type]['more_node_buttons_cancel_'. $type]),
        drupal_render($form['node_buttons'][$type]['more_node_buttons_cancel_referer_redirect_'. $type]),
        drupal_render($form['node_buttons'][$type]['more_node_buttons_sac_'. $type]),
        drupal_render($form['node_buttons'][$type]['more_node_buttons_sacn_'. $type]),
        drupal_render($form['node_buttons'][$type]['more_node_buttons_tabcn_'. $type]),
      ),
      'class' => $evenodd .' '. $evenodd .'-elements',
    );

    unset($form['node_buttons'][$type]);
    ++$i;
  }

  $output .= theme('table', $header, $rows, array('class' => 'mnb-admin-table'));

  // Display additional informations.
  if ($extra_info != '') {
    $output .= $extra_info;
  }

  $output .= drupal_render($form);
  $output .= '<p style="text-align: right">'. t('Module development by <a href="@development-url">Quiptime Group</a>.', array('@development-url' => url('http://www.quiptime.com'))) .'</p>';

  return $output;
}

/**
 * Save settings from admin form.
 */
function more_node_buttons_admin_submit($form, &$form_state) {
  $mappings = $form['#mappings'];

  if ($form_state['clicked_button']['#id'] == 'edit-save') {
    // Save the Mnb button and tab settings.
    foreach ($mappings as $type => $maps) {
      if ($type == 'panel') {
        continue;
      }
      variable_set('more_node_buttons_cancel_'. $type, $form_state['values']['more_node_buttons_cancel_'. $type]);
      variable_set('more_node_buttons_cancel_referer_redirect_'. $type, $form_state['values']['more_node_buttons_cancel_referer_redirect_'. $type]);
      variable_set('more_node_buttons_sac_'. $type, $form_state['values']['more_node_buttons_sac_'. $type]);
      variable_set('more_node_buttons_sacn_'. $type, $form_state['values']['more_node_buttons_sacn_'. $type]);
      variable_set('more_node_buttons_tabcn_'. $type, $form_state['values']['more_node_buttons_tabcn_'. $type]);
    }
    // Save the Mnb value settings.
    // Don't make value strings translatable here!
    $more_node_buttons_values = array(
      'cancel' => $form_state['values']['more_node_buttons_value_cancel'] ? trim($form_state['values']['more_node_buttons_value_cancel']) : 'Cancel',
      'sac' => $form_state['values']['more_node_buttons_value_sac'] ? trim($form_state['values']['more_node_buttons_value_sac']) : 'Save and continue',
      'sacn' => $form_state['values']['more_node_buttons_value_sacn'] ? trim($form_state['values']['more_node_buttons_value_sacn']) : 'Save and create new',
      'tabcn' => $form_state['values']['more_node_buttons_value_tabcn'] ? trim($form_state['values']['more_node_buttons_value_tabcn']) : 'Create new',
    );
    variable_set('more_node_buttons_values', $more_node_buttons_values);

    drupal_set_message(t('Your changes have been saved.'), 'status');
  }
  elseif ($form_state['clicked_button']['#id'] == 'edit-reset') {
    $form_state['redirect'] = 'admin/settings/more-node-buttons/reset';
  }
}

/**
 * Menu callback.
 *
 * Define the confirm form output.
 *
 * @return
 *   The confirm form.
 */
function more_node_buttons_reset() {
  $question = t('Are you sure you want to reset all %module settings?', array('%module' => t('More node buttons')));
  
  return confirm_form(array(),
    $question,
    array('path' => 'admin/settings/more-node-buttons'), '<p>'. t('This action cannot be undone.') .'</p>',
    t('Reset'),
    t('Cancel')
  );
}

/**
 * Delete all system variables of the Mnb module to reset the module settings.
 */
function more_node_buttons_reset_submit($form, &$form_state) {
  db_query("DELETE FROM {variable} WHERE name LIKE 'more_node_buttons\_%'");

  // Important to clear this cache.
  cache_clear_all('variables', 'cache');

  drupal_set_message(t('The %module settings have been set back.', array('%module' => t('More node buttons'))), 'status');
  // Add an entry to the watchdog log.
  watchdog('More node buttons', 'The %module settings have been set back.', array('%module' => t('More node buttons')), WATCHDOG_NOTICE, l(t('view'), 'admin/settings/more-node-buttons'));
  
  $form_state['redirect'] = 'admin/settings/more-node-buttons';
}
