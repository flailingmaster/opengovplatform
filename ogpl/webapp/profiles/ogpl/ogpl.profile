<?php

// Define the default WYSIWYG editor
define('OGPL_EDITOR', 'tinymce');

// Define the default theme
define('DMS_DEFAULT_THEME', 'dms');

/**
 * Return an array of the modules to be enabled when this profile is installed.
 *
 * To save time during installation, only enable module here that are either
 * required by Features or not included in any Commons features
 *
 * @return
 *   An array of modules to enable.
 */

function ogpl_profile_modules() {
    $modules = array(
        'block',
        'filter',
        'node',
        'system',
        'user',

        'color',
        'comment',
        'dblog',
        'help',
        'locale',
        'menu',
        'path',
        'search',
        'statistics',
        'syslog',
        'taxonomy',
        'trigger',
        'update',
        'upload',

        'administerusersbyrole',
        'admin_menu',
        'admin_theme',
        'advanced_help',
        'agency_wise_metrics',
        'aggregator',
        'ahah_response',
        'apachesolr',
        'apachesolr_autocomplete',
        'apachesolr_exclude',
        'apachesolr_nodeaccess',
        'apachesolr_nodereference',
        'apachesolr_search',
        'assigneewise_feedback_listing_urm',
        'autologout',
        'auto_nodetitle',
        'better_formats',
        'blockify',
        'bulk_export',
	'calendar',
        'calendar_ical',
        'calendar_multiday',
        'captcha',
        'catalog_home_tabs',
        'cckformsettings',
        'clientside_validation',
        'clientside_validation_fapi',
        'clientside_validation_form',
        'cms_apachesolr_config',
        'cms_customizations',
        'cms_notify_email',
        'cms_themes_file_uploader',
        'cms_views',
        'cms_workflow_alter',
        'cms_workflow_summary',
        'commentformsettings',
        'content',
        'content_copy',
        'content_permissions',
        'content_profile',
        'content_profile_registration',
        'content_profile_tokens',
        'content_taxonomy',
        'content_taxonomy_options',
        'ctools',
	'context',
        'context_layouts',
        'context_ui',
	'conditional_fields',
        'conditional_styles',
        'date',
        'date_api',
        'date_locale',
        'date_php4',
        'date_popup',
        'date_repeat',
        'date_timezone',
        'date_tools',
        'devel',
        'devel_node_access',
	/*'devel_themer',
        'dms_customizations',
        'dms_ds_upload',
        'dms_save_settings',*/
        'download_by_category_organisation',
        'download_count',
        'download_count_statistics',
        'download_file',
        'dynamic_views_for_the_what_s_new_page',
        'email',
        'email_registration',
        'extlink',
        'fapi_validation',
        'faq',
        'featured_gallery',
        'features',
        'feedback_category',
        'feedback_category_listing_urm',
        'fe_block',
        'fe_taxonomy',
        'fieldgroup',
        'filefield',
	'fivestar',
	'libraries',
        'flexifield',
        'flexifield_displaycontexts',
        'flexifield_fieldgroup',
        'flexifield_filefield',
        'flowplayer',
        'flowplayer3',
        /*'mp3player',
        'filefieldmp3player',*/
	'footermenus',
        'front_end_major_events_tab',
        'front_footer_menu',
        'front_page',
        'fusioncharts',
        'hacked',
        'home_page_panels',
        'ie6update',
        'imageapi',
        'imageapi_gd',
        'imagecache',
        'imagecache_ui',
        'imagefield',
        'image_captcha',
        'imce',
        'imce_wysiwyg',
        'jammer',
        'jammer_generic',
        'jcalendar',
        'jquery_plugin',
        'jquery_ui',
        'jquery_update',
        'libraries',
        'link',
        'list_of_datasets',
        'location',
        'logintoboggan',
        'logintoboggan_rules',
        'login_destination',
        'main_menus',
        'markup',
        'mass_change',
        'menu_perms',
        'menu_per_role',
        'metrics_visitor_stats_reports',
        'module_grants',
        'month_wise_metrics',
        'month_wise_metrics_per_year',
        'more_node_buttons',
        'multistep',
        'nice_menus',
        'nodeaccess_userreference',
        'nodeblock',
        'nodeformsettings',
        'nodereference',
        'nodewords',
        'nodewords_basic',
        'nodewords_extra',
        'node_expiry_alert',
        'node_tools',
        'number',
        'number_of_views_report',
        'open_data_site_view_and_content_types',
        'optionwidgets',
        'ownerwise_feedback_stat',
        'panels',
        'panels_ipe',
        'panels_mini',
        'password_policy',
        'pathauto',
        'pet',
        'php',
        'pngfix',
        'poormanscron',
        'print_mail',
        'print_pdf',
        'quicktabs',
        'rate',
        'rate_expiration',
        'rate_slider',
        'realname',
        'recaptcha',
        'recent_ideas_view',
        'revisioning',
        'revisioning_scheduler',
        'role_delegation',
        'role_theme_switcher',
        'rotating_panel',
        'rotating_panel_half',
        'rss_feed_views',
        'rules',
        'rules_admin',
        'rules_forms',
        'rules_scheduler',
        'schema',
        'search404',
        'site_map',
	/*'sitemap_menus',*/
        'skinr',
        'strongarm',
        'stylizer',
        'suggested_datasets_and_apps',
        'superfish',
        'swfobject',
        'swftools',
        'text',
        'textsize',
        /*'themer',*/
        'token',
        'tokenSTARTER',
        'token_actions',
        'token_filter',
        'tw',
        'tw_import_delimited',
        'unique_field',
        'unlimited_css',
        'uploadfield',
        'userprotect',
        'userreference',
        'user_management',
        'video',
        'video_field_for_faq',
        'views',
	'reverse_node_reference',
        'views_block',
        'views_bulk_operations',
        'views_customfield',
        'views_data_export',
        'views_display_block_path',
        'views_embed_form',
        'views_export',
        'views_filters_autosubmit',
        'views_for_the_what_s_new_page',
        'views_fusioncharts',
        'views_groupby',
        'views_or',
        'views_php',
        'views_slideshow',
        'views_slideshow_imageflow',
        'views_slideshow_singleframe',
        'views_slideshow_thumbnailhover',
        'views_ui',
	'better_exposed_filters',
        'votingapi',
        'vrm_customization',
        'vrm_custom_comment',
        'vrm_feedback_history',
        'vrm_feedback_reply',
        'vrm_feedback_type',
        'vrm_tabs',
        'vrm_views',
        'vrm_workflow_states_description',
        'webform',
        'web_captcha_alter',
        'web_catalogs_search',
        'web_charts_export',
        'web_contact_owner',
        'web_embed_code',
        'web_feed_aggregator',
        'web_filefield_icons',
        'web_metrics_report',
        'web_print',
        'web_site_config',
        'web_tellafriend',
        'web_views_query_alter',
        'what_s_new',
        'what_s_new_placeholder_for_pages',
        'workflow',
        'workflow_access',
        'workflow_customizations',
        'workflow_email_notification',
        'workflow_extensions',
        'workflow_node_revisions',
        'wysiwyg', 
    );
    return $modules;
}

/**
 * Return a description of the profile for the initial installation screen.
 *
 * @return
 *   An array with keys 'name' and 'description' describing this profile,
 *   and optional 'language' to override the language selection for
 *   language-specific profiles.
 */
function ogpl_profile_details() {
  $logo = '<a href="http://someurl.com" target="_blank"><img alt="Open Oovernment Platform" title="Open Oovernment Platform" src="./profiles/ogpl/themes/dms/logo.png"/></a>';
  $description = st('Select this profile to install the Open Government Platform powering your community website.');
  $description .= '<br/>' . $logo;

  return array(
    'name' => 'OGPL',
    'description' => $description,
  );
}
/**
 * Return a list of tasks that this profile supports.
 *
 * @return
 *   A keyed array of tasks the profile will perform during
 *   the final stage. The keys of the array will be used internally,
 *   while the values will be displayed to the user in the installer
 *   task list.
 */
function ogpl_profile_task_list() {
    return array(
   	'profile-import-table-data' => st('Import profile data') 
    );
}

function ogpl_profile_tasks(&$task, $url) {
    //if ($task == 'profile-import-table-data') {
	
	//module_enable($module_list);
	ogpl_run_sql();
    //}
}

function ogpl_run_sql() {

    $current_dir = dirname(__FILE__); 
    $sql_path = $current_dir.'/sql/';
    $files = scandir($current_dir.'/sql/');
    foreach($files as $file)
    {
        if ( substr($file, -4) == '.sql') {
        	$sql = file_get_contents($sql_path.$file);
		if (0 == strlen(trim($sql))) continue;
		$queries = explode("\n", $sql);
		foreach($queries as $query) { 
			if(trim($query) != '')
        			db_query($query);
		}
	}
    }
}
