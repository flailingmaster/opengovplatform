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

<?php if (!empty($title)) : ?>
<caption><?php print $title; ?></caption>
<?php endif; ?>
<div class="tableData">
<table class="<?php print $class; ?>" <?php print $attributes; ?> width="100%" cellspacing="0" cellpadding="0" border="0" >
  <thead>
    <tr>
      <?php foreach ($header as $field => $label): ?>
        
          <?php 
		  if($field=='title')
		  {
		   print '<th class="views-field views-field-'. $fields[$field].'  ds-list-head-new ds-list-head-top-left twoline-sort " style="width:210px; "><h3>';
		   print $label; 
		   }
		   else if($field!='phpcode_5' )
		   {
		    print '<th class="views-field views-field-'. $fields[$field].'  ds-list-head-new" style="text-align:center;"><h3>';
		    print $label.'<br>(high-value)'; 
		   	   
		   }
		   else 
		  {  print '<th class="views-field views-field-'. $fields[$field].'  ds-list-head-new ds-list-head-top-right " style="text-align:center; width:85px;"><h3>';
		    print $label; }
		  
		  
		  ?>
        </h3></th>
		
      <?php
		
	  endforeach; ?>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($rows as $count => $row):
	 if($row['phpcode_5']!=''){
	?>
	 
      <tr class="<?php print implode(' ', $row_classes[$count]); ?> ">
        <?php foreach ($row as $field => $content): ?>
         
            <?php 
			if($field!='title')
				print ' <td class="views-field views-field-'. $fields[$field].' agency-bgcolor" style="text-align:center; "><p>';	
			else 
			  print  '<td class="views-field views-field-'. $fields[$field].' agency-bgcolor " style="font-size:1em !important; "><p>';
			print $content; 
			
			
			?>
          </p></td>
        <?php endforeach; ?>
      </tr>
	
<?php } endforeach; ?>
	  <tr><th style="padding-left:20px;"><h3>Total</h3></th> 
	<?php
	   		$cat=array('catalog_type_raw_data','catalog_type_document','catalog_type_data_apps','catalog_type_data_tools','catalog_type_data_service');
			for($i=0;$i<5;$i++){
			print '<th class="ds-list-item-new-summary" ><h3>';
			$result=db_query("SELECT count(distinct ds.nid) as cnt FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE ds.field_ds_catlog_type_type ='$cat[$i]' AND WF.sid=10");
			$val=db_query("SELECT count(distinct ds.nid) as cnt  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid  where ( ds.field_ds_catlog_type_type ='$cat[$i]')  AND ppog.field_ppog_high_value_dataset_value='Yes' AND WF.sid=10 ");
			if($row=mysql_fetch_object($result))
			$total=$row->cnt;
			if($high=mysql_fetch_object($val))
			$val=$high->cnt;
			
			if($val!=0)
			print $total.'&nbsp;('.$val.')';
			else 
			print $total;

			print '</h3></th>';	        
			}
			print '<th class="ds-list-item-new-summary" ><h3>';
			$result=db_query("SELECT count(distinct ds.nid) as cnt FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid where ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10");
			$val=db_query("SELECT count(distinct ds.nid) as cnt  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid where ppog.field_ppog_high_value_dataset_value='Yes' AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10");
			if($row=mysql_fetch_object($result))
			$total=$row->cnt;
			if($high=mysql_fetch_object($val))
			$val=$high->cnt;
			
			if($val!=0)
			print $total.'&nbsp;('.$val.')';
			else 
			print $total;

			print '</h3></th>';
			$total=db_query("SELECT max(ds.field_ds_date_submitted_value) as date FROM content_type_dataset ds INNER JOIN workflow_node wf on wf.nid=ds.nid WHERE  ds.field_ds_catlog_type_type IS NOT NULL AND wf.sid=10");
			if($row=mysql_fetch_object($total))
			$date=$row->date;
			print '<th class="ds-list-item-new-summary ds-list-head-btm-right "><h3>'.date('d/m/Y',$date).'</h3></th>';
					
            
			//$val=db_result(db_query("SELECT Count(*)  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  where ( ds.field_ds_catlog_type_type ='catalog_type_raw_data')  AND ppog.	field_ppog_high_value_dataset_value='Yes'  "));
	   
	   print '</tr>'; ?>
  </tbody>
</table>
</div>
<!-- <div class="metrics-visitorstats-table-heading"><p>Summary</p></div> -->
