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
  global $base_url;
print '<script>
$(document).ready(

function(){
$("input#year_submit").click(
function(){
if($("select#datasets-per-year").val()=="past")
window.location ="'.$base_url.'/agency-publications/month-wise";
else
window.location ="'.$base_url.'/agency-publications/month-wise/month-wise-report-per-year/"+$("select#datasets-per-year").val();
}
);
}
);
</script>';
?>
<table class="<?php print $class; ?> header-width cBoth"<?php print $attributes; ?>>
  <?php if (!empty($title)) : ?>
    <caption><?php print $title; ?></caption>
  <?php endif; ?>
  <thead>
    <tr>
		<th class="ds-list-head-new" rowspan ="2"style=" border-right:1px solid; border-radius:8px 0 0 0; width:220px; vertical-align:center;">Agency Name</th>
		<th colspan="12" class="ds-list-head-new" style="text-align:center; border-bottom:1px solid; border-right:1px solid;"> Number of Datasets published by month </th>
		<th class="ds-list-head-new" rowspan="2" style="text-align:center; border-right:1px solid; border-radius:0 8px 0 0; width:180px; vertical-align:center;">Total in the past 12 months</th>
	</tr>
	
	<tr>
      <?php
		
		$year=date('Y');
		print '<div class="metrics-datasetreport-select cBoth" style="padding:0 0 20px; "><label name="year">Select the year to view month wise report </label>: ';
		print '<select id="datasets-per-year">';
		print '<option value="past"> Past 12 months </option>';
		$year=$year-1;
		for($i=0; $i<100; $i++)
		{
			
			$yr=$year-$i;
			if($yr<2011)
			 break;
			 
			print '<option value="'.$yr.'">'.$yr.'</option>';
		}
		print '</select>';
		print '<input type="submit" name="submit" id="year_submit" value="Submit" class="form-submit"></div>';
			global	 $base_url;
		print '<div class="download-report" style="margin-top:-65px;">Download report as :<a class="hyperlink" target="download-frame" href="'.$base_url.'/agency-publications/month-wise/csv"><img src="'.$base_url.'/sites/all/themes/cms/images/csv.png" /></a> ' ;

		print '<a class="hyperlink" target="download-frame" href="'.$base_url.'/agency-publications/month-wise/xls"><img src="'.$base_url.'/sites/all/themes/cms/images/xls.png" /></a></div>';
		  
	  
	  $month=13;
	  foreach ($header as $field => $label): 
	  $month_name= date('M',mktime(0, 0, 0, date('m'), 1, date('Y')) - $month*30*3600*24);
	  $year=date('y',mktime(0, 0, 0, date('m'), 1, date('Y')) - $month*30*3600*24);
	  ?>
	    
        
		
          <?php
				  
			/*if($month==13 )
			 {       print '<th class="views-field views-field-'.$fields[$field].' ds-list-head-new-center " style="vertical-align:top;" >';
					print $label;
					}*/
			/*else if($month<=0)
			 {       print '<th class="views-field views-field-'.$fields[$field].' ds-list-head-new-center " >';
					print $label;		
					}*/
			   if($month!=13 && $month>0){
			    print '<th class="views-field views-field-'.$fields[$field].' ds-list-head-new-center ">';
				print $month_name."<br>'".$year;
				}

				$month--;		
		  ?>
        </th>
      <?php endforeach; ?>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($rows as $count => $row): ?>
      <tr class="<?php print implode(' ', $row_classes[$count]); ?> ">
        <?php 
		 $month=12;
		foreach ($row as $field => $content):
		?>
          
            <?php 
				//if(!($month==12 || $month<0) && is_numeric($content))
				 // print '<a href=agency-publication-per-month/'.$month.'>'.$content.'</a>';
				//else
				 if($field!='title')
				 {
				   print '<td class="views-field views-field-'.$fields[$field].' ds-list-item-new-center agency-bgcolor" >';
				  }
				 else
				  print '<td class="views-field views-field-'.$fields[$field].' ds-list-item-new agency-bgcolor bold-font">';
				
				 if(strlen(strstr($content,">-<")))
				  print '-';
				 else 
				  print $content; 
				 
				$month--;	
			?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
	<tr><td class="ds-list-head-new ds-list-head-btm-left" style="border-right:1px solid">Total Datasets published per month</td> 
	<?php
	   for($i=12;$i>0;$i--)
	   {
			$starttime = mktime(0, 0, 0, date('m'), 1, date('Y')) -$i*30*3600*24;    
			$endtime = mktime(0, 0, 0, date('m'), 1, date('Y'))-($i-1)*30*3600*24; 

			print '<td class="ds-list-head-new-center">';
			$result=db_query("SELECT count(*) as  cnt FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime");
			if($row=mysql_fetch_object($result))
			$total=$row->cnt;
			if($total==0) print '-';
			else
			print $total;
			print '</td>';
	   }
	   $starttime = mktime(0, 0, 0, date('m'), 1, date('Y')) -12*30*3600*24;    
	   $endtime = mktime(0, 0, 0, date('m'), 1, date('Y')); 
	   $result=db_query("SELECT count(*) as  cnt FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime");
		print '<td class="ds-list-head-new-center ds-list-head-btm-right"  >';
		if($row=mysql_fetch_object($result))
		$total=$row->cnt;
		if($total==0) print '-';
			else
			print $total;
	   print '</td></tr>';
	?>
	
  </tbody>
</table>