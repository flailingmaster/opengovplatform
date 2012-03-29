<?php

/**
 * @file
 * Contains administrative pages for creating, editing, and deleting previewable email templates (PETs).
 */

/**
 * PET administration page. Display a list of existing PETs.
 */
function pet_admin_page() {
  $pets = pet_get_pets();
  return theme('pet_admin_page', $pets);
}

/**
 * Theme the output for the main PET administration page.
 */
function theme_pet_admin_page($pets) {
  $output = '<p>' . t('This page lists all the <em>previewable email templates</em> that are currently defined on this system. You may <a href="@add-url">add new templates</a>.', array('@add-url' => url('admin/build/pets/add'))) . '</p>';
  
  $destination = drupal_get_destination();
  foreach ($pets as $pet) {
    $ops = theme('links', array(
      'pets_edit' =>  array('title' => t('edit'), 'href' => "admin/build/pets/edit/". $pet->name),
      'pets_delete' =>  array('title' => t('delete'), 'href' => "admin/build/pets/delete/". $pet->name),
    ));
    
    $rows[] = array(
      l($pet->name, 'pet/' . $pet->name),
      $pet->title,
      $pet->recipient_callback,
      $pet->object_types,
      $ops,
    );
  }
  
  if (empty($pets)) {
    $rows[] = array(
      array('data' => t('No templates are currently defined.'), 'colspan' => 4),
    );
  }

  $header = array(t('Name'), t('Title'), t('Recipient callback'), t('Custom tokens'), t('Operations'));
  $output .= theme('table', $header, $rows);

  return $output;
}

/**
 * Add/Edit PET page.
 */
function pet_add_form(&$form_state, $name = NULL) {
  if (!isset($name)) {
    drupal_set_title(t('Add new template'));
  }
  else {
    // Editing an existing template.
    $pet = pet_load($name);
    if (empty($pet)) {
      drupal_goto('admin/build/pets');
    }
    drupal_set_title(t('Edit %name template', array('%name' => $pet->name)));
  }

  $form['pid'] = array(
    '#type' => 'value',
    '#value' => $pet->pid,
  );
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => $pet->name,
    '#description' => t('The machine-name for this email template. It may be up to 32 characters long and my only contain lowercase letters, underscores, and numbers. It will be used in URLs and in all API calls.'),
    '#maxlength' => 32,
    '#required' => TRUE,
  );
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $pet->title,
    '#description' => t('A short, descriptive title for this email template. It will be used in administrative interfaces, and in page titles and menu items.'),
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => $pet->subject,
    '#description' => t('The subject line of the email template. May includes tokens of any token type specified below.'),
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['mail_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => $pet->body,
    '#description' => t('The body of the email template. May includes tokens of any token type specified below.'),
  );
  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#access' => user_access('administer previewable email templates'),
  );
  $form['advanced']['recipient_callback'] = array(
    '#type' => 'textfield',
    '#title' => t('Recipient callback'),
    '#default_value' => $pet->recipient_callback,
    '#description' => t('The name of a function which will be called to retrieve a list of recipients. This function will be called if the query parameter uid=0 is in the URL. This function should return an array of recipients in the form uid|email, as in 136|bob@example.com. If the recipient has no uid, leave it blank but leave the pipe in. Providing the uid allows token substitution for the user.'),
    '#maxlength' => 255,
  );
  $form['advanced']['object_types'] = array(
    '#type' => 'textarea',
    '#title' => t('Custom tokens'),
    '#default_value' => $pet->object_types,
    '#description' => t('List of custom token types this template can handle, one per line. Format is type-name|object-it-acts-on, e.g. my-token-type|user. For types that don\'t require an object, leave the object empty, as in HCI global|. All tokens of type user and node are automatically available to all templates.'),
  );
  $form['token_help'] = array(
    '#title' => t('Replacement patterns'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Make sure that the tokens you choose are available to your template when in use.'),
  );
  $form['token_help']['help'] = array(
    '#value' => theme('token_help', 'all'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * Validate the PET.  Could do better callback and token type validation
 */
function pet_add_form_validate($form, &$form_state) {
  pet_validate_name($form_state['values']['name'], $form_state);
}

/**
 * Validate the PET name.
 */
function pet_validate_name($name, $form_state) {
  // Ensure a safe machine name.
  if (!preg_match('/^[a-z_][a-z0-9_]*$/', $name)) {
    form_set_error('name', t('The template name may only contain lowercase letters, underscores, and numbers.'));
  }
  
  // Ensure the machine name is unique
  if (empty($form_state['values']['pid'])) {
    $pet = pet_load($name);
    if ($pet->name == $name) {
      form_set_error('name', t('Template names must be unique. This name is already in use.'));
    }
  }
}
/**
 * Update/create a PET.
 */
function pet_add_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $values['body'] = $values['mail_body'];
  unset($values['mail_body']);
  
  if (empty($values['pid'])) {
    drupal_write_record('pets', $values);
    drupal_set_message(t('Template %name has been added.', array('%name' => $values['name'])));
    watchdog('pet', 'Template %name has been added.', array('%name' => $values['name']), WATCHDOG_NOTICE);
  }
  else {    
    drupal_write_record('pets', $values, 'pid');
    drupal_set_message(t('Template %name has been updated.', array('%name' => $values['name'])));
    watchdog('pet', 'Template %name has been updated.', array('%name' => $values['name']), WATCHDOG_NOTICE);
  }
  
  $form_state['redirect'] = 'admin/build/pets';
}

/**
 * Delete PET.
 */
function pet_delete_confirm(&$form_state, $name) {
  $pet = pet_load($name);
  if (empty($pet)) {
    drupal_goto('admin/build/pets');
  }

  $form['name'] = array('#type' => 'value', '#value' => $pet->name);

  return confirm_form(
    $form,
    t('Are you sure you want to delete template %title?', 
    array('%title' => $pet->title)),
    'admin/build/pets',
    t('This action cannot be undone.'),
    t('Delete'), 
    t('Cancel')
  );
}

/**
 * Process template delete form submission.
 */
function pet_delete_confirm_submit($form, &$form_state) {
  $pet = pet_load($form_state['values']['name']);
  
  db_query("DELETE FROM {pets} WHERE pid = %d", $pet->pid);
  drupal_set_message(t('Template %title has been deleted.', array('%title' => $pet->title)));
  watchdog('mail', 'Template %title has been deleted.', array('%title' => $pet->title), WATCHDOG_NOTICE);

  $form_state['redirect'] = 'admin/build/pets';
}

/**
 * Multi-step PET form.
 */
function pet_user_form(&$form_state, $pet) {
  $step = empty($form_state['storage']['step']) ? 1 : $form_state['storage']['step'];
  $form_state['storage']['step'] = $step;
  $form_state['storage']['pet'] = $pet;
  $nid = $form_state['storage']['nid'] = $_REQUEST['nid'];
  $uid = $form_state['storage']['uid'] = $_REQUEST['uid'];

  switch ($step) {
    case 1:
      if (!isset($uid)) {
        $form['mail'] = array(
          '#type' => 'textfield',
          '#title' => t('Recipient\'s e-mail address'),
          '#maxlength' => 255,
          '#required' => TRUE,
        );
      }
      elseif ($uid > 0) {
        $user = user_load(array('uid' => $uid));
        $form['mail'] = array(
          '#type' => 'value',
          '#value' => $user->mail,
        );
        $form['recipients'] = array(
          '#value' => t('Recipient will be ') . $user->mail,
        );
      }
      else {
        $form['recipients'] = array(
          '#value' => t('Recipient list will be generated for preview.'),
        );
      }
      $form['subject'] = array(
        '#type' => 'textfield',
        '#title' => t('Subject'),
        '#maxlength' => 255,
        '#default_value' => $form_state['storage']['subject'] ? $form_state['storage']['subject'] : $pet->subject,
        '#required' => TRUE,
      );
      $form['mail_body'] = array(
        '#type' => 'textarea',
        '#title' => t('Body'),
        '#default_value' => $form_state['storage']['mail_body'] ? $form_state['storage']['mail_body'] : $pet->body,
        '#required' => TRUE,
        '#rows' => 15,
        '#description' => t('Review and edit template before previewing. This will not change the template for future emailings, just for this one. To change the template permanently, go to the <a href="@settings">template page</a>. You may use the tokens below.', array('@settings' => url('admin/build/pets/edit/' . $pet->name))),
      );
      $form['token_help'] = array(
        '#title' => t('Replacement patterns'),
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
        '#description' => t('Make sure that the tokens you choose are available to your template when previewed. This list has all tokens. If you use tokens outside the node and user groups, be sure to include them in Custom tokens above. Only tokens accepting node, user, and global objects are currently supported.'),
      );
      $form['token_help']['help'] = array(
        '#value' => theme('token_help', 'all'),
      );
      $form['preview'] = array(
        '#type' => 'submit',
        '#value' => t('Preview'),
      );
      break;

    case 2:
      $form['info'] = array(
        '#value' => t('A preview of the email is shown below. If you\'re satisfied, click Send. If not, click Back to edit the email.'),
      );
      $form['recipients'] = array(
        '#type' => 'textarea',
        '#title' => t('Recipients'),
        '#rows' => 4,
        //'#value' => implode("\n", $form_state['storage']['recipients']),
        '#value' => pet_recipients_formatted($form_state['storage']['recipients']),
        '#disabled' => TRUE,
      );
      $form['subject'] = array(
        '#type' => 'textfield',
        '#title' => t('Subject'),
        '#size' => 80,
        '#value' => $form_state['storage']['subject_preview'],
        '#disabled' => TRUE,
      );
      $form['mail_body'] = array(
        '#type' => 'textarea',
        '#title' => t('Body'),
        '#rows' => 15,
        '#value' => $form_state['storage']['body_preview'],
        '#disabled' => TRUE,
      );
      $form['body_label'] = array(
        '#prefix' => '<div class="pet_body_label">',
        '#suffix' => '</div>',
        '#value' => '<label>' . t('Body markup:') . '</label>',
      );
      $form['body_preview'] = array(
        '#prefix' => '<div class="pet_body_preview">',
        '#suffix' => '</div>',
        '#value' => $form_state['storage']['body_preview'],
      );
      $form['back'] = array(
        '#type' => 'submit',
        '#value' => t('Back'),
        '#submit' => array('pet_user_form_back'),
      );
      $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Send email(s)'),
      );
      break;

    case 3:
      drupal_set_message(t('Email(s) sent'));
      unset($form_state['storage']);
      break;
  }
  
  return $form;
}

/**
 * Validate PET form.
 */
function pet_user_form_validate($form, &$form_state) {
  $step = empty($form_state['storage']['step']) ? 1 : $form_state['storage']['step'];

  if ($step == 1) {
    if ($form_state['storage']['uid'] == '0') {
      $recipients = pet_recipients($form_state);
      if (!is_array($recipients)) {
        form_set_error('pet', t('Callback is not returning an array of recipients.'));
      }
      elseif (count($recipients) < 1) {
        form_set_error('pet', t('There are no recipients for this email.'));
      }
    }
    elseif (!valid_email_address($form_state['values']['mail'])) {
      form_set_error('mail', t('You must enter a valid e-mail address.'));
    }
  }
}

/**
 * Form submission.  Take action on step 2 (confirmation of the populated templates).
 */
function pet_user_form_submit($form, &$form_state) {  
  $step = empty($form_state['storage']['step']) ? 1 : $form_state['storage']['step'];
  $form_state['storage']['step'] = $step;
  
  switch ($step) {
    case 1:
      $form_state['storage']['mail'] = $form_state['values']['mail'];
      $form_state['storage']['recipients'] = pet_recipients($form_state);
      $form_state['storage']['subject'] = $form_state['values']['subject'];
      $form_state['storage']['mail_body'] = $form_state['values']['mail_body'];
      pet_make_preview($form_state);
      break;
      
    case 2:
      $name = $form_state['storage']['pet']->name;
      $recipients = $form_state['storage']['recipients'];
      $nid = $form_state['storage']['nid'];
      $subject = $form_state['storage']['subject'];
      $body = $form_state['storage']['mail_body'];
      pet_send_mail($name, $recipients, $nid, $subject, $body);
      break;
  }
  
  $form_state['storage']['step']++;
}

/**
 * Return user to starting point on template multi-form.
 */
function pet_user_form_back($form, &$form_state) {
  $form_state['storage']['step'] = 1;
}

/**
 * Generate a preview of the tokenized email for the first in the list.
 */
function pet_make_preview(&$form_state) {
  $recipients = $form_state['storage']['recipients'];
  list($uid, $mail) = explode('|', $recipients[0]);
  $params = array(
    'pet_uid' => $uid,
    'pet_nid' => $form_state['storage']['nid'],
  );
  $subs = pet_substitutions($form_state['storage']['pet'], $params);
  
  $form_state['storage']['subject_preview'] = token_replace_multiple($form_state['values']['subject'], $subs);
  $form_state['storage']['body_preview'] = token_replace_multiple($form_state['values']['mail_body'], $subs);
}

/**
 * Return an array of email recipients
 */
function pet_recipients($form_state) {
  $uid = $form_state['storage']['uid'];
    
  if ($uid == '0') {
    return pet_callback_recipients($form_state);
  }
  
  return array($uid . '|' . $form_state['storage']['mail']);
}

/**
 * Return an array of email recipients provided by a callback function
 */
function pet_callback_recipients($form_state) {
  $nid = $form_state['storage']['nid'];
  $pet = $form_state['storage']['pet'];
  $callback = $pet->recipient_callback;
  $node = empty($nid) ? NULL : node_load($nid); 
  
  if (!empty($callback)) {
    if (function_exists($callback)) {
      return $callback($node);
    }
  }
  
  return array();
}

function pet_recipients_formatted($recipients) {
  if (is_array($recipients)) {
    foreach ($recipients as $recipient) {
      list($uid, $mail) = explode('|', $recipient);
      $output .= $mail;
      $output .= $uid ? t(' (user @uid)', array('@uid' => $uid)) : t(' (no user id)');
      $output .= "\n";
    }
    return $output;
  }
}

/**
 * PET test recipient callback
 */
function pet_test_callback($node = NULL) {
  return array('3|fred@example.com', '7|sally@example.com', '|non.user@example.com');
}





