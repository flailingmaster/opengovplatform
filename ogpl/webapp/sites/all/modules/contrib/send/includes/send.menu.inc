<?php // $Id$

function send_menu_menu() {
  $path = drupal_get_path('module', 'send') .'/includes';
  $items = array(
    'send/%send_profile/%' => array(
      'title'            => 'Send',
      'page callback'    => 'drupal_get_form',
      'page arguments'   => array('send_form', 1, 2),
      'access callback'  => 'send_access',
      'access arguments' => array(1, 2),
      'type'             => MENU_CALLBACK,
      'file'             => 'send.form.inc',
      'file path'        => $path,
    ),
    'admin/settings/send' => array(
      'title'            => 'Send API',
      'description'      => 'Default settings for "Send to Friend" and other modules that send content via e-mail',
      'page callback'    => 'send_admin_overview',
      'access arguments' => array('administer send'),
      'type'         => MENU_NORMAL_ITEM,
      'file'             => 'send.admin.inc',
      'file path'        => $path,
    ),
    'admin/settings/send/template' => array(
      'title'            => 'Message templates',
      'page callback'    => 'send_template_admin_overview',
      'access arguments' => array('administer send'),
      'type'             => MENU_LOCAL_TASK,
      'file'             => 'send.template.inc',
      'file path'        => $path,
    ),
    'admin/settings/send/template/list' => array(
      'title'            => 'List',
      'page callback'    => 'send_template_admin_overview',
      'access arguments' => array('administer send'),
      'type'             => MENU_DEFAULT_LOCAL_TASK,
      'file'             => 'send.template.inc',
      'file path'        => $path,
      'weight'           => -10,
    ),
    'admin/settings/send/template/add' => array(
      'title'            => 'Add',
      'page callback'    => 'drupal_get_form',
      'page arguments'   => array('send_template_form'),
      'access arguments' => array('administer send'),
      'type'             => MENU_LOCAL_TASK,
      'file'             => 'send.template.inc',
      'file path'        => $path,
    ),
    'admin/settings/send/template/%/edit' => array(
      'page callback'    => 'drupal_get_form',
      'page arguments'   => array('send_template_form', 4),
      'access arguments' => array('administer send'),
      'type'             => MENU_LOCAL_TASK,
      'file'             => 'send.template.inc',
      'file path'        => $path,
    ),
    'admin/settings/send/oveview' => array(
      'title'            => 'Overview',
      'page callback'    => 'send_admin_overview',
      'access arguments' => array('administer send'),
      'type'             => MENU_DEFAULT_LOCAL_TASK,
      'weight'           => -10,
      'file'             => 'send.admin.inc',
      'file path'        => $path,
    ),
    'send/js/send_form' => array(
      'page callback'    => 'send_form_js',
      'access arguments' => array('administer send'), // TODO not correct.
      'file'             => 'send.form.inc',
      'file path'        => $path,
    ),
    'node/%node/send' => array(  //TODO this isn't done yet.
    ),
  );
  return $items;
}
