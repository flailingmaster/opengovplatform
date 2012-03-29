<?php

// $Id$
/**
 * @file Admin settings for Clientside Validation
 */
function clientside_validation_admin_settings() {

  //jquery.validate.js settings
  $form['clientside_validation_min'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Use minified version of jquery.validate.js'),
    '#description' => t('You can use the minified version of the library.'),
  );

  $form['clientside_validation_min']['clientside_validation_use_minified'] = array(
    '#type' => 'radios',
    '#options' => array(
      '1' => t('Yes'),
      '0' => t('No'),
    ),
    '#default_value' => variable_get('clientside_validation_use_minified', 0),
    '#title' => t('Use minified version?'),
  );

  //Validate options
  $form['clientside_validation_validate_options'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Validate options'),
    '#description' => t('Set the validate options for Clientside Validation.'),
  );

  $form['clientside_validation_validate_options']['clientside_validation_validate_onsubmit'] = array(
    '#type' => 'radios',
    '#options' => array(
      '1' => t('Yes'),
      '0' => t('No'),
    ),
    '#title' => t('Validate fields on submit'),
    '#description' => t('"No" disables onsubmit validation, allowing the user to submit whatever he wants, while still validating on keyup/blur/click events (if not specified otherwise).'),
    '#default_value' => variable_get('clientside_validation_validate_onsubmit', 1),
  );

  $form['clientside_validation_validate_options']['clientside_validation_validate_onblur'] = array(
    '#type' => 'radios',
    '#options' => array(
      '1' => t('Yes'),
      '0' => t('No'),
    ),
    '#title' => t('Validate fields on blur'),
    '#description' => t('Validate elements (except checkboxes/radio buttons) on blur. <strong>If nothing is entered, all rules are skipped, except when the field was already marked as invalid.</strong>'),
    '#default_value' => variable_get('clientside_validation_validate_onblur', 1),
  );

  $form['clientside_validation_validate_options']['clientside_validation_validate_onkeyup'] = array(
    '#type' => 'radios',
    '#options' => array(
      '1' => t('Yes'),
      '0' => t('No'),
    ),
    '#title' => t('Validate fields on key up'),
    '#description' => t('Validate elements on keyup. <strong>As long as the field is not marked as invalid, nothing happens</strong>. Otherwise, all rules are checked on each key up event.'),
    '#default_value' => variable_get('clientside_validation_validate_onkeyup', 1),
  );

  //Error message settings
  $form['clientside_validation_error'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Error message settings'),
    '#description' => t('Change error message related settings.'),
  );

  $form['clientside_validation_error']['clientside_validation_prefix'] = array(
    '#title' => t('Field name prefix'),
    '#description' => t('The prefix of the field name in the error messages.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('clientside_validation_prefix', ''),
  );

  $form['clientside_validation_error']['clientside_validation_suffix'] = array(
    '#title' => t('Field name suffix'),
    '#description' => t('The suffix of the field name in the error messages.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('clientside_validation_suffix', ''),
  );

  $form['clientside_validation_error']['example_image'] = array(
    '#type' => 'item',
    '#title' => t('Example'),
    '#value' => '<img id="clientside_validation_example_image" src="' . base_path() . drupal_get_path('module', 'clientside_validation') . '/errormsg.png" alt="' . t('Error message example') . '" />',
    '#description' => t('Filling in double quotes in both the above fields will give this result.'),
  );

  $form['clientside_validation_error']['clientside_validation_scrollto_errormessage'] = array(
    '#title' => t('Scroll to error message'),
    '#description' => t('If checked, the page will automatically scroll to the error messages when validation fails.'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('clientside_validation_scrollto_errormessage', 1),
  );

  $form['clientside_validation_error']['clientside_validation_scroll_speed'] = array(
    '#title' => t('Scroll speed'),
    '#description' => t('The scroll speed in milliseconds'),
    '#type' => 'textfield',
    '#default_value' => variable_get('clientside_validation_scroll_speed', 1000),
  );

  if (module_exists('fapi_validation') && module_exists('clientside_validation_fapi')) {
    $form['clientside_validation_error']['clientside_validation_scroll_speed'] += array('#rules' => array('numeric'));
  }

  //Error Placement
   $form['clientside_validation_error_placement'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Error message placement'),
    '#description' => t('Change error message placement settings.'),
  );

  $form['clientside_validation_error_placement']['clientside_validation_error_placement_default'] = array(
    '#type' => 'select',
    '#title' => t('Default location'),
    '#description' => t('Default location to show the error messages.
      If you choose "jQuery selector", provide a valid jQuery selector in the appropriate textfield.
      If you choose "Custom function", provide the name of the custom javascript function.
      This function will be given to !errorPlacement',
      array(
        '!errorPlacement' =>
        l('the errorPlacement option of jQuery.validate()', 'http://docs.jquery.com/Plugins/Validation/validate#options')
      )
    ),
    '#options' => array(
      CLIENTSIDE_VALIDATION_JQUERY_SELECTOR => t('jQuery selector'),
      CLIENTSIDE_VALIDATION_TOP_OF_FORM => t('Top of form'),
      CLIENTSIDE_VALIDATION_BEFORE_LABEL => t('Before label'),
      CLIENTSIDE_VALIDATION_AFTER_LABEL => t('After label'),
      CLIENTSIDE_VALIDATION_BEFORE_INPUT => t('Before input'),
      CLIENTSIDE_VALIDATION_AFTER_INPUT => t('After input'),
      CLIENTSIDE_VALIDATION_TOP_OF_FIRST_FORM => t('Top of first form'),
      CLIENTSIDE_VALIDATION_CUSTOM_ERROR_FUNCTION => t('Custom function'),
    ),
    '#default_value' => variable_get('clientside_validation_error_placement_default', CLIENTSIDE_VALIDATION_TOP_OF_FIRST_FORM),
  );

  $form['clientside_validation_error_placement']['clientside_validation_jquery_selector'] = array(
    '#type' => 'textfield',
    '#title' => t('jQuery selector'),
    '#description' => t('Enter a jQuery selector here if you selected "jQuery selector" in the previous step. 
                      The error messages will be shown in this div if it exists.
                      If it doesn\'t, error messages will be shown above the first form on the page.'),
    '#default_value' => variable_get('clientside_validation_jquery_selector', ''),
  );

  $form['clientside_validation_error_placement']['clientside_validation_custom_error_function'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom function name'),
    '#description' => t('If you selected "Custom function" in the previous step, provide the name of the custom javascript function.
      This function will be given to !errorPlacement',
      array(
        '!errorPlacement' =>
        l('the errorPlacement option of jQuery.validate()', 'http://docs.jquery.com/Plugins/Validation/validate#options')
      )),
    '#default_value' => variable_get('clientside_validation_custom_error_function', ''),
  );

  //Error placement exceptions
  $form['clientside_validation_error_placement']['clientside_validation_error_placement_exceptions'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Error message placement exceptions'),
    '#description' => t('Add exceptions to the default error message placement.'),
  );

  $form['clientside_validation_error_placement']['clientside_validation_error_placement_exceptions']['clientside_validation_error_placement_jquery'] = array(
    '#type' => 'textarea',
    '#title' => t('jQuery selector forms'),
    '#description' => t('Enter form IDs of the forms of which the errors should appear in the div with the entered jQuery selector.'),
    '#default_value' => variable_get('clientside_validation_error_placement_jquery', ''),
  );

  $form['clientside_validation_error_placement']['clientside_validation_error_placement_exceptions']['clientside_validation_error_placement_top_of_form'] = array(
    '#type' => 'textarea',
    '#title' => t('Top of form'),
    '#description' => t('Enter form IDs of the forms of which the errors should appear right above the form.'),
    '#default_value' => variable_get('clientside_validation_error_placement_top_of_form', ''),
  );

  $form['clientside_validation_error_placement']['clientside_validation_error_placement_exceptions']['clientside_validation_error_placement_before_label'] = array(
    '#type' => 'textarea',
    '#title' => t('Before label'),
    '#description' => t('Enter form IDs of the forms of which the errors should appear before the label of the element.'),
    '#default_value' => variable_get('clientside_validation_error_placement_before_label', ''),
  );

  $form['clientside_validation_error_placement']['clientside_validation_error_placement_exceptions']['clientside_validation_error_placement_after_label'] = array(
    '#type' => 'textarea',
    '#title' => t('Before label'),
    '#description' => t('Enter form IDs of the forms of which the errors should appear after the label of the element.'),
    '#default_value' => variable_get('clientside_validation_error_placement_after_label', ''),
  );

  $form['clientside_validation_error_placement']['clientside_validation_error_placement_exceptions']['clientside_validation_error_placement_before_input'] = array(
    '#type' => 'textarea',
    '#title' => t('Before input'),
    '#description' => t('Enter form IDs of the forms of which the errors should appear before the input element.'),
    '#default_value' => variable_get('clientside_validation_error_placement_before_input', ''),
  );

  $form['clientside_validation_error_placement']['clientside_validation_error_placement_exceptions']['clientside_validation_error_placement_after_input'] = array(
    '#type' => 'textarea',
    '#title' => t('After input'),
    '#description' => t('Enter form IDs of the forms of which the errors should appear after the input element.'),
    '#default_value' => variable_get('clientside_validation_error_placement_after_input', ''),
  );

  $form['clientside_validation_error_placement']['clientside_validation_error_placement_exceptions']['clientside_validation_error_placement_custom_function'] = array(
    '#type' => 'textarea',
    '#title' => t('Custom function'),
    '#description' => t('Enter form IDs of the forms of which the errors should appear according to the the custom function.'),
    '#default_value' => variable_get('clientside_validation_error_placement_custom_function', ''),
  );

  //Page settings
  $form['clientside_validation_pages'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Paths'),
    '#description' => t('Include or exclude paths for Clientside Validation.'),
  );

  $form['clientside_validation_pages']['clientside_validation_filter_paths'] = array(
    '#type' => 'radios',
    '#options' => array(
      CLIENTSIDE_VALIDATION_EXCLUDE_PATHS => t('Add Clientside Validation on all paths except those specified below'),
      CLIENTSIDE_VALIDATION_INCLUDE_PATHS => t('Only add Clientside Validation on the paths specified below'),
    ),
    '#default_value' => variable_get('clientside_validation_filter_paths', CLIENTSIDE_VALIDATION_EXCLUDE_PATHS),
    '#title' => t('Include or exclude paths'),
  );

  $form['clientside_validation_pages']['clientside_validation_path_list'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('clientside_validation_path_list', ''),
    '#title' => t("Enter paths"),
    '#description' => t("Enter one page per line as Drupal paths.
      The '*' character is a wildcard. Example paths are %blog for the blog page and
      %blog-wildcard for every personal blog. %front is the front page.",
      array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')),
  );

  //Hidden fields and vertical tabs
  $form['clientside_validation_include_hidden'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Behaviour for hidden fields and vertical tabs'),
  );

  $form['clientside_validation_include_hidden']['clientside_validation_include_hidden'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('clientside_validation_include_hidden', ''),
    '#title' => t("Don't ignore hidden fields on the following forms"),
    '#description' => t('You can specify form IDs (one per line) of forms that should have hidden elements validated.'),
  );

  $form['clientside_validation_include_hidden']['clientside_validation_validate_tabs'] = array(
    '#type' => 'checkbox',
    '#default_value' => variable_get('clientside_validation_validate_tabs', 1),
    '#title' => t('Validate all vertical tabs'),
    '#description' => t('If you check this, all tabs will be validated on submit
                      (including the hidden ones). Warning: if there are other hidden
                      fields (e.g. conditional fields), those will be validated too.'),
  );

  //Form settings
  $form['clientside_validation_validate_forms'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Forms to validate'),
  );

  $form['clientside_validation_validate_forms']['clientside_validation_validate_all'] = array(
    '#type' => 'radios',
    '#default_value' => variable_get('clientside_validation_validate_all', CLIENTSIDE_VALIDATION_VALIDATE_ALL),
    '#title' => t('Select the forms to validate'),
    '#options' => array(
      CLIENTSIDE_VALIDATION_VALIDATE_ALL => t('Validate all forms'),
      CLIENTSIDE_VALIDATION_VALIDATE_SPECIFIC => t('Only validate forms listed below'),
      CLIENTSIDE_VALIDATION_VALIDATE_ALL_EXCEPT => t('Validate all forms except those listed below')
    )
  );

  $form['clientside_validation_validate_forms']['clientside_validation_validate_specific'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('clientside_validation_validate_specific', ''),
    '#title' => t("Enter form IDs below"),
    '#description' => t('You can specify form IDs (one per line) of forms that should or should not be validated.'),
  );

  return system_settings_form($form);
}