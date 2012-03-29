/**
 * @file
 * Javascript api documentation for Clientside Validation.
 */
/**
 * It speaks for itself that Clientside Validation cannot provide javascript
 * validation codes for custom validation rules defined in php. So if you want
 * to support Clientside Validation you will have to code the javascript
 * equivalent of your custom php validation rule and make it available for
 * Clientside validation. Below is an example of how you would do this.
 */
//Define a Drupal behaviour with a custom name
Drupal.behaviors.myModuleBehavior = function (context) {
  //Add an eventlistener to the document reacting on the
  //'clientsideValidationAddCustomRules' event.
  $(document).bind('clientsideValidationAddCustomRules', function(event){
    //Add your custom method with the 'addMethod' function of jQuery.validator
    //http://docs.jquery.com/Plugins/Validation/Validator/addMethod#namemethodmessage
    jQuery.validator.addMethod("myCustomMethod", function(value, element, param) {
      //let an element match an exact value defined by the user
      return value == param;
    //Enter a default error message, numbers between {} will be replaced
    //with the matching value of that key in the param array, enter {0} if
    //param is a value and not an array.
    }, jQuery.format('Value must be equal to {0}'));
  });
}
