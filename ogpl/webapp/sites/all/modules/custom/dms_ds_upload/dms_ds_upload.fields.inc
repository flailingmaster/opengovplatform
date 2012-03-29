<?php

/**
 * @file
 * Part of module to deal with CCK fields.
 */

/**
 * Get CCK fieldnames for the dataset or other content_type.
 */
function dms_ds_upload_get_fields($content_type = '', $exclude_group = '') {

  if (empty($content_type)) {
    return;
  }

  $fields = content_types($content_type);
  $fields = $fields['fields'];
  $ret = array();

  $supported_types = $GLOBALS['dms_ds_upload_supported_types'];

  if ($exclude_group) {
    $excluded_fields = dms_ds_upload_get_excluded_fields($exclude_group);
  }

  $types_have_child = array (
    'nodereference',
    'flexifield',
  );

  foreach ($fields as $key => $value) {

    //temp array to hold the array result.
    $temp_ret = array();

    // skip if not the type we support
    if (!in_array($value['type'], $supported_types)) {
      continue;
    }

    // skip if excluded.
    if ($excluded_fields && in_array($key, $excluded_fields)) {
      continue;
    }

    //now we have the names. remove the leading 'field_'
    $temp_ret['fieldname'] = preg_replace('/^field_/', '', $value['field_name']);
    $temp_ret['multiple'] = $value['multiple'];

    //for complex types, we are not done yet. record child content-type.
    if (in_array($value['type'], $types_have_child)) {
      if ($value['type'] == 'nodereference') {
        //the goodie is in 'referenceable_types'
        $key_look_for = 'referenceable_types';
      }
      elseif ($value['type'] == 'flexifield') {
        //the goodie is in 'item_types'
        $key_look_for = 'item_types';
      }

      foreach ($value[$key_look_for] as $key_1 => $value_1) {
        if (!empty($value_1)){
          $temp_ret['child_fieldnames'][] = $value_1;
        }
      }
    }
    //now we got everything we need..
    $ret[$value['type']][] = $temp_ret;
  }
  return $ret;
}

/**
 * My db query to get all fields in the right order.
 */
function dms_ds_upload_get_sequenced_fields($content_type = '', $exclude_group = '') {
  $ret = array();
  $query = "  SELECT" .
      "    null AS groupname," .
      "    cnfi.field_name AS fieldname," .
      "    cnfi.label AS fieldlabel," .
      "    cnf.type AS fieldtype," .
      "    cnf.global_settings AS settings," .
      "    cnfi.weight AS groupweight," .
      "    null AS fieldweight" .
      "  FROM" .
      "    content_node_field_instance cnfi" .
      "  JOIN " .
      "    content_node_field cnf" .
      "  ON" .
      "    cnfi.field_name = cnf.field_name" .
      "  WHERE" .
      "    cnfi.type_name = '%s'" .
      "  AND" .
      "    cnfi.field_name NOT IN (SELECT field_name FROM content_group_fields WHERE type_name = '%s')" .
      //above are orphaned fields that do not belong to any group.
      //of which weight should be compared to group weight down below.
      "  UNION" .
      //now grouped fields.
      "  SELECT" .
      "    cg.group_name AS groupname," .
      "    cnfi.field_name AS fieldname," .
      "    cnfi.label AS fieldlabel," .
      "    cnf.type AS fieldtype," .
      "    cnf.global_settings AS settings," .
      "    cg.weight AS groupweight," .
      "    cnfi.weight AS fieldweight" .
      "  FROM" .
      "    content_group cg" .
      "  JOIN" .
      "    content_group_fields cgf" .
      "  ON" .
      "    cg.group_name = cgf.group_name" .
      "  JOIN" .
      "    content_node_field_instance cnfi" .
      "  ON" .
      "    cnfi.field_name = cgf.field_name" .
      "  JOIN" .
      "    content_node_field cnf" .
      "  ON" .
      "    cnfi.field_name = cnf.field_name" .
      "  WHERE" .
      "    cg.group_type = 'standard'" .
      "  AND" .
      "    cg.type_name = '%s'" .
      "  AND" .
      "    cgf.type_name = '%s'" .
      "  AND" .
      "    cnfi.type_name = '%s'" .
      "  AND cg.group_name != '%s'" .
      //order by group weight first, then field weight.
      "  ORDER BY" .
      "    6, 7";

  $data = db_query($query, $content_type, $content_type, $content_type, $content_type, $content_type, $exclude_group);

  while ($a = db_fetch_array($data)) {
    $ret[] = $a;
  }

  return $ret;
}

/**
 * Merge recurive node fields and strip leading /^field_/.
 */
function dms_ds_upload_display_sequenced_fields($list = array()){

  $ret = array();
  $ret['fieldname'] = array();
  $ret['fieldlabel'] = array();
  $ret['settings'] = array();

  $supported_types = $GLOBALS['dms_ds_upload_supported_types'];

  foreach ($list as $field) {
    $fieldtype = $field['fieldtype'];
    if (!in_array($fieldtype, $supported_types)) {
      continue;
    }

    switch ($fieldtype) {

      case 'flexifield':
        $ret['fieldname'][] = preg_replace('/^field_/', '', $field['fieldname']);
        $ret['fieldlabel'][] = $field['fieldlabel'];
        $settings = unserialize($field['settings']);
        $ret['settings'][] = $settings;
        foreach ($settings['item_types'] as $key => $value) {
          if ($value) {
            $child_list = dms_ds_upload_get_sequenced_fields($value);
            $child_ret = call_user_func(__FUNCTION__, $child_list);
            $ret['fieldname'] = array_merge($ret['fieldname'], $child_ret['fieldname']);
            $ret['fieldlabel'] = array_merge($ret['fieldlabel'], $child_ret['fieldlabel']);
            $ret['settings'] = array_merge($ret['settings'], $child_ret['settings']);
          }
        }
        break;

      default:
        $ret['fieldname'][] = preg_replace('/^field_/', '', $field['fieldname']);
        $ret['fieldlabel'][] = $field['fieldlabel'];
        $settings = unserialize($field['settings']);
        $ret['settings'][] = $settings;

    }
  }
  return $ret;
}

/**
 * Get node->title and node->id to prepare for parent field entries.
 */
function dms_ds_upload_get_nodereference_entries($content_type = '') {
  $ret = array();
  $query = "SELECT nid, title from {node} WHERE type='%s'";
  $result = db_query($query, $content_type);

  while ($obj = db_fetch_object($result)) {
    $ret[$obj->title] = $obj->nid;
  }

  return $ret;
}

/**
 * Get a list of excluded fields' names.
 */
function dms_ds_upload_get_excluded_fields($groupname = '') {
  $ret = array();
  $query = "SELECT field_name FROM content_group_fields WHERE group_name = '%s'";
  $data = db_query($query, $groupname);

  while ($a = db_fetch_array($data)) {
    $ret[] = $a['field_name'];
  }

  return $ret;
}