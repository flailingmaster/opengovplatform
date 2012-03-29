<?php // $Id$

/**
 * The site-wide administration form for "Send to friend" functionality.
 */
function send_node_admin_settings(&$form_state) {
  drupal_add_js(drupal_get_path('module', 'send_node') .'/js/send_node.admin.js');
  $form = array();
  $form['#send_node_vars'] = array();

  // Add vertical_tabs support, if that module is installed.
  $form['#pre_render'][] = 'vertical_tabs_form_pre_render';

  // Invoke the settings form for the default send-to-friend configuration.
  $profile = send_profile_load('send_node');
  $profile->settings_form($form, $form_state);
  $form[$profile->name()]['#type'] = 'fieldset';
  $form[$profile->name()]['#title'] = t('Default settings');
  $form[$profile->name()]['#description'] = t('These settings will apply to all "send to friend" forms unless you override them in the Content types section.');

  // Show an overview of current node types.
  $form['content'] = array(
    '#type' => 'fieldset',
    '#title' => t('Content types'),
    '#description' => t('This is a summary of the enabled status and basic settings for each content type.  There are additional settings and customizations on each content type\'s settings page.'),
    'types' => array('#theme' => 'send_node_admin_types'),
  );

  foreach (node_get_types('names') as $type => $name) {
    $form['content']['types'][$type] = array();

    $var = $form['#send_node_vars'][] = 'send_enabled_'. $type;
    $form['content']['types'][$type][$var] = array(
      '#type' => 'checkbox',
      '#title' => $name,
      '#default_value' => variable_get($var, FALSE),
    );

    $var = $form['#send_node_vars'][] = 'send_default_'. $type;
    $form['content']['types'][$type][$var] = array(
      '#type' => 'checkbox',
      '#title' => t('Use the global default settings'),
      '#default_value' => variable_get($var, TRUE),
    );

    $var = $form['#send_node_vars'][] = 'send_pernode_'. $type;
    $form['content']['types'][$type][$var] = array(
      '#type' => 'checkbox',
      '#title' => t('Permit customizations on every post'),
      '#default_value' => variable_get($var, FALSE),
    );
  }

  // Set message and recipient limits.
  $form['limits'] = array(
    '#type' => 'fieldset',
    '#title' => t('Message limits'),
    '#description' => t('It is important to limit the number of messages delivered by your site.  If these limits are set too high, your site could be used to relay spam messages.'),
  );

  $var = $form['#send_node_vars'][] = 'send_node_limit';
  $form['limits'][$var] = array(
    '#type'         => 'textfield',
    '#title'         => t('Message limit'),
    '#description'   => t('The maximum number of times per hour a user can use a "Send to friend" form.  0 for unlimited.'),
    '#default_value' => variable_get($var, 5),
    '#size'          => 3,
    '#maxlength'     => 3,
  );

  $var = $form['#send_node_vars'][] = 'send_node_recipient_limit';
  $form['limits'][$var] = array(
    '#type'         => 'textfield',
    '#title'         => t('Recipient limit'),
    '#description'   => t('The maximum number of recipients per message. 0 for unlimited.'),
    '#default_value' => variable_get($var, 10),
    '#size'          => 3,
    '#maxlength'     => 3,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset to defaults'),
  );

  return $form;
}

function send_node_admin_settings_submit($form, &$form_state) {
  $vars = $form['#send_node_vars'];

  if ($form_state['clicked_button']['#value'] == t('Save configuration')) {
    // Set limits and other variables.
    foreach ($vars as $name) {
      variable_set($name, $form_state['values'][$name]);
    }

    // Load the default profile and save it with these values.
    $profile = send_profile_load('send_node');
    $profile->save($form_state['values']['send_node']);
    drupal_set_message(t('The configuration options have been saved.'));
  }
  elseif ($form_state['clicked_button']['#value'] == t('Reset to defaults')) {
    // Delete all of our variables.
    foreach ($vars as $name) variable_del($name);

    // Reset the send_node profile to whatever came from hook_send_profile_info.
    $profile = send_profile_load('send_node');
    $profile->reset();
    drupal_set_message(t('The configuration options have been reset to their default values.'));
  }
}

/**
 * "Send to friend" settings for a node type 
 */
function send_node_admin_node_type_form_alter(&$form, &$form_state) {
  drupal_add_js(drupal_get_path('module', 'send_node') .'/js/send_node.admin.js');

  // Add a submit hook to this form so that we can intercept profile changes.
  $form['#submit'][] = 'send_node_admin_submit';

  $suffix = '_' . $form['#node_type']->type;

  $form['send_node'] = array(
    '#type' =>  'fieldset',
    '#title' =>  t('Send to friend'),
    '#collapsible' =>  TRUE,
    '#collapsed' =>  !variable_get('send_enabled'. $suffix, FALSE),
  );

  // Enabled for this node type.
  $form['send_node']['send_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable "Send to friend" functionality on this content type'),
    '#default_value' => variable_get('send_enabled'. $suffix, FALSE),
  );

  // Per-node customizations.
  $form['send_node']['send_pernode'] = array(
    '#type' => 'checkbox',
    '#title' => t('Permit customizations on every post'),
    '#default_value' => variable_get('send_pernode'. $suffix, FALSE),
    '#attributes' => array('class' => 'send-settings'),
  );

  // Use global defaults?
  $form['send_node']['send_default'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use the global default settings'),
    '#default_value' => variable_get('send_default'. $suffix, TRUE),
    '#attributes' => array('class' => 'send-settings'),
  );

  // Load either the global or per-nodetype send profile.
  if (!$profile = send_profile_load('send_node_type'. $suffix)) {
    $profile = send_profile_load('send_node');
  }

  // Show the settings for the global/per-nodetype form.
  $profile->setName('send_node');
  $profile->settings_form($form['send_node'], $form_state);

  // Add a fieldset so that we can apply fieldsets.
  $form['send_node']['send_node']['#type'] = 'fieldset';
  $form['send_node']['send_node']['#title'] = t('Default settings');
  $form['send_node']['send_node']['#collapsible'] = FALSE;
  $form['send_node']['send_node']['#attributes']['class'] = 'send-defaults';
}

/**
 * "Send to friend" settings for a particular node, assuming that the "pernode"
 * setting is enabled for this node's type.
 */
function send_node_admin_node_form_alter(&$form, &$form_state) {
  drupal_add_js(drupal_get_path('module', 'send_node') .'/js/send_node.admin.js');

  // Add a submit hook to this form so that we can intercept profile changes.
  $form['#submit'][] = 'send_node_admin_submit';
  $nid = $form['#node']->nid;

  $suffix = '_'. $form['#node']->type;

  // Send to friend not enabled for this node type, nothing to see here!
  if (!variable_get('send_enabled'. $suffix, FALSE)) return;

  // Not allowing per-node configurations for this node type.
  if (!variable_get('send_pernode'. $suffix, FALSE)) return;

  // Load the per-node profile or the default profile, whichever exists.
  $profile = send_node_profile_load($form['#node']);

  $form['send_node'] = array(
    '#type' =>  'fieldset',
    '#title' =>  t('Send to friend'),
    '#collapsible' =>  TRUE,
    '#collapsed' =>  !$profile->enabled,
  );

  // Add the "enabled" and "override default" settings to the node itself.
  $form['send_node']['send_enabled'] = array(
    '#type' =>  'checkbox',
    '#title' =>  t('Enable "Send to friend" functionality for this node'),
    '#default_value' => $profile->enabled,
  );

  $types = node_get_types('names');
  $type = ($default == 'send_node') ? t('Send to friend') : t('@type content type', array('@type' => $types[$form['#node']->type]));

  $form['send_node']['send_default'] = array(
    '#type' =>  'checkbox',
    '#title' =>  t('Use the default settings for !type', array('!type' => $type)),
    '#default_value' => $profile->default,
    '#attributes' => array('class' => 'send-settings'),
  );

  // Set the profile's name to have a consistent namespace for its values.
  $profile->setName('send_node');
  $profile->settings_form($form['send_node'], $form_state);

  $form['send_node']['send_node']['#type'] = 'fieldset';
  $form['send_node']['send_node']['#title'] = t('@type settings', array('@type' => $type));
  $form['send_node']['send_node']['#collapsible'] = FALSE;
  $form['send_node']['send_node']['#attributes']['class'] = 'send-defaults';
}

/**
 * A submit handler that saves a send_profile based on node type settings.
 */
function send_node_admin_submit(&$form, &$form_state) {
  // If we're using the default handler, there's no reason to save a new one.
  if (!$form_state['values']['send_default']) {
    $default = $name = 'send_node';

    // We're on the node type configuration form.
    if (isset($form['#node_type'])) {
      $name .= '_type_'. $form['#node_type']->type;
    }

    // Load the node type/node profile or extend the defaults.
    if (!$profile = send_profile_load($name)) {
      $profile = send_profile_copy($default, $name);
    }

    $profile->save($form_state['values']['send_node']);
  }

  // Remove the send_node key from $form_state so that it's not saved as a
  // variable by system_settings_form_submit()
  unset($form_state['values']['send_node']);
}

/**
 * A nodeapi:insert or nodeapi:update callback.
 */
function send_node_admin_nodeapi_save(&$node, $op, $teaser = NULL, $a4 = NULL) {
  $suffix = '_'. $node->type;

  // Not enabled at all, or not allowing per-node overrides.
  if (!variable_get('send_enabled'. $suffix, FALSE)) return;
  if (!variable_get('send_pernode'. $suffix, FALSE)) return;

  if (!is_null($node->send_enabled)) {
    $send_node = (object) array(
      'nid' => $node->nid,
      'enabled' => $node->send_enabled,
      'use_default' => $node->send_default,
    );

    // If we've got a custom profile, create or update it.
    if (!$send_node->use_default) {
      $profile = send_node_profile_load($node, $send_node);
      $profile->save($node->send_node);
    }

    // Store the per-node settings for enabled/default.
    if ($op == 'update') {
      db_query("DELETE FROM {send_profile_node} WHERE nid = %d", $node->nid);
    }
    drupal_write_record('send_profile_node', $send_node);
  }
}
