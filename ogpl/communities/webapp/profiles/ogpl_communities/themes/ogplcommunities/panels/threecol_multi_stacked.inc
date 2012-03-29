<?php // $Id $

/**
 * @file threecol_multi_stacked.inc
 * Implementation of hook_panels_layouts()
 */
function ogplcommunities_threecol_multi_stacked_panels_layouts() {
  $items['threecol_multi_stacked'] = array(
    'title' => t('ogplcommunities 3 column multi-stacked panel'),
    'icon' => 'threecol_multi_stacked.png',
    'theme' => 'threecol_multi_stacked',
    'theme arguments' => array('id', 'content'),
    'css' => 'threecol_multi_stacked.css',
    'panels' => array(
	  'top' => t('Top Banner'),
      'left1' => t('Left Column - 1st row'),
	  'center1' => t('Center Column - 1st row'),
      'right1' => t('Right Column - 1st row'),
      'left2' => t('Left Column - 2nd row'),
	  'center2' => t('Center Column - 2nd row'),
      'right2' => t('Right Column - 2nd row'),
      'left3' => t('Left Column - 3rd row'),
	  'center3' => t('Center Column - 3rd row'),
      'right3' => t('Right Column - 3rd row'),
      'left4' => t('Left Column - 4th row'),
	  'center4' => t('Center Column - 4th row'),
      'right4' => t('Right Column - 4th row'),
      'left5' => t('Left Column - 5th row'),
	  'center5' => t('Center Column - 5th row'),
      'right5' => t('Right Column - 5th row'),
	  'bottom' => t('Bottom Banner')
    ),
  );

  return $items;
}