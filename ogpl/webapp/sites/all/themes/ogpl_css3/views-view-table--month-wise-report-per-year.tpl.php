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

if($page == 1) {
	$year = date('Y');
	if($_POST && $_POST['year']!='past')
		drupal_goto($base_url.'/agency-publications/month-wise/month-wise-report-per-year/'.$_POST['year']); 
	else if($_POST && $_POST['year']=='past')
		drupal_goto($base_url.'/agency-publications/month-wise'); 
		  
	print '<div class="metrics-datasetreport-select cBoth" style="padding:0 0 20px; ">';
	print '<form action="" method="post" id="month-select-form"> <label for="datasets-per-year">Select the year to view month wise report </label>: '; 
	print '<select name="year" id="datasets-per-year">';
	print '<option value="past"> Past 12 months </option>';
	$this_page = $_SERVER['REQUEST_URI'];
	
	$li = strripos($this_page,'/');
	$arg = substr($this_page,$li+1);
	
	$cur_year=$arg;
	$year=$year-1;
	for($i=0; $i<100; $i++) {
		$yr = $year-$i;
		if($yr<2011)
			break;
		if($cur_year==$yr) 
			print '<option value="'.$yr.'" selected="selected">'.$yr.'</option>';
		else
			print '<option value="'.$yr.'">'.$yr.'</option>';
	}
	print '</select>';
	print '<input type="submit"  id="year_submit" value="Submit" class="form-submit" title="Submit"/></form></div>';
	global	 $base_url;
	$this_page = $_SERVER['REQUEST_URI'];
	$last =strripos($this_page,'/');
	$argument=substr($this_page,$last);
	
	print '<div style="margin-top:-65px;" class="download-report">Download report as :<a title="CSV Download" class="hyperlink"  href="'.$base_url.'/month-wise-report-per-year/csv'.$argument.'"><img alt="CSV" src="'.$base_url.'/sites/all/themes/ogpl_css3/images/csv.png" /></a> ' ;
	print '<a title="XLS Download"  class="hyperlink" href="'.$base_url.'/month-wise-report-per-year/xls'.$argument.'"><img alt="XLS" src="'.$base_url.'/sites/all/themes/ogpl_css3/images/xls.png" /></a>';
	print '<a style="padding-left:3px;" title="PDF Download"  class="hyperlink" href="'.$base_url.'/printpdf/agency-publications/month-wise/month-wise-report-per-year/pdf'.$argument.'"><img alt="PDF" src="'.$base_url.'/sites/all/themes/ogpl_css3/images/pdf.png" /></a></div>';	
}
?>
<table class="<?php print $class; ?> header-width  cBoth"<?php print $attributes; ?>>
	<?php if (!empty($title)) : ?>
	<caption><?php print $title; ?></caption>
	<?php endif;
		
		$y = $view->args[0];
		
		if($page == 2) {
			$this_page = $_SERVER['REQUEST_URI'];			
			$li=strripos($this_page,'/');
			$arg=substr($this_page,$li+1);
			$cur_year=$arg;
			$year=date('Y');
		}
		$month = 13;
		if($page == 2) {
			$y = date('y',mktime(0,0,0,1,2,$arg));
			$display_year = date('Y',mktime(0,0,0,1,2,$arg));
		} else 
			$display_year = $y;
		
	?>
	<thead>
		<tr>
			<th class="ds-list-head-new" rowspan="2" style=" border-right:1px solid; <?php if($page == 1) { echo 'border-radius:8px 0 0 0; min-width:220px;'; } ?> vertical-align:center;">Agency Name</th>
			<th colspan="12" class="ds-list-head-new" style="text-align:center; <?php if($page == 1) { echo 'border-bottom:1px solid; border-right:1px solid;'; } ?>"> Number of Datasets published by month </th>
			<th class="ds-list-head-new" rowspan="2"  style=" <?php if($page == 1) { echo 'border-right:1px solid; border-radius:0 8px 0 0; min-width:180px;'; } else { echo 'border-left:1px solid;'; } ?> vertical-align:center; text-align:center;">Total in <?php print $display_year ?></th>
		</tr>
	
		<tr>
		   <?php			
			foreach ($header as $field => $label): 
	 			if($page == 2) { 
					$month_name= date('M',mktime(0, 0, 0, date('m'), 1, date('Y')) - $month*30*3600*24);
	 				$year=date('y',mktime(0, 0, 0, date('m'), 1, date('Y')) - $month*30*3600*24);
				}			
				  
				/*if($month==13)
				 {     // print '<th class="views-field views-field-'. $fields[$field].'  ds-list-head-new-center" style="width:210px;">';
						//print $label;
						}
				else if($month<=0)	
				{     // print '<th class="views-field views-field-'. $fields[$field].'  ds-list-head-new-center" style="padding:0 20px !important;">';
						//print $label;
				}	*/
                              $y = date('y',mktime(0,0,0,1,2,$y));
				if($month!=13 && $month>0) {
					if($page == 1) {
						print '<th class="views-field views-field-'. $fields[$field].'  ds-list-head-new-center" style="width:115px;" >';	
						print $label."<br/>'".$y;
						print '</th>';
					} else {
						print '<th class="views-field views-field-'.$fields[$field].' ds-list-head-new-center " >';
						print $label."<br>'".$y;
						print '</th>';	
					} 
				}
				$month--;
			endforeach; ?>
		</tr>
	</thead>
	<tbody>
	<?php foreach ($rows as $count => $row): ?>
		<tr class="<?php print implode(' ', $row_classes[$count]); ?> ">
		<?php 
			foreach ($row as $field => $content):
				if($field!='title') {
					if($page == 1)
						print '<td class="views-field views-field-'. $fields[$field].'  ds-list-item-new-center  agency-bgcolor " style="background:#EEEEEE ;" >';
					else
						print '<td class="views-field views-field-'. $fields[$field].'  ds-list-item-new-center  agency-bgcolor " style="text-align:center; background:#EEEEEE ;">';	
				} else
					print '<td class="views-field views-field-'. $fields[$field].'  ds-list-item-new  agency-bgcolor bold-font" style="background:#EEEEEE ;">';
				
				if(strlen(strstr($content,">-<")))
					print '-';
				else 
					print $content; 
				  ?>
		  </td>
		<?php endforeach; ?>
		</tr>
	<?php endforeach; ?>
	<tr><td class="ds-list-head-new-center" <?php if($page == 1){ echo 'style="border-radius:0 0 0 8px;"'; } ?>>Total Datasets published per month</td> 
	<?php
		$days=array(1=>31,28,31,30,31,30,31,31,30,31,30,31);
		for($i=1;$i<13;$i++)
		{
			$starttime = mktime(0, 0, 0, $i, 1, $cur_year);    
			$endtime = $starttime+ $days[$i]*24*3600;
			if($page == 1)
				print '<td class="ds-list-head-new-center">';
			else
				print '<td style="text-align:center;" class="ds-list-head-new-center">';
			$result=db_query("SELECT count(*) as  cnt FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime");
			if($row=mysql_fetch_object($result))
				$total=$row->cnt;
			if($total==0) 
				print '-';
			else
				print $total;
			print '</td>';
		}
		$starttime = mktime(0, 0, 0, 1, 1, $cur_year);    
		$endtime =mktime(0, 0, 0, 1, 1, $cur_year+1);

		$result=db_query("SELECT count(*) as  cnt FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime");
		if($page == 1)
			print '<td class="ds-list-head-new-center"  style="border-radius:0 0 8px 0;" >';
		else
			print '<td class="ds-list-head-new-center"  style="text-align:center;" >';	
		if($row=mysql_fetch_object($result))
			$total=$row->cnt;
		if($total==0) 
			print '-';
		else
			print $total;
		print '</td></tr>';
	?>
	</tbody>
</table>