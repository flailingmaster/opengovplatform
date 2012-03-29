<?php

function apachesolr_exclude_views_data() {
  $data = array();

  $data['apachesolr_exclude']['table']['group']  = t('Apachesolr');

  // Advertise this table as a possible base table
  $data['apachesolr_exclude']['table']['base'] = array(
    'field' => 'nid',
    'title' => t('Apachesolr exclude'),
    'help' => t('Exclude certain nodes from indexing.'),
    'weight' => -10,
  );

  // For other base tables, explain how we join
  $data['apachesolr_exclude']['table']['join'] = array(
    // this explains how the 'node' table (named in the line above)
    // links toward the node_revisions table.
    'node' => array(
      'handler' => 'views_join', // this is actually optional
      'left_table' => 'node', // Because this is a direct link it could be left out.
      'left_field' => 'nid',
      'field' => 'nid',
     ),
  );

  // published status + extra
  $data['apachesolr_exclude']['nid'] = array(
    'title' => t('Hidden from solr'),
    'help' => t('Whether or not the node is excluded from solr indexing.'),
    // Not sure the field really makes sense without some custom magic.
//    'field' => array(
//      'handler' => 'views_handler_field_numeric',
//      'click sortable' => TRUE,
//    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Hidden'),
      'type' => 'yes-no',
      'accept_null' => TRUE, // Empty entries are not filtered.
    ),
  );

  return $data;
}
