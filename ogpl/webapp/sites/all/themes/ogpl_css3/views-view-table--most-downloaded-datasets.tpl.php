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
$view = views_get_current_view();
$current_view_name = $view->name;
switch($current_view_name) {
	case 'most_rated_datasets' :$compare_field = 'phpcode_1'; break;
	case 'most_viewed_10_datasets' :$compare_field = 'totalcount_1'; break;
	case 'recently_added_10_datasets':$compare_field = 'phpcode_1'; break;
	default: $compare_field = 'dcid';
}
?>
<table class="header-width <?php print $class; ?> cBoth"<?php print $attributes; ?>>
  <?php if (!empty($title)) : ?>
    <caption><?php print $title; ?></caption>
  <?php endif; ?>
  <thead>
    <tr>
      <?php foreach ($header as $field => $label): ?>
		<?php
	   if($field=='rownumber')
		  {
		   print '<th class="views-field views-field-<?php print $fields[$field]; ?> ds-list-head-new-first" style="text-align:center; ">';
		   print $label; 
		   }
		   else if($field=='field_ds_agency_short_name_value')
		   {
		    print '<th class="views-field views-field-.$fields[$field]; ?> ds-list-head-new" style="text-align:center;">';
		    print $label;
		   	   
		   }
		   if($field==='title'||$field==='field_ds_sector_nid')
		   {print '<th class="views-field views-field-<?php print $fields[$field]; ?> ds-list-head-new">';
		    print $label;
		   }
		  if($field==$compare_field) 
		  {  print '<th class="views-field views-field-<?php print $fields[$field]; ?> ds-list-head-new-last" style="text-align:center;">';
		    print $label; 
		  }
			?>        
	</th>
      <?php endforeach; ?>
    </tr>
  </thead>
  
  <?php
	if($current_view_name == 'most_rated_datasets') {
		for($i=0;$i<count($rows);$i++) {
			for($j=$i+1;$j<count($rows);$j++) {
				if($rows[$i][phpcode_1]<$rows[$j][phpcode_1]) {   
					$tmp=$rows[$i];
					$rows[$i]=$rows[$j];
					$rows[$j]=$tmp;
				}
			}
		}
		for($i=0;$i<count($rows);$i++) {
			for($j=$i+1;$j<count($rows);$j++) {
				if($rows[$i][rownumber]>$rows[$j][rownumber]) {   
					$tmp=$rows[$i][rownumber];
					$rows[$i][rownumber]=$rows[$j][rownumber];
					$rows[$j][rownumber]=$tmp;
				}
			}
		}
		$rows=array_slice($rows,0,10);
	}
	
?>
  <tbody>
    <?php foreach ($rows as $count => $row): ?>
      <tr class="<?php print implode(' ', $row_classes[$count]); ?> ">
        <?php foreach ($row as $field => $content): ?>
          <?php if($field=='rownumber' || $field==$compare_field || $field=='field_ds_agency_short_name_value')
				 {
				   print '<td class="views-field views-field-<?php print $fields[$field]; ?> ds-list-item-new-center"  >';
				  }
				 else
				  print '<td class="views-field views-field-<?php print $fields[$field]; ?> ds-list-item-new">';?>
            <?php print $content; ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
