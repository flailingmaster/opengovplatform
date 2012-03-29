<?php /* $Id$ */

/**
 * An overview page for the Send API.
 *
 * Allow each handler to provide some overview text and links for display on 
 * the main Send API page.
 */
function send_admin_overview() {
  $output = '';
  foreach (send_profiles() as $name => $info) {
    if ($profile = send_profile_load($name)) {
      if (method_exists('overview', $profile) && $ret = $profile->overview()) {
        $output .= '<h3>'. $info['title'] .'</h3>' . $ret;
      }
    }
  }
  return $output;
}
