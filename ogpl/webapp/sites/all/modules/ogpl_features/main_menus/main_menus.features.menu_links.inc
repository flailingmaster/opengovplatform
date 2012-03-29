<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function main_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-menulinks:node/1
  $menu_links['menu-menulinks:node/1'] = array(
    'menu_name' => 'menu-menulinks',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Data',
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
    'weight' => '-50',
  );
  // Exported menu link: menu-menulinks:node/2
  $menu_links['menu-menulinks:node/2'] = array(
    'menu_name' => 'menu-menulinks',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'Apps Tools',
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
    'weight' => '-48',
  );
  // Exported menu link: menu-menulinks:node/3
  $menu_links['menu-menulinks:node/3'] = array(
    'menu_name' => 'menu-menulinks',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Community',
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
    'weight' => '-46',
  );
  // Exported menu link: menu-menulinks:node/4
  $menu_links['menu-menulinks:node/4'] = array(
    'menu_name' => 'menu-menulinks',
    'link_path' => 'node/4',
    'router_path' => 'node/%',
    'link_title' => 'Metrics',
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
    'weight' => '-44',
  );
  // Exported menu link: menu-menulinks:node/5
  $menu_links['menu-menulinks:node/5'] = array(
    'menu_name' => 'menu-menulinks',
    'link_path' => 'node/5',
    'router_path' => 'node/%',
    'link_title' => 'Open Data Sites',
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
    'weight' => '-42',
  );
  // Exported menu link: menu-menulinks:node/6
  $menu_links['menu-menulinks:node/6'] = array(
    'menu_name' => 'menu-menulinks',
    'link_path' => 'node/6',
    'router_path' => 'node/%',
    'link_title' => 'Gallery',
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
    'weight' => '-40',
  );
  // Exported menu link: menu-menulinks:node/7
  $menu_links['menu-menulinks:node/7'] = array(
    'menu_name' => 'menu-menulinks',
    'link_path' => 'node/7',
    'router_path' => 'node/%',
    'link_title' => 'What\'s New',
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
    'weight' => '-38',
  );
  // Exported menu link: menu-menulinks:node/8
  $menu_links['menu-menulinks:node/8'] = array(
    'menu_name' => 'menu-menulinks',
    'link_path' => 'node/8',
    'router_path' => 'node/%',
    'link_title' => 'Linked Data',
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
    'weight' => '-36',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Apps Tools');
  t('Community');
  t('Data');
  t('Gallery');
  t('Linked Data');
  t('Metrics');
  t('Open Data Sites');
  t('What\'s New');


  return $menu_links;
}
