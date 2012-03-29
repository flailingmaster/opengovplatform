$Id: README.txt,v 1.1.4.6 2010/10/11 08:34:20 zuuperman Exp $

Description
-----------
This module makes a javascript toolbox action available thanks to the power
of Imagecache. It can currently 'hook' into several modules by adding
a 'javascript crop' link on the edit forms of supported modules and/or fields. 
The popup window will display all available imagecache presets with
a javascript crop action. In your theming you can use the imagecache theme function with
a preset. The imagecache action will make a database call to choose the right crop area.

The main difference with projects like eyedrop or imagefield_crop is that it doesn't 
provide it's own widget to upload images, instead it just 'hooks' into image modules/fields.

Everyone is invited to submit patches for more module support. I might
even give some people cvs access.

Supported modules
-----------------
image : Link is underneath the thumbnail on the edit page.
node_images : Underneath the thumbnail. Read on to implement a theme override.
imagefield : On node edit form. Previews & multiple values not supported (yet).

Installation
------------
You need imagecache, imageapi and jquery_ui
After you enable the module, you can go to admin/settings/imagecrop and enable 
support for modules & fields to display a link.

If you use jquery update. Make sure you also have the latest version from jquery_ui.
(For example jquery update 1.3.2 needs jquery ui 1.7.3)

A cron task cleans up the imagecrop table clearing records from files and/or presets
which do not exist anymore, so make sure cron is running.

Extra Coolness
--------------
Imagecrop supports several modal modules to open your popup with.
Supported modules are:
  - thickbox
  - colorbox (make sure you included node/*/edit in the module settings)
  - modalframe
  - shadowbox (make sure you included node/*/edit in the module settings)
  
Specific installation instructions for node_images module
---------------------------------------------------------
You need to paste the code underneath in the template.php file of your theme.
This makes sure the javascript link is available for the thumbnail.

/**
 * Theme function override of node_images to support imagecrop module
 */
function phptemplate_node_images_form_list($form) {

  $is_translation_source = $form['is_translation_source']['#value'];

  $header = array();
  if ($is_translation_source) {
    $header = array('', t('Delete'), t('List'));
  }
  $header =  array_merge($header, array(t('Thumbnail'), t('Description and info'), t('Weight'), t('Size')));
  drupal_add_tabledrag('node_images_list', 'order', 'sibling', 'node_images-weight');

  foreach (element_children($form['images']) as $key) {
    if (!$form['images'][$key]['thumbnail']) continue;

    // Add class to group weight fields for drag and drop.
    $form['images'][$key]['weight']['#attributes']['class'] = 'node_images-weight';

    $info = '<div class="node_images_info">'. t('Author: !name', array('!name' => drupal_render($form['images'][$key]['author']))).'</div>';
    $info .= '<div class="node_images_info">'. t('Uploaded on: %date', array('%date' => drupal_render($form['images'][$key]['date']))).'</div>';
    $info .= '<div class="node_images_info">'. t('Path: !path', array('!path' => drupal_render($form['images'][$key]['filepath']))).'</div>';

    if (isset($form['imagecrop'])) {
      $info .= '<div class="node_images_info">'. imagecrop_linkitem($form['images'][$key]['id']['#value'], 'node_images') .'</div>';
    }

    $row = array();
    if ($is_translation_source) {
      $row[] = '';
      $row[] = drupal_render($form['images'][$key]['delete']);
      $row[] = drupal_render($form['images'][$key]['list']);
    }
    $row[] = drupal_render($form['images'][$key]['thumbnail']);
    $row[] = array('data' => drupal_render($form['images'][$key]['description']).$info, 'width' => '100%');
    $row[] = drupal_render($form['images'][$key]['weight']);
    $row[] = array('data' => drupal_render($form['images'][$key]['filesize']), 'class' => 'nowrap');
    if ($is_translation_source) {
      $rows[] = array('data' => $row, 'class' => 'draggable');
    }
    else {
      $rows[] = $row;
    }
  }

  $output = '&nbsp;';
  if (!empty($rows)) $output .= theme('table', $header, $rows, array('id' => 'node_images_list'));
  $output .= drupal_render($form['translation_warning']);
  $output .= drupal_render($form);
  return $output;

}

Features, support, bugs etc
---------------------------
File request,bugs,patches on http://drupal.org/project/imagecrop

Inspiration
-----------
Came from the imagefield_crop module on which I based the html and jquery 
with some adjustments.

Author
------
Kristof De Jaeger - http://drupal.org/user/107403 - http://realize.be
Nils Destoop - http://drupal.org/user/361625 - http://www.menhir.be
