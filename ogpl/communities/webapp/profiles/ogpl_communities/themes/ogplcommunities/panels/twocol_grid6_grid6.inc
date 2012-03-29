<?php // $Id $

/**
 * @file twocol_grid6_grid6.inc
 * Implementation of hook_panels_layouts()
 */
function ogplcommunities_twocol_grid6_grid6_panels_layouts() {
  $items['twocol_grid6_grid6'] = array(
    'title' => t('ogplcommunities 2 column panel (grid-6, grid-6)'),
    'icon' => 'twocol_grid6_grid6.png',
    'theme' => 'twocol_grid6_grid6',
    'theme arguments' => array('id', 'content'),
    'css' => 'twocol_grid6_grid6.css',
    'panels' => array(
	  'top' => t('Top Banner'),
      'left' => t('Left Column'),
	  'right' => t('Right Column'),
	  'bottom' => t('Bottom Banner'),
    ),
  );

  return $items;
}
