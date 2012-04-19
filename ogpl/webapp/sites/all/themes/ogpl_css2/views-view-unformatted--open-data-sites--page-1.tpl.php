<?php
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="open-data-sites-list">
<?php $row_count = 0; $total_count=count($rows); ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="<?php print $classes[$id]; ?> open-data-sites-country">
    <?php 
    $row_count++;
    $row = str_replace("()", "(0)", $row);
    print $row;
    ?>
  </div>
  <?php if($row_count%3 == 0 && $row_count < $total_count){ ?>
  <div class="seperator cBoth"></div>
  <?php } ?>
<?php endforeach; ?>
</div>