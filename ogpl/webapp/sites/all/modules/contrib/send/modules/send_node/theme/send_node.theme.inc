<?php // $Id$

/**
 * Implementation of hook_theme().
 */
function send_node_theme_theme() {
  $path = drupal_get_path('module', 'send_node') .'/theme';

  return array(
    'send_node_admin_types' => array(
      'arguments' => array('form' => array()),
      'file' => 'send_node.theme.inc',
      'path' => $path,
    ),
  );
}

/**
 * A theme callback for the types overview on the administration form.
 */
function theme_send_node_admin_types(&$form) {
  $hdrs = array(t('Type'), t('Settings'), t('Operations'));
  $rows = array();

  foreach (element_children($form) as $type) {
    $row = array();
    $row[] = drupal_render($form[$type]['send_enabled_'. $type]) .'<br />';
    $row[] = drupal_render($form[$type]['send_default_'. $type]) .
      drupal_render($form[$type]['send_pernode_'. $type]);
    $row[] = l(t('edit'), 'admin/content/node-type/'. $type, array('query' => drupal_get_destination()));

    $rows[] = $row;
  }
  return theme('table', $hdrs, $rows);
}
