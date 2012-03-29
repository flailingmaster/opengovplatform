<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function front_footer_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-frontfooter
  $menus['menu-frontfooter'] = array(
    'menu_name' => 'menu-frontfooter',
    'title' => 'Home Page Footer Menu',
    'description' => 'footer menu for the Home page',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Home Page Footer Menu');
  t('footer menu for the Home page');


  return $menus;
}
