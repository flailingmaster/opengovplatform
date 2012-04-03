<?php
// $Id$

/**
 * @file
 * An example installation profile that uses a database dump to recreate a
 * Drupal site rather than API function calls of a traditional installation
 * profile.
 */

/**
 * Name of profile; visible in profile selection form.
 */
define('OGPL_PROFILE_NAME', 'ogpl');

/**
 * Description of profile; visible in profile selection form.
 */
define('OGPL_PROFILE_DESCRIPTION', 'This is your ogpl that you built from a base distribution at one time.');

/**
 * Implementation of hook_profile_modules().
 */
function ogpl_profile_modules() {
  // The database dump will take care of enabling the required modules for us.
  // Return an empty array to just enable the required modules.
  return array();
}

/**
 * Implementation of hook_profile_details().
 */
function ogpl_profile_details() {
  return array(
    'name' => OGPL_PROFILE_NAME,
    'description' => OGPL_PROFILE_DESCRIPTION,
  );
}

/**
 * Implementation of hook_profile_form_alter().
 */
function ogpl_form_alter(&$form, $form_state, $form_id) {
  // Add an additional submit handler. 
  if ($form_id == 'install_configure') {
    $form['#submit'][] = 'ogpl_form_submit';
  }
}

/**
 * Custom form submit handler for configuration form.
 *
 * Drops all data from existing database, imports database dump, and restores
 * values entered into configuration form.
 */
function ogpl_form_submit($form, &$form_state) {
  // Import database dump file.
  $ogpl_file = 'profiles/ogpl/ogpl.mysql';
  $success = import_ogpl($ogpl_file);

  if (!$success) {
    return;
  }

  // Now re-set the values they filled in during the previous step.
  variable_set('site_name', $form_state['values']['site_name']);
  variable_set('site_mail', $form_state['values']['site_mail']);
  variable_set('date_default_timezone', $form_state['values']['date_default_timezone']);
  variable_set('clean_url', $form_state['values']['clean_url']);
  variable_set('update_status_module', $form_state['values']['update_status_module']);

  // Perform additional clean-up tasks.
  variable_del('file_directory_temp');

  // Replace their username and password and log them in.
  $name = $form_state['values']['account']['name'];
  $pass = $form_state['values']['account']['pass'];
  $mail = $form_state['values']['account']['mail'];
  db_query("UPDATE {users} SET name = '%s', pass = MD5('%s'), mail = '%s' WHERE uid = 1", $name, $pass, $mail);
  user_authenticate(array('name' => $name, 'pass' => $pass));

  // Finally, redirect them to the front page to show off what they've done.
  drupal_goto('<front>');
}

/// The rest is copy/paste/modify code from demo module. ///

/**
 * Imports a database dump file.
 *
 * @see demo_reset().
 */
function import_ogpl($filename) {
  // Open dump file.
  if (!file_exists($filename) || !($fp = fopen($filename, 'r'))) {
    drupal_set_message(t('Unable to open dump file %filename.', array('%filename' => $filename)), 'error');
    return FALSE;
  }

  // Drop all existing tables.
  foreach (ogpl_list_tables() as $table) {
    db_query("DROP TABLE %s", $table);
  }

  // Load data from dump file.
  $success = TRUE;
  $query = '';
  $new_line = TRUE;

  while (!feof($fp)) {
    // Better performance on PHP 5.2.x when leaving out buffer size to
    // fgets().
    $data = fgets($fp);
    if ($data === FALSE) {
      break;
    }
    // Skip empty lines (including lines that start with a comment).
    if ($new_line && ($data == "\n" || !strncmp($data, '--', 2) || !strncmp($data, '#', 1))) {
      continue;
    }

    $query .= $data;
    $len = strlen($data);
    if ($data[$len - 1] == "\n") {
      if ($data[$len - 2] == ';') {
        // Reached the end of a query, now execute it.
        if (!_db_query($query, FALSE)) {
          $success = FALSE;
        }
        $query = '';
      }
      $new_line = TRUE;
    }
    else {
      // Continue adding data from the same line.
      $new_line = FALSE;
    }
  }
  fclose($fp);

  if (!$success) {
    drupal_set_message(t('Failed importing database from %filename.', array('%filename' => $filename)), 'error');
  }

  return $success;
}

/**
 * Returns a list of tables in the active database.
 *
 * Only returns tables whose prefix matches the configured one (or ones, if
 * there are multiple).
 *
 * @see demo_enum_tables()
 */
function ogpl_list_tables() {
  global $db_prefix;

  $tables = array();

  if (is_array($db_prefix)) {
    // Create a regular expression for table prefix matching.
    $rx = '/^' . implode('|', array_filter($db_prefix)) . '/';
  }
  else if ($db_prefix != '') {
    $rx = '/^' . $db_prefix . '/';
  }

  switch ($GLOBALS['db_type']) {
    case 'mysql':
    case 'mysqli':
      $result = db_query("SHOW TABLES");
      break;

    case 'pgsql':
      $result = db_query("SELECT table_name FROM information_schema.tables WHERE table_schema = '%s'", 'public');
      break;
  }

  while ($table = db_fetch_array($result)) {
    $table = reset($table);
    if (is_array($db_prefix)) {
      // Check if table name matches a configured prefix.
      if (preg_match($rx, $table, $matches)) {
        $table_prefix = $matches[0];
        $plain_table = substr($table, strlen($table_prefix));
        if ($db_prefix[$plain_table] == $table_prefix || $db_prefix['default'] == $table_prefix) {
          $tables[] = $table;
        }
      }
    }
    else if ($db_prefix != '') {
      if (preg_match($rx, $table)) {
        $tables[] = $table;
      }
    }
    else {
      $tables[] = $table;
    }
  }

  return $tables;
}
