<?php
//truncate the cache tables and reset the ip in the database
// Establish a connection to the database.
  // require_once 'includes/database.inc';
   // db_set_active();
	include_once('includes/bootstrap.inc');
	drupal_bootstrap(DRUPAL_BOOTSTRAP_DATABASE); 

	$sql='TRUNCATE cache';
	db_query($sql);
	db_query("TRUNCATE cache_apachesolr");
	db_query("TRUNCATE cache_block");
	db_query("TRUNCATE cache_content");
	db_query("TRUNCATE cache_filter");
	db_query("TRUNCATE cache_form");
	db_query("TRUNCATE cache_menu");
	db_query("TRUNCATE cache_page");
	db_query("TRUNCATE cache_rules");
	db_query("TRUNCATE cache_update");
	db_query("TRUNCATE cache_views");
	db_query("TRUNCATE cache_views_data");
	db_query("TRUNCATE watchdog");

	db_query("UPDATE variable SET value = 's:0:\"\";' WHERE CONVERT(variable.name USING utf8 ) = 'super_admin_ip' LIMIT 1");
	echo("done");