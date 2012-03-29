<?php

/**
 * Implementation of hook_menu_default_menu_custom().
 */
function main_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-menulinks
  $menus['menu-menulinks'] = array(
    'menu_name' => 'menu-menulinks',
    'title' => 'Global Navigation',
    'description' => 'Global Navigation for the Front End Website',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Global Navigation');
  t('Global Navigation for the Front End Website');


  return $menus;
}
