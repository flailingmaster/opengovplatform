<?php
class send_views_handler_sort_count extends views_handler_sort {
  function options(&$options) {
    parent::options($options);
    $options['group_by_node'] = FALSE;
    $options['count_type'] = 'send_count';
  }
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['group_by_node'] = array(
      '#title' => t('Group results by node'),
      '#description' => t('Group results by node id making them unique'),
      '#type'  => 'checkbox',
      '#default_value' => $this->options['group_by_node'],
    );
    $form['count_type'] = array(
      '#title' => t('Sort by'),
      '#type'  => 'select',
      '#options' => array(
        'send_count' => 'Number of times the node was sent',
        'recipient_count' => 'Number of recipients of the node',
      ),
      '#default_value' => $this->options['count_type'],
    );
  }
  function query() {
    $this->ensure_my_table();
    // Add the field.
    $field_alias = $this->field .'_'. $this->options['count_type'] . '_total';
    $this->query->add_orderby($this->table_alias, NULL, $this->options['order'], $field_alias);
    if ($this->options['group_by_node']) {
      $node = $this->query->get_table_info('node');
      if (isset($node['alias'])) {
        $this->query->add_groupby($node['alias'] .'.nid');
      }
    }
  }
}
