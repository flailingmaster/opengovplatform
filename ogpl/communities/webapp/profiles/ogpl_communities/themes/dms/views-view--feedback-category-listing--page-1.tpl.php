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
$from=$_GET['from'];
$to=$_GET['to'];
drupal_add_js('sites/all/modules/contrib/date/date_popup/lib/jquery.timeentry.pack.js');
drupal_add_js('sites/all/libraries/jquery.ui/ui/minified/ui.datepicker.min.js');
drupal_add_js('sites/all/modules/contrib/date/date_popup/date_popup.js');
?>
<html>
<head>


<link type="text/css" href="sites/all/modules/contrib/date/date.css" rel="Stylesheet" />	
<link type="text/css" href="sites/all/modules/contrib/date/date_popup/themes/datepicker.css" rel="Stylesheet" />	
<link type="text/css" href="sites/all/modules/contrib/date/date_popup/themes/jquery.timeentry.css" rel="Stylesheet" />	
<script>
$(document).ready(function()
{
$("#from_datepicker").val("<?= $from ?>");
$("#to_datepicker").val("<?= $to ?>");
$( "#from_datepicker" ).datepicker({ dateFormat: 'yy-mm-dd' });
$( "#from_datepicker" ).focus(function(){
	if ($(this).val() == 'yyyy-mm-dd')
	{
		$(this).val("").css({'color':'black'});	}
});
$( "#from_datepicker" ).blur(function(){
	if ($(this).val() == ''){
		$(this).val("yyyy-mm-dd").css({'color':'gray'});
	}else{$(this).css({'color':'black'});}
}).trigger("blur");
$( "#from_datepicker" ).change(function(){
	if ($(this).val() == 'yyyy-mm-dd'){
		$(this).css({'color':'gray'});
	}else{$(this).css({'color':'black'});}
});
$( "#from_datepicker" ).datepicker({ dateFormat: 'yy-mm-dd' });


$( "#to_datepicker" ).focus(function(){
	if ($(this).val() == 'yyyy-mm-dd')
	{
		$(this).val("").css({'color':'black'});
	}
});
$( "#to_datepicker" ).blur(function(){
	if ($(this).val() == ''){
		$(this).val("yyyy-mm-dd").css({'color':'gray'});
	}else{$(this).css({'color':'black'});}
}).trigger("blur");
$( "#to_datepicker" ).change(function(){
	if ($(this).val() == 'yyyy-mm-dd'){
		$(this).css({'color':'gray'});
	}else{$(this).css({'color':'black'});}
});
$( "#to_datepicker" ).datepicker({ dateFormat: 'yy-mm-dd' });
$('#report-submit').submit(function() {
  if($( "#to_datepicker" ).val() =="yyyy-mm-dd" && $( "#from_datepicker" ).val() !="yyyy-mm-dd"){
      alert(" To date is invalid");
	  return false;
	  }
  if($( "#to_datepicker" ).val() !="yyyy-mm-dd" && $( "#from_datepicker" ).val() =="yyyy-mm-dd"){
      alert(" From date is invalid");
      return false;	  
	  }
if($( "#from_datepicker" ).val() !="yyyy-mm-dd" && $( "#to_datepicker" ).val() !="yyyy-mm-dd"){
      from_month = document.getElementById("from_datepicker").value;
      to_month = document.getElementById("to_datepicker").value;
      month_from=from_month.split("-");
      month_to=to_month.split("-");
	  if(month_from.length!=3 && month_to.length!=3){
	    alert("From and To dates are invalid");  
		return false;
	}
	  if(month_from.length!=3){
        alert(" From date is invalid");
        return false;
      }
     if(month_to.length!=3){  
        alert(" To date is invalid");
        return false;
     }
	 
      if(month_from[0] < 1902 || month_to[0] < 1902){
       alert("Select date above year 1902");
      return false;
      }
	
   if((month_from[0]==month_to[0] && month_from[1]==month_to[1] && month_from[2]>month_to[2])  || (month_from[0]==month_to[0] && month_from[1]>month_to[1]) || (month_from[0]>month_to[0]) ){
      alert("Invalid date range");
      return false;	 
}		  
}	  
if($( "#from_datepicker" ).val() =="yyyy-mm-dd" && $( "#to_datepicker" ).val() =="yyyy-mm-dd"){
      $( "#from_datepicker" ).val("");
	  $( "#to_datepicker" ).val("");
	  }
});
});
</script>

</head>
<body>
<form class='report-form' id='report-submit'>
<div class="demo">


<label>From</label><input type="text" id="from_datepicker" name="from">

<label>To</label><input type="text" id="to_datepicker" name="to">
    <input class="report-submit" type="submit" name="submit" value="Apply">


</div><!-- End demo -->
</form>
</body>

</html>


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