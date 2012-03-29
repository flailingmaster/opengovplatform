<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function footermenus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footerlinks
  $menus['menu-footerlinks'] = array(
    'menu_name' => 'menu-footerlinks',
    'title' => 'Bottom Links',
    'description' => 'Bottom Links for the Front End Website',
  );
  // Exported menu: menu-footermenu
  $menus['menu-footermenu'] = array(
    'menu_name' => 'menu-footermenu',
    'title' => 'Inner Page Footer Menu',
    'description' => 'Footer Menu for Inner Page',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Bottom Links');
  t('Bottom Links for the Front End Website');
  t('Footer Menu for Inner Page');
  t('Inner Page Footer Menu');


  return $menus;
}
