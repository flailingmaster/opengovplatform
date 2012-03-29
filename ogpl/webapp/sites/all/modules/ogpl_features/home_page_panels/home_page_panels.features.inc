<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function home_page_panels_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => 1);
  }
}
