<?php

/**
 * @file
 * Part of module to deal with VBO bulk node validations.
 */

/**
 * Validate node data against required field, and syntax.
 */
function workflow_customizations_validate_node($node) {
  if (!$node) {
    return;
  }
  $required_fields = workflow_customizations_get_requred_fields($node->type);
  
  $validated = 1;
  foreach ($required_fields as $fieldname => $fieldinfo) {
    if (!$validated) {
      break;
    }

    switch ($fieldinfo['module']) {
      // case NULL means not-required flexifield. 
      case 'flexifield':
      case NULL:
        $type_chosen = $node->{'field_' . $fieldname}[0]['type'];
        if ($type_chosen === NULL && $fieldinfo['required']) {
          $validated = 0;
        }
        elseif ($type_chosen !== NULL) {
          // TODO: recursive flexifield handling.
          // TODO: multiple flexifield handling.
          $required_child_fields = $fieldinfo['childfields'][$type_chosen];
          if(is_array($required_child_fields)) {
          foreach ($required_child_fields as $child_fieldname => $child_fieldinfo) {
            if (!$child_fieldinfo['required']) {
              continue; // Assuming no recrsive flexifield.
            }
            // Assuming no multiple flexifield
            $child_value_element = $node->{'field_' . $fieldname}[0]['value']['field_' . $child_fieldname][0];
            if ( $child_value_element['value'] === NULL && $child_value_element['nid'] === NULL && $child_value_element['url'] === NULL && $child_value_element['email'] === NULL) {
              $validated = 0;
              break;
            }
           }
          }
        }
        break;

      default: //text, number, email, link, date, nodereference...what else?
        $value_element = $node->{'field_' . $fieldname}[0];
        if ( $value_element['value'] === NULL && $value_element['nid'] === NULL && $value_element['url'] === NULL && $value_element['email'] === NULL) {
          $validated = 0;
        }
        //validate email and URL fields
        else if ($value_element['email'] !== NULL && !valid_email_address($value_element['email'])) {
          $validated = 0;     
        }
        else if ($value_element['url'] !== NULL && !valid_url($value_element['url'], TRUE)) {
          $validated = 0;
        }
        break;
    }
  }

  // TODO: Field type that need format validation, such as email.

  return $validated;
}


/**
 * Collect all required fields, or fields containing required child fields.
 */
function workflow_customizations_get_requred_fields($content_type) {

  if (empty($content_type)) {
    return;
  }
  
  $ret = NULL;

  $fields = content_types($content_type);
  $fields = $fields['fields'];

  foreach ($fields as $key => $value) {

    $fieldname = preg_replace('/^field_/', '', $value['field_name']);

    // Exit if not a required field, and no possible required child field
    if (!$value['required'] && $value['type'] != 'flexifield') {
      continue;
    }
    // Dig into child fields (regardless required or not)
    elseif ($value['type'] == 'flexifield') {
      if ($value['required']) {
        $ret[$fieldname]['required'] = $value['required'];
        $ret[$fieldname]['module'] = $value['module'];        
      }

      foreach($value['item_types'] as $key_1 => $value_1) {
        if ($value_1) {
          $ret_child = call_user_func(__FUNCTION__, $value_1);
          if ($ret_child) {
            $ret[$fieldname]['childfields'][$value_1] = $ret_child; 
          }
        }
      }
    }
    // Required field
    else {
      $ret[$fieldname]['required'] = $value['required'];
      $ret[$fieldname]['module'] = $value['module'];
    }
  }
  
  return $ret;
}
