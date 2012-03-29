<?php

/**
 * Returns the rendered logo.
 *
 * @ingroup themeable
 */
function theme_blockify_logo($logo_path) {
  $site_name = filter_xss_admin(variable_get('site_name', 'Drupal'));

  // Strip the base_path from the beginning of the logo path.
  $path = preg_replace('|^' . base_path() . '|', '', $logo_path);

  $image = theme('image', $path, t('!site_name logo', array(
    '!site_name' => $site_name,
  )));

  return l($image, '<front>', array(
    'html' => TRUE,
    'attributes' => array(
      'id' => 'logo',
      'rel' => 'home',
      'title' => t('Return to the !site_name home page', array(
        '!site_name' => $site_name,
      )),
    ),
  ));
}

/**
 * Returns the rendered site name.
 *
 * @ingroup themeable
 */
function theme_blockify_site_name($site_name) {
  $title = drupal_get_title();

  // If there is no page title set for this page, use an h1 for the site name.
  $tag = ($title !== '') ? 'span' : 'h1';

  return '<' . $tag . ' class="site-name">' . $site_name . '</' . $tag . '>';
}

/**
 * Returns the rendered site slogan.
 *
 * @ingroup themeable
 */
function theme_blockify_site_slogan($site_slogan) {
  return '<span class="site-slogan">' . $site_slogan . '</span>';
}

/**
 * Returns the rendered mission.
 *
 * @ingroup themeable
 */
function theme_blockify_mission($site_mission) {
  return '<span class="mission">' . $site_mission . '</span>';
}

/**
 * Returns the rendered footer message.
 *
 * @ingroup themeable
 */
function theme_blockify_footer_message($site_footer) {
  return '<span class="footer-message">' . $site_footer . '</span>';
}

/**
 * Returns the rendered page title.
 *
 * @ingroup themeable
 */
function theme_blockify_page_title($page_title) {
  if ($page_title !== '') {
    return '<h1>' . $page_title . '</h1>';
  }
}

/**
 * Returns the rendered breadcrumb.
 *
 * @ingroup themeable
 */
function theme_blockify_breadcrumb($page_breadcrumb) {
  return theme('breadcrumb', $page_breadcrumb);
}

/**
 * Returns the rendered node details.
 *
 * This block can be used to render details for the current node and author
 * object outside of the node container.
 *
 * @ingroup themeable
 */
function theme_blockify_node($user, $node) {
  $items = array(
    'username' => theme('username', $user),
    'submitted' => theme('node_submitted', $node),
  );
  return theme('item_list', $items, t('Node details'));
}
