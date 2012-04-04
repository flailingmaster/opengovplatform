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
<table class="<?php print $class; ?>"<?php print $attributes; ?>>
  <?php if (!empty($title)) : ?>
    <caption><?php print $title; ?></caption>
  <?php endif; ?>
  
  
  <thead>
    <tr>
     <th>
	Current Workflow State
	</th>
<?php
for($i=0;$i<sizeof($rows);$i++)
	{	
		print '<th>';
		print $rows[$i][state];}
	?>
       </th>         
        
</tr>
  </thead>
  <tbody>
    <tr>
	<td> Count </td>
 <?php
for($i=0;$i<sizeof($rows);$i++)
	{	
		print '<td>';
		print $rows[$i][nid];}
	?>
       </td> 

	</tr>
  </tbody>
</table>