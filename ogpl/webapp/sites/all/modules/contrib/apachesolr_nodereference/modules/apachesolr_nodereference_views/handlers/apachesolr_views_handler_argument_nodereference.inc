<?php
// $Id$

/**
 * @file
 * Provides an argument handler for nodereferences
 */
class apachesolr_views_handler_argument_nodereference extends content_handler_argument_many_to_one {
  var $value;

  function construct() {
    parent::construct();

    $this->content_field = content_fields($this->definition['cck_field']['field_name']);
  }

  function query() {
    $argument_values = @$this->get_value();
    $allowed_arguments = $this->allowed_values();

    if (!empty($this->options['break_phrase'])) {
      $passed_arguments = explode(',', $argument_values);
    }
    else {
      $passed_arguments = array($argument_values);
    }

    // check passed arguments against allowed values
    $valid_arguments = array();

    foreach ($passed_arguments as $value) {
      if (array_key_exists($value, $allowed_arguments)) {
        $valid_arguments[] = (int) $value;
      }
    }

    if (!empty($valid_arguments)) {
      foreach ($valid_arguments as $facet_value) {
        $this->query->add_filter($this->real_field, apachesolr_views_query::escape_term($facet_value));
      }
    }
    else {
      $this->query->add_filter($this->real_field, apachesolr_views_query::escape_term('-1'));
    }
  }

  /**
   * Get the title this argument will assign the view, given the argument.
   */
  function title() {
    $options = $this->title_query();

    return $options[0];
  }

  /**
   * Get allowed values from hook_allowed_values(), if any, or from
   * content_allowed_values();
   */
  function allowed_values() {
    $options = nodereference_allowed_values($this->content_field);

    return (array) $options;
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['break_phrase'] = array('default' => FALSE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    unset($form['require_value']);
    unset($form['add_table']);

    // allow for , delimited values
    $form['break_phrase'] = array(
      '#type' => 'checkbox',
      '#title' => t('Allow multiple terms per argument.'),
      '#description' => t('If selected, users can enter multiple arguments in the form of 1,2,3.'),
      '#default_value' => !empty($this->options['break_phrase']),
    );
  }

  /**
   * Provide a list of default behaviors for this argument if the argument
   * is not present.
   *
   * Provide fewer methods that the standard. Remove summary views
   */
  function default_actions($which = NULL) {
    $defaults = array(
      'ignore' => array(
        'title' => t('Display all values'),
        'method' => 'default_ignore',
        'breadcrumb' => TRUE, // generate a breadcrumb to here
      ),
      'not found' => array(
        'title' => t('Hide view / Page not found (404)'),
        'method' => 'default_not_found',
        'hard fail' => TRUE, // This is a hard fail condition
      ),
      'empty' => array(
        'title' => t('Display empty text'),
        'method' => 'default_empty',
        'breadcrumb' => TRUE, // generate a breadcrumb to here
      ),
      'default' => array(
        'title' => t('Provide default argument'),
        'method' => 'default_default',
        'form method' => 'default_argument_form',
        'has default argument' => TRUE,
        'default only' => TRUE, // this can only be used for missing argument, not validation failure
      ),
    );

    if ($which) {
      if (!empty($defaults[$which])) {
        return $defaults[$which];
      }
    }
    else {
      return $defaults;
    }
  }
}