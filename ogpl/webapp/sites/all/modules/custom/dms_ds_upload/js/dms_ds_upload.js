$(document).ready(function () {

  //detecting file upload status every 0.5 sec
  setInterval(function(){
    var $btn_remove = $('#edit-field-ds-file-0-filefield-remove');
    var $btn_populate = $('#edit-field-ds-file-0-filefield-populate');

    //is file uploaded and is populate button present?
    if ($btn_remove.length && !$btn_populate.length){
      //get file name
      var file_name = $('#edit-field-ds-file-0-upload-wrapper a').attr('href').split('/');
      if (file_name && file_name.length >= 1) {
        file_name = file_name[file_name.length - 1];
      }

      //get full url including filename
      var url_string = Drupal.settings.basePath + 'dataset/populate/' + file_name;

      //add populate button
      $btn_remove.parent().append('<input type=button onclick="window.location=\'' + url_string + '\'" id=edit-field-ds-file-0-filefield-populate value=Populate>')
    }   
  }, 500)
});