<?php
// $Id: download_file.formatter.inc,v 1.1.2.3 2010/10/08 07:15:58 xmattx Exp $

/**
 * @file
 * Download file formatter hooks and callbacks.
 */

/**
 * Theming function for displaying the link to direct download the file.
 *
 * @param $element
 *   Element(s) to format.
 * @return
 *   A string containing the HTML ouput.
 */
function theme_download_file_formatter_direct_download($element) {
  $output = '';
  
  foreach (element_children($element) as $i) {
    $file = $element[$i]['#item'];
    
    if (!empty($file)) {
      $output .= theme('download_file_direct_download_item', $file);
    }
  }
  
  return $output;
}

/**
 * Theming function for displaying the link to direct download the file with 
 * the type icon.
 *
 * @param $element
 *   Element(s) to format.
 * @return
 *   A string containing the HTML ouput.
 */
function theme_download_file_formatter_direct_download_icon($element) {
  $output = '';
  
  foreach (element_children($element) as $i) {
    $file = $element[$i]['#item'];
    
    if (!empty($file)) {
      $output .= theme('download_file_direct_download_icon_item', $file);
    }
  }
  
  return $output;
}

/**
 * Theming function for displaying the link accessible to direct download the 
 * file.
 *
 * @param $element
 *   Element(s) to format.
 * @return
 *   A string containing the HTML ouput.
 */
function theme_download_file_formatter_direct_download_accessible($element) {
  $output = '';
  
  foreach (element_children($element) as $i) {
    $file = $element[$i]['#item'];
    
    if (!empty($file)) {
      $output .= theme('download_file_direct_download_item_accessible', $file);
    }
  }
  
  return ($output) ? '<ul class="download-file">' . $output . '</ul>' : $output;
}

/**
 * Theming function for displaying the link accessible to direct download the 
 * file with the type icon.
 *
 * @param $element
 *   Element(s) to format.
 * @return
 *   A string containing the HTML ouput.
 */
function theme_download_file_formatter_direct_download_accessible_icon($element) {
  $output = '';
  
  foreach (element_children($element) as $i) {
    $file = $element[$i]['#item'];
  
    if (!empty($file)) {
      $output .= theme('download_file_direct_download_icon_item_accessible', $file);
    }
  }
  
  return ($output) ? '<ul class="download-file">' . $output . '</ul>' : $output;
}

/**
 * Theme function for the 'direct_download' single file formatter.
 *
 * @param $file
 *   File to format.
 * @return
 *   A string containing the HTML ouput.
 */
function theme_download_file_direct_download_item($file) {
  // Views may call this function with a NULL value, return an empty string.
  if (empty($file['fid'])) {
    return '';
  }

  $url  = download_file_path($file['fid']);

  // Use the description as the link text if available.
  if (empty($file['data']['description'])) {
    $link_text = $file['filename'];
  }
  else {
    $link_text                      = $file['data']['description'];
    $options['attributes']['title'] = $file['filename'];
  }
  
  return '<div class="download-file clear-block">' . l($link_text, $url) . '</div>';
}

/**
 * Theme function for the 'direct_download_icon' single file formatter.
 *
 * @param $file
 *   File to format.
 * @return
 *   A string containing the HTML ouput.
 */
function theme_download_file_direct_download_icon_item($file) {
  // Views may call this function with a NULL value, return an empty string.
  if (empty($file['fid'])) {
    return '';
  }

  $url  = download_file_path($file['fid']);
  $icon = theme('filefield_icon', $file);

  // Use the description as the link text if available.
  if (empty($file['data']['description'])) {
    $link_text = $file['filename'];
  }
  else {
    $link_text                      = $file['data']['description'];
    $options['attributes']['title'] = $file['filename'];
  }

  return '<div class="download-file clear-block">' . $icon . l($link_text, $url) . '</div>';
}

/**
 * Theme function for the 'direct_download_accessible' single file formatter.
 *
 * @param $file
 *   File to format.
 * @return
 *   A string containing the HTML ouput.
 */
function theme_download_file_direct_download_item_accessible($file) {
  // Views may call this function with a NULL value, return an empty string.
  if (empty($file['fid'])) {
    return '';
  }
  
  $url             = download_file_path($file['fid']);
  $accessibility   = theme('download_file_detail_accessible', $file);
  $options['html'] = TRUE;
  
  // Use the description as the link text if available.
  if (empty($file['data']['description'])) {
    $link_text = $file['filename'];
  }
  else {
    $link_text                      = $file['data']['description'];
    $options['attributes']['title'] = $file['filename'];
  }
  
  return '<li>' . l($link_text . ' ' . $accessibility, $url, $options) . '</li>';
}

/**
 * Theme function for the 'direct_download_accessible_icon' single file 
 * formatter.
 *
 * @param $file
 *   File to format.
 * @return
 *   A string containing the HTML ouput.
 */
function theme_download_file_direct_download_icon_item_accessible($file) {
  // Views may call this function with a NULL value, return an empty string.
  if (empty($file['fid'])) {
    return '';
  }
  
  $url             = download_file_path($file['fid']);
  $icon            = theme('filefield_icon', $file);
  $accessibility   = theme('download_file_detail_accessible', $file);
  $options['html'] = TRUE;
  
  // Use the description as the link text if available.
  if (empty($file['data']['description'])) {
    $link_text = $file['filename'];
  }
  else {
    $link_text                      = $file['data']['description'];
    $options['attributes']['title'] = $file['filename'];
  }
  
  return '<li>' . $icon . l($link_text . ' ' . $accessibility, $url, $options) . '</li>';
}

/**
 * Theme function for the link accessible.
 *
 * @param $file
 *   File to format.
 * @return
 *   A string containing the HTML ouput.
 */
function theme_download_file_detail_accessible($file) {
  if (is_object($file)) {
    $file = (array) $file;
  }
  
  $extension = theme('download_file_extension_accessible', download_file_format_extension($file));
  $file_size = theme('download_file_bytes_accessible', $file['filesize']);
  $format = variable_get('download_file_accessible_format', '(format !extension / !file_size)');
  
  return '<span class="detail">' . t($format, array('!extension' => $extension, '!file_size' => $file_size)) . '</span>';
}

/**
 * Theme function for the extension accessible.
 *
 * @param $extension
 *   File extension to format.
 * @return
 *   A string containing the HTML ouput.
 */
function theme_download_file_extension_accessible($extension) {
  if (is_array($extension)) {
    $extension = '<acronym title="' . $extension['definition'] . '">' . $extension['name'] . '</acronym>';
  }
  
  return $extension;
}

/**
 * Theme function for the size format accessible.
 *
 * @param $filesize
 *   File size to format.
 * @return
 *   A string containing the HTML ouput.
 */
function theme_download_file_bytes_accessible($filesize) {
  if (empty($filesize)) {
    return '';
  }
  
  list($size, $unit) = download_file_format_bytes($filesize, 0);
  $acronyms          = array(t('B') => t('Bytes'),
                            t('KB') => t('Kilo Bytes'),
                            t('MB') => t('Mega Bytes'),
                            t('GB') => t('Giga Bytes'),
                            t('TB') => t('Tera Bytes'),
                            t('PB') => t('Peta Bytes'));
  
  return $size . ' <acronym title="' . $acronyms[$unit] . '">' . $unit . '</acronym>';
}