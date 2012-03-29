<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function front_footer_menu_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-frontfooter:node/1
  $menu_links['menu-frontfooter:node/1'] = array(
    'menu_name' => 'menu-frontfooter',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-frontfooter:node/12
  $menu_links['menu-frontfooter:node/12'] = array(
    'menu_name' => 'menu-frontfooter',
    'link_path' => 'node/12',
    'router_path' => 'node/%',
    'link_title' => 'Contact Info',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-frontfooter:node/3
  $menu_links['menu-frontfooter:node/3'] = array(
    'menu_name' => 'menu-frontfooter',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'FAQ',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: menu-frontfooter:node/7
  $menu_links['menu-frontfooter:node/7'] = array(
    'menu_name' => 'menu-frontfooter',
    'link_path' => 'node/7',
    'router_path' => 'node/%',
    'link_title' => 'Link To Us',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Contact Info');
  t('FAQ');
  t('Link To Us');


  return $menu_links;
}
