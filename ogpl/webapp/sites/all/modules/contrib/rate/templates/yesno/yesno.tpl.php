<?php
/**
 * @file
 * Rate widget theme
 */

print theme('item_list', $buttons);

if ($info) {
  print '<div class="rate-info">' . $info . '</div>';
}

if ($display_options['description']) {
  print '<div class="rate-description">' . $display_options['description'] . '</div>';
}
