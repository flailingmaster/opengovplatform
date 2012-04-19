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

 if($current_view_name == 'views_by_agency')
	$comparefield = 'field_agency_name_value' ;
 else
	$comparefield = 'field_sector_title_value';
?>

<table class="<?php print $class; ?> header-width cBoth"<?php print $attributes; ?>>
  <?php if (!empty($title)) : ?>
    <caption><?php print $title; ?></caption>
  <?php endif; ?>
  <thead>
    <tr>
      <?php foreach ($header as $field => $label): ?>
        
          <?php
		    
			if($field==$comparefield)
				print '<th class="views-field views-field-'.$fields[$field].' ds-list-head-new-first ">';
			else 
				print '<th class="views-field views-field-'.$fields[$field].' ds-list-head-new-center ds-list-head-new-last ">';
		  print $label; ?>
        </th>
      <?php endforeach; ?>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($rows as $count => $row): ?>
      <tr class="<?php print implode(' ', $row_classes[$count]); ?>">
        <?php foreach ($row as $field => $content): ?>
          
            <?php 
			if($field==$comparefield)
			print '<td class="views-field views-field-'.$fields[$field].' ds-list-item-new sort-bgcolor">';
			else 
			print '<td class="views-field views-field-'.$fields[$field].' ds-list-item-new-center sort-bgcolor" >';
			print $content; 
			
			?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
<?php 
if($current_view_name == 'views_by_agency'){
	if ($pager): ?>
    <?php print $pager; ?>

	<?php endif; ?>
<?php  }?>