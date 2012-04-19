<?php
/**
 * @file views-view-table.tpl.php
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $class: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
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
    var pathName = loc.pathname.substring(0, loc.pathname.lastIndexOf('/') + 3);
    return loc.href.substring(0, loc.href.length - ((loc.pathname + loc.search + loc.hash).length - pathName.length));
}

function loadedfun()
{
var itemcount = getUrlVars()["itemcount"];
$('#'+itemcount).attr('selected',true);
}

function itemsperpage(itemcount)
{

var selObj = document.getElementById('itemcount');
$('#'+itemcount).attr('selected',true);
window.location=getAbsolutePath()+'?itemcount='+itemcount ;
}
</script>
<?php
$select_options=array('10'=>'10','25'=>'25','50'=>'50','100'=>'100');
$selected_count=$_GET['itemcount'];
print '<div style="display:none;" class="metrics-result-per-page-dropdown cBoth switch-js-enabled">';
print '<label for="itemcount">Results per page: </label>';
print '<select id="itemcount" name="itemcount" onchange="itemsperpage(this.options[this.options.selectedIndex].value);">';
foreach($select_options as $key=>$value)
	{
		if($selected_count == $select_options[$value]) {
		print '<option value="'.$select_options[$value].'" selected = "selected" onclick="itemsperpage('.$select_options[$value].')">'.$select_options[$value].'&nbsp;</option>';
		}
		else{
		print '<option value="'.$select_options[$value].'" onclick="itemsperpage('.$select_options[$value].')">'.$select_options[$value].'&nbsp;</option>';

		}
	}
print '</select>';
print '</div>';
?>

<?php

$count=10;
$count=$_GET['itemcount'];
if($count==0) $count=10;
$this_page = $_SERVER['REQUEST_URI'];
$this_page=substr($this_page,0,stripos($this_page,"?"));
print '<div  class="metrics-result-per-page-links cBoth switch-js-disabled"> Results Per Page: ';
if($count=='10')
print ' 10 |';
else
print '<a title="Show 10 results per page" href="'.$this_page.'?&amp;itemcount=10"> 10 </a>|';
if($count=='25') print ' 25 |';
else
print '<a title="Show 25 results per page" href="'.$this_page.'?&amp;itemcount=25"> 25 </a>|';
if($count=='50') print ' 50 |';
else
print '<a title="Show 50 results per page" href="'.$this_page.'?&amp;itemcount=50"> 50 </a>|';

if($count=='100') print ' 100 ';
else
print '<a title="Show 100 results per page" href="'.$this_page.'?&amp;itemcount=100"> 100 </a>';

print '</div>';
?>


  <?php if (!empty($title)) : ?>
    <caption><?php print $title; ?></caption>
  <?php endif;
    $view = views_get_current_view();
	global $pager_total;
	$total_pages = $pager_total['0'];
	
	$pno=$_GET['page'];
	$fpage=0;
	if(!$pno)
	{ $fpage=1;}
	
	$pno=$pno+1;
    if($fpage) 
	print '<div class="metrics-page-records " >Page '.$fpage.' of '.$total_pages.' ('.$view->total_rows.' Records)</div>';
    else
	print '<div class="metrics-page-records" >Page '.$pno.' of '.$total_pages.' ('.$view->total_rows.' Records)</div>';
 
  ?>
  <table class="<?php print $class; ?> header-width"<?php print $attributes; ?>>
  <thead>
    <tr>
      <?php 
  
	  
	  foreach ($header as $field => $label): ?>
       
          <?php 
		  if($field=='phpcode_1')
		  { print ' <th class="views-field views-field-'.$fields[$field].' ds-list-head-new-first">';
		    print $label;} 
		  else if($field=='title')
		  { print ' <th class="views-field views-field-'.$fields[$field].' ds-list-head-new" style="width:425px;">';
		    print $label;} 	
		  else if($field=='field_ds_sector_nid')
		   { 
		     print ' <th class="views-field views-field-'.$fields[$field].' ds-list-head-new-last" style="width:150px;">';
		     print $label;
			} 
		  else 
		  { 
		     print ' <th class="views-field views-field-'.$fields[$field].' ds-list-head-new" style="text-align:center; padding-left: 0; ">';
		     print $label;
			} 
		   ?>
        </th>
      <?php endforeach; ?>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($rows as $count => $row): ?>
      <tr class="<?php print implode(' ', $row_classes[$count]); ?> ">
        <?php foreach ($row as $field => $content): ?>
          
            <?php 
			if($field=='title' || $field=='field_ds_sector_nid')
			print '<td class="views-field views-field-'. $fields[$field].' ds-list-item-new  ">';
			else
			print '<td class="views-field views-field-'.$fields[$field].' ds-list-item-new-center  sort-bgcolor">';	
			
			print $content; 
			
			
			?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>