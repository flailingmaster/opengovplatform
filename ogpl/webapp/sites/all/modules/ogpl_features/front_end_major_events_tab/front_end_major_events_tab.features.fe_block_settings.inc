<?php

/**
 * Implementation of hook_default_fe_block_settings().
 */
function front_end_major_events_tab_default_fe_block_settings() {
  $export = array();

  // dms
  $theme = array();

  $export['dms'] = $theme;

  // ogpl_css3
  $theme = array();

  $export['ogpl_css3'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}
