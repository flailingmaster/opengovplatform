<?php
/**
 * Return an array of the modules to be enabled when this profile is installed.
 *
 * To save time during installation, only enable module here that are either
 * required by Features or not included in any Commons features
 *
 * @return
 *   An array of modules to enable.
 */

function ogpl_communities_profile_modules() {
    $modules = array(

        //Default Drupal modules.
        'blog','color', 'comment','help','menu', 'taxonomy', 'dblog','profile',
        'search', 'tracker', 'php', 'path','contact','forum',

        //Other contrib modules
        'conditional_styles','features','pathauto','libraries','blockify','jquery_update','superfish','revisioning', 'skinr','token',
        //Views
        'views','views_bulk_operations', 'views_customfield','views_ui',
        // Ctools
        'ctools','page_manager','stylizer','ctools_custom_content',
        //OG modules
        'og','og_features','og_forum','og_invite_link','og_user_roles','og_access','og_views','comment_og','uuid',
        //node_export
        'node_export','node_export_features',
        'node_tools',
        //Panels
        'panels','panels_ipe','panels_mini','panels_export',
        //Features
        'community',
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
function ogpl_communities_profile_details() {
  $logo = '<a href="http://someurl.com" target="_blank"><img alt="Open Oovernment Platform" title="Open Oovernment Platform" src="./profiles/ogpl_communities/themes/ogplcommunities/images/logo.png"></img></a>';
  $description = st('Select this profile to install the Open Government Platform powering your community website.');
  $description .= '<br/>' . $logo;

  return array(
    'name' => 'OGPL Communities',
    'description' => $description,
  );
}

/**
 * Implementation of hook_profile_task_list().
 */
function ogpl_communities_profile_task_list(){
    // Need to finishes define stages of install and configure tasks
    // for now we can use use the 'profile' stage and set theme
    //$tasks['configure-ogpl'] = st('Configuring Communities');
    return $tasks;
}

/**
 * Implementation of hook_profile_tasks().
 */

function ogpl_communities_profile_tasks( &$task, $url) {
    if ($task == 'profile') {
        variable_set('theme_default', 'ogplcommunities');
    }
}