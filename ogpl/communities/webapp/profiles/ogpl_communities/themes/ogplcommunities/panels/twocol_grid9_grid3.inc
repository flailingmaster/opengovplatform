<?php // $Id $

/**
 * @file twocol_grid9_grid3.inc
 * Implementation of hook_panels_layouts()
 */
function ogplcommunities_twocol_grid9_grid3_panels_layouts() {
  $items['twocol_grid9_grid3'] = array(
    'title' => t('ogplcommunities 2 column panel (grid-9, grid-3)'),
    'icon' => 'twocol_grid9_grid3.png',
    'theme' => 'twocol_grid9_grid3',
    'theme arguments' => array('id', 'content'),
    'css' => 'twocol_grid9_grid3.css',
    'panels' => array(
      'left' => t('Left Column'),
	  'right' => t('Right Column')
    ),
  );

  return $items;
}
