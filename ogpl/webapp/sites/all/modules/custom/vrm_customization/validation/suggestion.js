$(document).ready(function(){
	var container1 = $('div.clientside.messages.error');
	$("#node-form").validate(
		{
			errorContainer: container1,
			errorLabelContainer: $("ul", container1),
			wrapper: 'li',
			meta: "validate",

			rules: {
				"field_sender_name[0][value]":"required",
				"field_email[0][email]":{email: true},
				"field_feedback_body[0][value]":"required",
			},
			messages: {
				"field_sender_name[0][value]": {
					required: "Your Name field is required."
				},
				"field_email[0][email]": {
					email: "Please enter a valid email id in Your E-mail Address field eg. sam@xyz.com"
				},
				"field_feedback_body[0][value]": {
					required: "Suggestion field is required."
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