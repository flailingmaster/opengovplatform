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

<?php
//Pre-process results for matrix output
$states = workflow_customizations_non_system_workflow_states();
$state_table = array('Current Workflow State' => 'Count');
foreach ($states as $sid => $name ) {
  $short_name = workflow_get_state_name($sid);
  $state_table[$short_name] = 0;
}

foreach ($rows as $count => $val) {
  $state_table[$val['state']] = $val['nid'];
}
?>


<table class="<?php print $class; ?>"<?php print $attributes; ?>>
  <?php if (!empty($title)) : ?>
    <caption><?php print $title; ?></caption>
  <?php endif; ?>


  <thead>
    <tr>
      <?php foreach ($state_table as $state_name => $count): ?>
        <th class="views-field">
          <?php print $state_name; ?>
        </th>
      <?php endforeach; ?>
    </tr>
  </thead>
  <tbody>
    <tr class="<?php print implode(' ', $row_classes[0]); ?>">
      <?php foreach ($state_table as $state_name => $count): ?>
        <td class="views-field">
          <?php print $count; ?>
        </td>
      <?php endforeach; ?>
    </tr>
  </tbody>
</table>
