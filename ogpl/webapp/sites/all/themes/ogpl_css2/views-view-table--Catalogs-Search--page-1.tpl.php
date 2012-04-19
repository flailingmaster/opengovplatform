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
<div class="tableData">
<table class="<?php print $class; ?> "<?php print $attributes; ?> width="100%" cellspacing="0" cellpadding="0" border="0">
  <?php if (!empty($title)) : ?>
    <caption><?php print $title; ?></caption>
  <?php endif; ?>
  <thead>
    <tr>
      <?php $i=0;
          $width=array('40','300','80','90','85'); 
         foreach ($header as $field => $label):
        
         ?>
        <th class="views-field views-field-<?php print $fields[$field]; ?> title " style="width:<?php print $width[$i]; $i++;  ?>px;">
          <h3><?php print $label; ?></h3>
        </th>
      <?php endforeach; ?>
    </tr>
  </thead>
  <tbody >
    <?php foreach ($rows as $count => $row): ?>
      <tr class="<?php print implode(' ', $row_classes[$count]); ?> ds-list-item">
        <?php foreach ($row as $field => $content): ?>
          <td class="views-field views-field-<?php print $fields[$field]; ?> item " style="height:50px;" valign="top" align="left">
            <p><?php print $content; ?></p>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
 </table> 
</div>