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
function getUrlVars()
    {
        var vars = [], hash;
        var hashes = window.location.href.slice(window.location.href.indexOf('?') + 1).split('&');
        for(var i = 0; i < hashes.length; i++)
        {
            hash = hashes[i].split('=');
            vars.push(hash[0]);
            vars[hash[0]] = hash[1];
        }
    return vars;
    }

function getAbsolutePath() {
    var loc = window.location;
    var pathName = loc.pathname.substring(0, loc.pathname.lastIndexOf('/') + 1);
    return loc.href.substring(0, loc.href.length - ((loc.pathname + loc.search + loc.hash).length - pathName.length));
}
function getCompletePath() {
     var loc = window.location;
	var pathName;
	if(window.location.href.lastIndexOf('&itemcount')==-1)
     return window.location.href;
     else
	 return window.location.href.substring(0,window.location.href.lastIndexOf('&itemcount'));
}
function loadedpage()
{
var itemcount = getUrlVars()["itemcount"];
$('#'+itemcount).attr('selected',true);
}

function itemsperpage(itemcount)
{
//alert( document.URL+'?itemcount='+itemcount );
//alert(jQuery(location).attr('href'));
//alert(getAbsolutePath()+'/downloadbycatagories'+'?itemcount='+itemcount);
var selObj = document.getElementById('itemcount');
//alert(document.getElementById(itemcount));
$('#'+itemcount).attr('selected',true);
//selObj.options[itemcount].selected=true;
if(window.location.href.indexOf('?')==-1)
window.location=getAbsolutePath()+'downloadbycategory' +'?&itemcount='+itemcount;
else
window.location=getCompletePath()+'&itemcount='+itemcount ;
}
</script>
<div class="<?php print $classes; ?>">
  <?php if ($admin_links): ?>
    <div class="views-admin-links views-hide">
      <?php print $admin_links; ?>
    </div>
  <?php endif; ?>
  
  
<?php
global $base_url;
$this_page = drupal_get_path_alias($_GET['q']);
//echo $this_page;
print '<div class="catalog-tabs-menu"  style="float:left !important; width:100%;">';
  print '<ul class="catalog-tabs catalog-adjust"><li>';
 if($this_page=='visitorstats/downloadbycategory')
    print '<a class="active" href="'.$base_url.'/'.$this_page.'">Category</a></li>';
 else
   print '<li><a href='.$base_url.'/visitorstats/downloadbycategory>Category</a></li>';

  if($this_page=='visitorstats/downloadbyagency')
    print '<li><a class="active" href="'.$base_url.'/'.$this_page.'">Agency</a></li>';
 else
   print '<li><a href='.$base_url.'/visitorstats/downloadbyagency>Agency</a></li>';
print'</ul>';
print'</div>';
print'<div class="metrics-category-report-border">';
print'<div class="view-header metrics-visitorstats-table-heading fLeft">';
print'Downloads by Category</div>';
?>
<?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; 
print'<div class="cBoth"><p>These numbers represent the number of times a user has clicked on the "XML" or "CSV" (for example) links in the Raw Data Catalogs to download datasets and user downloads of tools in the Tool Catalog available in these categories. </p></div>';
?> 
<body onload = "loadedpage()">
<form class="metrics-result-per-page-dropdown cBoth">
<label>Results per page</label>
<select name="itemcount"onchange="itemsperpage(this.options[this.options.selectedIndex].value);">
<option value="10" id="10" onclick="itemsperpage(10)">10</option> 
<option value="25" id="25" onclick="itemsperpage(25)">25</option> 
<option value="50" id="50" onclick="itemsperpage(50)">50</option> 
<option value="100" id="100" onclick="itemsperpage(100)">100</option> 
</select>
</form>
</body>
<?php 
    $view = views_get_current_view();
	global $pager_total;
	$total_pages = $pager_total['0'];
	
	$pno=$_GET['page'];
	$fpage=0;
	if(!$pno)
	{ $fpage=1;}
	
	$pno=$pno+1;
    if($fpage) 
	print '<div class="metrics-page-records cBoth">Page '.$fpage.' of '.$total_pages.' ('.$view->total_rows.' Records)</div>';
    else
	print '<div class="metrics-page-records cBoth">Page '.$pno.' of '.$total_pages.' ('.$view->total_rows.' Records)</div>';
 
  ?>
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
  <?php endif; ?>

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

</div>
</div>
 <?php /* class view */ ?>