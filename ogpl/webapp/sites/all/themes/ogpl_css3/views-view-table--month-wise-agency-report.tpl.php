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
$view = views_get_current_view();
foreach($view->result as $res) {
	if($res->view_name) { $view_name = $res->view_name; break; }
}
$page = 1;
if(strpos($view_name, "page_2"))
	$page = 2;	
?>
<?php
	if($page == 1) {
		$year=date('Y');
		
			  if($_POST && $_POST['year']!='past')
			   drupal_goto($base_url.'/agency-publications/month-wise/month-wise-report-per-year/'.$_POST['year']); 
			  print '<div class="metrics-datasetreport-select cBoth" style="padding:0 0 20px; ">';
			  print '<form action="" method="post" id="month-select-form"><label for="datasets-per-year">Select the year to view month wise report </label>: ';
		print '<select name="year" id="datasets-per-year">';
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
		print '<input type="submit" id="year_submit" value="Submit" class="form-submit" title="Submit"/></form></div>';
			global	 $base_url;
		print '<div class="download-report" style="margin-top:-65px;">Download report as :<a title="CSV Download" class="hyperlink"  href="'.$base_url.'/agency-publications/month-wise/csv"><img alt="CSV" src="'.$base_url.'/sites/all/themes/ogpl_css3/images/csv.png" /></a> ' ;

		print '<a title="XLS Download" class="hyperlink"  href="'.$base_url.'/agency-publications/month-wise/xls"><img alt="XLS" src="'.$base_url.'/sites/all/themes/ogpl_css3/images/xls.png" /></a>';
		print '<a style="padding-left:3px;" title="PDF Download"class="hyperlink" href="'.$base_url.'/printpdf/agency-publications/month-wise/pdf"><img alt="PDF" src="'.$base_url.'/sites/all/themes/ogpl_css3/images/pdf.png" /></a></div>';
	}
		  
?>	  
<table class="<?php print $class; ?> header-width cBoth"<?php print $attributes; ?>>
	<?php if (!empty($title)) : ?>
		<caption><?php print $title; ?></caption>
	<?php endif; ?>
	<thead>
		<tr>
			<th class="ds-list-head-new" rowspan ="2"style=" border-right:1px solid; <?php if($page == 1) echo 'border-radius:8px 0 0 0; width:220px;'; ?> vertical-align:center;">Agency Name</th>
			<th colspan="12" class="ds-list-head-new" style="text-align:center; <?php if($page == 1) echo 'border-bottom:1px solid; border-right:1px solid;'; ?>"> Number of Datasets published by month </th>
			<th class="ds-list-head-new" rowspan="2" style="text-align:center; <?php if($page == 1) { echo 'border-right:1px solid; border-radius:0 8px 0 0; width:180px;'; } else { echo 'border-left:1px solid;'; } ?> vertical-align:center;">Total in the past 12 months</th>
		</tr>
	
		<tr>
			<?php
				$month=13;
				foreach ($header as $field => $label): 
					$month_name= date('M',mktime(0, 0, 0, date('m'), 1, date('Y')) - $month*30*3600*24);
					$year=date('y',mktime(0, 0, 0, date('m'), 1, date('Y')) - $month*30*3600*24);
				       if(date('m')=='3'&& $month==1) $month_name='Feb';
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
						print $month_name."<br/>'".$year;
						print '</th>';    
					}
					$month--;		
				endforeach; 
			?>
		</tr>
	</thead>
	<tbody>
		<?php foreach ($rows as $count => $row):
               if(!strlen(strstr($row['phpcode_12'],">-<")))
		  {
                ?>
                    
			<tr class="<?php print implode(' ', $row_classes[$count]); ?> ">
				<?php 
				$month=12;
				foreach ($row as $field => $content):			
					//if(!($month==12 || $month<0) && is_numeric($content))
					 // print '<a href=agency-publication-per-month/'.$month.'>'.$content.'</a>';
					//else
					 if($field!='title')
					 {
					   if($page == 1)
							print '<td class="views-field views-field-'.$fields[$field].' ds-list-item-new-center agency-bgcolor" style="background:#EEEEEE ;" >';
						else
							print '<td class="views-field views-field-'.$fields[$field].' ds-list-item-new-center agency-bgcolor" style="text-align:center; background:#EEEEEE ;" >';	
					  }
					 else
					  print '<td class="views-field views-field-'.$fields[$field].' ds-list-item-new agency-bgcolor bold-font" style="background:#EEEEEE ;">';
					
					 if(strlen(strstr($content,">-<")))
					  print '-';
					 else 
					  print $content; 
					 
					$month--;	
				?>
				</td>
				<?php endforeach; ?>
			</tr>
		<?php } endforeach; ?>
		<tr><td class="ds-list-head-new ds-list-head-btm-left" <?php if($page == 1) echo 'style="border-right:1px solid"'; ?>>Total Datasets published per month</td> 
		<?php
		for($i=12;$i>0;$i--)
		{
			$starttime = mktime(0, 0, 0, date('m'), 1, date('Y')) -$i*30*3600*24;    
			$endtime = mktime(0, 0, 0, date('m'), 1, date('Y'))-($i-1)*30*3600*24; 
			if($page == 1)
			print '<td class="ds-list-head-new-center">';
			else
			print '<td class="ds-list-head-new-center" style="text-align:center;">';	
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
		$result = db_query("SELECT count(*) as  cnt FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime");
		if($page == 1)
			print '<td class="ds-list-head-new-center ds-list-head-btm-right"  >';
		else
			print '<td class="ds-list-head-new-center ds-list-head-btm-right" style="text-align:center;" >';	
		if($row=mysql_fetch_object($result))
			$total=$row->cnt;
		$total_value = ($total == 0) ? '-': $total;
		print $total_value;
		print '</td></tr>';
		?>
	</tbody>
</table>