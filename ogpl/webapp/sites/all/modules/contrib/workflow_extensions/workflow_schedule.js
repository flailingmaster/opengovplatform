
// Original version contributed by Brian Tully. See http://drupal.org/node/1162632
// This version handles multiple occurrences of the form on a page.

$(document).ready(function() {
  var i = 0;
  // Show/hide schedule fields based on which radio button is clicked.
  $("input:radio[class=form-radio]").each(function(index) {
    var radioButton = $(this);
 
    if (radioButton.attr("id").substring(0, 23) == "edit-workflow-scheduled") {
 
      j = Math.floor(i / 2);
      var wrappers = (j == 0)
        ? $("#edit-workflow-scheduled-date-wrapper,           #edit-workflow-scheduled-hour-wrapper")
        : $("#edit-workflow-scheduled-date-" + j + "-wrapper, #edit-workflow-scheduled-hour-" + j + "-wrapper");

      if (radioButton.is(':checked') && radioButton.val() < 1) {
        // "Immediately" is pressed upon page entry
        wrappers.hide();
      }
      radioButton.click(function() {
        if (radioButton.val() < 1) {
          // "Immediately" is clicked
          wrappers.hide();
        }
        else {
          // "Schedule for state change" is clicked
          wrappers.show();
        }
      });
      i++;
    }
  });

});
