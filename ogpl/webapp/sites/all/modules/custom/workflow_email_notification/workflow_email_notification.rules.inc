<?php
/**
 * @file rules integration for the workflow email notification module
 *
 * @addtogroup rules
 * @{
 
*/
/**
 * Implementation of hook_workflow_email_notification_action_info().
 */
function workflow_email_notification_rules_action_info() {
 return array(
  'workflow_email_notification_action_mail_to_users_of_agency_poc' => array(
      'label' => t('Send a mail to all POCs of the user agency'),
      'module' => 'Workflow Email Notification',
      'eval input' => array('subject', 'message', 'from'),
    ),
  'workflow_email_notification_action_mail_to_agency_poc' => array(
      'label' => t('Send a mail to one agency POC'),
      'module' => 'Workflow Email Notification',
      'eval input' => array('subject', 'message', 'from', 'recipient'),
    ),
  );
}

function workflow_email_notification_action_drupal_message($settings) {
  drupal_set_message($settings['message'], $settings['error'] ? 'error' : 'status');
}

/**
 * Implementation of hook_mail().
 *
 * Set's the message subject and body as configured in the $settings of the action.
 */ 
function workflow_email_notification_mail($key, &$message, $settings) {
  $message['subject'] .= str_replace(array("\r", "\n"), '', $settings['subject']);
  $message['body'][] = $settings['message'];
}

/**
 * Action Implementation: workflow_email_notification_action_mail
 * This action makes use of the workflow_email_notification_action_mail_to_user action implementation.
 */
function workflow_email_notification_action_mail($settings) {
  workflow_email_notification_action_mail_to_users_of_agency_poc(NULL, $settings);
  workflow_email_notification_action_mail_to_agency_poc(NULL, $settings);
}

/**
 * Action: Send mail to all users of a specific agency POC group(s).
 */
function workflow_email_notification_action_mail_to_users_of_agency_poc($settings) {
  $args = func_get_args();
  $node = $args[2]['variables']['node']->data->_data;
  $recipients = $settings['recipients'];
  $nid = $node->nid;
  $node_type = "profile";
  $agency_id = $node->field_ds_agency_name[0]['nid'];
  $from = ($settings['from']) ? str_replace(array("\r", "\n"), '', $settings['from']) : NULL;
  
  // Avoid sending emails to members of two or more target agency groups.
  $query = "SELECT ur.rid, u.uid, u.mail, node.nid, cta.field_agency_name_value FROM {users} as u LEFT JOIN {node} as node ON u.uid = node.uid AND node.type = '%s' LEFT JOIN {content_type_profile} as ctp ON node.nid = ctp.nid LEFT JOIN {content_type_agency} as cta ON ctp.field_prof_agency_nid = cta.nid LEFT JOIN {users_roles} as ur ON u.uid = ur.uid WHERE ctp.field_prof_agency_nid = %d AND  ur.rid = %d";
  $result = db_query($query, $node_type, $agency_id, $recipients[0]);
  // Now, actually send the mails.
  $message = array('result' => TRUE);
  while (($account = db_fetch_object($result)) && $message['result']) {
  $message = drupal_mail('workflow_email_notification', 'workflow_email_notification_action_mail', $account->mail, language_default(), $settings, $from);
  }
  if ($message['result']) {
  $roles = array_intersect_key(user_roles(TRUE), drupal_map_assoc($recipients));
  watchdog('workflow_email_notification', 'Successfully sent email to the role(s) %roles.', array('%roles' => implode(', ', $roles)));
  }
}

function workflow_email_notification_action_mail_to_agency_poc($settings) {
  $args = func_get_args();
  $node = $args[2]['variables']['node']->data->_data;
  $old_state = $args[2]['variables']['old_state']->data->_data;
  $new_state = $args[2]['variables']['new_state']->data->_data;
  
  $query = 'Select distinct u.mail, max(wnh.hid) from {users} as u, {workflow_node_history} as wnh WHERE wnh.nid = %d AND wnh.old_sid = %d AND wnh.sid = %d AND u.uid = wnh.uid';
  $result = db_query($query, $node->nid, $old_state, $new_state);
 
  while ($obj = db_fetch_object($result)) {
  $email = $obj->mail;
  }
  $to = $email;
  $from = ($settings['from']) ? str_replace(array("\r", "\n"), '', $settings['from']) : NULL;
  $message = drupal_mail('workflow_email_notification', 'workflow_email_notification_action_mail', $to, language_default(), $settings, $from);
  watchdog('workflow_email_notification', 'Successfully sent email to %recipient', array('%recipient' => $to));
 }
 
 function workflow_email_notification_action_watchdog($settings) {
  watchdog($settings['type'], $settings['message'], NULL, $settings['severity'], $settings['link']);
}