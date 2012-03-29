<?php
// $Id$

/**
 * @file
 * Provides an argument handler for nodereference taxonomy
 */
class apachesolr_views_handler_argument_nodereference_tid extends apachesolr_views_handler_argument_nodereference {
  /**
   * Get allowed values from hook_allowed_values(), if any, or from
   * content_allowed_values();
   */
  function allowed_values() {
    $result = db_query("SELECT tid, name FROM {term_data} WHERE vid = %d", $this->definition['vid']);
    $options = array();
    
    while ($obj = db_fetch_object($result)) {
      $options[$obj->tid] = $obj->name;
    }
    
    return $options;
  }
}