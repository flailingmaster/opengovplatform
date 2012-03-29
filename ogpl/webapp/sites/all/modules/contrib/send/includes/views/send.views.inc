<?php

/**
 * @file
 * Provide views data for send.module.
 */

/**
 * Implementation of hook_views_handlers().
 */
function send_views_handlers() {
  return array(
    'handlers' => array(
      'send_views_handler_field_profile' => array(
        'parent' => 'views_handler_field',
        'path' => drupal_get_path('module', 'send') . '/includes/views',
      ),
      'send_views_handler_field_count' => array(
        'parent' => 'views_handler_field',
        'path' => drupal_get_path('module', 'send') . '/includes/views',
      ),
      'send_views_handler_sort_count' => array(
        'parent' => 'views_handler_sort',
        'path' => drupal_get_path('module', 'send') . '/includes/views',
      ),
      'send_views_handler_sort_date' => array(
        'parent' => 'views_handler_sort_date',
        'path' => drupal_get_path('module', 'send') . '/includes/views',
      ),
      'send_views_handler_filter_in_operator_module' => array(
        'parent' => 'views_handler_filter_in_operator',
        'path' => drupal_get_path('module', 'send') . '/includes/views',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data().
 */
function send_views_data() {
  $data = array();

  $data['send']['table']['group'] = t('Send');
  $data['send']['table']['base'] = array(
    'field' => 'sid',
    'title' => t('Send'),
    'help'  => t('Data relating senders, recipients, and sent nodes'),
  );
  $data['send']['table']['join'] = array(
    // Join to the node table via the send_node table.
    'node' => array(
      'left_table' => 'send_node',
      'left_field' => 'sid',
      'field' => 'sid',
    ),

    // Join to the send_contact table via the send_contact table.
    'send_contact' => array(
      'left_field' => 'scid',
      'field' => 'scid',
    ),

    // Join to the users table via the send_contact table.
    'users' => array(
      'left_table' => 'send_contact',
      'left_field' => 'scid',
      'field' => 'scid',
    )
  );

  $data['send']['sid'] = array(
    'title' => t('Message'),
    'help' => t('The unique id of a send message'),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'subject'
    ),
  );
  /*
  $data['send']['scid'] = array(  // TODO - now joining scid => uid.
    'title' => t('Sender'),
    'help' => t('The contact who sent the message.'),
    'relationship' => array(
      'label' => t('sender'),
      'title' => t('Sender'),
      'help' => t('User information for the contact who sent the message.'),
      'base' => 'users',
      'base field' => 'uid',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
  */
  $data['send']['profile'] = array(
    'title' => t('Profile'),
    'help' => t('The module used to send the message.'),
    'field' => array(
      'handler' => 'views_handler_field', // TODO with label
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'send_views_handler_filter_in_operator_module',
      'options callback' => 'send_profile_names',
    ),
    'sort' => array(
      'help' => t('Sort by module used to send the message.'),
      'handler' => 'views_handler_sort',
    ),
    'argument' => array( // TODO with label.
      'help' => t('Filter by the module which sent the message'),
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['send']['timestamp'] = array(
    'title' => t('Timestamp'),
    'help'    => t('Date and time message was sent'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'help'    => t('Filter by date and time message was sent'),
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'help'    => t('Sort by date and time message was sent'),
      'handler' => 'send_views_handler_sort_date',
    ),
  );
  $data['send']['subject'] = array(
    'title' => t('Message subject'),
    'help'  => t('The subject of the sent message'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );
  $data['send']['message'] = array(
    'title' => t('Message text'),
    'help' => t('The message text.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => FALSE,
    ),
  );

  // The send_node table.
  $data['send_node']['table']['join'] = array(
    'send' => array(
      'field' => 'sid',
      'left_field' => 'sid',
      'type' => 'inner',
    ),
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
      'type' => 'inner',
    ),
  );

  // The send_contact table.
  $data['send_contact']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );

  $data['send_recipient']['table']['group'] = t('Send');
  $data['send_recipient']['table']['join'] = array(
    // Join to the send table.
    'send' => array(
      'left_field' => 'sid',
      'field' => 'sid',
      'type' => 'inner',
    ),

    // Join to the users table via the send_contact table.
    'users' => array(
      'left_table' => 'send_contact',
      'left_field' => 'scid',
      'field' => 'scid',
    )
  );

  $data['send_recipient']['scid'] = array(
    'title' => t('Recipient'),
    'help' => t('The contact who received the message.'),
    'relationship' => array(
      'label' => t('recipient'),
      'title' => t('Recipient'),
      'help' => t('User information for the contact who received the message.'),
      'relationship table' => 'users',
      'base' => 'users',
      'relationship field' => 'uid',
      'field' => 'scid',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  return $data;
}
