<?php
/**
 * @file views-view.tpl.php
 * Main view template
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 * - $admin_links: A rendered list of administrative links
 * - $admin_links_raw: A list of administrative links suitable for theme('links')
 *
 * @ingroup views_templates
 */
?>
<?php
drupal_add_js('sites/all/modules/contrib/date/date_popup/lib/jquery.timeentry.pack.js');
drupal_add_js('sites/all/libraries/jquery.ui/ui/minified/ui.datepicker.min.js');
drupal_add_js('sites/all/modules/contrib/date/date_popup/date_popup.js');

?>

<link type="text/css" href="sites/all/modules/contrib/date/date.css" rel="Stylesheet" />	
<link type="text/css" href="sites/all/modules/contrib/date/date_popup/themes/datepicker.css" rel="Stylesheet" />	
<link type="text/css" href="sites/all/modules/contrib/date/date_popup/themes/jquery.timeentry.css" rel="Stylesheet" />	

<div class="<?php print $classes; ?>">
  <?php if ($admin_links): ?>
    <div class="views-admin-links views-hide">
      <?php print $admin_links; ?>
    </div>
  <?php endif; ?>
  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows): ?>
    <div class="view-content">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div> <?php /* class view */ ?>
<?php $view_name = $classes_array[3]; 
$display_name = str_replace("_", "-", substr($classes_array[3], strpos($classes_array[3], 'page'))); 
?>
<script>
$(document).ready(function()
{
$(".<?php echo $view_name; ?> form input#edit-date-filter-min-date").attr('id', 'min-date-<?php echo $display_name; ?>');
$(".<?php echo $view_name; ?> form input#edit-date-filter-max-date").attr('id', 'max-date-<?php echo $display_name; ?>');

$("#min-date-<?php echo $display_name; ?>").val(("<?= date("Y-m-d",strtotime('-31 days')) ?>"));
$("#max-date-<?php echo $display_name; ?>").val(("<?= date("Y-m-d" ) ?>"));
$("#min-date-<?php echo $display_name; ?>").datepicker({ dateFormat: 'yy-mm-dd' });
$("#max-date-<?php echo $display_name; ?>").datepicker({ dateFormat: 'yy-mm-dd' });
});
</script>
