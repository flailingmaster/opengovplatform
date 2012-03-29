<?php

/**
 * @file
 * Administrative page callbacks for the download_count module.
 */

/**
 * Download_count administration settings.
 *
 * @return
 * Form for download_count configuration options.
 */
function download_count_admin_settings() {
  switch (variable_get('file_downloads', FILE_DOWNLOADS_PUBLIC)) {
    case FILE_DOWNLOADS_PUBLIC:
      $output = '<p>' . t('The site is configured to use the <i>public</i> download method (at <a href="/admin/settings/file-system">admin/settings/file-system</a>). In order for downloads to be counted, you must either use the <i>private</i> download method or protect one or more files directories as described at <a href="http://drupal.org/node/189239">http://drupal.org/node/189239</a> or <a href="http://drupal.org/node/540754">http://drupal.org/node/540754</a>. Only file paths prefixed with the "system" menu item will be counted.') . '</p>';
      break;
    case FILE_DOWNLOADS_PRIVATE:
      $output = '<p>' . t('The site is configured to use the <i>private</i> download method at <a href="admin/settings/file-system">admin/settings/file-system</a>.') . '</p>';
      break;
  }
  $output .= '<p>' . t('Also, don\'t forget to visit the permissions <a href="@page">page</a> to allow roles to view download counts.', array('@page' => url('admin/user/permissions'))) . '</p>';

  $form['help text'] = array(
    '#value' => $output,
  );
  $form['excluded file extensions'] = array(
    '#type' => 'fieldset',
    '#title' => t('Excluded file extensions'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['excluded file extensions']['download_count_excluded_file_extensions'] = array(
    '#type' => 'textfield',
    '#title' => t('Excluded file extensions'),
    '#default_value' => variable_get('download_count_excluded_file_extensions', 'jpg jpeg gif png'),
    '#maxlength' => 255,
    '#description' => t('This module only considers files that have been uploaded with the upload module and that become file attachments.  However, if you are using a contributed module to upload images and display them in the body of nodes, these files may get flagged as downloaded whenever a visitor or robot views the node page, because strictly speaking they are file attachments. This will happen with the module img_assist. Note that this won\'t happen with the module imce, because imce treats inline images as nodes. If you do not want to set a download count for image files, list their extension here. Separate extensions with a space and do not include the leading dot. For example, you could list these extensions&nbsp: jpg jpeg gif png. If you do not want to exclude any file, leave that field blank. '),
  );
  $form['download count page'] = array(
    '#type' => 'fieldset',
    '#title' => t('Download count page settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['download count page']['download_count_file_links'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display file names as links (based on permissions).'),
    '#default_value' => variable_get('download_count_file_links', 1),
  );
  $form['download count page']['download_count_view_page_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of items to display'),
    '#size' => 10,
    '#weight' => -1,
    '#default_value' => variable_get('download_count_view_page_limit', ''),
    '#description' => t('Leave blank for no limit.'),
  );
  $form['download count page']['download_count_view_page_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('download_count_view_page_title', t('Download Count')),
    '#description' => t('Title of this <a href="@page">page</a>.', array('@page' => url('download_count'))),
  );
  $form['download count page']['download_count_view_page_header'] = array(
    '#type' => 'textarea',
    '#title' => t('Header'),
    '#cols' => 60,
    '#rows' => 6,
    '#default_value' => variable_get('download_count_view_page_header', ''),
    '#description' => t('Text to appear between the title of the page and the download count table.'),
  );
  $form['download count page']['download_count_view_page_footer'] = array(
    '#type' => 'textarea',
    '#title' => t('Footer'),
    '#cols' => 60,
    '#rows' => 6,
    '#default_value' => variable_get('download_count_view_page_footer', ''),
    '#description' => t('Text to appear underneath the download count table.'),
  );
  $form['download count page']['download_count_view_page_format'] = filter_form(variable_get('download_count_view_page_format', 2), 0, array('download_count_view_page_format'));

  $form['my download count page'] = array(
    '#type' => 'fieldset',
    '#title' => t('My download count page settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['my download count page']['download_count_mypage_file_links'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display file names as links (based on permissions).'),
    '#default_value' => variable_get('download_count_mypage_file_links', 1),
  );
  $form['my download count page']['download_count_mypage_view_page_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of items to display'),
    '#size' => 10,
    '#weight' => -1,
    '#default_value' => variable_get('download_count_mypage_view_page_limit', ''),
    '#description' => t('Leave blank for no limit.'),
  );
  $form['my download count page']['download_count_mypage_view_page_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => variable_get('download_count_mypage_view_page_title', t('My Download Counts')),
    '#description' => t('Title of this <a href="@page">page</a>.', array('@page' => url('my_download_count'))),
  );
  $form['my download count page']['download_count_mypage_view_page_header'] = array(
    '#type' => 'textarea',
    '#title' => t('Header'),
    '#cols' => 60,
    '#rows' => 6,
    '#default_value' => variable_get('download_count_mypage_view_page_header', ''),
    '#description' => t('Text to appear between the title of the page and the download count table.'),
  );
  $form['my download count page']['download_count_mypage_view_page_footer'] = array(
    '#type' => 'textarea',
    '#title' => t('Footer'),
    '#cols' => 60,
    '#rows' => 6,
    '#default_value' => variable_get('download_count_mypage_view_page_footer', ''),
    '#description' => t('Text to appear underneath the download count table.'),
  );
  $form['my download count page']['download_count_mypage_view_page_format'] = filter_form(variable_get('download_count_mypage_view_page_format', 2), 0, array('download_count_mypage_view_page_format'));

  return system_settings_form($form);
}
