<?php
// $Id: upanddown.inc,v 1.1.2.1 2010/07/24 23:23:54 marvil07 Exp $

/**
 * @file
 * Up Down Widget.
 */

/**
 * Implementation of hook_vud_widgets(). (Specialized)
 */
function ogplcommunities_thumbupanddown_vud_widgets() {
  return array(
    'title' => t('Thumb Up and down'),
    'widget template' => 'widget',
  );
}
