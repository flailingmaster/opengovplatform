<?php
class send_views_handler_filter_in_operator_module extends views_handler_filter_in_operator {
  function get_value_options() {
    $this->value_options = send_profile_names();
  }
}
