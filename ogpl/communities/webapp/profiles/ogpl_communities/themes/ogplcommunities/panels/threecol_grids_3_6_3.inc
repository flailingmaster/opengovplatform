<?php // $Id $

/**
 * @file threecol_grids_3_6_3.inc
 * Implementation of hook_panels_layouts()
 */
function ogplcommunities_threecol_grids_3_6_3_panels_layouts() {
  $items['threecol_grids_3_6_3'] = array(
    'title' => t('ogplcommunities 3 column 25/50/25'),
    'icon' => 'threecol_grids_3_6_3.png',
    'theme' => 'threecol_grids_3_6_3',
    'theme arguments' => array('id', 'content'),
    'css' => 'threecol_grids_3_6_3.css',
    'panels' => array(
      'left' => t('Left Column'),
	  'center' => t('Center Column'),
      'right' => t('Right Column'),
    ),
  );

  return $items;
}