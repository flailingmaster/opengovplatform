<?php // $Id $

/**
 * @file twocol_grid8_grid4.inc
 * Implementation of hook_panels_layouts()
 */
function ogplcommunities_twocol_grid8_grid4_panels_layouts() {
  $items['twocol_grid8_grid4'] = array(
    'title' => t('ogplcommunities 2 column panel (grid-8, grid-4)'),
    'icon' => 'twocol_grid8_grid4.png',
    'theme' => 'twocol_grid8_grid4',
    'theme arguments' => array('id', 'content'),
    'css' => 'twocol_grid8_grid4.css',
    'panels' => array(
      'left' => t('Left Column'),
	  'right' => t('Right Column'),
    ),
  );

  return $items;
}
