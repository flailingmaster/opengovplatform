/* $Id */

/**
 * Conditionally show/hide settings based on the enabled status of different
 * Send to friend options.
 */
var oldDefaultLegend;
Drupal.behaviors.sendNodeAdminSettings = function () {
  // Hide per-content type or per-node settings based on status click.
  $('#edit-send-enabled').change(function () {
    if (this.checked) {
      $('.send-settings').parent().show();
      $('.send-defaults').show();
    }
    else {
      $('.send-settings').parent().hide();
      $('.send-defaults').hide();
    }
  });
  // Trigger this action so that the form starts out lookin' right.
  $('#edit-send-enabled').change();

  // Disable profile editing fields if using defaults
  $('#edit-send-default').change(function () {
    if (oldDefaultLegend == undefined) {
      oldDefaultLegend = $('.send-defaults legend').text();
    }

    if (this.checked) {
      $('.send-defaults *').attr("disabled", true);

      $('.send-defaults legend').text(oldDefaultLegend);
    }
    else {
      $('.send-defaults *').removeAttr("disabled");
      $('.send-defaults legend').text(Drupal.t('Custom settings'));
    }
  });
  // Trigger this action so that the form starts out lookin' right.
  $('#edit-send-default').change();

  // Hide content type settings admin/settings/send/node if not enabled.
  $("input[id*='edit-send-enabled-']").change(function () {
    typeName = this.id.substring(18);
    if (this.checked) {
      $('#edit-send-pernode-' + typeName).parent().show();
      $('#edit-send-default-' + typeName).parent().show();
    }
    else {
      $('#edit-send-pernode-' + typeName).parent().hide();
      $('#edit-send-default-' + typeName).parent().hide();
    }
  });

  // Trigger this action.
  $("input[id*='edit-send-enabled-']").change();
};

// Vertical Tabs love
if (Drupal.jsEnabled) {
  Drupal.verticalTabs = Drupal.verticalTabs || {};

  Drupal.verticalTabs.send_node = function() {
    var sendEnabled = $('#edit-send-enabled').attr('checked');
    var sendDefault = $('#edit-send-default').attr('checked');

    if (sendEnabled) {
      vtStatus = Drupal.t('Enabled');

      if (sendDefault) {
       vtStatus += ', ' + Drupal.t('Using default values');
      }
      return vtStatus;
    }

    return '';
  }
}
