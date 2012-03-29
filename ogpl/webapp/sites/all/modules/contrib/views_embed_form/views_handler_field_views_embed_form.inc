<?php
// $Id: views_handler_field_views_embed_form.inc,v 1.1.2.1 2009/01/07 15:05:09 meba Exp $

class views_handler_field_views_embed_form extends views_handler_field {

  /**
   * Helper counter for generating unique form ids
   *
   * @return int
   */
  static function form_counter() {
    static $counter = 0;
    return $counter++;
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['embedded_form'] = array('default' => FALSE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    $options = array('--' => '--');
    $options += views_embed_form_get_forms();
    $form['embedded_form'] = array(
        '#title' => t('Embedded form name'),
        '#type' => 'select',
        '#description' => t('Select a form you want to embed. These names are provided using an API implemented by various modules. See <a href="@help">module documentation</a> for help with implementing this API.', array('@help' => 'http://drupal.org/node/329511')),
        '#options' => $options,
        '#default_value' => $this->options['embedded_form'],
        '#required' => TRUE,
        );
  }
  function options_validate($form, &$form_state) {
    if ($form_state['values']['options']['embedded_form'] == '--') {
      form_set_error('embedded_form', t('Please select embedded form name.'));
    }
  }


  function render($values) {
    foreach(module_implements('views_embed_form') as $module) {
      $function = $module . '_views_embed_form';
      $form_names = $function();
      foreach ($form_names as $form_name => $form_description) { 
        if ($form_name === $this->options['embedded_form'] && function_exists($this->options['embedded_form'])) {
          return drupal_get_form($this->options['embedded_form'] . self::form_counter(), $values);
        }
      }
    }
    return t('You do not have permission to access embedded form.');
  }
}
