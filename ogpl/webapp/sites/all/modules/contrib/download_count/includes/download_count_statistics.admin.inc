<?php

/**
 * @file
 * Administrative page callbacks for the download_count_statistics module.
 */

/**
 * Download_count_statistics administration settings.
 *
 * @return
 * Form for download_count_statistics configuration options.
 */
function download_count_statistics_admin_settings() {
  $output = '<p>' . t('Don\'t forget to visit the permissions <a href="@page">page</a> to allow the desired roles to view the download count statistics.', array('@page' => url('admin/user/permissions'))) . '</p>';

  $form['help text'] = array(
    '#value' => $output,
  );
  $form['daily'] = array(
    '#type' => 'fieldset',
    '#title' => t('Daily Statistics'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['daily']['download_count_statistics_daily'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable daily download counts on the statistics page.'),
    '#default_value' => variable_get('download_count_statistics_daily', 1),
  );
  $form['daily']['download_count_statistics_daily_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Item Limit'),
    '#size' => 8,
    '#default_value' => variable_get('download_count_statistics_daily_limit', '0'),
    '#description' => 'The maximum number of items to display. Use 0 for unlimited.',
  );
  $form['weekly'] = array(
    '#type' => 'fieldset',
    '#title' => t('Weekly Statistics'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['weekly']['download_count_statistics_weekly'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable weekly download counts on the statistics page.'),
    '#default_value' => variable_get('download_count_statistics_weekly', 1),
  );
  $form['weekly']['download_count_statistics_weekly_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Item Limit'),
    '#size' => 8,
    '#default_value' => variable_get('download_count_statistics_daily_weekly', '0'),
    '#description' => 'The maximum number of items to display. Use 0 for unlimited.',
  );
  $form['monthly'] = array(
    '#type' => 'fieldset',
    '#title' => t('Monthly Statistics'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['monthly']['download_count_statistics_monthly'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable monthly download counts on the statistics page.'),
    '#default_value' => variable_get('download_count_statistics_monthly', 1),
  );
  $form['monthly']['download_count_statistics_monthly_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Item Limit'),
    '#size' => 8,
    '#default_value' => variable_get('download_count_statistics_monthly_limit', '0'),
    '#description' => 'The maximum number of items to display. Use 0 for unlimited.',
  );
  $form['yearly'] = array(
    '#type' => 'fieldset',
    '#title' => t('Yearly Statistics'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['yearly']['download_count_statistics_yearly'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable yearly download counts on the statistics page.'),
    '#default_value' => variable_get('download_count_statistics_yearly', 1),
  );
  $form['yearly']['download_count_statistics_yearly_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Item Limit'),
    '#size' => 8,
    '#default_value' => variable_get('download_count_statistics_yearly_weekly', '0'),
    '#description' => 'The maximum number of items to display. Use 0 for unlimited.',
  );
  $form['sparklines'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sparkline Options'),
    '#description' => is_file(drupal_get_path('module', 'download_count_statistics') . '/jquery.sparkline.min.js') ? t('The jquery sparkline plugin is available at: ') . drupal_get_path('module', 'download_count_statistics') . '/jquery.sparkline.min.js' : '<em><span style="color: #A50000;">' . t('This option requires the jquery.sparkline.min.js plugin which is unavailable-- you can download it at <a href="http://omnipotent.net/jquery.sparkline">http://omnipotent.net/jquery.sparkline</a> (just copy the file to the download_count module directory).') . '</span></em>',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['sparklines']['download_count_statistics_sparklines'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable sparkline graphs on the statistics page.'),
    '#default_value' => !is_file(drupal_get_path('module', 'download_count_statistics') . '/jquery.sparkline.min.js') ? 0 : variable_get('download_count_statistics_sparklines', 1),
    '#disabled' => !is_file(drupal_get_path('module', 'download_count_statistics') . '/jquery.sparkline.min.js'),
  );
  $form['sparklines']['download_count_statistics_sparkline_type'] = array(
    '#type' => 'select',
    '#title' => t('Sparkline Type'),
    '#default_value' => variable_get('download_count_statistics_sparkline_type', 'line'),
    '#options' => array(
      'line' => t('Line'),
      'bar' => t('Bar'),
    ),
    '#disabled' => !is_file(drupal_get_path('module', 'download_count_statistics') . '/jquery.sparkline.min.js'),
    '#description' => 'Specify line or bar graph type.',
  );
  $form['sparklines']['download_count_statistics_sparkline_min'] = array(
    '#type' => 'textfield',
    '#title' => t('Chart Minimum Value'),
    '#size' => 8,
    '#default_value' => variable_get('download_count_statistics_sparkline_min', '0'),
    '#disabled' => !is_file(drupal_get_path('module', 'download_count_statistics') . '/jquery.sparkline.min.js'),
    '#description' => 'Specify the minimum value to use for the range of the chart (starting point).',
  );
  $form['sparklines']['download_count_statistics_sparkline_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Chart Height'),
    '#size' => 8,
    '#default_value' => variable_get('download_count_statistics_sparkline_height', '150px'),
    '#disabled' => !is_file(drupal_get_path('module', 'download_count_statistics') . '/jquery.sparkline.min.js'),
    '#description' => 'The height of the sparkline graph. May be any valid css height (ie 1.5em, 20px, etc). Must include units.',
  );
  $form['sparklines']['download_count_statistics_sparkline_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Chart Width'),
    '#size' => 8,
    '#default_value' => variable_get('download_count_statistics_sparkline_width', '300px'),
    '#disabled' => !is_file(drupal_get_path('module', 'download_count_statistics') . '/jquery.sparkline.min.js'),
    '#description' => 'The width of the sparkline graph. May be any valid css width (ie 1.5em, 20px, etc). Must include units.',
  );

  return system_settings_form($form);
}
