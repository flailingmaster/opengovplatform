<?php

/**
 * @file
 * Theme related functions for the download_count module.
 */
function theme_download_count_upload_attachments($files, $downloads) {
  $header = array(t('Attachment'), t('Size'), t('Downloads'), t('Last Download'));
  $rows = array();
  foreach ($files as $file) {
    $file = (object) $file;
    if (isset($file->list) && empty($file->remove)) {
      $href = function_exists('_private_upload_create_url') ? _private_upload_create_url($file) : file_create_url($file->filepath);
      $text = $file->description ? $file->description : $file->filename;
      $last = isset($downloads[$file->filename]['last']) ? t('@time ago', array('@time' => format_interval(time() - $downloads[$file->filename]['last']))) : 'never';
      $count = isset($downloads[$file->filename]['count']) ? $downloads[$file->filename]['count'] : 0;
      $rows[] = array(l($text, $href), format_size($file->filesize), $count, $last);
    }
  }
  if (count($rows)) {
    return theme('table', $header, $rows, array('id' => 'attachments'));
  }
}

function theme_download_count_formatter_download_count($element) {

  if (empty($element['#item']['fid'])) {
    return '';
  }

  global $user;
  $file = $element['#item'];
  $node = $element['#node'];
  $field = content_fields($element['#field_name']);
  $filepath = $file['filepath'];

  if (user_access('view own download counts') && $user->uid != 1) {
    $count = db_result(db_query("SELECT COUNT(dc.dcid) FROM {download_count} dc JOIN {files} f ON dc.fid = f.fid WHERE f.filepath = '%s' AND dc.nid = %d AND dc.uid = %d", $filepath, $node->nid, $user->uid));
  }
  elseif (user_access('view all download counts')) {
    $count = db_result(db_query("SELECT COUNT(dc.dcid) FROM {download_count} dc JOIN {files} f ON dc.fid = f.fid WHERE f.filepath = '%s' AND dc.nid = %d", $filepath, $node->nid));
  }

  $output = theme('filefield_file', $file);
  if ($output) {

    if (user_access('view all download counts') || user_access('view own download counts')) {
      //$text = ' &mdash; ';
	  $split = explode(".",$file['filename']);
	  $ext = strtoupper($split[count($split)-1]);
	  $extension = theme('download_file_extension_accessible', $ext);
  	  $file_size = theme('download_file_bytes_accessible', $file['filesize']);
      $text = ''.variable_get('download_file_accessible_format', '(!extension / !file_size)').'';
	  $text = t($text, array('!extension' => $extension, '!file_size' => $file_size));
      if ($count) {
      $text .='<span class="download-stat">'.format_plural($count, 'Downloaded 1 time', 'Downloaded @count times').'</span>';
      }
      else {
        $text .= '<span class="download-stat">Never Downloaded</span>';
      }
    }
    else {
      $text = '';
    }

    if (drupal_substr($output, -6) == '</div>') {
      return drupal_substr($output, 0, -6) . $text . '</div>';
    }
    else {
      return $output . $text;
    }
  }
  return $output;
}
