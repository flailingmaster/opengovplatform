<?php // $Id$

function send_template_load($stid) {
  $template = db_fetch_object(db_query("SELECT * FROM {send_template} WHERE stid = %d", $stid));
  if (is_array($settings = unserialize($template->settings))) {
    foreach ($settings as $key => $val) {
      $template->$key = $val;
    }
  }
  return $template;
}

function send_template_admin_overview() {
  $hdrs = array(
    'name' => array('data' => t('Name'), 'field' => 'name', 'sort' => 'asc'),
    'status' => array('data' => t('Status'), 'field' => 'status'),
    'ops' => array('data' => t('Operations')),
  );

  if ($templates = send_template_list(NULL, FALSE, 0, $hdrs)) {
    $rows = array();
    foreach ($templates as $row) {
      $rows[] = array(
        $row->name,
        $row->status ? t('active') : t('disabled'),
        l(t('edit'), $_GET['q'] .'/'. $row->stid .'/edit', array('query' => 'destination='. $_GET['q'])),
      );
    }
    return theme('table', $hdrs, $rows);
  }

  // Create a default template form.
  return drupal_get_form('send_template_form');
}

function send_template_form($form_state, $stid = NULL) {
  $template = NULL;
  if ($stid) $template = send_template_load($stid);
  $form = array('#send_template' => $template);
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Template name'),
    '#length' => 30,
    '#default_value' => $template ? $template->name : '',
  );
  $form['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#length' => 30,
    '#default_value' => $template ? $template->status : 1,
  );
  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Message subject'),
    '#length' => 30,
    '#default_value' => $template ? $template->subject : '',
  );
  $form['subject_editable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Subject is editable'),
    '#default_value' => $template->subject_editable,
  );
  $build_modes = send_template_build_modes();
  if (module_exists('token')) {
    $build_modes[] = t("None, I'll add the node tokens myself");
  }

  $form['build_mode'] = array(
    '#type' => 'select',
    '#title' => t('Node listing'),
    '#length' => 30,
    '#options' => $build_modes,
    '#default_value' => $template ? $template->build_mode : 'teaser',
  );
  $form['build_mode_editable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Node listing mode is editable'),
    '#default_value' => $template->build_mode_editable,
  );

  $form['body_filter']['body'] = array(
    '#type' => 'textarea',
    '#rows' => 20,
    '#cols' => 20,
    '#title' => t('Message layout'),
    '#default_value' => $template ? $template->body : "%message\n%body",
    '#description' => t("This template controls the appearance of HTML messages.  You can use the tokens %body and %message to place message content and include additional HTML, images and styles to format messages.")
  );
  $form['body_editable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Body is editable'),
    '#default_value' => $template->body_editable,
  );

  $format = $template ? $template->format : FILTER_FORMAT_DEFAULT;
  $form['body_filter']['format'] = filter_form($format);

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
  );

  return $form;
}

function send_template_form_validate($form, &$form_state) {
}

function send_template_form_submit($form, &$form_state) {
  $schema = drupal_get_schema('send_template');
  $template = $form['#send_template'];
  $template->name = check_plain($form_state['values']['name']);
  $template->status = $form_state['values']['status'];
  $template->subject = $form_state['values']['subject'];
  $template->body = $form_state['values']['body'];
  $template->format = $form_state['values']['format'];
  $template->settings = array();
  foreach ($form_state['values'] as $key => $val) {
    if (!isset($schema['fields'][$key])) {
      $template->settings[$key] = $val;
    }
  }

  $update = isset($template->stid) ? 'stid' : NULL;
  drupal_write_record('send_template', $template, $update);

  unset($form_state['rebuild'], $form_state['storage']);
  $form_state['redirect'] = 'admin/settings/send';
}

function send_template_list($profile = NULL, $active_only = TRUE, $limit = 0, $sort = array()) {
  $templates = array();

  $sql = array("SELECT * FROM {send_template}");

  if ($limit) {
    $sql[] = $limit;
    $sql[] = 1;
    $sql[] = NULL;
  }

  if ($active_only) {
    $sql[0] .= " WHERE status = 1";
  }
  $sql[0] = db_rewrite_sql($sql[0] . tablesort_sql($sort), 'send_template');

  if ($pager_limit) {
    $res = call_user_func_array('pager_query', $sql);
  }
  else {
    $res = call_user_func_array('db_query', $sql);
  }

  while ($row = db_fetch_object($res)) {
    $templates[$row->stid] = $row;
  }

  return $templates;
}

/**
 * A helper function returning a list of node build_modes.
 */
function send_template_build_modes() {
  static $build_modes;
  if (!isset($build_modes)) {
    $build_modes = array();

    // CCK is installed, use its hooks.
    if (function_exists('content_build_modes')) {
      foreach (content_build_modes() as $name => $info) {
        $build_modes[$name] = $info['title'];
      }
    }

    // Set generic defaults.
    else {
      $build_modes['teaser'] = t('Teaser');
      $build_modes['full'] = t('Full node');
    }
  }
  return $build_modes;
}

