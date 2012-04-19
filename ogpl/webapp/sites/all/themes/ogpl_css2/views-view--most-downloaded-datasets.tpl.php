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
if(strpos($classes_array[3], 'page_1')) {
	global $base_url;
	print '<script>
	$(document).ready(
	function(){
	$("input#submit_btn").click(
	function(){
	window.location ="'.$base_url.'/visitorstats/top10datasetreport/"+$("select#Top10DatasetReportType").val();
	}
	);
	}
	);
	</script>';

	$viewname = $classes_array[2];

	switch($viewname) {
		case 'view-id-most_viewed_10_datasets': $selected_view = 1;break;
		case 'view-id-recently_added_10_datasets': $selected_view = 2;break;
		case 'view-id-most_downloaded_datasets': $selected_view = 3;break;
		case 'view-id-most_rated_datasets': $selected_view = 4;break;
		case 'view-id-most_downloaded_10_datasets30day': $selected_view = 5;break;
		case 'view-id-most_downloaded_10_dataset1year': $selected_view = 6;break;
		default: $selected_view = 0;
	}
	?>
	<div class="metrics-datasetreport-select" style="margin-top:32px">
	<div style="float:left;"><label for="Top10DatasetReportType">Select the type of Report to view: </label> </div>
		<div style="float:left;">
			<div style="margin:0 0 0 20px;" class="switch-js-disabled">
				<?php
				print '<ul>';
				if($selected_view == 3)
					print '<li>Most Downloaded 10 Datasets (All Time)</li>';
				else
					print '<li><a href="'.$base_url.'/visitorstats/top10datasetreport/MostdownloadedAllTime" title="Most Downloaded 10 Datasets (All Time)">Most Downloaded 10 Datasets (All Time)</a></li>';
				
				if($selected_view == 5)
					print '<li>Most Downloaded 10 Datasets (Last 30 Days)</li>';
				else
					print '<li><a href="'.$base_url.'/visitorstats/top10datasetreport/Mostdownloaded30Days" title="Most Downloaded 10 Datasets (Last 30 Days)">Most Downloaded 10 Datasets (Last 30 Days)</a></li>';
				
				if($selected_view == 6)
					print '<li>Most Downloaded 10 Datasets(Last One Year)</li>';
				else
					print '<li><a href="'.$base_url.'/visitorstats/top10datasetreport/Mostdownloaded1Year" title="Most Downloaded 10 Datasets(Last One Year)">Most Downloaded 10 Datasets(Last One Year)</a></li>';
				
				if($selected_view == 2)
					print '<li>Most Recently Added 10 Datasets</li>';
				else
					print '<li><a href="'.$base_url.'/visitorstats/top10datasetreport/Mostrecent" title="Most Recently Added 10 Datasets">Most Recently Added 10 Datasets</a></li>';
				
				if($selected_view == 4)
					print '<li>Highest Rated 10 Datasets</li>';
				else
					print '<li><a href="'.$base_url.'/visitorstats/top10datasetreport/HighestRatedDatasets" title="Highest Rated 10 Datasets">Highest Rated 10 Datasets</a></li>';
				if($selected_view == 1)
					print '<li>Most Viewed 10 Datasets</li>';
				else
					print '<li><a href="'.$base_url.'/visitorstats/top10datasetreport/Mostviewed" title="Most Viewed 10 Datasets">Most Viewed 10 Datasets</a></li>';
				print '</ul>'; 
			?>

			</div>
		<div style="display:none;" class="switch-js-enabled">
			<select id="Top10DatasetReportType">
			<option <?php if($selected_view == 3) echo 'selected="selected"'; ?> value="MostdownloadedAllTime">Most Downloaded 10 Datasets (All Time) </option>
			<option <?php if($selected_view == 5) echo 'selected="selected"'; ?>  value="Mostdownloaded30Days">Most Downloaded 10 Datasets (Last 30 Days) </option>
			<option <?php if($selected_view == 6) echo 'selected="selected"'; ?> value="Mostdownloaded1Year">Most Downloaded 10 Datasets (Last One Year) </option>
			<option <?php if($selected_view == 2) echo 'selected="selected"'; ?> value="Mostrecent">Most Recently Added 10 Datasets </option>
			<option <?php if($selected_view == 4) echo 'selected="selected"'; ?> value="HighestRatedDatasets">Highest Rated 10 Datasets </option>
			<option <?php if($selected_view == 1) echo 'selected="selected"'; ?> value="Mostviewed">Most Viewed 10 Datasets </option>
			</select>
			<input type="submit" name="submit" id="submit_btn" value="Submit" style="margin-top:-6px;" title="Submit" />
		</div>
		</div>
		<div style="clear:both;"></div>
	</div>
<?php } ?>

<div class="<?php print $classes; ?>">
  <?php if ($admin_links): ?>
    <div class="views-admin-links views-hide">
      <?php print $admin_links; ?>
    </div>
  <?php endif; ?>
  <?php if ($header): ?>
    <div class="view-header" style="clear:both;">
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
