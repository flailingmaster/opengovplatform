<?php

/**
 * @file
 * Admin functions for the Views Slideshow: ImageFlow module.
 */

/**
 * Configure Views Slideshow: Imageflow; menu callback for
 * admin/build/views/views_slideshow_imageflow.
 */
function views_slideshow_imageflow_settings() {
  // First attempt to autodiscover the path to the ImageFlow plugin.
  $path = views_slideshow_imageflow_path();

  $form = array();

  $message = t('To use !imageflow, you must first !download the plugin package, extract it, and place the entire contents into the folder on your server specified here. (An attempt at autodiscovery will be made if it is within the %sites or %other folders.)', array('%sites' => 'sites/all/libraries', '%other' => 'sites/example.com/libraries', '!imageflow' => l(t('ImageFlow'), 'http://finnrudolph.de/ImageFlow', array('attributes' => array('target' => '_blank'))), '!download' => l(t('download'), 'http://finnrudolph.de/ImageFlow/Download', array('attributes' => array('target' => '_blank')))));
  if (!file_exists($path .'/imageflow.js')) {
    drupal_set_message($message, 'error');
  }

  $form[views_slideshow_imageflow_variable_name('plugin_path')] = array(
    '#type' => 'textfield',
    '#title' => t('Path to the ImageFlow plugin'),
    '#description' => $message,
    '#default_value' => $path,
  );
  $form[views_slideshow_imageflow_variable_name('packed')] = array(
    '#type' => 'checkbox',
    '#title' => t('Use packed scripts'),
    '#description' => t('If checked, then use the packed JS and CSS files when displaying the ImageFlow player.'),
    '#default_value' => views_slideshow_imageflow_variable_get('packed'),
  );
  $form[views_slideshow_imageflow_variable_name('include_css')] = array(
    '#type' => 'checkbox',
    '#title' => t('Include CSS'),
    '#description' => t('If checked, then use the supplied CSS file when displaying the ImageFlow player. Note that you may experience problems when Optimizing CSS files from the !performance_page. Please see !issue for help resolving this.', array('!performance_page' => l(t('performance page'), 'admin/settings/performance'), '!issue' => l(t('SOLVED: Enabling CSS File Optimization makes ImageFlow Container show Images vertical'), 'http://drupal.org/node/769968', array('attributes' => array('target' => '_blank'))))),
    '#default_value' => views_slideshow_imageflow_variable_get('include_css'),
  );

  return system_settings_form($form);
}
