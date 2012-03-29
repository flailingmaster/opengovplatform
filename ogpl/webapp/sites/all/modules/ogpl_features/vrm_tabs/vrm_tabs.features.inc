<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function vrm_tabs_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => 1);
  }
}
