<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function catalog_home_tabs_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_views_api().
 */
function catalog_home_tabs_views_api() {
  return array(
    'api' => '2',
  );
}
