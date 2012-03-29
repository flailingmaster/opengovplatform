<?php

/**
 *  @file
 *  The default options available with Views Slideshow: ImageFlow.
 */

/**
 *  Implements hook_views_slideshow_modes().
 */
function views_slideshow_imageflow_views_slideshow_modes() {
  // Expose the mode for ImageFlow slide shows.
  $options = array(
    'views_slideshow_imageflow' => t('ImageFlow'),
  );
  return $options;
}

/**
 *  Implements hook_views_slideshow_option_definition().
 */
function views_slideshow_imageflow_views_slideshow_option_definition() {
  // Set our default options.
  $options['views_slideshow_imageflow'] = array(
    'default' => array(
      'aspect_ratio' => views_slideshow_imageflow_variable_get('aspect_ratio'),
      'images_height' => views_slideshow_imageflow_variable_get('images_height'),
      'image_cursor' => views_slideshow_imageflow_variable_get('image_cursor'),
      'slider_cursor' => views_slideshow_imageflow_variable_get('slider_cursor'),
      'slider' => views_slideshow_imageflow_variable_get('slider'),
      'start' => views_slideshow_imageflow_variable_get('start'),
      'captions' => views_slideshow_imageflow_variable_get('captions'),
      'imageFocusM' => views_slideshow_imageflow_variable_get('imageFocusM'),
      'scrollbarP' => views_slideshow_imageflow_variable_get('scrollbarP'),
      'imageFocusMax' => views_slideshow_imageflow_variable_get('imageFocusMax'),
      'onClick' => views_slideshow_imageflow_variable_get('onClick'),
	  'buttons' => views_slideshow_imageflow_variable_get('buttons'),
	  'circular' => views_slideshow_imageflow_variable_get('circular'),
    ),
  );
  return $options;
}

/**
 *  Implements hook_views_slideshow_options_form().
 */
function views_slideshow_imageflow_views_slideshow_options_form(&$form, &$form_state, &$view) {
  // Create the form elements for our ImageFlow view options.
  $form['views_slideshow_imageflow'] = array(
    '#type' => 'fieldset',
    '#title' => t('ImageFlow options'),
    '#collapsible' => TRUE,
    '#collapsed' => !($view->options['mode'] == 'views_slideshow_imageflow'),
  );
  $form['views_slideshow_imageflow']['aspect_ratio'] = array(
    '#type' => 'textfield',
    '#title' => t('Aspect ratio'),
    '#description' => t('Aspect ratio of the ImageFlow container (width divided by height).'),
    '#default_value' => $view->options['views_slideshow_imageflow']['aspect_ratio'],
  );
  $form['views_slideshow_imageflow']['images_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Images height'),
    '#description' => t('Height of the images div container to be multiplied.'),
    '#default_value' => $view->options['views_slideshow_imageflow']['images_height'],
  );
  $form['views_slideshow_imageflow']['image_cursor'] = array(
    '#type' => 'select',
    '#title' => t('Image cursor'),
    '#description' => t('Cursor type for the images.'),
    '#default_value' => $view->options['views_slideshow_imageflow']['image_cursor'],
    '#options' => array(
      'pointer' => t('pointer'),
      'default' => t('default'),
      'e-resize' => t('e-resize'),
    ),
  );
  $form['views_slideshow_imageflow']['slider'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show slider'),
    '#description' => t('Disables / enables the scrollbar.'),
    '#default_value' => $view->options['views_slideshow_imageflow']['slider'],
  );
  $form['views_slideshow_imageflow']['slider_cursor'] = array(
    '#type' => 'select',
    '#title' => t('Slider cursor'),
    '#description' => t('Cursor type for the slider.'),
    '#default_value' => $view->options['views_slideshow_imageflow']['slider_cursor'],
    '#options' => array(
      'pointer' => t('pointer'),
      'default' => t('default'),
      'e-resize' => t('e-resize'),
    ),
  );
  $form['views_slideshow_imageflow']['start'] = array(
    '#type' => 'select',
    '#title' => t('Start position'),
    '#description' => t('The position to begin the ImageFlow.'),
    '#default_value' => $view->options['views_slideshow_imageflow']['start'],
    '#options' => array(
      'start' => t('Start'),
      'middle' => t('Middle'),
      'end' => t('End'),
      'random' => t('Random'),
    ),
  );
  $form['views_slideshow_imageflow']['captions'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display captions'),
    '#description' => t('Disables / enables the display of captions.'),
    '#default_value' => $view->options['views_slideshow_imageflow']['captions'],
  );
  $form['views_slideshow_imageflow']['imageFocusM'] = array(
    '#type' => 'textfield',
    '#title' => t('Image focus multiplier'),
    '#description' => t('Multiplier for the focussed image size.'),
    '#default_value' => $view->options['views_slideshow_imageflow']['imageFocusM'],
  );
  $form['views_slideshow_imageflow']['scrollbarP'] = array(
    '#type' => 'textfield',
    '#title' => t('Scrollbar width multiplier'),
    '#description' => t('Multiplier width of the scrollbar (0-1).'),
    '#default_value' => $view->options['views_slideshow_imageflow']['scrollbarP'],
  );
  $form['views_slideshow_imageflow']['imageFocusMax'] = array(
    '#type' => 'textfield',
    '#title' => t('Image focus max'),
    '#description' => t('Maximum number of images on each side of the focussed one.'),
    '#default_value' => $view->options['views_slideshow_imageflow']['imageFocusMax'],
  );

  $form['views_slideshow_imageflow']['onClick'] = array(
    '#type' => 'textarea',
    '#title' => t('onClick override'),
    '#description' => t('You may override the onClick JavaScript function of slide show image frames here.'),
    '#default_value' => $view->options['views_slideshow_imageflow']['onClick'],
  );
  
    $form['views_slideshow_imageflow']['buttons'] = array(
  '#type' => 'checkbox',
  '#title' => t('Buttons'),
  '#description' => t('Enables scrollbar previous and next buttons'),
  '#default_value' => $view->options['views_slideshow_imageflow']['buttons'],
  );
  $form['views_slideshow_imageflow']['circular'] = array(
   '#type' => 'checkbox',
  '#title' => t('Circular'),
  '#description' => t('Enables circular mode (ignores image focus multiplier)'),
  '#default_value' => $view->options['views_slideshow_imageflow']['circular'],
 );
}
