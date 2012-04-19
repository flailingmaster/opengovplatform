// $Id: safer_login.js,v 1.5 2010/08/19 19:25:39 richardp Exp $ 

Drupal.behaviors.saferLoginStartup = function() {

  var saferLoginTokenMD5 = "";
  // Because of caching, we actually need to get the token via
  // ajax!  We will pass it some random characters at the end of the URL
  // to keep drupal from caching the result.
  $.get(Drupal.settings.basePath + '?q=safer-login/ajax-get-token-md5/' + saferLoginRandomString(), function (data) {
    saferLoginTokenMD5 = data;
  });
  
  // Add an "on submit" handler to the login form(s):
  $("form#user-login-form, form#user-login").submit(function() {

    // We only do any of this if the visitor wants us to, as indicated
    // by checking the edit-safer-login-checkbox.  OR, if that element
    // doesn't exist (because the administrator disabled it).
    // So, let's just see if it exists at all, and if so, if it is
    // unchecked.

    if ($("#edit-safer-login-checkbox").length != 0 && !$('#edit-safer-login-checkbox').is(':checked')) {
      // Okay, the checkbox is on the page and it is NOT checked.  So just return!
      return;
    }
    
    // Get what the user has entered for their password.
    var passid = "edit-pass";
    var pass = $("#" + passid).val();
   
    // We might have a situation where the user has a login block
    // on the same page as the login form.  So, we need to check
    // both #edit-pass and #edit-pass-1
    if (pass == "" || pass == null) {
      passid = "edit-pass-1";
      pass = $("#" + passid).val();
    }
     
    // If the pass begins with our prefix, then this user is supplying a hash already,
    // possibly because they are trying to use a password manager.  So, let's
    // allow it through w/o modification.
    // NOTE:  This is only a security risk if the administrator has selected
    // "use minimal protection".  Under the default settings, it wouldn't matter
    // if the user supplies a hash, the token will be wrong and it would fail
    // authentication.
    if (pass.substring(0, 15) == "~~safer_login~~" && pass.length == 47) {
      return;
    }
    
    // Now, to encrypt this, we are going to first take it's MD5 hash.
    // We are assuming the jquery.md5.js file is located
    // in /modules/safer_login/jquery_md5/jquery.md5.js and the module
    // has loaded it first.
    var pass_md5 = $.md5(pass);
    
    // Now, we take this new md5 hash, and concat with the saferLoginTokenMD5 like so:
    var new_pass_md5 = $.md5(pass_md5 + "" + saferLoginTokenMD5);
    
    // Okay, so, it is new_pass_md5 which we will pass to Drupal.  So all we need
    // to do is set the password field's value to = new_pass_md5.    
    $("#" + passid).val("~~safer_login~~" + new_pass_md5);
    
    // And we're done!  We will let the form submit normally now.

  });
  
}


/**
 * This function is not actually used in the regular functioning of the module,
 * but is used by the module function safer_login_md5_test() to 
 * make sure that the javascript MD5 function gives the same results as the
 * PHP md5 function.  It is included here purely for educational reasons.
 **/
function saferLoginPerformMD5Test() {
  
  // Get the number of results to test.
  var limit = $("#encode_test_limit").text();
  
  for (var t = 0; t < limit; t++) {
    var to_encode = $("#to_encode_" + t).text();
    var to_encode_md5 = $("#to_encode_md5_" + t).text();
    var js_encode_md5 = $.md5(to_encode);
    //var js_encode_md5 = hex_md5(to_encode);
    $("#js_encode_md5_" + t).text(js_encode_md5);
    
    if (js_encode_md5 == to_encode_md5) {
      $("#js_encode_result_" + t).text("success");
    }
    else {
       $("#js_encode_result_" + t).html("<span style='color: red'>FAIL</span>");
    }
    
  }
}



/**
 * Returns a X-length string of random letters and numbers.
 * Used to construct a random URL which circumvents Drupal's caching system.
 **/
function saferLoginRandomString() {
	var chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXTZabcdefghiklmnopqrstuvwxyz";
	var length = 20;
	var randomstring = '';
	for (var i = 0; i < length; i++) {
		var rnum = Math.floor(Math.random() * chars.length);
		randomstring += chars.substring(rnum,rnum+1);
	}
	return randomstring;
}