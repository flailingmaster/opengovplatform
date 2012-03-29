Drupal.behaviors.clientsideValidation = function (context) {
  if (!Drupal.myClientsideValidation) {
    Drupal.myClientsideValidation = new Drupal.clientsideValidation();
  }
  else {
    var update = false;
    jQuery.each(Drupal.settings.clientsideValidation.forms, function (f) {
      if ($(context).find('#' + f).length || $(context).attr('id') == f) {
        update = true;
      }
    });
    //update settings
    if (update) {
      Drupal.myClientsideValidation.data = Drupal.settings.clientsideValidation;
      Drupal.myClientsideValidation.forms = Drupal.myClientsideValidation.data['forms'];
      Drupal.myClientsideValidation.bindForms();
    }
  }
}

Drupal.clientsideValidation = function() {
  var self = this;
  this.prefix = 'clientsidevalidation-';
  this.data = Drupal.settings.clientsideValidation;
  this.forms = this.data['forms'];
  this.validators = {};
  this.groups = {};

  //disable class and attribute rules
  $.validator.classRules = function() {
    return {};
  };
  $.validator.attributeRules = function() {
    return {};
  };

  this.addExtraRules();
  this.bindForms();
};

Drupal.clientsideValidation.prototype.findVerticalTab = function(element) {
  element = $(element);

  // Check for the vertical tabs fieldset and the verticalTab data
  var fieldset = element.parents('fieldset.vertical-tabs-pane');
  if ((fieldset.size() > 0) && (typeof(fieldset.data('verticalTab')) != 'undefined')) {
    var tab = $(fieldset.data('verticalTab').item[0]).find('a');
    if (tab.size()) {
      return tab;
    }
  }

  // Return null by default
  return null;
};

Drupal.clientsideValidation.prototype.bindForms = function(){
  var self = this;
  jQuery.each (self.forms, function(f) {
    var errorel = self.prefix + f + '-errors';
    self.groups[f] = {};
    // Remove any existing validation stuff
    if (self.validators[f]) {
      // Doesn't work :: $('#' + f).rules('remove');
      var form = $('#' + f).get(0);
      if (typeof(form) != 'undefined') {
        jQuery.removeData(form, 'validator');
      }
    }

    if('checkboxrules' in self.forms[f]){
      groupkey = "";
      jQuery.each (self.forms[f]['checkboxrules'], function(r) {
        groupkey = r + '_group';
        self.groups[f][groupkey] = "";
        jQuery.each(this, function(){
          i = 0;
          $(this[2] + ' input[type=checkbox]').each(function(){
            if(i > 0){
              self.groups[f][groupkey] += ' ';
            }
            self.groups[f][groupkey] += $(this).attr('name');
            i++;
          });
        });
      });
    }

    if('daterangerules' in self.forms[f]){
      groupkey = "";
      jQuery.each (self.forms[f]['daterangerules'], function(r) {
        groupkey = r + '_group';
        self.groups[f][groupkey] = "";
        jQuery.each(this, function(){
          i = 0;
          $('#' + f + ' #' + r + ' :input').not('input[type=image]').each(function(){
            if(i > 0){
              self.groups[f][groupkey] += ' ';
            }
            self.groups[f][groupkey] += $(this).attr('name');
            i++;
          });
        });
      });
    }

    if('dateminrules' in self.forms[f]){
      groupkey = "";
      jQuery.each (self.forms[f]['dateminrules'], function(r) {
        groupkey = r + '_group';
        self.groups[f][groupkey] = "";
        jQuery.each(this, function(){
          i = 0;
          $('#' + f + ' #' + r + ' :input').not('input[type=image]').each(function(){
            if(i > 0){
              self.groups[f][groupkey] += ' ';
            }
            self.groups[f][groupkey] += $(this).attr('name');
            i++;
          });
        });
      });
    }

    if('datemaxrules' in self.forms[f]){
      groupkey = "";
      jQuery.each (self.forms[f]['datemaxrules'], function(r) {
        groupkey = r + '_group';
        self.groups[f][groupkey] = "";
        jQuery.each(this, function(){
          i = 0;
          $('#' + f + ' #' + r + ' :input').not('input[type=image]').each(function(){
            if(i > 0){
              self.groups[f][groupkey] += ' ';
            }
            self.groups[f][groupkey] += $(this).attr('name');
            i++;
          });
        });
      });
    }

    if ('daterequiredrules' in self.forms[f]) {
      groupkey = "";
      jQuery.each (self.forms[f]['daterequiredrules'], function(r) {
        groupkey = r + '_group';
        self.groups[f][groupkey] = "";
        jQuery.each(this, function(){
          i = 0;
          $('#' + f + ' #' + self.forms[f]['daterequiredrules'][r]['required'][2] + ' :input').not('input[type=image]').each(function(){
            if(i > 0){
              self.groups[f][groupkey] += ' ';
            }
            self.groups[f][groupkey] += $(this).attr('name');
            i++;
          });
        });
      });
    }
    self.groups;

    // Add basic settings
    // todo: find cleaner fix
    // ugly fix for nodes in colorbox
    if(typeof $('#' + f).validate == 'function') {
      var validate_options = {
        errorClass: 'error',
        groups: self.groups[f],
        unhighlight: function (element, errorClass, validClass) {
          // Default behavior
          $(element).removeClass(errorClass).addClass(validClass);

          // Sort the classes out for the tabs - we only want to remove the
          // highlight if there are no inputs with errors...
          var fieldset = $(element).parents('fieldset.vertical-tabs-pane');
          if (fieldset.size() && fieldset.find('.' + errorClass).size() == 0) {
            var tab = self.findVerticalTab(element);
            if (tab) {
              tab.removeClass(errorClass).addClass(validClass);
            }
          }
        },
        highlight: function (element, errorClass, validClass) {
          // Default behavior
          $(element).addClass(errorClass).removeClass(validClass);

          // Sort the classes out for the tabs
          var tab = self.findVerticalTab(element);
          if (tab) {
            tab.addClass(errorClass).removeClass(validClass);
          }
        },
        invalidHandler: function(form, validator) {
          if (validator.errorList.length > 0) {
            // Check if any of the errors are in the selected tab
            var errors_in_selected = false;
            for (var i = 0; i < validator.errorList.length; i++) {
              var tab = self.findVerticalTab(validator.errorList[i].element);
              if (tab && tab.parent().hasClass('selected')) {
                errors_in_selected = true;
                break;
              }
            }

            // Only focus the first tab with errors if the selected tab doesn't have
            // errors itself. We shouldn't hide a tab that contains errors!
            if (!errors_in_selected) {
              var tab = self.findVerticalTab(validator.errorList[0].element);
              if (tab) {
                tab.click();
              }
            }
            if (self.data.general.scrollTo) {
              if ($("#" + errorel).length) {
                $("#" + errorel).show();
                var x = $("#" + errorel).offset().top - $("#" + errorel).height() - 100; // provides buffer in viewport
              }
              else {
                var x = $(validator.errorList[0].element).offset().top - $(validator.errorList[0].element).height() - 100;
              }
              $('html, body').animate({scrollTop: x}, self.data.general.scrollSpeed);
              $('.wysiwyg-toggle-wrapper a').each(function() {
                $(this).click();
                $(this).click();
              });
            }
          }
        }
      };

      //CLIENTSIDE_VALIDATION_JQUERY_SELECTOR: 0
      //CLIENTSIDE_VALIDATION_TOP_OF_FORM: 1
      //CLIENTSIDE_VALIDATION_BEFORE_LABEL: 2
      //CLIENTSIDE_VALIDATION_AFTER_LABEL: 3
      //CLIENTSIDE_VALIDATION_BEFORE_INPUT: 4
      //CLIENTSIDE_VALIDATION_AFTER_INPUT: 5
      //CLIENTSIDE_VALIDATION_TOP_OF_FIRST_FORM: 6
      //CLIENTSIDE_VALIDATION_CUSTOM_ERROR_FUNCTION: 7
      switch (parseInt(self.forms[f].errorPlacement)) {
        case 0:
          if ($(self.forms[f].errorJquerySelector).length) {
            if (!$(self.forms[f].errorJquerySelector + ' #' + errorel).length) {
              $('<div id="' + errorel + '" class="messages error clientside-error"><ul></ul></div>').prependTo(self.forms[f].errorJquerySelector).hide();
            }
          }
          else if (!$('#' + errorel).length) {
            $('<div id="' + errorel + '" class="messages error clientside-error"><ul></ul></div>').insertBefore('#' + f).hide();
          }
          validate_options.errorContainer = '#' + errorel;
          validate_options.errorLabelContainer = '#' + errorel + ' ul';
          validate_options.wrapper = 'li';
          break;
        case 1:
          if (!$('#' + errorel).length) {
            $('<div id="' + errorel + '" class="messages error clientside-error"><ul></ul></div>').insertBefore('#' + f).hide();
          }
          validate_options.errorContainer = '#' + errorel;
          validate_options.errorLabelContainer = '#' + errorel + ' ul';
          validate_options.wrapper = 'li';
          break;
        case 2:
          validate_options.errorPlacement = function(error, element) {
            if (element.is(":radio")) {
              error.insertBefore(element.parents('.form-radios').prev('label'));
            }
            else if (element.is(":checkbox")) {
              error.insertBefore(element.parents('.form-checkboxes').prev('label'));
            }
            else {
              error.insertBefore('label[for="'+ element.attr('id') +'"]');
            }
          }
          break;
        case 3:
          validate_options.errorPlacement = function(error, element) {
            if (element.is(":radio")) {
              error.insertAfter(element.parents('.form-radios').prev('label'));
            }
            else if (element.is(":checkbox")) {
              error.insertAfter(element.parents('.form-checkboxes').prev('label'));
            }
            else {
              error.insertAfter('label[for="'+ element.attr('id') +'"]');
            }
          }
          break;
        case 4:
          validate_options.errorPlacement = function(error, element) {
            error.insertBefore(element);
          }
          break;
        case 5:
          validate_options.errorPlacement = function(error, element) {
            if (element.is(":radio")) {
              error.insertAfter(element.parents('.form-radios'));
            }
            else if (element.is(":checkbox")) {
              error.insertAfter(element.parents('.form-checkboxes'));
            }
            else {
              error.insertAfter(element);
            }
          }
          break;
        case 6:
          if ($('div.messages.error').length) {
            if ($('div.messages.error').attr('id').length) {
              errorel = $('div.messages.error').attr('id');
            }
            else {
              $('div.messages.error').attr('id', errorel);
            }
          }
          else if (!$('#' + errorel).length) {
            $('<div id="' + errorel + '" class="messages error clientside-error"><ul></ul></div>').insertBefore('#' + f).hide();
          }
          validate_options.errorContainer = '#' + errorel;
          validate_options.errorLabelContainer = '#' + errorel + ' ul';
          validate_options.wrapper = 'li';
          break;
        case 7:
          validate_options.errorPlacement = function (error, element) {
            window[self.forms[f].customErrorFunction](error, element);
          }
          break;
      }


      if (!self.forms[f].includeHidden) {
        validate_options.ignore = ':input:hidden';
      }
      else {
        validate_options.ignore = '';
      }
      if (self.data.general.validateTabs) {
        if($('.vertical-tabs-pane input').length) {
          validate_options.ignore += ' :not(.vertical-tabs-pane:input)';
        }
      }
      //Since we can only give boolean false to onsubmit, onfocusout and onkeyup, we need
      //a lot of if's (boolean true can not be passed to these properties).
      if (!Boolean(parseInt(self.data.general.validateOnSubmit))) {
        validate_options.onsubmit = false;
      }
      if (!Boolean(parseInt(self.data.general.validateOnBlur))) {
        validate_options.onfocusout = false;
      }
      if (!Boolean(parseInt(self.data.general.validateOnKeyUp))) {
        validate_options.onkeyup = false;
      }
      self.validators[f] = $('#' + f).validate(validate_options);

      //disable class and attribute rules
      jQuery.validator.disableAutoAddClassRules = true;
      jQuery.validator.disableAutoAddAttributeRules = true;

      // Bind all rules
      self.bindRules(f);

    }
  });
}

Drupal.clientsideValidation.prototype.bindRules = function(formid){
  var self = this;
  var hideErrordiv = function(){
    //wait just one milisecond until the error div is updated
    window.setTimeout(function(){
      var visibles = 0;
      $("div.messages.error ul li").each(function(){
        if($(this).is(':visible')){
          visibles++;
        }
        else {
          $(this).remove();
        }
      });
      if(visibles < 1){
        $("div.messages.error").hide();
      }
    }, 1);
  };
  if('checkboxrules' in self.forms[formid]){
    jQuery.each (self.forms[formid]['checkboxrules'], function(r) {
      $("#" + formid + " " + this['checkboxgroupminmax'][2] + ' :input[type="checkbox"]').addClass('require-one');
    });
    jQuery.each (self.forms[formid]['checkboxrules'], function(r) {
      // Check if element exist in DOM before adding the rule
      if ($("#" + formid + " " + this['checkboxgroupminmax'][2] + " .require-one").length) {
        $("#" + formid + " " + this['checkboxgroupminmax'][2] +  " .require-one").each(function(){
          $(this).rules("add", self.forms[formid]['checkboxrules'][r]);
          $(this).change(hideErrordiv);
        });
      }
    });
  }

  if('daterangerules' in self.forms[formid]){
    jQuery.each (self.forms[formid]['daterangerules'], function(r) {
      $('#' + formid + ' #' + r + ' :input').not('input[type=image]').each(function(){
        $(this).rules("add", self.forms[formid]['daterangerules'][r]);
        $(this).blur(hideErrordiv);
      });
    });
  }

  if('dateminrules' in self.forms[formid]){
    jQuery.each (self.forms[formid]['dateminrules'], function(r) {
      $('#' + formid + ' #' + r + ' :input').not('input[type=image]').each(function(){
        $(this).rules("add", self.forms[formid]['dateminrules'][r]);
        $(this).blur(hideErrordiv);
      });
    });
  }

  if('datemaxrules' in self.forms[formid]){
    jQuery.each (self.forms[formid]['datemaxrules'], function(r) {
      $('#' + formid + ' #' + r + ' :input').not('input[type=image]').each(function(){
        $(this).rules("add", self.forms[formid]['datemaxrules'][r]);
        $(this).blur(hideErrordiv);
      });
    });
  }

  if ('daterequiredrules' in self.forms[formid]) {
    jQuery.each (self.forms[formid]['daterequiredrules'], function(r) {
      $('#' + formid + ' #' + self.forms[formid]['daterequiredrules'][r]['required'][2] + ' :input').not('input[type=image]').each(function(){
        $(this).rules("add", self.forms[formid]['daterequiredrules'][r]);
        $(this).blur(hideErrordiv);
      });
    });
  }

  if('rules' in self.forms[formid]){
    jQuery.each (self.forms[formid]['rules'], function(r) {
      // Check if element exist in DOM before adding the rule
      if ($("#" + formid + " :input[name='" + r + "']").length) {
        $("#" + formid + " :input[name='" + r + "']").rules("add", self.forms[formid]['rules'][r]);
        $("#" + formid + " :input[name='" + r + "']").change(function(){
          //wait just one millisecond until the error div is updated
          window.setTimeout(function(){
            var visibles = 0;
            $("div.messages.error ul li").each(function(){
              if($(this).is(':visible')){
                visibles++;
              }
              else {
                $(this).remove();
              }
            });
            if(visibles < 1){
              $("div.messages.error").hide();
            }
          }, 1);
        });
      }
    });
  }
}

Drupal.clientsideValidation.prototype.addExtraRules = function(){

  jQuery.validator.addMethod("numberDE", function(value, element) {
    return this.optional(element) || /^-?(?:\d+|\d{1,3}(?:\.\d{3})+)(?:,\d+)?$/.test(value);
  });

  // Min a and maximum b checkboxes from a group
  jQuery.validator.addMethod("checkboxgroupminmax", function(value, element, param) {
    var validOrNot = $(param[2] + ' input:checked').length >= param[0] && $(param[2] + ' input:checked').length <= param[1];

    /* This gives problems */

    /*if(!$(element).data('being_validated')) {
      var fields = $(param[2] + ' input');
      fields.data('being_validated', true).valid();
      fields.data('being_validated', false);
    }*/


    return validOrNot;

  }, jQuery.format('Minimum {0}, maximum {1}'));

  // Allow integers, same as digits but including a leading '-'
  jQuery.validator.addMethod("digits_negative", function(value, element, param) {
    return this.optional(element) || /^-?\d+$/.test(value);
  }, jQuery.format('Please enter only digits.'));

  // One of the values
  jQuery.validator.addMethod("oneOf", function(value, element, param) {
    for (var p in param) {
      if (param[p] == value) {
        return true;
        break;
      }
    }
    return false;
  }, jQuery.format(''));

  jQuery.validator.addMethod("specificVals", function(value, element, param){
    for (var i in value){
      if(param.indexOf(value[i]) == -1) {
        return false;
      }
    }
    return true;
  });

  jQuery.validator.addMethod("regexMatchPCRE", function(value, element, param) {
    var result = false;
    jQuery.ajax({
      'url': Drupal.settings.basePath + 'clientside_validation/ajax',
      'type': "POST",
      'data': {
        'value': value,
        'param': JSON.stringify(param)
      },
      'dataType': 'json',
      'async': false,
      'success': function(res){
        result = res;
      }
    });
    if (result['result'] === false) {
      if (result['message'].length) {
        jQuery.extend(jQuery.validator.messages, {
          "regexMatchPCRE": result['message']
        });
      }
    }
    return result['result'];
  }, jQuery.format('The value does not match the expected format.'));

  // Unique values
  jQuery.validator.addMethod("notEqualTo", function(value, element, param) {
    var target = $(param).unbind(".validate-notEqualTo").bind("blur.validate-notEqualTo", function() {
      $(element).valid();
    });
    return value != target.val();
  }, jQuery.format('Please don\'t enter the same value again.'));

  jQuery.validator.addMethod("regexMatch", function(value, element, param) {
    if (this.optional(element) && value == '') {
      return this.optional(element);
    }
    else {
      var regexp = new RegExp(param);
      if(regexp.test(value)){
        return true;
      }
      return false;
    }

  }, jQuery.format('The value does not match the expected format.'));

  jQuery.validator.addMethod("daterange", function(value, element, param) {
    //Assume [month], [day], and [year] ??
    var dayelem, monthelem, yearelem, name;
    if ($(element).attr('name').indexOf('[day]') > 0) {
      dayelem = $(element);
      name = dayelem.attr('name').replace('[day]', '');
      monthelem = $("[name='" + name + "[month]']");
      yearelem = $("[name='" + name + "[year]']");
    }
    else if ($(element).attr('name').indexOf('[month]') > 0) {
      monthelem = $(element);
      name = monthelem.attr('name').replace('[month]', '');
      dayelem = $("[name='" + name + "[day]']");
      yearelem = $("[name='" + name + "[year]']");
    }
    else if ($(element).attr('name').indexOf('[year]') > 0) {
      yearelem = $(element);
      name = yearelem.attr('name').replace('[year]', '');
      dayelem = $("[name='" + name + "[day]']");
      monthelem = $("[name='" + name + "[month]']");

    }

    if (parseInt(yearelem.val(), 10) < parseInt(param[0][0], 10)) {
      return false;
    }
    else if (parseInt(yearelem.val(), 10) == parseInt(param[0][0], 10)){
      if (parseInt(monthelem.val(), 10) < parseInt(param[0][1])){
        return false;
      }
      else if (parseInt(monthelem.val(), 10) == parseInt(param[0][1], 10)){
        if(parseInt(dayelem.val(), 10) < parseInt(param[0][2], 10)) {
          return false;
        }
      }
    }

    if (parseInt(yearelem.val(), 10) > parseInt(param[1][0], 10)) {
      return false;
    }
    else if (parseInt(yearelem.val(), 10) == parseInt(param[1][0], 10)){
      if (parseInt(monthelem.val(), 10) > parseInt(param[1][1])){
        return false;
      }
      else if (parseInt(monthelem.val(), 10) == parseInt(param[1][1], 10)){
        if(parseInt(dayelem.val(), 10) > parseInt(param[1][2], 10)) {
          return false;
        }
      }
    }
    yearelem.removeClass('error');
    monthelem.removeClass('error');
    dayelem.removeClass('error');
    return true;
  });

  jQuery.validator.addMethod("datemin", function(value, element, param) {
    //Assume [month], [day], and [year] ??
    var dayelem, monthelem, yearelem, name;
    if ($(element).attr('name').indexOf('[day]') > 0) {
      dayelem = $(element);
      name = dayelem.attr('name').replace('[day]', '');
      monthelem = $("[name='" + name + "[month]']");
      yearelem = $("[name='" + name + "[year]']");
    }
    else if ($(element).attr('name').indexOf('[month]') > 0) {
      monthelem = $(element);
      name = monthelem.attr('name').replace('[month]', '');
      dayelem = $("[name='" + name + "[day]']");
      yearelem = $("[name='" + name + "[year]']");
    }
    else if ($(element).attr('name').indexOf('[year]') > 0) {
      yearelem = $(element);
      name = yearelem.attr('name').replace('[year]', '');
      dayelem = $("[name='" + name + "[day]']");
      monthelem = $("[name='" + name + "[month]']");

    }

    if (parseInt(yearelem.val(), 10) < parseInt(param[0], 10)) {
      return false;
    }
    else if (parseInt(yearelem.val(), 10) == parseInt(param[0], 10)){
      if (parseInt(monthelem.val(), 10) < parseInt(param[1])){
        return false;
      }
      else if (parseInt(monthelem.val(), 10) == parseInt(param[1], 10)){
        if(parseInt(dayelem.val(), 10) < parseInt(param[2], 10)) {
          return false;
        }
      }
    }
    yearelem.removeClass('error');
    monthelem.removeClass('error');
    dayelem.removeClass('error');
    return true;
  });

  jQuery.validator.addMethod("datemax", function(value, element, param) {
    //Assume [month], [day], and [year] ??
    var dayelem, monthelem, yearelem, name;
    if ($(element).attr('name').indexOf('[day]') > 0) {
      dayelem = $(element);
      name = dayelem.attr('name').replace('[day]', '');
      monthelem = $("[name='" + name + "[month]']");
      yearelem = $("[name='" + name + "[year]']");
    }
    else if ($(element).attr('name').indexOf('[month]') > 0) {
      monthelem = $(element);
      name = monthelem.attr('name').replace('[month]', '');
      dayelem = $("[name='" + name + "[day]']");
      yearelem = $("[name='" + name + "[year]']");
    }
    else if ($(element).attr('name').indexOf('[year]') > 0) {
      yearelem = $(element);
      name = yearelem.attr('name').replace('[year]', '');
      dayelem = $("[name='" + name + "[day]']");
      monthelem = $("[name='" + name + "[month]']");

    }

    if (parseInt(yearelem.val(), 10) > parseInt(param[0], 10)) {
      return false;
    }
    else if (parseInt(yearelem.val(), 10) == parseInt(param[0], 10)){
      if (parseInt(monthelem.val(), 10) > parseInt(param[1])){
        return false;
      }
      else if (parseInt(monthelem.val(), 10) == parseInt(param[1], 10)){
        if(parseInt(dayelem.val(), 10) > parseInt(param[2], 10)) {
          return false;
        }
      }
    }
    yearelem.removeClass('error');
    monthelem.removeClass('error');
    dayelem.removeClass('error');
    return true;
  });

  // EAN code
  jQuery.validator.addMethod("validEAN", function(value, element, param) {
    if (this.optional(element) && value == '') {
      return this.optional(element);
    }
    else {
      if (value.length > 13) {
        return false;
      }
      else if (value.length != 13) {
        value = '0000000000000'.substr(0, 13 - value.length).concat(value);
      }
      if (value == '0000000000000') {
        return false;
      }
      if (parseInt(value) == NaN || parseInt(value) == 0) {
        return false;
      }
      var runningTotal = 0;
      for (var c = 0; c < 12; c++) {
        if (c % 2 == 0) {
          runningTotal += 3 * parseInt(value.substr(c, 1));
        }
        else {
          runningTotal += parseInt(value.substr(c, 1));
        }
      }
      var rem = runningTotal % 10;
      if (rem != 0) {
        rem = 10 - rem;
      }

      return rem == parseInt(value.substr(12, 1));

    }
  }, jQuery.format('Not a valid EAN number.'));

  //Allow other modules to add more rules:
  jQuery.event.trigger('clientsideValidationAddCustomRules');
}
