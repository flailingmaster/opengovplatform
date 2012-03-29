<?php

/**
 * @file
 * Download count per file views handler.
 */

/**
 * Download count per file views field handler.
 */
class download_count_views_handler_field_count extends views_handler_field_numeric {
  function query() {
    $this->table_alias = $this->ensure_my_table();
    if (empty($this->relationship)) {
      $sql = "SELECT COUNT(dc.fid) FROM {download_count} dc WHERE dc.fid = " . $this->table_alias . ".fid";
      $this->field_alias = $this->query->add_field(NULL, "(" . $sql . ")", $this->table_alias . '_' . $this->field);
    }
    else {
      $sql = "SELECT COUNT(dc.fid) FROM {download_count} dc WHERE dc.fid = " . $this->relationship . ".fid";
      $this->field_alias = $this->query->add_field(NULL, "(" . $sql . ")", $this->relationship . '_' . $this->field);
    }
  }
}
