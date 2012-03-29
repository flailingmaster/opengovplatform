<?php

/**
 * Implementation of hook_default_fe_block_boxes().
 */
function what_s_new_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Front End Newest Features Header What\'s New Page';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'heading_new_features';
  $fe_block_boxes->body = '<h2 class="centered">New Features</h2>';

  $export['heading_new_features'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'heading_rss_feeds';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'heading_rss_feeds';
  $fe_block_boxes->body = '<h2 class="centered">RSS Feeds</h2>';

  $export['heading_rss_feeds'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Front End Newest Features Content What\'s New Page';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'new_features';
  $fe_block_boxes->body = '<div class="content"><div class="read-more-align"><a href="whats-new/latest-pages" style="font-size: 1.1355em;" title="Read More">Read More </a></div><div><img alt="New Features" src="[token global site-url]sites/all/themes/ogpl_css3/images/whatsnew-geoviewer.jpg" style="width: 288px; height: 155px;" title="New Features" /></div><div class="block-data-whats-new">Check this space for latest new features introduced by OGPL<p>&nbsp;</p></div></div>';

  $export['new_features'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Front End Newest Dataset Image What\'s New Page';
  $fe_block_boxes->format = '3';
  $fe_block_boxes->machine_name = 'newest_dataset_contentimage';
  $fe_block_boxes->body = '<?php
global $base_url;
$view7 = views_get_view_result(\'latest_dataset_in_last_7_days\');
$count7=sizeof($view7);
$view30 = views_get_view_result(\'Newest_dataset\');
$count30=sizeof($view30);
echo\'<div class="content"><img alt="Data Sets" src="\'.$base_url.\'/sites/all/themes/cms/images/whatsnew-datasets.jpg" style="width: 279px; height: 155px;" title="Newest Datasets" /><div class="block-data-whats-new">Find out what datasets and tools have been added to OGPL catalogs.</div><ul class="lists new-dataset-margin"><li><span class="number-count"><b>\' .$count7.\'</b></span> new datasets/tools added in last 7 days(<a href="\'.$base_url.\'/new/7" title="view list" class="hyperlink" style="font-weight:normal;">view list</a>)</li><li><span class="number-count"><b>\'.$count30.\'</b></span> new datasets/tools added in last 30 days(<a href="\'.$base_url.\'/new/30" title="view list" class="hyperlink" style="font-weight:normal;">view list</a>)</li></ul></div>\'?>';

  $export['newest_dataset_contentimage'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Front End Newest Dataset Header What\'s New Page';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'newest_dataset_heading';
  $fe_block_boxes->body = '<h2 class="centered">Newest Datasets</h2>';

  $export['newest_dataset_heading'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Rss feeds html';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'rss_feeds_html';
  $fe_block_boxes->body = '<div class="read-more-align"><a href="whats-new" class="hyperlink">Read More </a></div><div class="lists"><ul class="lists"><li><a href="#">Jackson doctor faces sentencing</a></li><li><a href="#">Kenyan Court:Arrest Sudan\'s Bashir</a></li><li><a href="#">U.N. warns of infighting Libya brigades </a></li><li><a href="#">Egypt\'s historic vote</a></li><li><a href="#">UAE pardons political activists</a></li></ul><p>&nbsp;</p></div>';

  $export['rss_feeds_html'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Front End What\'s New Content';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'whats_new_content';
  $fe_block_boxes->body = '<p></p><h3 class="font-h3">OGPL\'s Latest News</h3><p>OGPL gets you the latest news and updates on OGPL activity here. Watch this space to keep yourself updated on the latest OGPL happenings and introductions.</p>';

  $export['whats_new_content'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'Front End What\'s New Page Title';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'whats_new_title';
  $fe_block_boxes->body = '<h2>OGPL’s Latest Updates</h2>';

  $export['whats_new_title'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass;
  $fe_block_boxes->info = 'whatsnew_news';
  $fe_block_boxes->format = '2';
  $fe_block_boxes->machine_name = 'whatsnew_news';
  $fe_block_boxes->body = '<div class="content"><img alt="New Features" src="[token global site-url]sites/all/themes/cms/images/whatsnew-.jpg" title="New Features" /><div class="data">Check out how Data.gov is making news. You\'ll also find stories about Open Government and learn how Data.gov is supporting its core principles of transparency, participation and collaboration.<div class="btnsPan "><a class="buttons green" href="datasetcatalog">Read More </a></div></div></div><p>&nbsp;</p>';

  $export['whatsnew_news'] = $fe_block_boxes;

  return $export;
}
