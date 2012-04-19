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
      $ops,
    );
  }
  
  if (empty($pets)) {
    $rows[] = array(
      array('data' => t('No templates are currently defined.'), 'colspan' => 4),
    );
  }

  $header = array(
    t('Name'), 
    t('Title'), 
    t('Operations')
  );
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
    '#description' => t('The subject line of the email template. May include tokens of any token type specified below.'),
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['mail_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => $pet->body,
    '#description' => t('The body of the email template. May include tokens of any token type specified below.'),
  );
  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional options'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#access' => user_access('administer previewable email templates'),
  );
  $form['advanced']['from_override'] = array(
    '#type' => 'textfield',
    '#title' => t('From override'),
    '#default_value' => $pet->from_override,
    '#description' => t('By default, the From: address is the site address, which is %site_mail and which is configurable on the core <a href="@site_url">site information page</a>. You may specify a different From: address here, which will override the system default for this PET.', array('%site_mail' => variable_get('site_mail', ini_get('sendmail_from')), '@site_url' => url('admin/settings/site-information'))),
    '#maxlength' => 255,
    '#required' => FALSE,
  );
  $form['advanced']['cc_default'] = array(
    '#type' => 'textarea',
    '#title' => t('CC default'),
    '#rows' => 3,
    '#default_value' => $pet->cc_default,
    '#description' => t('Emails to be copied by default for each mail sent to recipient. Enter emails separated by lines or commas.'),
    '#required' => FALSE,
  );
  $form['advanced']['bcc_default'] = array(
    '#type' => 'textarea',
    '#title' => t('BCC default'),
    '#rows' => 3,
    '#default_value' => $pet->bcc_default,
    '#description' => t('Emails to be blind copied by default for each mail sent to recipient. Enter emails separated by lines or commas.'),
    '#required' => FALSE,
  );
  $form['advanced']['recipient_callback'] = array(
    '#type' => 'textfield',
    '#title' => t('Recipient callback'),
    '#default_value' => $pet->recipient_callback,
    '#description' => t('The name of a function which will be called to retrieve a list of recipients. This function will be called if the query parameter uid=0 is in the URL. It will be called with one argument, the loaded node (if the PET takes one) or NULL if not. This function should return an array of recipients in the form uid|email, as in 136|bob@example.com. If the recipient has no uid, leave it blank but leave the pipe in. Providing the uid allows token substitution for the user.'),
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
  
  if (!empty($form_state['values']['from_override'])) {
    if (!valid_email_address($form_state['values']['from_override'])) {
      form_set_error('from_override', t('From address is not a valid email address.'));
    }
  }
  
  $errors = pet_validate_emails($form_state['values']['cc_default']);
  if (!empty($errors)) {
    form_set_error('cc_default', '<ul><li>' . implode('</li><li>', $errors) . '</li></ul>');
  }
  
  $errors = pet_validate_emails($form_state['values']['bcc_default']);
  if (!empty($errors)) {
    form_set_error('bcc_default', '<ul><li>' . implode('</li><li>', $errors) . '</li></ul>');
  }
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
  
  // Get any query args
  $nid = $form_state['storage']['nid'] = pet_is_natural($_REQUEST['nid']) ? $_REQUEST['nid'] : NULL;
  $uid = $form_state['storage']['uid'] = pet_is_natural($_REQUEST['uid']) ? $_REQUEST['uid'] : NULL;
  $recipient_callback = $form_state['storage']['recipient_callback'] = (
    pet_isset_or($_REQUEST['recipient_callback']) === 'true' || 
    pet_isset_or($_REQUEST['uid']) === '0' // backward compatibility
  );
  
  switch ($step) {
    case 1:
      if ($recipient_callback) {
        $default_mail = t('Recipient list will be generated for preview.');
      }
      elseif ($form_state['storage']['recipients_raw']) {
        $default_mail = $form_state['storage']['recipients_raw'];
      }
      else {
        $default_mail = '';
        if ($uid) {
          if ($account = user_load(array('uid' => $uid))) {
            $default_mail = $account->mail;
          }
          else {
            drupal_set_message(t('Cannot load a user with uid @uid.', array('@uid' => $uid)), 'error');
          }
        }
      }
      $form['recipients'] = array(
        '#title' => t('To'),
        '#type' => 'textarea',
        '#required' => TRUE,
        '#rows' => 3,
        '#default_value' => $default_mail,
        '#description' => t('Enter the recipient(s) separated by lines or commas. A separate email will be sent to each, with token substitution if the email corresponds to a site user.'),
        '#disabled' => $recipient_callback,
      );
      $form['copies'] = array(
        '#title' => t('Copies'),
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => empty($pet->cc_default) && empty($pet->bcc_default),
      );
      $form['copies']['cc'] = array(
        '#title' => t('Cc'),
        '#type' => 'textarea',
        '#rows' => 3,
        '#default_value' => $form_state['storage']['cc'] ? $form_state['storage']['cc'] : $pet->cc_default,
        '#description' => t('Enter any copied emails separated by lines or commas.'),
      );
      $form['copies']['bcc'] = array(
        '#title' => t('Bcc'),
        '#type' => 'textarea',
        '#rows' => 3,
        '#default_value' => $form_state['storage']['bcc'] ? $form_state['storage']['bcc'] : $pet->bcc_default,
        '#description' => t('Enter any blind copied emails separated by lines or commas.'),
      );
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
        '#title' => t('To'),
        '#rows' => 4,
        '#value' => pet_recipients_formatted($form_state['storage']['recipients']),
        '#disabled' => TRUE,
      );
      if ($form_state['values']['cc']) {
        $form['cc'] = array(
          '#type' => 'textarea',
          '#title' => t('CC'),
          '#rows' => 4,
          '#value' => $form_state['values']['cc'],
          '#disabled' => TRUE,
        );
      }
      if ($form_state['values']['bcc']) {
        $form['bcc'] = array(
          '#type' => 'textarea',
          '#title' => t('BCC'),
          '#rows' => 4,
          '#value' => $form_state['values']['bcc'],
          '#disabled' => TRUE,
        );
      }
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
    $errors = pet_validate_recipients($form_state, $recipients);
    if (!empty($errors)) {
      form_set_error('recipients', '<ul><li>' . implode('</li><li>', $errors) . '</li></ul>');
    }
    else {
      // Save recipients to avoid redundant processing on form submit
      $form_state['storage']['recipients'] = $recipients;
    }
    
    $errors = pet_validate_emails($form_state['values']['cc']);
    if (!empty($errors)) {
      form_set_error('cc', '<ul><li>' . implode('</li><li>', $errors) . '</li></ul>');
    }

    $errors = pet_validate_emails($form_state['values']['bcc']);
    if (!empty($errors)) {
      form_set_error('bcc', '<ul><li>' . implode('</li><li>', $errors) . '</li></ul>');
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
      $form_state['storage']['recipients_raw'] = $form_state['values']['recipients'];
      $form_state['storage']['subject'] = $form_state['values']['subject'];
      $form_state['storage']['mail_body'] = $form_state['values']['mail_body'];
      $form_state['storage']['cc'] = $form_state['values']['cc'];
      $form_state['storage']['bcc'] = $form_state['values']['bcc'];
      pet_make_preview($form_state);
      break;
      
    case 2:
      $name = $form_state['storage']['pet']->name;
      $recipients = $form_state['storage']['recipients'];
      $nid = $form_state['storage']['nid'];
      $subject = $form_state['storage']['subject'];
      $body = $form_state['storage']['mail_body'];
      $from = NULL;  // use PET or default setting
      $cc = $form_state['storage']['cc'];
      $bcc = $form_state['storage']['bcc'];
      pet_send_mail($name, $recipients, $nid, $subject, $body, $from, $cc, $bcc);
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
  $params = array(
    'pet_uid' => $form_state['storage']['recipients'][0]['uid'],
    'pet_nid' => $form_state['storage']['nid'],
  );
  $subs = pet_substitutions($form_state['storage']['pet'], $params);
  
  $form_state['storage']['subject_preview'] = token_replace_multiple($form_state['values']['subject'], $subs);
  $form_state['storage']['body_preview'] = token_replace_multiple($form_state['values']['mail_body'], $subs);
}

/**
 * Validate existence of a non-empty recipient list free of email errors.
 */
function pet_validate_recipients($form_state, &$recipients) {
  $errors = array();
  $recipients = array();
  
  if ($form_state['storage']['recipient_callback']) {
    // Get recipients from callback
    $mails = pet_callback_recipients($form_state);
    if (!is_array($mails)) {
      $errors[] = t('There is no recipient callback defined for this template or it is not returning an array.');
      return $errors;
    }
  }
  else {
    // Get recipients from form field
    $mails = pet_parse_mails($form_state['values']['recipients']);
  }
  
  // Validate and build recipient array with uid on the fly
  foreach ($mails as $mail) {
    if (!valid_email_address($mail)) {
      $errors[] = t('Invalid email address found: %mail.', array('%mail' => $mail));
    }
    else {
      $recipients[] = array('mail' => $mail, 'uid' => pet_lookup_uid($mail));
    }
  }
  
  // Check for no recipients
  if (empty($errors) && count($recipients) < 1) {
    $errors[] = t('There are no recipients for this email.');
  }
  
  return $errors;
}

/**
 * Return an array of email recipients provided by a callback function.
 */
function pet_callback_recipients($form_state) {
  $nid = $form_state['storage']['nid'];
  $pet = $form_state['storage']['pet'];
  $callback = $pet->recipient_callback;
  $node = empty($nid) ? NULL : node_load($nid); 
  
  if (!empty($callback)) {
    if (function_exists($callback)) {
      $recipients = $callback($node);
      
      // Remove uid for backward compatibility
      if (isset($recipients) && is_array($recipients)) {
        $new_recipients = array();
        foreach ($recipients as $recipient) {
          $recipient = preg_replace('/^[0-9]*\|/', '', $recipient);
          $new_recipients[] = $recipient;
        }
        return $new_recipients;
      }
    }
  }
  
  return NULL;
}

/**
 * Return formatted list of PET recipients for preview display.
 */
function pet_recipients_formatted($recipients) {
  if (is_array($recipients)) {
    foreach ($recipients as $recipient) {
      $output .= $recipient['mail'];
      $output .= $recipient['uid'] ? t(' (user @uid)', array('@uid' => $recipient['uid'])) : t(' (no user id)');
      $output .= "\n";
    }
    return $output;
  }
}

/**
 * Return TRUE if a $val is a natural number (integer 1, 2, 3, ...).  Base can
 * be changed to zero if desired.
 */
function pet_is_natural($val, $base = 1) {
  if (!isset($val)) {
    return FALSE;
  }
  $return = ((string)$val === (string)(int)$val);
  if ($return && intval($val) < $base) {
    $return = FALSE;
  }
  return $return;
}

/**
 * Check if a variable is set and return it if so, otherwise the alternative.
 */
function pet_isset_or(&$val, $alternate = NULL) {
  return isset($val) ? $val : $alternate;
}

/**
 * PET test recipient callback
 */
function pet_test_callback($node = NULL) {
  return array('fred@example.com', 'sally@example.com');
}

/**
 * Parse a list of emails and return errors if any.
 */
function pet_validate_emails($mail_text) {
  $errors = array();
  
  foreach (pet_parse_mails($mail_text) as $mail) {
    if (!valid_email_address($mail)) {
      $errors[] = t('Invalid email address found: %mail.', array('%mail' => $mail));
    }
  }
  
  return $errors;
}

