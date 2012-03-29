<?php

/**
 * @file
 * Views field handler for node edit link based on Module Grants access.
 */
class module_grants_views_handler_field_node_link_edit extends views_handler_field_node_link {
  function render($values) {
    $nid = $values->{$this->aliases['nid']};
    $node = node_load($nid);
    if ( module_grants_node_access('update', $node) ) {
      $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
      return l($text, "node/$node->nid/edit", array('query' => drupal_get_destination()));
    }
  }
}
