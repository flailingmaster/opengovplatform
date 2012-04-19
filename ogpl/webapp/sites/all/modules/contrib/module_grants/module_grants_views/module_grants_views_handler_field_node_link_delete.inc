<?php

/**
 * @file
 * Views field handler for node delete link based on Module Grants access.
 */
class module_grants_views_handler_field_node_link_delete extends views_handler_field_node_link {
  function render($values) {
    $nid = $values->{$this->aliases['nid']};
    $node = node_load($nid);
    if ( module_grants_node_access('delete', $node) ) {
      $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
      return l($text, "node/$node->nid/delete", array('query' => drupal_get_destination()));
    }
  }
}
