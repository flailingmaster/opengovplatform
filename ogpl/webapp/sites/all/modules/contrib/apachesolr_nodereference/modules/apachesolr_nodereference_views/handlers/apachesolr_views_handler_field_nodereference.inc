<?php
// $Id$

/**
 * @file
 * provides a field handler for the snippet coming from the ApacheSolr search engine
 */
class apachesolr_views_handler_field_nodereference extends views_handler_field {
  function query() {
    $this->query->add_solr_field($this->real_field);
  }

  function render($doc) {
    if (is_array($doc->{$this->real_field})) {
      $values = $doc->{$this->real_field};
    }
    else {
      $values = array($doc->{$this->real_field});
    }

    $titles = array();

    foreach ($values as $nid) {
      $titles[] = db_result(db_query('SELECT title FROM {node} WHERE nid = %d', $nid));
    }

    return implode(', ', $titles);
  }
}