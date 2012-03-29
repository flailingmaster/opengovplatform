<?php
class send_views_handler_field_count extends views_handler_field {
  function options() {
    parent::options($options);
    $options['count_type'] = 'send_count';
  }
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['count_type'] = array(
      '#title' => t('Count by'),
      '#type'  => 'select',
      '#options' => array(
        'send_count' => 'Number of times the node was sent',
        'recipient_count' => 'Number of recipients of the node',
      ),
      '#default_value' => $this->options['count_type'],
    );
  }
  function query() {
    $send_recipient_table = $this->query->ensure_table('send_recipient');
    $node_table = $this->query->ensure_table('node', 'send');
    $base_table = $this->query->base_table;
    $node_alias = $this->query->tables[$base_table]['node']['alias'];
    if (isset($node_alias)) {
      $nid = $node_alias .'.nid';
      if ($this->options['count_type'] === 'send_count') {
        $sql_function = 'COUNT';
        $table_alias  = 'send_node_count';
        $field = 'nid';
      }
      elseif ($this->options['count_type'] === 'recipient_count') {
        $sql_function = 'SUM';
        $table_alias  = 'send_recipient_rcount';
        $field = 'rcount';
      }
      $sql = "SELECT $sql_function($table_alias.$field) FROM {send_recipient}
              $table_alias WHERE $table_alias.nid=$nid";
      $field_alias = $this->query->add_field($this->table_alias, "($sql)",
        $this->real_field .'_'. $this->options['count_type'] .'_total');
      $this->field_alias = $field_alias;
    }
  }
}
