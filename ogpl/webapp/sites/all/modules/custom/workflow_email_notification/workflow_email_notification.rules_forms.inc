<?php
/**
 * @file Rules configuration forms for the workflow email notification module
 *
 * @addtogroup rules
 * @{
 
*/
/**
 * Action "Send a mail to a user" configuration form
 */
function workflow_email_notification_mail_form($settings = array(), &$form) {
  $settings += array('from' => '', 'subject' => '', 'message' => '');
  $form['settings']['from'] = array(
    '#type' => 'textfield',
    '#title' => t('Sender'),
    '#default_value' => $settings['from'],
    '#description' => t("The mail's from address. Leave it empty to use the site-wide configured address."),
  );
  $form['settings']['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#default_value' => $settings['subject'],
    '#description' => t("The mail's subject."),
  );
  $form['settings']['message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message'),
    '#default_value' => $settings['message'],
    '#description' => t("The mail's message body."),
  );
}

/**
 * Action "Send a mail to users of a role" configuration form
 */
function workflow_email_notification_action_mail_to_users_of_agency_poc_form($settings = array(), &$form) {
// Select only non-anonymous user roles because anonymous users won't have emails.
  $roles = array_map('filter_xss_admin', user_roles(TRUE));
  
  $form['settings']['recipients'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Recipient roles'),
    '#prefix' => t('WARNING: This may cause problems if there are too many users of these roles on your site, as your server may not be able to handle all the mail requests all at once.'),
    '#required' => TRUE,
    '#default_value' => isset($settings['recipients']) ? $settings['recipients'] : array(),
    '#options' => $roles,
    '#description' => t('Select the roles whose users should receive this email.'),
  );
  workflow_email_notification_mail_form($settings, $form);
}

function workflow_email_notification_action_mail_to_agency_poc_form($settings = array(), &$form) {
  workflow_email_notification_mail_form($settings, $form);
}

function workflow_email_notification_action_mail_to_users_of_agency_poc_submit(&$settings, $form, $form_state) {
  $settings['recipients'] = array_filter(array_keys(array_filter($settings['recipients'])));
}
