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
    var pathName = loc.pathname.substring(0, loc.pathname.lastIndexOf('/') + 5);
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
<body onload = "loadedfun()">
<form class="metrics-result-per-page-dropdown metricsbacklink-space">
<label>Results per page</label>
<select name="itemcount" onchange="itemsperpage(this.options[this.options.selectedIndex].value);"> 
<option value="10" id="10" onchange="itemsperpage(10)">10</option> 
<option value="25" id="25" onchange="itemsperpage(25)">25</option> 
<option value="50" id="50" onchange="itemsperpage(50)">50</option> 
<option value="100" id="100" onchange="itemsperpage(100)">100</option> 
</select>
</form>
</body>
<table class="<?php print $class; ?> header-width"<?php print $attributes; ?>>
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
	print '<div class="metrics-page-records " >Page '.$pno.' of '.$total_pages.' ('.$view->total_rows.' Records)</div>';
 
  
  ?>
  <thead>
    <tr>
      <?php foreach ($header as $field => $label): ?>
       
          <?php 
		  
		  if($field=='phpcode_1')
		  { print ' <th class="views-field views-field-'.$fields[$field].' ds-list-head-new-first">';
		    print $label;
			} 
		  else if($field=='title')
		  { print ' <th class="views-field views-field-'.$fields[$field].' ds-list-head-new" style="width:450px;">';
		    print $label;
			} 	 
		  else if($field=='field_ds_sector_nid')
		   { 
		     print ' <th class="views-field views-field-'.$fields[$field].' ds-list-head-new-last" style="width:160px;">';
		     print $label;
			} 
		  else 
		  { 
		     print ' <th class="views-field views-field-'.$fields[$field].' ds-list-head-new " style="text-align:center; padding-left: 0;"  >';
		     print $label;
			} 
		  
		  
		  ?>
        </th>
      <?php endforeach; ?>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($rows as $count => $row): ?>
      <tr class="<?php print implode(' ', $row_classes[$count]); ?> ds-list-item-new">
        <?php foreach ($row as $field => $content): ?>
          
            <?php 
			//print_r($field);
			if($field=='title' || $field=='field_ds_sector_nid')
			print '<td class="views-field views-field-'.$fields[$field].'">';
			else 
			print '<td class="views-field views-field-'.$fields[$field].' ds-list-item-new-center">';
			print $content; 
			
			
			?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>