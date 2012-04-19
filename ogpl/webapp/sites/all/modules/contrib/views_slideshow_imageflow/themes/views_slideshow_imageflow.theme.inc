<?php

/**
 *  @file
 *  Theme & preprocess functions for the Views Slideshow: Imageflow module.
 */

/**
 *  We'll grab only the first image from each row.
 */
function template_preprocess_views_slideshow_imageflow(&$vars) {
  // Initialize our $images array.
  $vars['images'] = array();

  // Strip all images from the $rows created by the original view query.
  foreach($vars['rows'] as $item) {
    preg_match('@(<\s*img\s+[^>]*>)@i', $item, $matches);
    if ($image = $matches[1]) {
      // We need to add a URL to 'longdesc', as required by the plugin.
      // If our image is in an anchor tag, use its URL.
      preg_match('@<\s*a\s+href\s*=\s*"\s*([^"]+)\s*"[^>]*>[^<]*'. preg_quote($image) .'[^<]*<\s*/a\s*>@i', $item, $urls);
      if (!($url = $urls[1])) {
        // Otherwise link to the original image.
        preg_match('@src\s*=\s*"([^"]+)"@i', $image, $urls);
        if (!($url = $urls[1])) {
          // If we get this far, there are probably more serious problems.
          // But for now, we'll go to the front page instead.
          $url = url('<front>');
        }
      }

      // Add the URL to the image's longdesc tag.
      $image = preg_replace('@img\s+@i', 'img longdesc="'. $url .'" ', $image);

      // Add the image to our image array to display.
      $vars['images'][] = $image;
    }
  }

  // Find the path to our plugin.
  $path = views_slideshow_imageflow_path();

  // Add the required JS and CSS.
  $packed = views_slideshow_imageflow_variable_get('packed') ? '.packed' : '';
  drupal_add_js($path .'/imageflow'. $packed .'.js');

  // Only include the CSS if we're supposed to.
  // @see issue at http://drupal.org/node/769968.
  if (views_slideshow_imageflow_variable_get('include_css')) {
    drupal_add_css($path .'/imageflow'. $packed .'.css');
  }

  $drupal_path = drupal_get_path('module', 'views_slideshow_imageflow') . '/themes';
  drupal_add_js($drupal_path .'/js/views_slideshow_imageflow.js');

  $view = $vars['view'];
  $rows = $vars['rows'];
  $options = $vars['options'];
  switch ($options['views_slideshow_imageflow']['start']) {
    case 'start':
      $start = 1;
      break;
    case 'end':
      $start = sizeof($rows);
      break;
    case 'middle':
      $start = ceil(sizeof($rows) / 2);
      break;
    case 'random':
      $start = rand(1, sizeof($rows));
      break;
  }

  // Deal with views created before various options were available:
  // @TODO: Do this in an update function instead?
  $options['views_slideshow_imageflow']['captions'] = isset($options['views_slideshow_imageflow']['captions']) ? $options['views_slideshow_imageflow']['captions'] : TRUE;
  $options['views_slideshow_imageflow']['imageFocusM'] = isset($options['views_slideshow_imageflow']['imageFocusM']) ? $options['views_slideshow_imageflow']['imageFocusM'] : 1.0;
  $options['views_slideshow_imageflow']['scrollbarP'] = isset($options['views_slideshow_imageflow']['scrollbarP']) ? $options['views_slideshow_imageflow']['scrollbarP'] : 0.6;
  $options['views_slideshow_imageflow']['imageFocusMax'] = isset($options['views_slideshow_imageflow']['imageFocusMax']) ? $options['views_slideshow_imageflow']['imageFocusMax'] : 4;
  $options['views_slideshow_imageflow']['buttons'] = isset($options['views_slideshow_imageflow']['buttons']) ? $options['views_slideshow_imageflow']['buttons'] : FALSE;
  $options['views_slideshow_imageflow']['circular'] = isset($options['views_slideshow_imageflow']['circular']) ? $options['views_slideshow_imageflow']['circular'] : FALSE;
  $settings = array(
    'aspectRatio' => $options['views_slideshow_imageflow']['aspect_ratio'],
    'imagesHeight' => $options['views_slideshow_imageflow']['images_height'],
    'imageCursor' => $options['views_slideshow_imageflow']['image_cursor'],
    'sliderCursor' => $options['views_slideshow_imageflow']['slider_cursor'],
    'startID' => $start,
    'slider' => $options['views_slideshow_imageflow']['slider'],
    'captions' => $options['views_slideshow_imageflow']['captions'],
    'imageFocusM' => $options['views_slideshow_imageflow']['imageFocusM'],
    'scrollbarP' => $options['views_slideshow_imageflow']['scrollbarP'],
    'imageFocusMax' => $options['views_slideshow_imageflow']['imageFocusMax'],
    'onClick' => $options['views_slideshow_imageflow']['onClick'],
	'buttons'=>$options['views_slideshow_imageflow']['buttons'],
	'circular' => $options['views_slideshow_imageflow']['circular'],
	
  );
  drupal_add_js(array('viewsSlideshowImageFlow' => array('views-slideshow-imageflow-images-'. $vars['id'] => $settings)), 'setting');
}
