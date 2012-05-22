<?php
/**
 * @file views-view.tpl.php
 * Main view template
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 * - $admin_links: A rendered list of administrative links
 * - $admin_links_raw: A list of administrative links suitable for theme('links')
 *
 * @ingroup views_templates
 */
?>

<script type="text/javascript">
<!--//--><![CDATA[//><!--
function getAbsolutePath() {
    var loc = window.location;
    var pathName = loc.pathname.substring(0, loc.pathname.lastIndexOf('/') + 1);
    return loc.href.substring(0, loc.href.length - ((loc.pathname + loc.search + loc.hash).length - pathName.length));
}
function getCompletePath(itemcount) {
     var loc = window.location;
	var pathName;
	if(window.location.href.lastIndexOf('results=<?php print $_GET['results']; ?>')==-1)
     return window.location.href+'&results='+itemcount;
     else
	 return window.location.href.replace('results=<?php print $_GET['results']; ?>','results='+itemcount);
}

function itemsperpage(itemcount)
{

if(window.location.href.indexOf('?')==-1)
window.location=getAbsolutePath()+'catalogs' +'?&results='+itemcount;
else
window.location=getCompletePath(itemcount);
}
//--><!]]>
</script>




<?php

 /* Calculating average ratings for all items (AR) */
  $result=db_query("select distinct(content_id) as nid from votingapi_vote V LEFT JOIN node N on V.content_id=N.nid where N.type='dataset' ");
  while($row=db_fetch_object($result))
  {
     $sum=$sum+get_average_ratings($row->nid);
     $count++;
  }
  
  $AR=$sum/$count;
  //print "AR=".$AR;

  /*Calculating average number of votes for all items (AV) */
$result=db_query("select distinct(content_id) as nid from votingapi_vote V LEFT JOIN node N on V.content_id=N.nid where N.type='dataset' ");

  $sum=0;
  while($row=db_fetch_object($result))
  {   
     $sum=$sum+get_average_rating_votes($row->nid);
  }
  $AV=$sum/$count;
  $AV=round($AV);

 variable_set('average_rating',$AR);
 variable_set('average_votes',$AV); 

?>
<div class="<?php print $classes; ?>">
  <?php if ($admin_links): ?>
    <div class="views-admin-links views-hide">
      <?php print $admin_links; ?>
    </div>
  <?php endif; ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>
<?php
 $result=views_get_view_result('Catalogs_Search');
   if($result)
      {
print '<div id="big-catalog-panel" class="fRight">';

global $base_url;
$this_page = $_GET['filter'];
$search_title='Browse Datasets';
	drupal_set_title('Datasets'); 

		 
		if(strlen(strstr($this_page,"catalog_type"))>0)
		{
			drupal_set_title('Datasets'); 
			if(strlen(strstr($this_page,"catalog_type_data_apps"))>0)
			{
				drupal_set_title('Apps'); 
				$search_title='Browse Apps';
			}
			else if(strstr($this_page,"catalog_type_raw_data"))
			{
				drupal_set_title('Raw Data'); 
				$search_title='Browse Raw Data';
			}
			else if(strstr($this_page,"catalog_type_document"))
			{
				drupal_set_title('Documents');
				$search_title='Browse Documents';					
			}
			else if(strstr($this_page,"catalog_type_data_tools"))
			{
				drupal_set_title('Tools');
				$search_title='Browse Tools';					
			}
			else if(strstr($this_page,"catalog_type_data_service"))
			{
				drupal_set_title('Services');
				$search_title='Browse Services';					
			}
				
}


$results_page=array('10'=>'10','25'=>'25','50'=>'50','100'=>'100');

$form['page-results']=array(

	'#type' => 'select',
	'#id'=>'selectpage',
	'#title' => t('Results Per Page'),
	'#options' =>  $results_page,
	'#value'=>$_GET['results'],
	'#attributes' => array('onchange' => 'itemsperpage(this.options[this.options.selectedIndex].value)',),

	);
print '<div class="heading">'.$search_title;
print '<div  style="display:none;" class="sort-select-box switch-js-enabled ">';
	print drupal_render($form['page-results']).'</div>';
	$count=10;
	$count=$_GET['results'];
	if($count==0) $count=10;
	$page_uri = $_SERVER['REQUEST_URI'];
	if($_GET['pageop']=='1')
	{
	  $page_uri=substr($page_uri,0,strpos($page_uri,"&pageop=1"));
    }
     $page_uri=str_replace("&","&amp;",$page_uri);
	print '<div  class="sort-select-box cBoth switch-js-disabled"> Results Per Page: ';
	if($count=='10')
	print ' 10 |';
	else
	print '<a title="Show 10 results per page" href="'.$page_uri.'?&amp;pageop=1&amp;results=10"> 10 </a>|';
	if($count=='25') print ' 25 |';
	else
	print '<a title="Show 25 results per page" href="'.$page_uri.'&amp;pageop=1&amp;results=25"> 25 </a>|';
	if($count=='50') print ' 50 |';
	else
	print '<a title="Show 50 results per page" href="'.$page_uri.'&amp;pageop=1&amp;results=50"> 50 </a>|';

	if($count=='100') print ' 100 ';
	else
	print '<a title="Show 100 results per page" href="'.$page_uri.'&amp;pageop=1&amp;results=100"> 100 </a>';

	print '</div>';
  }
?>
</div>
  <?php if ($rows): ?>
    <div class="view-content">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif;
if ($result){
  print '<div style="text-align:center;margin-right:20px;">';
	  
  print '<div class=" suggest-label">Didn`t find what you are looking for? Would like to inform/suggest?<a title="Suggest Dataset"  href="'.$base_url.'/suggest_dataset" >Suggest</a></div></div>';
  print '</div></div>';
  }
 else
{
 print'<div class="box"><div class="content"><ul>
<li>Check if your spelling is correct, or try removing filters.</li>
<li>Remove quotes around phrases to match each word individually: <em>"blue drop"</em> will match less than <em>blue drop</em>.</li>
<li>You can require or exclude terms using + and -: <em>big +blue drop</em> will require a match on <em>blue</em> while <em>big blue -drop</em> will exclude results that contain <em>drop</em>.</li>
</ul></div></div>';

}

 ?>
  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

 <?php /* class view */ ?>