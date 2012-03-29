$(document).ready(function () {

// Search box default message
    message = "Search This Community...";
    obj = $('#edit-search-theme-form-1');
    obj.val(message);
    $('#search #edit-submit').click(function(){
        if(obj.val()==message || obj.val()==''){
            obj.val(message);
            alert('Please Enter a Search Term');

            return false;
        }
    });
    $('#search #edit-submit-1').click(function(){
        if(obj.val()==message || obj.val()==''){
            obj.val(message);
            alert('Please Enter a Search Term');

            return false;
        }
    });
    $('#edit-search-theme-form-1').focus(function(){
        if($(this).val()== message){
            $(this).val("");
        };
    });
    $('#edit-search-theme-form-1').blur(function(){
        if($(this).val()==''){
            $(this).val(message);
        }
    });

});
