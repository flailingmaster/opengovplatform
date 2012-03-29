
Drupal.behaviors.download_count = function(){
$('#edit-download-count-export-date-range-from-wrapper').hide();
$('#edit-download-count-export-date-range-to-wrapper').hide();

$('input#edit-download-count-export-range-0').bind('click', function(){
  $('#edit-download-count-export-date-range-from-wrapper').hide();
  $('#edit-download-count-export-date-range-to-wrapper').hide();
  }
)

$('input#edit-download-count-export-range-1').bind('click', function(){
  $('#edit-download-count-export-date-range-from-wrapper').show();
  $('#edit-download-count-export-date-range-to-wrapper').show();
  }
)

};
