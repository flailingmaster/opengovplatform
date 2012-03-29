<?php

/**
 * @file
 * Page callback file for the download_count module.
 */
function download_count_view_page($arg = NULL) {

  global $user;
  $rows = array();
  $header = array();
  $result = NULL;

  $header[] = array(
    'data' => t('Count'),
    'field' => 'count',
    'sort' => 'desc',
    'class' => 'count',
  );
  $header[] = array(
    'data' => t('File'),
    'field' => 'filename',
    'class' => 'file',
  );
  $header[] = array(
    'data' => t('Page'),
    'field' => 'title',
    'class' => 'page',
  );
  $header[] = array(
    'data' => t('Last Download'),
    'field' => 'last',
    'class' => 'date',
  );

  if ($arg == 'download_count') {
    drupal_set_title(check_plain(variable_get('download_count_view_page_title', t('Download Count'))));
    $limit = (int) variable_get('download_count_view_page_limit', '');
    $file_links = variable_get('download_count_file_links', 1);

    if (!$limit) {
      $result = db_query("SELECT COUNT(dc.dcid) AS count, dc.dcid, f.filename, MAX(dc.timestamp) AS last, dc.nid, f.filepath, f.fid, n.title FROM {download_count} dc JOIN {files} f ON dc.fid = f.fid JOIN {node} n ON dc.nid = n.nid GROUP BY dc.nid, f.filename" . tablesort_sql($header));
    }
    else {
      $result = db_query("SELECT COUNT(dc.dcid) AS count, dc.dcid, f.filename, MAX(dc.timestamp) AS last, dc.nid, f.filepath, f.fid, n.title FROM {download_count} dc JOIN {files} f ON dc.fid = f.fid JOIN {node} n ON dc.nid = n.nid GROUP BY dc.nid, f.filename" . tablesort_sql($header) . " LIMIT %d", $limit);
    }
    $output = '<div id="download_count_page">';
  }
  elseif ($arg == 'my_download_count') {
    drupal_set_title(check_plain(variable_get('download_count_mypage_view_page_title', t('My Download Counts'))));
    $limit = (int) variable_get('download_count_mypage_view_page_limit', '');
    $file_links = variable_get('download_count_mypage_file_links', 1);

    if (!$limit) {
      $result = db_query("SELECT COUNT(dc.dcid) AS count, dc.dcid, f.filename, MAX(dc.timestamp) AS last, dc.nid, f.filepath, f.fid, n.title FROM {download_count} dc JOIN {files} f ON dc.fid = f.fid JOIN {node} n ON dc.nid = n.nid WHERE dc.uid = %d GROUP BY dc.nid, f.filename" . tablesort_sql($header), $user->uid);
    }
    else {
      $result = db_query("SELECT COUNT(dc.dcid) AS count, dc.dcid, f.filename, MAX(dc.timestamp) AS last, dc.nid, f.filepath, f.fid, n.title FROM {download_count} dc JOIN {files} f ON dc.fid = f.fid JOIN {node} n ON dc.nid = n.nid WHERE dc.uid = %d GROUP BY dc.nid, f.filename" . tablesort_sql($header) . " LIMIT %d", $user->uid, $limit);
    }
    $output = '<div id="my_download_count_page">';
  }

  $total_downloads = 0;
  $files = array();
  $nodes = array();
  $colspan = 0;

  while ($file = db_fetch_object($result)) {
    $row = array();
    $node = node_load($file->nid);
    $row[] = $file->count;
    $row[] = ($file_links && (user_access('view uploaded files') || _download_count_is_accessible_by_filefield($file->filepath))) ? l(t('@filename', array('@filename' => $file->filename)), function_exists('_private_upload_create_url') ? _private_upload_create_url($file) : file_create_url($file->filepath)) : $file->filename;
    $row[] = node_access('view', $node) ? l(t('@title', array('@title' => $node->title)), 'node/' . $node->nid) : check_plain($node->title);
    $row[] = t('@time ago', array('@time' => format_interval(time() - $file->last)));
    module_exists('download_count_statistics') && user_access('view download count statistics') ? $row[] = l(t('Details'), 'download_count/' . $file->dcid . '/details') : NULL;
    user_access('export download counts') ? $row[] = l(t('Export'), 'download_count/' . $file->dcid . '/export') : NULL;
    user_access('administer site configuration') ? $row[] = l(t('Reset'), 'download_count/' . $file->dcid . '/reset') : NULL;
    $rows[] = $row;

    $total_downloads += $file->count;
    $files[] = $file->filename;
    $nodes[] = $node->title;
    $colspan = count($rows[0]) - count($header);
  }

  if (empty($rows)) {
    $rows[] = array(array(
        'data' => t('No files have been downloaded.'),
        'colspan' => '4',
      ));
  }

  if ($colspan > 1) {
    $header[] = array(
      'data' => t('Action')
        . (user_access('export download counts') ? l(t(' (Export All)'), 'download_count/all/export') : NULL)
        . (user_access('administer site configuration') ? l(t(' (Reset All)'), 'download_count/all/reset') : NULL),
      'colspan' => $colspan,
    );
  }
  $output .= $arg == 'download_count' ? check_markup(variable_get('download_count_view_page_header', ''), variable_get('download_count_view_page_format', 0), FALSE) : check_markup(variable_get('download_count_mypage_view_page_header', ''), variable_get('download_count_mypage_view_page_format', 0), FALSE);
  $output .= '<span id="download_count_summary_top">' . t('Unique Pages: ') . count(array_unique($nodes)) . (', Unique Files: ') . count(array_unique($files)) . ', Total Downloads: ' . $total_downloads . '</span>';
  $output .= theme('table', $header, $rows, array('id' => 'download_count_table'));
  $output .= '<span id="download_count_summary_bottom">' . t('Unique Pages: ') . count(array_unique($nodes)) . (', Unique Files: ') . count(array_unique($files)) . ', Total Downloads: ' . $total_downloads . '</span>';
  $output .= $arg == 'download_count' ? check_markup(variable_get('download_count_view_page_footer', ''), variable_get('download_count_view_page_format', 0), FALSE) : check_markup(variable_get('download_count_mypage_view_page_footer', ''), variable_get('download_count_mypage_view_page_format', 0), FALSE);
  $output .= '</div>';

  return $output;
}

function download_count_reset_form($form_state, $dc_entry = array()) {
  $form = array();
  if ($dc_entry != 'all') {
    $form['dcid'] = array(
      '#type' => 'value',
      '#value' => $dc_entry['dcid'],
    );
    $form['filename'] = array(
      '#type' => 'value',
      '#value' => $dc_entry['filename'],
    );
    $form['fid'] = array(
      '#type' => 'value',
      '#value' => $dc_entry['fid'],
    );
    $form['nid'] = array(
      '#type' => 'value',
      '#value' => $dc_entry['nid'],
    );
    return confirm_form(
      $form,
      t('Are you sure you want to reset the download count for %filename?',
        array('%filename' => $dc_entry['filename'])
      ),
      'download_count',
      t('This action cannot be undone.'),
      t('Reset'),   t('Cancel')
    );
  }
  else {
    $form['dcid'] = array(
      '#type' => 'value',
      '#value' => 'all',
    );
    return confirm_form(
      $form,
      t('Are you sure you want to reset all download counts?'),
      'download_count',
      t('This action cannot be undone.'),
      t('Reset All'),   t('Cancel')
    );
  }
}

/**
 * Implementation of hook_submit().
 */
function download_count_reset_form_submit($form, &$form_state) {
  $result = NULL;
  if ($form['dcid']['#value'] == 'all') {
    if (module_exists('download_count_statistics')) {
      db_query('TRUNCATE TABLE {download_count_statistics}');
    }
    $result = db_query('TRUNCATE TABLE {download_count}');
    if ($result) {
      drupal_set_message(t('All download counts have been reset.'));
      watchdog('download_count', 'All download counts have been reset.', WATCHDOG_NOTICE);
    }
    else {
      drupal_set_message(t('Unable to reset all download counts.'), 'error');
      watchdog('download_count', 'Unable to reset all download counts.', WATCHDOG_ERROR);
    }
  }
  else {
    if (module_exists('download_count_statistics')) {
      db_query('DELETE FROM {download_count_statistics} WHERE fid = %d AND nid = %d', $form['fid']['#value'], $form['nid']['#value']);
    }
    $result = db_query('DELETE FROM {download_count} WHERE fid = %d AND nid = %d', $form['fid']['#value'], $form['nid']['#value']);
    if ($result) {
      drupal_set_message(t('Download count for %name was reset.', array('%name' => $form['filename']['#value'])));
      watchdog('download_count', 'Download count for %name was reset.', array('%name' => $form['filename']['#value']), WATCHDOG_NOTICE);
    }
    else {
      drupal_set_message(t('Unable to reset download count for %name.', array('%name' => $form['filename']['#value'])), 'error');
      watchdog('download_count', 'Unable to reset download count for %name.', array('%name' => $form['filename']['#value']), WATCHDOG_ERROR);
    }
  }
  $form_state['redirect'] = 'download_count';
}
