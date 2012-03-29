// $Id: multistep.js,v 1.1.2.3 2009/07/22 18:45:32 vkareh Exp $

if (Drupal.jsEnabled) {
  $(document).ready(function () {
    $("input[name=multistep_expose]").ready(function() { multistep_toggle_settings(); });
    $("input[name=multistep_expose]").click(function() { multistep_toggle_settings(); });
  });
}

function multistep_toggle_settings() {
  if ($("#edit-multistep-expose-enabled").attr("checked") == true) {
    $("#multistep-settings").removeClass("collapsed");
  }
  else {
    $("#multistep-settings").addClass("collapsed");
  }
}
