<?php

/**
 * Implementation of hook_menu_default_menu_links().
 */
function footermenus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footerlinks:node/1
  $menu_links['menu-footerlinks:node/1'] = array(
    'menu_name' => 'menu-footerlinks',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Data Policy',
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
  // Exported menu link: menu-footerlinks:node/3
  $menu_links['menu-footerlinks:node/3'] = array(
    'menu_name' => 'menu-footerlinks',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Accessibility',
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
    'weight' => '-49',
  );
  // Exported menu link: menu-footerlinks:node/4
  $menu_links['menu-footerlinks:node/4'] = array(
    'menu_name' => 'menu-footerlinks',
    'link_path' => 'node/4',
    'router_path' => 'node/%',
    'link_title' => 'Privacy Policy',
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
  // Exported menu link: menu-footerlinks:node/7
  $menu_links['menu-footerlinks:node/7'] = array(
    'menu_name' => 'menu-footerlinks',
    'link_path' => 'node/7',
    'router_path' => 'node/%',
    'link_title' => 'Terms And Conditions',
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
  // Exported menu link: menu-footermenu:node/2
  $menu_links['menu-footermenu:node/2'] = array(
    'menu_name' => 'menu-footermenu',
    'link_path' => 'node/2',
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
    'weight' => '-49',
  );
  // Exported menu link: menu-footermenu:node/3
  $menu_links['menu-footermenu:node/3'] = array(
    'menu_name' => 'menu-footermenu',
    'link_path' => 'node/3',
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
    'weight' => '-48',
  );
  // Exported menu link: menu-footermenu:node/7
  $menu_links['menu-footermenu:node/7'] = array(
    'menu_name' => 'menu-footermenu',
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
    'weight' => '-46',
  );
  // Exported menu link: menu-footermenu:node/8
  $menu_links['menu-footermenu:node/8'] = array(
    'menu_name' => 'menu-footermenu',
    'link_path' => 'node/8',
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
    'weight' => '-50',
  );
  // Exported menu link: menu-footermenu:sitemap
  $menu_links['menu-footermenu:sitemap'] = array(
    'menu_name' => 'menu-footermenu',
    'link_path' => 'sitemap',
    'router_path' => 'sitemap',
    'link_title' => 'Site Map',
    'options' => array(
      'attributes' => array(
        'title' => 'Sitemap',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Accessibility');
  t('Contact Info');
  t('Data Policy');
  t('FAQ');
  t('Link To Us');
  t('Privacy Policy');
  t('Site Map');
  t('Terms And Conditions');


  return $menu_links;
}
