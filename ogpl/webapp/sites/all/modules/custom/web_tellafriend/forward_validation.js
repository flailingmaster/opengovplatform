$(document).ready(function(){
	var container1 = $('div.clientside.messages.error');
	$.validator.addMethod(   
	 "validMultipleEmails",  
	 function(value, element){
		var Regex = /^[()\[\]<>!#:;$%&'*+\/=?^`@"{|}\\~a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]+$/;
		var text = value;
		text = text.replace(new RegExp( "\\n", "g" ),",");
		if (text != '') {
			var result = text.split(",");
			for (var i = 0; i < result.length; i++) {
				trimmed = result[i].trim();
				if (trimmed != '') {
					if (!(Regex.test(trimmed)) ? true : false) {
						$.validator.messages.validMultipleEmails= "Send To field has one or more invalid email addresses like "+window.trimmed+". Please enter a valid email id eg: sam@xyz.com";
						return false;
					}
				}
			}
		}
		return true;
	},   
	 $.validator.messages.validMultipleEmails
	);
	$("#web-tellafriend-form").validate(
		{
			errorContainer: container1,
			errorLabelContainer: $("ul", container1),
			wrapper: 'li',
			meta: "validate",

			rules: {
				"name":"required",
				"email":{email: true,required: true},
				"recipients":{required: true,validMultipleEmails: true},				 
			},
			messages: {
				"name": {
					required: "Your Name field is required."
				},
				"email": {
					required: "Your E-mail Address field is required.",
					email: "Please enter a valid email id in Your E-mail Address field eg. sam@xyz.com"
				},
				"recipients": {
					required: "Send To field is required.",
				}
			},
			invalidHandler: function(form, validator) {
				if (validator.errorList.length > 0) {
					$('html, body').animate({scrollTop: 120}, 1000);
					$('.wysiwyg-toggle-wrapper a').each(function() {
						$(this).click();
						$(this).click();
					});
				}
			}
		}
	);
});