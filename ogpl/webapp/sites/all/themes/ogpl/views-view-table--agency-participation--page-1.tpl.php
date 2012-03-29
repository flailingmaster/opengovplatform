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
<table class="<?php print $class; ?>" <?php print $attributes; ?>  width="100%" cellspacing="0" cellpadding="0" border="0" >
  <thead>
    <tr>
      <?php foreach ($header as $field => $label): ?>
        
          <?php 
		  if($field=='title')
		  {
		   print '<th class="views-field views-field-<?php print $fields[$field]; ?> ds-list-head-new-first" style="width:210px; "><h3>';
		   print $label; 
		   }
		   else if($field!='phpcode_5' )
		   {
		    print '<th class="views-field views-field-<?php print $fields[$field]; ?> ds-list-head-new" style="text-align:center;"><h3>';
		    print $label.'<br>(high-value)'; 
		   	   
		   }
		   else 
		  {  print '<th class="views-field views-field-<?php print $fields[$field]; ?> ds-list-head-new-last" style="text-align:center; width:85px;"><h3>';
		    print $label; }
		  
		  
		  ?>
        </h3></th>
		
      <?php
		
	  endforeach; ?>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($rows as $count => $row): ?>
      <tr class="<?php print implode(' ', $row_classes[$count]); ?> ds-list-item-new">
        <?php foreach ($row as $field => $content): ?>
         
            <?php 
			if($field!='title')
				print ' <td class="views-field views-field-<?php print $fields[$field]; ?> " style="text-align:center;"><p>';	
			else 
			  print  '<td class="views-field views-field-<?php print $fields[$field]; ?> " style="font-size:1em !important;"><p>';
			print $content; 
			
			
			?>
          </p></td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
<p class="metrics-visitorstats-table-heading"><p>Summary</p></p>

<table width="100%" cellspacing="0" cellpadding="0" border="0" >
 <?php foreach ($header as $field => $label): ?>
        
          <?php 
		  if($field=='title')
		  {
		   print '<th class="views-field views-field-<?php print $fields[$field]; ?> ds-list-head-new-first" style=" width:210px; "><h3>';
		   print $label; 
		   }
		   else if($field!='phpcode_5' )
		   {
		    print '<th class="views-field views-field-<?php print $fields[$field]; ?> ds-list-head-new" style="text-align:center;"><h3>';
		    print $label.'<br>(high-value)'; 
		   	   
		   }
		   else 
		  {  print '<th class="views-field views-field-<?php print $fields[$field]; ?> ds-list-head-new-last" style="text-align:center; width:85px;"><h3>';
		    print $label; }
		  
		  
		  ?>
        </h3></th>
		
      <?php
		
	  endforeach; ?>
	<tr><td class="ds-list-item-new" style="padding-left:10px"><p>Total</p></td> 
	<?php
	   		$cat=array('catalog_type_raw_data','catalog_type_document','catalog_type_data_apps','catalog_type_data_tools','catalog_type_data_service');
			for($i=0;$i<5;$i++){
			print '<td class="ds-list-item-new-center" ><p>';
			$result=db_query("SELECT count(*) as cnt FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid WHERE ds.field_ds_catlog_type_type ='$cat[$i]'");
			$val=db_query("SELECT Count(*)as cnt  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  where ( ds.field_ds_catlog_type_type ='$cat[$i]')  AND ppog.field_ppog_high_value_dataset_value='Yes'  ");
			if($row=mysql_fetch_object($result))
			$total=$row->cnt;
			if($high=mysql_fetch_object($val))
			$val=$high->cnt;
			
			if($val!=0)
			print $total.'<span style="color:red">('.$val.')</span>';
			else 
			print $total;

			print '</p></td>';	        
			}
			print '<td class="ds-list-item-new-center" ><p>';
			$result=db_query("SELECT count(*) as cnt FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid where ds.field_ds_catlog_type_type IS NOT NULL");
			$val=db_query("SELECT Count(*)as cnt  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  where ppog.field_ppog_high_value_dataset_value='Yes'  ");
			if($row=mysql_fetch_object($result))
			$total=$row->cnt;
			if($high=mysql_fetch_object($val))
			$val=$high->cnt;
			
			if($val!=0)
			print $total.'<span style="color:red"> ('.$val.')</span>';
			else 
			print $total;

			print '</p></td>';
			$total=db_query("SELECT max(ds.field_ds_date_submitted_value) as date FROM content_type_dataset ds ");
			if($row=mysql_fetch_object($total))
			$date=$row->date;
			print '<td class="ds-list-item-new-center"><p>'.date('d/m/Y',$date).'</p></td>';
					
            
			//$val=db_result(db_query("SELECT Count(*)  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  where ( ds.field_ds_catlog_type_type ='catalog_type_raw_data')  AND ppog.	field_ppog_high_value_dataset_value='Yes'  "));
	   
	   print '</tr>';
	?>
  
</table>	
</div>
