<?php
class send_views_handler_sort_date extends views_handler_sort_date {
  function options(&$options) {
    parent::options($options);
    $options['group_by_node'] = FALSE;
  }
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    if ($this->field === 'timestamp') {
     $form['group_by_node'] = array(
       '#title' => t('Group results by node'),
       '#description' => t('Group results by node id making them unique'),
       '#type'  => 'checkbox',
       '#default_value' => $this->options['group_by_node'],
      );
    }
  }
  function query() {
    $this->ensure_my_table();
    if ($this->options['group_by_node']) {
      $node = $this->query->get_table_info('node');
      if (isset($node['alias'])) {
        $this->query->add_groupby($node['alias'] .'.nid');
      }
    }
  }
}
