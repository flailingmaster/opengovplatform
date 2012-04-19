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

foreach($view->result as $res) {
	if($res->view_name) {
		$view_name = $res->view_name;
		break;
	}
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
			if($field=='counter')
			{
				print '<th class="views-field views-field-<?php print $fields[$field]; ?> ds-list-head-new-first" style="text-align:center; ">';
				print $label; 
			}
			else if($field==='field_feedback_body_value')
			{
				print '<th class="views-field views-field-<?php print $fields[$field]; ?> ds-list-head-new" style="width:550px; ">';
				print $label;
			}
			else if($field=='value') 
			{  
				print '<th class="views-field views-field-<?php print $fields[$field]; ?> ds-list-head-new-last" style="text-align:center;">';
				print $label; 
			}
			else 
			{
			    print '<th class="views-field views-field-<?php print $fields[$field]; ?> ds-list-head-new" style="text-align:center;">';
				print $label; 
			}
			?>      
        </th>
      <?php endforeach; ?>
    </tr>
  </thead>
  <tbody>
    <?php  if((count($rows)) > 0 || strpos($view_name,'page_1') || strpos($view_name,'page_3') ) { ?>
    <?php foreach ($rows as $count => $row): ?>
      <tr class="<?php print implode(' ', $row_classes[$count]); ?>">
        <?php foreach ($row as $field => $content): ?>
		<?php 	if($field=='counter'||$field=='phpcode') {
					print '<td class="views-field views-field-<?php print $fields[$field]; ?> ds-list-item-new-center"  >';
					print $content;
				}
				else if($field=='field_feedback_body_value') {
					print '<td class="views-field views-field-<?php print $fields[$field]; ?> ds-list-item-new">';
					print $content;
				}
				else
				{
				   print '<td class="views-field views-field-<?php print $fields[$field]; ?> ds-list-item-new-center"  >';
				   print $content;
				}
		?>
            <?php //print $field.'(' .$content; ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
	<?php }else{
		print "No Suggested Apps exist";
		}
	?>
  </tbody>
</table>