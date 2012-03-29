<?php
// $Id: views-view-unformatted.tpl.php,v 1.6 2008/10/01 20:52:11 merlinofchaos Exp $
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<ul>
<?php 
$i = 1;
foreach ($view->blog_archive_statistics as $date => $count): 
$row_class = ($i%2==1?'views-row-odd':'views-row-even');
?>
  <li class="blog-archive-row <?php print $row_class?>"><?php echo l($date." ( $count )",'node/'.$view->args[0].'/blogs',array('query'=>array("date_filter[value][date]"=>date('Y-m',strtotime("01 ".$date)))));?></li>
<?php endforeach; ?>
</ul>