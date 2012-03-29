<?php
/**
 * @file
 * Part of module to deal with creating node from file data.
 */

require_once 'dms_ds_upload.fields.inc';
require_once 'dms_ds_upload.files.inc';

/**
 * Add dataset nodes from uploaded file.
 */
function dms_ds_upload_add_dataset($filename = '') {

  //get records from the file content
  $data_from_file = array();
  $path = $_SERVER['DOCUMENT_ROOT'] . base_path() . file_directory_path();
  $filename = $path . '/' . $filename;

  $data_from_file = dms_ds_upload_parse_file($filename);

  //delete file after done.
  file_delete($filename);

  $num_of_records = count($data_from_file);
  $num_of_nodes = 0;

  if ($num_of_records) {
    //walk thru all valid fields
    $all_fields = dms_ds_upload_get_fields('dataset', $GLOBALS['dms_ds_upload_exclude_group']);
    //create one node for each record
    for ($i = 0; $i < $num_of_records; $i++) {
      $nid = dms_ds_upload_create_node($data_from_file[$i], $all_fields);
      if (!empty($nid)) {
        $num_of_nodes++;
      }
    }
  }

  //Now node(s) added, redirecting user to appropriate page.
  if ($num_of_nodes == 0) { //either bad entries, or 0 entries.
    drupal_set_message(t('Uploaded file is not valid. ' .
          'No dataset has been created.'
    ));
    drupal_goto('node/add/dataset');
  }
  elseif ($num_of_records == 1) {
    //one entry and it is good. redirect to node view page.
    drupal_set_message(t("New dataset has been created with uploaded file."));
    drupal_goto('node/' . $nid . '/edit');
  }
  else {
    //multiple entries and at least one good entry.
    //redirect to home with content listing.
    drupal_set_message(t('@count new datasets have been created with uploaded file.',
      array('@count' => $num_of_nodes)
    ));
    drupal_goto('');
  }

}

/**
 * Put data into fields and we got a node.
 */
function dms_ds_upload_create_node($data = array(), $fields = array()) {

  global $user;
  // Insert new data:
  $node->type = 'dataset';
  module_load_include('inc', 'node', 'node.pages');
  $type = node_get_types('type', $node->type);
  node_object_prepare($node);
  $node->uid = $user->uid;
  //commented out. let us use default publishing status
  //$node->status = 0;

  $supported_types = $GLOBALS['dms_ds_upload_supported_types'];
  foreach ($supported_types as $type) {
    if (isset($fields[$type])) {
      dms_ds_upload_insert_field($node, $fields[$type], $data, $type);
    }
  }

  //hard code these values when node been created.
  $node->field_request_type[0]['value'] = 'Create';
  $node->field_ds_date_submitted[0]['value'] = time();

  node_save($node);
  //we are done already. but let caller know what nid we created.
  return $node->nid;
}

/**
 * Treat each type of field differently when it comes to inserting data.
 */
function dms_ds_upload_insert_field(&$node = NULL, $fields, $data = array(), $field_type = '') {
  global $user;

  //$node can be a node, or a node element for recursive flexifield.
  $is_node = is_object($node);

  switch ($field_type) {

    case 'datestamp':
      $default_timezone = date_default_timezone_get();
      $user_timezone = $user->timezone_name;
      //use user timezone temporarily, so strtotime will do things right.
      date_default_timezone_set($user_timezone);
      foreach ($fields as $field) {
        if ($is_node) {
          $node_element = &$node->{'field_' . $field['fieldname']};
        }
        else {
          $node_element = &$node['field_' . $field['fieldname']];
        }

        $values = $data[$field['fieldname']];
        for ($i = 0; $i < count($values); $i++) {
          $value = dms_ds_upload_clean_input($values[$i]);
          if (!is_null($value)) {
            $value = strtotime($value);
          }
          $node_element[$i]['value'] = $value;
        }

      }
      //revert back to original timezone
      date_default_timezone_set($default_timezone);
      break;

    case 'nodereference':
      foreach ($fields as $field) {

        if ($is_node) {
          $node_element = &$node->{'field_' . $field['fieldname']};
        }
        else {
          $node_element = &$node['field_' . $field['fieldname']];
        }

        $values = $data[$field['fieldname']];
        for ($i = 0; $i < count($values); $i++) {
          $value = dms_ds_upload_clean_input($values[$i]);
          //what is the content_type this referenced to?
          $child_content_type = $field['child_fieldnames'][0];
          //give me an array of valid entries in the format of ($node_title => $nid) for all $child_content_type nodes
          $valid_entries = dms_ds_upload_get_nodereference_entries($child_content_type);
          $node_element[$i]['nid'] = $valid_entries[$value];
        }

      }
      break;

    case 'link':
      foreach ($fields as $field) {

        if ($is_node) {
          $node_element = &$node->{'field_' . $field['fieldname']};
        }
        else {
          $node_element = &$node['field_' . $field['fieldname']];
        }

        $values = $data[$field['fieldname']];
        for ($i = 0; $i < count($values); $i++) {
          $value = dms_ds_upload_clean_input($values[$i]);
          $node_element[$i]['url'] = $value;
        }

      }
      break;

    case 'email':
      foreach ($fields as $field) {
        if ($is_node) {
          $node_element = &$node->{'field_' . $field['fieldname']};
        }
        else {
          $node_element = &$node['field_' . $field['fieldname']];
        }

        $values = $data[$field['fieldname']];
        for ($i = 0; $i < count($values); $i++) {
          $value = dms_ds_upload_clean_input($values[$i]);
          $node_element[$i]['email'] = $value;
        }
      }
      break;

    case 'flexifield':
      foreach ($fields as $field) {

        if ($is_node) {
          $node_element = &$node->{'field_' . $field['fieldname']};
        }
        else {
          $node_element = &$node['field_' . $field['fieldname']];
        }

        $values = $data[$field['fieldname']];
        for ($i = 0; $i < count($values); $i++) {
          $value = dms_ds_upload_clean_input($values[$i]);
          //what node type does user choose?
          $type_chosen = $value;
          //machine name for this type?
          $query = "SELECT type from {node_type} WHERE name ='%s'";
          $type_chosen = db_result(db_query($query, $type_chosen));

          $node_element[$i]['type'] = $type_chosen;

          //now deal with flexifield child fields  
          $child_fields = dms_ds_upload_get_fields($type_chosen);
          if (!isset($node_element[$i]['value'])) {
            $node_element[$i]['value'] = array();
          }
          $child_node = &$node_element[$i]['value'];
          $supported_types = $GLOBALS['dms_ds_upload_supported_types'];
          foreach ($supported_types as $type) {
            if (isset($child_fields[$type])) {
              dms_ds_upload_insert_field($child_node, $child_fields[$type], $data, $type);
            }
          }
        }

      }
      break;

    default: //text, number_integer...
      foreach ($fields as $field) {

        if ($is_node) {
          $node_element = &$node->{'field_' . $field['fieldname']};
        }
        else {
          $node_element = &$node['field_' . $field['fieldname']];
        }

        $values = $data[$field['fieldname']];
        for ($i = 0; $i < count($values); $i++) {
          $value = dms_ds_upload_clean_input($values[$i]);
          $node_element[$i]['value'] = $value;
        }

      }

  }
}

/**
 * Retrieve readable data from node and put into array.
 */
function dms_ds_upload_retrieve_node($node = NULL, $fields = array()) {

  $ret = array();

  $supported_types = $GLOBALS['dms_ds_upload_supported_types'];
  foreach ($supported_types as $type) {
    if (isset($fields[$type])) {
      dms_ds_upload_retrieve_field($ret, $fields[$type], $node, $type);
    }
  }

  return $ret;
}

/**
 * Treat each type of field differently when it comes to retrieving data.
 */
function dms_ds_upload_retrieve_field(&$ret = array(), $fields, $data, $field_type = '') {
  global $user;

  //is the data from a node?
  //if so, we are dealing with first level node field.
  //otherwise it is derivative fields from unserialize flexifield value.
  $is_from_node = is_object($data);

  switch ($field_type) {

    case 'datestamp':
      $default_timezone = date_default_timezone_get();
      $user_timezone = $user->timezone_name;
      //use user timezone temporarily, so date will do things right.
      date_default_timezone_set($user_timezone);
      foreach ($fields as $field) {
        $data_element = $is_from_node?$data->{'field_' . $field['fieldname']}:$data['field_' . $field['fieldname']];

        foreach ($data_element as $key => $value) {
          if ($value && $value['value']) {
            $ret[$field['fieldname']][$key] = date('Y-m-d H:i', $value['value']);
          }
        }
      }
      //revert back to original timezone
      date_default_timezone_set($default_timezone);
      break;

    case 'nodereference':
      foreach ($fields as $field) {
        $data_element = $is_from_node?$data->{'field_' . $field['fieldname']}:$data['field_' . $field['fieldname']];
        foreach ($data_element as $key => $value) {

          $node_id = $value['nid'];
          $child_node_title ='';

          //what is the content_type this referenced to?
          $child_content_type = $field['child_fieldnames'][0];

          //give me an array of valid entries in the format of ($node_title => $nid) for all $child_content_type nodes
          $valid_entries = dms_ds_upload_get_nodereference_entries($child_content_type);
          foreach ($valid_entries as $key_1 => $value_1) {
            if ($value_1 == $node_id) {
              $child_node_title = $key_1;
              break;
            }
          }
          $ret[$field['fieldname']][$key] = $child_node_title;
        }
      }
      break;

    case 'flexifield':
      foreach ($fields as $field) {
        $data_element = $is_from_node?$data->{'field_' . $field['fieldname']}:$data['field_' . $field['fieldname']];
        foreach ($data_element as $key => $value) {


          //what node type in the record?
          $type_chosen = $value['type'];

          if (empty($type_chosen)) {
            continue;
          }
          //label name for this type?
          $query = "SELECT name from {node_type} WHERE type ='%s'";
          $type_name = db_result(db_query($query, $type_chosen));
          $ret[$field['fieldname']][$key] = $type_name;

          $child_fields = dms_ds_upload_get_fields($type_chosen);
          //if ($is_from_node) {
          //  $child_data = unserialize($value['value']);
          //}
          //else {
          $child_data = $value['value'];
          //}
          $supported_types = $GLOBALS['dms_ds_upload_supported_types'];
          foreach ($supported_types as $type) {
            if (isset($child_fields[$type])) {
              dms_ds_upload_retrieve_field($ret, $child_fields[$type], $child_data, $type);
            }
          }
        }
      }
      break;

    case 'link':
      foreach ($fields as $field) {
        $data_element = $is_from_node?$data->{'field_' . $field['fieldname']}:$data['field_' . $field['fieldname']];
        foreach ($data_element as $key => $value) {
          $ret[$field['fieldname']][$key] = $value['url'];
        }
      }
      break;

    case 'email':
      foreach ($fields as $field) {
        $data_element = $is_from_node?$data->{'field_' . $field['fieldname']}:$data['field_' . $field['fieldname']];
        foreach ($data_element as $key => $value) {
          $ret[$field['fieldname']][$key] = $value['email'];
        }
      }
      break;

    default: //text, number_integer...
      foreach ($fields as $field) {
        $data_element = $is_from_node?$data->{'field_' . $field['fieldname']}:$data['field_' . $field['fieldname']];
        foreach ($data_element as $key => $value) {
          $ret[$field['fieldname']][$key] = $value['value'];
        }
      }

  }
}

/**
 * Make input data NULL if we dont like it.
 */
function dms_ds_upload_clean_input($data = NULL) {
  if ($data === "" || $data === array()) {
    return NULL;
  }
  else {
    return trim($data);
  }
}