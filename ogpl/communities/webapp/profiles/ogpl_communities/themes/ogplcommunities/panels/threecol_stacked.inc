<?php // $Id $

/**
 * @file threecol_stacked.inc
 * Implementation of hook_panels_layouts()
 */
function ogplcommunities_threecol_stacked_panels_layouts() {
  $items['threecol_stacked'] = array(
    'title' => t('ogplcommunities 3 column stacked panel'),
    'icon' => 'threecol_stacked.png',
    'theme' => 'threecol_stacked',
    'theme arguments' => array('id', 'content'),
    'css' => 'threecol_stacked.css',
    'panels' => array(
	  'top' => t('Top Banner'),
      'left' => t('Left Column'),
	  'center' => t('Center Column'),
      'right' => t('Right Column'),
	  'bottom' => t('Bottom Banner')
    ),
  );

  return $items;
}