<?php // $Id $

/**
 * @file threecol.inc
 * Implementation of hook_panels_layouts()
 */
function ogplcommunities_threecol_panels_layouts() {
  $items['threecol'] = array(
    'title' => t('ogplcommunities 3 column panel'),
    'icon' => 'threecol.png',
    'theme' => 'threecol',
    'theme arguments' => array('id', 'content'),
    'css' => 'threecol.css',
    'panels' => array(
      'left' => t('Left Column'),
	  'center' => t('Center Column'),
      'right' => t('Right Column'),
    ),
  );

  return $items;
}
