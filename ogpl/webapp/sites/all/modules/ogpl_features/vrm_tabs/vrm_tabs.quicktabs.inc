<?php

/**
 * Implementation of hook_quicktabs_default_quicktabs().
 */
function vrm_tabs_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass;
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'poc_tabs_list';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = 0;
  $quicktabs->default_tab = FALSE;
  $quicktabs->title = 'POC tabs List';
  $quicktabs->tabs = array(
    0 => array(
      'machine_name' => 'vrm_poc_tabs_list',
      'title' => 'List',
      'weight' => '-100',
      'type' => 'qtabs',
    ),
    1 => array(
      'vid' => 'vrmadmin_status_description',
      'display' => 'default',
      'args' => '',
      'get_displays' => 'vdisp_1',
      'title' => 'Status',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->style = 'default';
  $export['poc_tabs_list'] = $quicktabs;

  $quicktabs = new stdClass;
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'vrm_admin_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = 0;
  $quicktabs->default_tab = FALSE;
  $quicktabs->title = 'Vrm Admin Tabs';
  $quicktabs->tabs = array(
    0 => array(
      'machine_name' => 'vrm_admin_tabs_list',
      'title' => 'List',
      'weight' => '-100',
      'type' => 'qtabs',
    ),
    1 => array(
      'machine_name' => 'vrm_manage_actions',
      'title' => 'Manage Actions',
      'weight' => '-98',
      'type' => 'qtabs',
    ),
    2 => array(
      'machine_name' => 'vrm_manage_categories',
      'title' => 'Manage Categories',
      'weight' => '-97',
      'type' => 'qtabs',
    ),
    3 => array(
      'machine_name' => 'vrm_admin_tabs_delay_time',
      'title' => 'Manage Delay Time',
      'weight' => '-96',
      'type' => 'qtabs',
    ),
    4 => array(
      'machine_name' => 'vrm_admin_tabs_status',
      'title' => 'Status',
      'weight' => '-95',
      'type' => 'qtabs',
    ),
  );
  $quicktabs->style = 'nostyle';
  $export['vrm_admin_tabs'] = $quicktabs;

  $quicktabs = new stdClass;
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'vrm_admin_tabs_delay_time';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = 0;
  $quicktabs->default_tab = FALSE;
  $quicktabs->title = 'Vrm Admin Tabs Delay Time';
  $quicktabs->tabs = array(
    0 => array(
      'path' => 'manage/delay/time',
      'title' => 'Manage Delay Time',
      'weight' => '-100',
      'type' => 'callback',
    ),
    1 => array(
      'vid' => 'vrm_admin_actions_log',
      'display' => 'page_3',
      'args' => '',
      'get_displays' => 'vdisp_1',
      'title' => 'History',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->style = 'default';
  $export['vrm_admin_tabs_delay_time'] = $quicktabs;

  $quicktabs = new stdClass;
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'vrm_admin_tabs_list';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = 0;
  $quicktabs->default_tab = TRUE;
  $quicktabs->title = 'Vrm Admin Tabs List';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_1',
      'args' => '',
      'get_displays' => 'vdisp_0',
      'title' => 'All',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_7',
      'args' => '',
      'get_displays' => 'vdisp_1',
      'title' => 'My List',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_3',
      'args' => '',
      'get_displays' => 'vdisp_2',
      'title' => 'Opened',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_4',
      'args' => '',
      'get_displays' => 'vdisp_3',
      'title' => 'Assigned',
      'weight' => '-97',
      'type' => 'view',
    ),
    4 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_5',
      'args' => '',
      'get_displays' => 'vdisp_4',
      'title' => 'Replied',
      'weight' => '-96',
      'type' => 'view',
    ),
    5 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_6',
      'args' => '',
      'get_displays' => 'vdisp_5',
      'title' => 'Reviewed',
      'weight' => '-95',
      'type' => 'view',
    ),
    6 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_13',
      'args' => '',
      'get_displays' => 'vdisp_6',
      'title' => 'Reverted',
      'weight' => '-94',
      'type' => 'view',
    ),
    7 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_16',
      'args' => '',
      'get_displays' => 'vdisp_7',
      'title' => 'Closed',
      'weight' => '-93',
      'type' => 'view',
    ),
    8 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_15',
      'args' => '',
      'get_displays' => 'vdisp_8',
      'title' => 'Archived',
      'weight' => '-92',
      'type' => 'view',
    ),
    9 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_17',
      'args' => '',
      'get_displays' => 'vdisp_9',
      'title' => 'Irrelevant',
      'weight' => '-91',
      'type' => 'view',
    ),
  );
  $quicktabs->style = 'nostyle';
  $export['vrm_admin_tabs_list'] = $quicktabs;

  $quicktabs = new stdClass;
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'vrm_admin_tabs_status';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = 0;
  $quicktabs->default_tab = FALSE;
  $quicktabs->title = 'Vrm Admin Tabs Status';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'vrm_category_view',
      'display' => 'page_3',
      'args' => '',
      'get_displays' => 'vdisp_0',
      'title' => 'Status',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'vrm_admin_actions_log',
      'display' => 'page_4',
      'args' => '',
      'get_displays' => 'vdisp_1',
      'title' => 'History',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->style = 'default';
  $export['vrm_admin_tabs_status'] = $quicktabs;

  $quicktabs = new stdClass;
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'vrm_manage_actions';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = 0;
  $quicktabs->default_tab = FALSE;
  $quicktabs->title = 'Vrm Manage Actions';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'vrm_category_view',
      'display' => 'page_2',
      'args' => '',
      'get_displays' => 'vdisp_0',
      'title' => 'List',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'path' => 'manage/add/actions',
      'title' => 'Add',
      'weight' => '-99',
      'type' => 'callback',
    ),
    2 => array(
      'vid' => 'vrm_admin_actions_log',
      'display' => 'page_2',
      'args' => '',
      'get_displays' => 'vdisp_2',
      'title' => 'History',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->style = 'default';
  $export['vrm_manage_actions'] = $quicktabs;

  $quicktabs = new stdClass;
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'vrm_manage_categories';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = 0;
  $quicktabs->default_tab = FALSE;
  $quicktabs->title = 'Vrm Manage Categories';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'vrm_category_view',
      'display' => 'page_1',
      'args' => '',
      'get_displays' => 'vdisp_0',
      'title' => 'List',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'path' => 'manage/add/categories',
      'title' => 'Add',
      'weight' => '-99',
      'type' => 'callback',
    ),
    2 => array(
      'vid' => 'vrm_admin_actions_log',
      'display' => 'page_1',
      'args' => '',
      'get_displays' => 'vdisp_2',
      'title' => 'History',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->style = 'default';
  $export['vrm_manage_categories'] = $quicktabs;

  $quicktabs = new stdClass;
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'vrm_pmo_list';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = 0;
  $quicktabs->default_tab = FALSE;
  $quicktabs->title = 'VRM PMO List';
  $quicktabs->tabs = array(
    0 => array(
      'machine_name' => 'vrm_pmo_tabs_list',
      'title' => 'List',
      'weight' => '-100',
      'type' => 'qtabs',
    ),
    1 => array(
      'vid' => 'vrmadmin_status_description',
      'display' => 'default',
      'args' => '',
      'get_displays' => 'vdisp_1',
      'title' => 'Status',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->style = 'default';
  $export['vrm_pmo_list'] = $quicktabs;

  $quicktabs = new stdClass;
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'vrm_pmo_tabs_list';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = 0;
  $quicktabs->default_tab = FALSE;
  $quicktabs->title = 'Vrm PMO Tabs List';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_2',
      'args' => '',
      'get_displays' => 'vdisp_0',
      'title' => 'My List',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_8',
      'args' => '',
      'get_displays' => 'vdisp_1',
      'title' => 'Forwarded',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_9',
      'args' => '',
      'get_displays' => 'vdisp_2',
      'title' => 'Assigned',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_10',
      'args' => '',
      'get_displays' => 'vdisp_3',
      'title' => 'Replied',
      'weight' => '-97',
      'type' => 'view',
    ),
    4 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_11',
      'args' => '',
      'get_displays' => 'vdisp_4',
      'title' => 'Reviewed',
      'weight' => '-96',
      'type' => 'view',
    ),
    5 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_12',
      'args' => '',
      'get_displays' => 'vdisp_5',
      'title' => 'Archived',
      'weight' => '-95',
      'type' => 'view',
    ),
    6 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_18',
      'args' => '',
      'get_displays' => 'vdisp_6',
      'title' => 'Closed',
      'weight' => '-94',
      'type' => 'view',
    ),
  );
  $quicktabs->style = 'nostyle';
  $export['vrm_pmo_tabs_list'] = $quicktabs;

  $quicktabs = new stdClass;
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'vrm_poc_tabs_list';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = 0;
  $quicktabs->default_tab = FALSE;
  $quicktabs->title = 'Vrm POC Tabs List';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_2',
      'args' => '',
      'get_displays' => 'vdisp_0',
      'title' => 'My List',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_8',
      'args' => '',
      'get_displays' => 'vdisp_1',
      'title' => 'Forwarded',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_9',
      'args' => '',
      'get_displays' => 'vdisp_2',
      'title' => 'Assigned',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_10',
      'args' => '',
      'get_displays' => 'vdisp_3',
      'title' => 'Replied',
      'weight' => '-97',
      'type' => 'view',
    ),
    4 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_11',
      'args' => '',
      'get_displays' => 'vdisp_4',
      'title' => 'Reviewed',
      'weight' => '-96',
      'type' => 'view',
    ),
    5 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_12',
      'args' => '',
      'get_displays' => 'vdisp_5',
      'title' => 'Archived',
      'weight' => '-95',
      'type' => 'view',
    ),
    6 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_18',
      'args' => '',
      'get_displays' => 'vdisp_6',
      'title' => 'Closed',
      'weight' => '-94',
      'type' => 'view',
    ),
  );
  $quicktabs->style = 'nostyle';
  $export['vrm_poc_tabs_list'] = $quicktabs;

  return $export;
}
