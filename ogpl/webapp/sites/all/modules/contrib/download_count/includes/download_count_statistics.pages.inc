<?php

/**
 * @file
 * Page callback file for the download_count_statistics module.
 */
function download_count_statistics_details_page($arg = NULL) {

  $header = array();
  $result = NULL;
  $fid = $arg['fid'];
  $filename = check_plain($arg['filename']);
  $total = db_result(db_query("SELECT SUM(count) from {download_count_statistics} WHERE fid = $fid"));
  drupal_set_title(t('Download Count Details - %filename', array('%filename' => $filename)));

  if (variable_get('download_count_statistics_sparklines', 0)) {
    $sparkline_type = check_plain(variable_get('download_count_statistics_sparkline_type', 'line'));
    $sparkline_min = check_plain(variable_get('download_count_statistics_sparkline_min', '0'));
    $sparkline_height = check_plain(variable_get('download_count_statistics_sparkline_height', '150px'));
    $sparkline_width = check_plain(variable_get('download_count_statistics_sparkline_width', '300px'));
    $sparkline_options = "{ chartRangeMin: '$sparkline_min', type: '$sparkline_type', width: '$sparkline_width', height: '$sparkline_height' }";
    $script  = "Drupal.behaviors.download_count_statistics = function (context) { ";
  }

  $output  = '<div id="download_count_statistics">';
  $output .= '<p>Total Downloads: ' . $total . '</p>';

  //daily statistics table
  if (variable_get('download_count_statistics_daily', 1)) {
    $caption = "Daily Statistics";
    $header[] = array(
      'data' => t('Day'),
      'field' => 'date',
      'sort' => 'desc',
      'class' => 'day',
    );
    $header[] = array(
      'data' => t('Count'),
      'field' => 'count',
      'class' => 'count',
    );

    $rows = array();
    $values = '[';
    $limit = check_plain(variable_get('download_count_statistics_daily_limit', 0));

    $result = db_query("SELECT * FROM {download_count_statistics} dcs WHERE dcs.fid = $fid ORDER BY datestamp DESC" . ($limit > 0 ? " LIMIT $limit" : NULL));
    while ($file = db_fetch_object($result)) {
      $row = array();
      $row[] = format_date($file->datestamp, 'custom', 'Y-m-d');
      $row[] = $file->count;
      $values .= $file->count . ',';
      $rows[] = $row;
    }
    $values .= ']';
    $output .= theme('table', $header, $rows, array('id' => 'download_count_statistics_weekly'), $caption);
    $output .= '<br />';

    if (variable_get('download_count_statistics_sparklines', 0)) {
      $output .= '<span class="download-count-sparkline-daily">' . t('Rendering Sparkline...') . '</span>';
      $script .= "\$('.download-count-sparkline-daily').sparkline($values, $sparkline_options);";
    }
  }

  //weekly statistics table
  if (variable_get('download_count_statistics_weekly', 1)) {
    $rows = array();
    $values = '[';
    $header[0] = array(
      'data' => t('Week'),
      'field' => 'date',
      'sort' => 'desc',
      'class' => 'week',
    );
    $caption = "Weekly Statistics";
    $first_day = variable_get('date_first_day', '0');
    if ($first_day == 0) {
      $mode = 3;
    }
    else {
      $mode = 6;
    }
    $limit = check_plain(variable_get('download_count_statistics_weekly_limit', 0));

    $result = db_query("SELECT *, SUM(count) as count, WEEK(DATE(FROM_UNIXTIME(datestamp)), $mode) as week FROM {download_count_statistics} dcs WHERE dcs.fid = $fid GROUP BY WEEK(DATE(FROM_UNIXTIME(datestamp)), $mode) ORDER BY datestamp DESC" . ($limit > 0 ? " LIMIT $limit" : NULL));
    while ($file = db_fetch_object($result)) {
      $row = array();
      $row[] = $file->week . ' (ending ' . date('l m-d-Y', strtotime('+6 days', strtotime(_download_count_statistics_week_start_date($file->week, date('Y', $file->datestamp), $first_day)))) . ')';
      $row[] = $file->count;
      $values .= $file->count . ',';
      $rows[] = $row;
    }
    $values .= ']';
    $output .= theme('table', $header, $rows, array('id' => 'download_count_statistics_montly'), $caption);
    $output .= '<br />';

    if (variable_get('download_count_statistics_sparklines', 0)) {
      $output .= '<span class="download-count-sparkline-weekly">' . t('Rendering Sparkline...') . '</span>';
      $script .= "\$('.download-count-sparkline-weekly').sparkline($values, $sparkline_options);";
    }
  }

  //monthly statistics table
  if (variable_get('download_count_statistics_monthly', 1)) {
    $rows = array();
    $values = '[';
    $header[0] = array(
      'data' => t('Month'),
      'field' => 'date',
      'sort' => 'desc',
      'class' => 'month',
    );
    $caption = "Monthly Statistics";
    $limit = check_plain(variable_get('download_count_statistics_monthly_limit', 0));

    $result = db_query("SELECT *, SUM(count) as count FROM {download_count_statistics} dcs WHERE dcs.fid = $fid GROUP BY MONTH(DATE(FROM_UNIXTIME(datestamp))) ORDER BY datestamp DESC" . ($limit > 0 ? " LIMIT $limit" : NULL));
    while ($file = db_fetch_object($result)) {
      $row = array();
      $row[] = format_date($file->datestamp, 'custom', 'Y-m');
      $row[] = $file->count;
      $values .= $file->count . ',';
      $rows[] = $row;
    }
    $values .= ']';
    $output .= theme('table', $header, $rows, array('id' => 'download_count_statistics_yearly'), $caption);
    $output .= '<br />';

    if (variable_get('download_count_statistics_sparklines', 0)) {
      $output .= '<span class="download-count-sparkline-monthly">' . t('Rendering Sparkline...') . '</span>';
      $script .= "\$('.download-count-sparkline-monthly').sparkline($values, $sparkline_options);";
    }
  }

  //yearly statistics table
  if (variable_get('download_count_statistics_yearly', 1)) {
    $rows = array();
    $values = '[';
    $header[0] = array(
      'data' => t('Year'),
      'field' => 'date',
      'sort' => 'desc',
      'class' => 'year',
    );
    $caption = "Yearly Statistics";
    $limit = check_plain(variable_get('download_count_statistics_yearly_limit', 0));

    $result = db_query("SELECT *, SUM(count) as count FROM {download_count_statistics} dcs WHERE dcs.fid = $fid GROUP BY YEAR(DATE(FROM_UNIXTIME(datestamp))) ORDER BY datestamp DESC" . ($limit > 0 ? " LIMIT $limit" : NULL));
    while ($file = db_fetch_object($result)) {
      $row = array();
      $row[] = format_date($file->datestamp, 'custom', 'Y');
      $row[] = $file->count;
      $values .= $file->count . ',';
      $rows[] = $row;
    }
    $values .= ']';
    $output .= theme('table', $header, $rows, array('id' => 'download_count_statistics_daily'), $caption);

    if (variable_get('download_count_statistics_sparklines', 0)) {
      $output .= '<span class="download-count-sparkline-yearly">' . t('Rendering Sparkline...') . '</span>';
      $script .= "\$('.download-count-sparkline-yearly').sparkline($values, $sparkline_options);";
    }
  }

  //rest of page
  if (variable_get('download_count_statistics_sparklines', 0)) {
    $script .= "};";
    drupal_add_js($script, 'inline');
  }
  $output .= '<hr>';
  $output .= '<br />' . l(t('Return to download count page.'), 'download_count');
  $output .= '</div>';

  return $output;
}

// from: http://stackoverflow.com/questions/1897727/get-first-day-of-week-in-php
function _download_count_statistics_week_start_date($week, $year, $first = 1, $format = 'F d, Y') {
  $week  = strtotime('+' . $week . ' weeks', strtotime($year . '0101'));
  $month = strtotime('-' . date('w', $week) + $first . ' days', $week);
  return date($format, $month);
}
