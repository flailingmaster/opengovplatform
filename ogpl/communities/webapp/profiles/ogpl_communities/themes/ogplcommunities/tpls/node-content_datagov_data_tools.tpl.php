<?php
// $Id: node-og-group-post.tpl.php,v 1.3 2008/11/09 17:17:54 weitzman Exp $

/**
 * @file node-og-group-post.tpl.php
 *
 * Og has added a brief section at bottom for printing links to affiliated groups.
 * This template is used by default for non group nodes.
 *
 * Theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: Node body or teaser depending on $teaser flag.
 * - $picture: The authors picture of the node output from
 *   theme_user_picture().
 * - $date: Formatted creation date (use $created to reformat with
 *   format_date()).
 * - $links: Themed links like "Read more", "Add new comment", etc. output
 *   from theme_links().
 * - $name: Themed username of node author output from theme_user().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $submitted: themed submission information output from
 *   theme_node_submitted().
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $teaser: Flag for the teaser state.
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags false if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags false when presented in the front page.
 * - $logged_in: Flags false when the current user is a logged-in member.
 * - $is_admin: Flags false when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 */
?>
<?php
function print_link($x) {
  $original = explode('; ', $x); // ; followed by space indicates the end of a url
  $temp = array();
  foreach ($original as $value) {
    $temp[] = _filter_url($value);
  }
  $modified = implode('; ', $temp);
  echo $modified;
}
?>
<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clear-block">
<?php
	$gid =array_keys($node->og_groups);
  	drupal_add_css(drupal_get_path('theme', 'ogplcommunities') . '/styles/style-data.gov.css');
	drupal_get_path('module', 'communities_customization')."/communities_customization.module";
	//get the dataset_id
	$dataset_id=$node->field_datasetid['0']['value'];
	$cid = "dataset_json_$datasetId";
	$url = $_GET['q'];
	$string = "ratings_received";
	$pos = strpos($url,$string);
	if($pos!==false){
	//clear the cache
    cache_clear_all($cid,'cache',true);
    }
	//fetch the $result object
	$result = fetchDatasetInfo($dataset_id);
	$ogplcommunitiespath="http://www.data.gov";
	//get the data_category_type_id
	$data_category_type_id = $result->data_category_type_id;

	//check for data_category_type
	if($data_category_type_id==1){
	   $category = "raw";
	}
	elseif($data_category_type_id==2){
	  $category = "tools";
	}
	elseif($data_category_type_id==0){
	  $category = "geodata";
	}
	
 ?>
<form id="rating_comment_frm" action="<?php print $ogplcommunitiespath."/".$category."/".$dataset_id."/submit"; ?>" method="post">
<div class="content">
<h1><?php echo $result->title; ?></h1>
 <div class="detail">
<a name="description"></a>
<div class="detail-left">
<div class="categories">
<div class="detail-header"><h2>Dataset Summary</h2></div>
<table border="0" cellpadding="0" cellspacing="0" class="details-table">
	<tbody>
		<tr>
			<td align="left" valign="top"
				nowrap="nowrap" class="detailhead1 pad-top tablepad">Agency</td>
			<td align="left" valign="top" class="pad-top tablepad"><?php echo $result->agency_name;?></td>
		</tr>
		<tr>
			<td align="left" valign="top"
				nowrap="nowrap" class="detailhead1 pad-top tablepad">Sub-Agency/Organization</td>
			<td align="left" valign="top" class="pad-top tablepad"><?php echo $result->subagency_name;?></td>
		</tr>
		<tr>
			<td align="left" valign="top" nowrap="nowrap" class="detailhead1 tablepad">
				Category
			</td>
			<td align="left" valign="top" class="data tablepad"><?php echo $result->category_name; ?></td>
		</tr>
		<tr>
			<td valign="top"
				nowrap="nowrap" class="detailhead1 tablepad">Date Released</td>
			<td align="left" valign="top" class="data tablepad"><?php echo $result->date_released;?></td>
		</tr>
		<tr>
			<td align="left" valign="top"
				nowrap="nowrap" class="detailhead1 tablepad">Date Updated</td>
			<td align="left" valign="top" class="data tablepad"><?php echo $result->date_updated;?></td>
		</tr>
		<tr>
			<td align="left" valign="top"
				nowrap="nowrap" class="detailhead1 tablepad">Time Period</td>
			<td align="left" valign="top" class="data tablepad">
			<?php echo $result->temporal_coverage ?>
			</td>
		</tr>
		<tr>
			<td align="left" valign="top"
				nowrap="nowrap" class="detailhead1 tablepad">Frequency
			</td>
			<td align="left" valign="top" class="data tablepad"><?php echo $result->periodicity;?></td>
		</tr>

		<tr>
			<td align="left" valign="top"
				nowrap="nowrap" class="detailhead1 tablepad">Description
				<?php
				if($result->public_suggested=='Y') {?>
                <br/>
				<img id='tooltip_public_suggested_dataset' src="<?php print '/'.path_to_theme().'/images/public_suggested.gif' ?>" alt="Dataset suggested by public" title="Dataset suggested by public"/>
				<?php }?>
			</td>
			<td align="left" valign="top" class="data tablepad">
			<?php
			/** Removed "more" logic 05182011 Will display full description on all nodes now. */
			//$descriptionDisplayCharacters = 400;
			$descriptionText = _filter_url($result->description);
			//Display description if it will fit within allowable display
			//if(strlen($descriptionText) <= $descriptionDisplayCharacters){
			echo $descriptionText;
			//}
			//else{
			//	$firstPart = substr($descriptionText, 0, $descriptionDisplayCharacters);
			//	$secondPart = substr($descriptionText, $descriptionDisplayCharacters);
			//	echo $firstPart;
			//	echo "<span id='description_text' class='collapsible'>$secondPart</span>&nbsp;<a id='description' onclick=\"return toggleCollapsible('description');\" href=\"#description\">(more)</a>";
			//}
			?>
			</td>
		</tr>
	</tbody>
</table>
</div>

<div class="ie6-ratingfix">
<div class="categories">
 <div class="detail-header"><h2>Dataset Ratings</h2></div>
 <table border="0" cellpadding="0" cellspacing="0" width="683">
 <?php if($pos!==false){ ?>

 <tr>
 <div class="results">
        <strong>FEEDBACK RECORDED.</strong> </div>
 </tr>
 <?php  }?>
	<tr>
		<td align="left" valign="top" class="rating" width="345">
		<table class="ratetable" border="0" cellpadding="0" cellspacing="0">
					<caption>
 				    </caption>
				    <thead>
					<tr>
                    	<td class="ratetitle">&nbsp;</td>
                    	<td class="ratetitle starwidth">Current</td>
						<?php if($pos===false){ ?>
						<td class="ratetitle" style="width:110px;">Your Rating <a href="javascript:popuprating()"><span class="help">[?]</span></a></td>
                        <?php } ?>
       				</tr>
	                </thead>
	                <tbody>
                    <tr>
                      <td class="rateheader">Overall</td>
                      <td class="votes ratepad">
                      <?php
						echo '<img src="/'.path_to_theme().'/images/stars'.$result->overall_rating.'.gif" alt="'.$result->overall_rating.' out of 5" width="70" height="14" />';
                        echo '<br />(' . $result->overall_votes . ' votes)';
						?>


                      </td>
					  <?php if($pos===false){?>
                       <td class="ratepad">

				       <input name="overallrating" value="1" type="radio" align="absmiddle" class="star" title="1 out of 5"></input>
						<input name="overallrating" value="2" type="radio" align="absmiddle" class="star" title="2 out of 5"></input>
						<input name="overallrating" value="3" type="radio" align="absmiddle" class="star" title="3 out of 5"></input>
						<input name="overallrating" value="4" type="radio" align="absmiddle" class="star" title="4 out of 5"></input>	<input name="overallrating" value="5" type="radio" align="absmiddle" class="star" title="5 out of 5"></input>



					   </td>
                     <?php } ?>
		            </tr>
                    <tr>
                      <td class="rateheader">Data Utility</td>
                      <td class="votes ratepad">
		                 <?php
							echo '<img src="/'.path_to_theme().'/images/stars'.$result->utility_rating.'.gif" alt="'.$result->utility_rating.' out of 5" width="70" height="14" />';
		                 	echo '<br />(' . $result->utility_votes . ' votes)';
							?>
					</td>
					<?php if($pos===false){?>
					 <td class="ratepad">

						<input name="utilityrating" value="1" type="radio" align="absmiddle" class="star" title="1 out of 5"></input>
						<input name="utilityrating" value="2" type="radio" align="absmiddle" class="star" title="2 out of 5"></input>
						<input name="utilityrating" value="3" type="radio" align="absmiddle" class="star" title="3 out of 5"></input>
						<input name="utilityrating" value="4" type="radio" align="absmiddle" class="star" title="4 out of 5"></input>
						<input name="utilityrating" value="5" type="radio" align="absmiddle" class="star" title="5 out of 5"></input>
                      </td>
                  <?php } ?>
				  </tr>
                    <tr>
                      <td class="rateheader">Usefulness</td>
                      <td class="votes ratepad">
                      <?php
							echo '<img src="/'.path_to_theme().'/images/stars'.$result->usefulness_rating.'.gif" alt="'.$result->usefulness_rating.' out of 5" width="70" height="14" />';
							echo '<br />(' . $result->usefulness_votes . ' votes)';
							?>
						</td>
					<?php if($pos===false){?>
	                 <td class="ratepad">

						<input name="usefulnessrating" value="1" type="radio" align="absmiddle" class="star" title="1 out of 5"></input>
						<input name="usefulnessrating" value="2" type="radio" align="absmiddle" class="star" title="2 out of 5"></input>
						<input name="usefulnessrating" value="3" type="radio" align="absmiddle" class="star" title="3 out of 5"></input>
						<input name="usefulnessrating" value="4" type="radio" align="absmiddle" class="star" title="4 out of 5"></input>
						<input name="usefulnessrating" value="5" type="radio" align="absmiddle" class="star" title="5 out of 5"></input>
                      </td>
					 <?php } ?>
		            </tr>
                    <tr>
                      <td class="rateheader">Ease of Access&nbsp;&nbsp;&nbsp;</td>
                      <td class="votes ratepad">
                      <?php
							echo '<img src="/'.path_to_theme().'/images/stars'.$result->ease_of_access_rating.'.gif" alt="'.$result->ease_of_access_rating.' out of 5" width="70" height="14" />';

							echo '<br />(' . $result->ease_of_access_votes . ' votes)';
							?>
					<?php if($pos===false){?>
					 <td class="ratepad">

						<input name="easeofaccessrating" value="1" type="radio" align="absmiddle" class="star" title="1 out of 5"></input>
						<input name="easeofaccessrating" value="2" type="radio" align="absmiddle" class="star" title="2 out of 5"></input>
						<input name="easeofaccessrating" value="3" type="radio" align="absmiddle" class="star" title="3 out of 5"></input>
						<input name="easeofaccessrating" value="4" type="radio" align="absmiddle" class="star" title="4 out of 5"></input>
						<input name="easeofaccessrating" value="5" type="radio" align="absmiddle" class="star" title="5 out of 5"></input>
                      </td>
					<?php } ?>
                   </tr>

                  <tr>
                  <td>
				  <input type="hidden" name="comment" value="" />
				  <input type="hidden" name="community" value="<?php print $gid[0]; ?>" />
				  <input type="hidden" name="nid" value="<?php print $node->nid;?>" />
				  </td>
				  </tr>
				  <?php if($pos===false){?>
                   <tr>
                    	<td colspan="3">
    <div class="button">
        <input type="image" img class="imgshadow" src="/<?php print path_to_theme().'/images/button.png'?>"/>
        <div class="privacy"><a href="/privacypolicy">(Privacy Policy)</a></div>
    </div>
                    	</td>
                    </tr>
				<?php } ?>
            </tbody>
          </table>
		</td>
		<td align="left" valign="middle" width="330">
<?php if ($data_category_type_id != 0): ?>		
<a href="<?php print "/communities/node/".$gid[0]."/commentondataset/".$dataset_id; ?>" >Visit the Comment on Dataset forum to post or view comments.</a>
<?php else: ?>
&nbsp;
<?php endif; ?>
		</td>
	</tr>
</table>
</div>
</div>
</form>
<div class="categories">
	<div class="detail-header"><h2>Dataset Metrics</h2></div>
	<table border="0" cellpadding="0" cellspacing="0" class="details-table" >
	<tbody>
                  <tr>
                  <?php
                  $tooltip = "";
                  if($result->data_category_type_id == 1){
                        $tooltip = "Download represents the number of times users have clicked on <br/>
                                XML / CSV / XLS / KML/KMZ /Shapefile / Maps in the Download Information section.";

                  }else{
                    $tooltip = "Download represents the number of times users have clicked on <br/>
                                Data Extraction / Feeds / Widgets in the Download Information section.";

                  }

                  ?>
            <td class="detailhead1 tablepad"
            title='<?php echo $tooltip?>'
                        id='tooltipTd'>Number of Downloads</td>
			<td class="tablepad data">
                      <?php
                      echo ($result->count!=null) ?
                            number_format($result->count)
                            :"0";
                      ?>
                      </td>
                  </tr>
</tbody></table></div>

<div class="categories">
	<div class="detail-header"><h2>Dataset Information</h2></div>
	<table border="0" cellpadding="0" cellspacing="0" class="details-table" >
	<tbody>
		<tr>
			<td class="detailhead1 tablepad">
			<div class="pad-top">Data.gov Data Category Type</div>
			</td>
			<td class="tablepad data">
			<div class="pad-top"><?php echo $result->data_category_type_name; ?></div>
			</td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Specialized Data
			Category Designation</td>
			<td class="tablepad data"><?php echo $result->data_specialized_category_name;?></td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Keywords</td>
			<td class="tablepad data"><?php echo $result->keywords; ?></td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Unique ID</td>
			<td class="tablepad data"><?php echo $result->unique_id;?></td>
		</tr>
	</tbody>
</table>
</div>
<div class="categories">
	<div class="detail-header"><h2>Contributing Agency Information</h2></div>
	<table border="0" cellpadding="0" cellspacing="0" class="details-table">
	<tbody>
		<tr>
			<td class="detailhead1 tablepad">
			<div class="pad-top">Citation</div>
			</td>
			<td class="tablepad data">
			<div class="pad-top"><?php print_link($result->citation);?></div>
			</td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Agency Program Page</td>
			<td class="tablepad data">
				<?php print_link($result->agency_program_page);?></td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Agency Data Series Page</td>
			<td class="tablepad data">
			    <?php print_link($result->agency_data_series_page);?></td>
		</tr>
	</tbody>
</table>
</div>
<div class="categories">
	<div class="detail-header"><h2>Dataset Coverage</h2></div>
	<table border="0" cellpadding="0" cellspacing="0" class="details-table">
	<tbody>
		<tr>
			<td class="detailhead1 tablepad">
			<div class="pad-top">Unit of Analysis</div>
			</td>
			<td class="tablepad data">
			<div class="pad-top"><?php echo $result->unit_of_analysis;?></div>
			</td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Granularity</td>
			<td class="tablepad data"><?php echo $result->granularity;?></td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Geographic Coverage</td>
			<td class="tablepad data"><?php echo $result->geographic_coverage;?></td>
		</tr>
	</tbody>
</table>
</div>
<div class="categories">
	<div class="detail-header"><h2>Data Description</h2></div>
	<table border="0" cellpadding="0" cellspacing="0" class="details-table">
	<tbody>
		<tr>
			<td class="detailhead1 tablepad">
			<div class="pad-top">Collection Mode</div>
			</td>
			<td class="tablepad data">
			<div class="pad-top"><?php echo $result->collection_mode;?></div>
			</td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Data
			Collection Instrument</td>
			<td class="tablepad data"><?php print_link($result->collection_instrument);?></td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Data
			Dictionary/Variable List</td>
			<td class="tablepad data"><?php print_link($result->dictionary_list); ?></td>
		</tr>
	</tbody>
</table>
</div>
<div class="categories">
<div class="detail-header"><h2>Additional Dataset Documentation</h2></div>
<table border="0" cellpadding="0" cellspacing="0" class="details-table">
	<tbody>
		<tr>
			<td class="detailhead1 tablepad">
			<div class="pad-top">Technical Documentation</div>
			</td>
			<td class="tablepad data">
			<div class="pad-top"><?php print_link($result->technical_documentation);?></div>
			</td>
		</tr>
		<?php if($result->data_specialized_category_id == 3) { //Only display if geospatial ?>
		<tr>
			<td class="detailhead1 tablepad">FGDC Compliance
			(Geospatial Only)</td>
			<td class="tablepad data">
				<?php echo $result->fgdc_compliance; ?>
			</td>
		</tr>
		<?php } ?>
		<tr>
			<td class="detailhead1 tablepad">Additional Metadata</td>
			<td class="tablepad data">
<?php if ($result->data_category_type_id != 0): ?>
<?php print_link($result->additional_metadata);?>
<?php else: ?>
<a href="http://geo.data.gov/geoportal/rest/document?id=%7B<?php echo $result->unique_id; ?>%7D">XML Format</a>
<?php endif; ?>
            </td>
		</tr>
	</tbody>
</table>
</div>
<?php if($result->data_specialized_category_id  == 2) {  //tools ?>
<div class="categories">
<div class="detail-header"><h2>Statistical Information</h2></div>
<table border="0" cellpadding="0" cellspacing="0" class="details-table">
	<tbody>
		<tr>
			<td class="detailhead1 tablepad">
			<div class="pad-top">Statistical Methodology</div>
			</td>
			<td class="tablepad data">
			<div class="pad-top"><?php print_link($result->statistical_methodology); ?></div>
			</td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Sampling</td>
			<td class="tablepad data">
				<?php print_link($result->statistical_sampling);?>
			</td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Estimation</td>
			<td class="tablepad data">
				<?php print_link($result->statistical_estimation); ?>
			</td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Weighting</td>
			<td class="tablepad data">
				<?php print_link($result->statistical_weighting); ?>
			</td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Disclosure
			avoidance</td>
			<td class="tablepad data">
				<?php print_link($result->statistical_disclosure_avoidance); ?>
			</td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Questionnaire
			design</td>
			<td class="tablepad data">
				<?php print_link($result->statistical_questionnaire_design); ?>
			</td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Series
			breaks</td>
			<td class="tablepad data">
				<?php print_link($result->statistical_series_breaks); ?>
			</td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Non-response
			adjustment</td>
			<td class="tablepad data">
				<?php print_link($result->statistical_non_response_adjustment);?>
			</td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Seasonal
			adjustment</td>
			<td class="tablepad data">
				<?php print_link($result->statistical_seasonal_adjustment); ?>
			</td>
		</tr>
		<tr>
			<td class="detailhead1 tablepad">Statistical Characteristics</td>
			<td class="tablepad data">
				<?php print_link($result->statistical_data_quality); ?>
			</td>
		</tr>
	</tbody>
</table>
</div>
<?php } ?>
</div>
<div class="sidepad">
<div class="sidebar">
<div class="detail-header"><h2>Download Information</h2></div>
<table border="0" cellpadding="0" cellspacing="0" class="download-table">
    <?php if($result->data_category_type_id == 1) { //Instant Download?>
    <tbody>
        <tr>
            <td width="50%" class="catheader2"><!--[if lt IE 7]><a href="javascript:popupxml()">XML<img src="<?php print '/'.path_to_theme().'/images/arrow-blue.gif' ?>" alt="" width="7" height="7" /></a><![endif]-->
            <div id="row1">
            <div id="popupdet">
            <p><a href="#">XML<img src="<?php print '/'.path_to_theme().'/images/arrow-blue.gif' ?>" alt="" width="7"
                height="7" /><span><img src="<?php print '/'.path_to_theme().'/images/popup-xml.gif' ?>"
                alt="Used by automated programs capable of handling raw XML files."
                width="176" height="85" /></span></a></p>
            </div>
            </div>
            </td>
            <td class="catheader2"><!--[if lt IE 7]><a href="javascript:popupcsv()">CSV/TXT<img src="<?php print '/'.path_to_theme().'/images/arrow-green.gif' ?>" alt="" width="7" height="7" /></a><![endif]-->
            <div id="row1">
            <div id="popupdet">
            <p><a href="#">CSV/TXT<img src="<?php print '/'.path_to_theme().'/images/arrow-green.gif' ?>" alt=""
                width="7" height="7" /><span><img src="<?php print '/'.path_to_theme().'/images/popup-csv.gif' ?>"
                alt="Used for easy access to data through most desktop spreadsheet applications."
                width="176" height="111" /></span></a></p>
            </div>
            </div>
            </td>
        </tr>
        <tr>
            <td class="row-gray small"><?php if($result->xml){?> <a
                href="<?php echo $ogplcommunitiespath; ?>/download/<?php echo $dataset_id; ?>/xml"><img
                src="<?php print '/'.path_to_theme().'/images/download-xml.gif' ?>" alt="xml document" title="xml document" width="41"
                height="13" /><br />
                <?php echo $result->xml[0]->file_size; ?></a>
                <?php } else { echo '&nbsp;'; } ?></td>
            <td class="row-gray small"><?php if($result->csv){?> <a
                href="<?php echo $ogplcommunitiespath; ?>/download/<?php echo $dataset_id; ?>/csv"><img
                src="<?php print '/'.path_to_theme().'/images/download-csv.gif' ?>" alt="csv document" title="csv document" width="41"
                height="13" /><br />
                <?php echo $result->csv[0]->file_size;; ?></a>
                <?php } else { echo '&nbsp;'; } ?></td>
        </tr>
        <tr>
            <td class="catheader2"><!--[if lt IE 7]><a href="javascript:popupexcel()">XLS<img src="<?php print '/'.path_to_theme().'/images/arrow-purple.gif' ?>" alt="" width="7" height="7" /></a><![endif]-->
            <div id="row2">
            <div id="popupdet">
            <p><a href="#">XLS<img src="<?php print '/'.path_to_theme().'/images/arrow-purple.gif' ?>" alt=""
                width="7" height="7" /><span><img src="<?php print '/'.path_to_theme().'/images/popup-excel.gif' ?>"
                alt="File format used with Microsoft Excel." width="176" height="97" /></span></a></p>
            </div>
            </div>
            </td>
            <td class="catheader2"><!--[if lt IE 7]><a href="javascript:popupkml()">KML/KMZ<img src="<?php print '/'.path_to_theme().'/images/arrow-red.gif' ?>" alt="" width="7" height="7" /></a><![endif]-->
            <div id="row2">
            <div id="popupdet">
            <p><a href="#">KML/KMZ<img src="<?php print '/'.path_to_theme().'/images/arrow-red.gif' ?>" alt=""
                width="7" height="7" /><span><img src="<?php print '/'.path_to_theme().'/images/popup-kml.gif' ?>"
                alt="Displays geospatial data in Google Earth/Maps, and similar applications."
                width="176" height="85" /></span></a></p>
            </div>
            </div>
            </td>
        </tr>
        <tr>
            <td class="row-gray small"><?php if($result->xls){?> <a
                href="<?php echo $ogplcommunitiespath; ?>/download/<?php echo $dataset_id; ?>/xls"><img
                src="<?php print '/'.path_to_theme().'/images/download-xls.gif' ?>" alt="XLS document"  title="XLS document" width="41"
                height="13" /><br />
                <?php echo $result->xls[0]->file_size; ?></a>
                <?php } else { echo '&nbsp;'; } ?></td>
            <td class="row-gray small"><?php if($result->kml){?> <a
                href="<?php echo $ogplcommunitiespath; ?>/download/<?php echo $dataset_id; ?>/kml"><img
                src="<?php print '/'.path_to_theme().'/images/download-kml.gif' ?>" alt="kml document" title="kml document" width="41"
                height="13" /><br />
                <?php echo $result->kml[0]->file_size; ?></a>
                <?php
					$raw_title = $result->title;
					$raw_resource = str_replace('%27','\\\\\\\'',$result->kml[0]->access_point);
					$extension = substr($raw_resource,strrpos($raw_resource,"."));
					$allowed_extns = array('.kml', '.kmz', '.zip', '.gzip', '.tar', '.xml');
					if(in_array($extension,$allowed_extns)
					   || (strpos($raw_resource,'service=wms')!=false)
					   || (strpos($raw_resource,'wmsserver')!=false)
					   || (strpos($raw_resource,'com.esri.wms.esrimap')!=false)
					   || (strpos($raw_resource,'com.esri.esrimap.esrimap')!=false)
					   || (strpos($raw_resource,'arcgis/rest')!=false && strpos($raw_resource,'MapServer')!=false)
					   || (strpos($raw_resource,'rest/services')!=false && strpos($raw_resource,'MapServer')!=false)){ ?>
<br/>
<script type="text/javascript">
document.write('<a href="javascript:viewer(\'<?php echo addslashes($raw_title); ?>\',\'<?php echo $raw_resource; ?>\');"><img src="<?php print '/'.path_to_theme().'/images/preview-kml.gif' ?>" alt="Preview Data" height="13" width="60" border="0"/></a>');
</script>
<noscript>
<a href="/ogplcommunitiesGeoViewer/?configXml=ogplcommunities.xml&title=<?php echo urlencode($raw_title); ?>&resource=:<?php echo $raw_resource; ?>" target="_blank"><img src="<?php print '/'.path_to_theme().'/images/preview-kml.gif' ?>" alt="Preview Data" height="13" width="60" border="0"/></a>
</noscript>
                <?php } } else { echo '&nbsp;'; } ?></td>
        </tr>
        <tr>
            <td class="catheader2"><!--[if lt IE 7]><a href="javascript:popupesri()">Shapefile<img src="<?php print '/'.path_to_theme().'/images/arrow-gold.gif' ?>" alt="" width="7" height="7" /></a><![endif]-->
            <div id="row3">
            <div id="popupdet">
            <p><a href="#">Shapefile<img src="<?php print '/'.path_to_theme().'/images/arrow-gold.gif' ?>" alt="" width="7"
                height="7" /><span><img src="<?php print '/'.path_to_theme().'/images/popup-esri.gif' ?>"
                alt="Used by ESRI-compatible mapping applications and are updated monthly/quarterly."
                width="176" height="120" /></span></a></p>
            </div>
            </div>
            </td>
            <td class="catheader2">Maps</td>
        </tr>
        <tr>
            <td class="row-gray small"><?php if($result->esri){?>
            <a
                href="<?php echo $ogplcommunitiespath; ?>/download/<?php echo $dataset_id; ?>/esri"><img
                src="<?php print '/'.path_to_theme().'/images/download-esri.gif' ?>" alt="Shapefile document" title="Shapefile document" width="41"
                height="13" /><br />
                <?php echo $result->esri[0]->file_size; ?></a>
                <?php
					$raw_title = $result->title;
					$raw_resource = str_replace('%27','\\\\\\\'',$result->esri[0]->access_point);
					$extension = substr($raw_resource,strrpos($raw_resource,"."));
					$allowed_extns = array('.kml', '.kmz', '.zip', '.gzip', '.tar', '.xml');
					if(in_array($extension,$allowed_extns)
					   || (strpos($raw_resource,'service=wms')!=false)
					   || (strpos($raw_resource,'wmsserver')!=false)
					   || (strpos($raw_resource,'com.esri.wms.esrimap')!=false)
					   || (strpos($raw_resource,'com.esri.esrimap.esrimap')!=false)
					   || (strpos($raw_resource,'arcgis/rest')!=false && strpos($raw_resource,'MapServer')!=false)
					   || (strpos($raw_resource,'rest/services')!=false && strpos($raw_resource,'MapServer')!=false)){ ?>
<br/>
<script type="text/javascript">
document.write('<a href="javascript:viewer(\'<?php echo addslashes($raw_title); ?>\',\'<?php echo $raw_resource; ?>\');"><img src="<?php print '/'.path_to_theme().'/images/preview-esri.gif' ?>" alt="Preview Data" height="13" width="60" border="0"/></a>');
</script>
<noscript>
<a href="/ogplcommunitiesGeoViewer/?configXml=ogplcommunities.xml&title=<?php echo urlencode($raw_title); ?>&resource=:<?php echo $raw_resource; ?>" target="_blank"><img src="<?php print '/'.path_to_theme().'/images/preview-esri.gif' ?>" alt="Preview Data" height="13" width="60" border="0"/></a>
</noscript>
                <?php } } else { echo '&nbsp;'; } ?></td>
            <td class="row-gray map">
            <?php if($result->map) { ?>
            <a href="<?php echo '/externallink/map/' . rawurlencode(str_replace('/', '###', $result->map[0]->access_point)) . '/' . rawurlencode(str_replace('/', '###', $_SERVER['REQUEST_URI'])) ?>">View Map</a>
            <?php } else { echo "&nbsp;"; } ?>
            </td>
        </tr>
        <tr>
            <td width="50%" class="catheader2"><!--[if lt IE 7]><a href="javascript:popupxml()">RDF<img src="<?php print '/'.path_to_theme().'/images/arrow-darkblue.gif' ?>" alt="" width="7" height="7" /></a><![endif]-->
            <div id="row4">
            <div id="popupdet">
            <p><a href="#">RDF<img src="<?php print '/'.path_to_theme().'/images/arrow-darkblue.gif' ?>" alt="" width="7"
                height="7" /><span><img src="<?php print '/'.path_to_theme().'/images/popup-rdf.gif' ?>"
                alt="Used by automated programs capable of handling RDF files."
                width="176" height="85" /></span></a></p>
            </div>
            </div>
            </td>
            <td width="50%" class="catheader2"><!--[if lt IE 7]><a href="javascript:popupxml()">PDF<img src="<?php print '/'.path_to_theme().'/images/arrow-pdfred.gif' ?>" alt="" width="7" height="7" /></a><![endif]-->
            <div id="row4">
            <div id="popupdet">
            <p><a href="#">PDF<img src="<?php print '/'.path_to_theme().'/images/arrow-pdfred.gif' ?>" alt="" width="7"
                height="7" /><span><img src="<?php print '/'.path_to_theme().'/images/popup-pdf.gif' ?>"
                alt="Portable Document Format files."
                width="176" height="265" /></span></a></p>
            </div>
            </div>
            </td>
        </tr>
        <tr>
            <td class="row-gray small"><?php if($result->rdf){?> <a
                href="<?php echo $result->rdf[0]->access_point; ?>"><img
                src="<?php print '/'.path_to_theme().'/images/download-rdf.gif' ?>" alt="RDF document" title="RDF document" width="41"
                height="13" /><br />
                <?php echo $result->rdf[0]->file_size; ?></a>
                <?php } else { echo '&nbsp;'; } ?></td>
            <td class="row-gray small"><?php if($result->pdf){?> <a
                href="<?php echo $result->pdf[0]->access_point; ?>"><img
                src="<?php print '/'.path_to_theme().'/images/download-pdf.gif' ?>" alt="PDF document" title="PDF document" width="22"
                height="23" /><br />
                <?php echo $result->pdf[0]->file_size; ?></a>
                <?php } else { echo '&nbsp;'; } ?></td>
        </tr>
    </tbody>
    <?php } else if ($result->data_category_type_id == 2) { // Tools ?>
    <tbody>
        <tr>
            <td width="70%" class="catheader3"><!--[if lt IE 7]><a href="javascript:popupext()">Data Extraction<img src="<?php print '/'.path_to_theme().'/images/arrow-black.gif' ?>" alt="" width="7" height="7" /></a><![endif]-->
            <div id="row1">
            <div id="popupdet">
            <p><a href="#">Data Extraction<img src="<?php print '/'.path_to_theme().'/images/arrow-black.gif' ?>"
                alt="" width="7" height="7" /><span><img
                src="<?php print '/'.path_to_theme().'/images/popup-extraction.gif' ?>"
                alt="Allows you to select a databasket full of variables and then recode those variables in a form that the user desires. The user can then develop and customize tables. Selecting the results in a table driven by customer requirements for one-time or continued reuse."
                width="176" height="179" /></span></a></p>
            </div>
            </div>
            </td>
            <td width="30%" class="catheader3">
                <?php if($result->data_extraction){?>
                <a href="<?php echo $ogplcommunitiespath; ?>/download/<?php echo $dataset_id; ?>/data_extraction"><img
                src="<?php print '/'.path_to_theme().'/images/icon-extraction.gif' ?>" alt="extraction documents" title="extraction documents"
                width="21" height="21" /></a>
                <?php } else { echo '&nbsp;';} ?>
                </td>
        </tr>
        <tr>
            <td width="70%" class="catheader3"><!--[if lt IE 7]><a href="javascript:popupfeeds()">Feeds<img src="<?php print '/'.path_to_theme().'/images/arrow-black.gif' ?>" alt="" width="7" height="7" /></a><![endif]-->
            <div id="row2">
            <div id="popupdet">
            <p><a href="#">Feeds<img src="<?php print '/'.path_to_theme().'/images/arrow-black.gif' ?>"
                alt="" width="7" height="7" /><span><img
                src="<?php print '/'.path_to_theme().'/images/popup-feeds.gif' ?>"
                alt="Feed files include RSS, CAP and Atom feeds"
                width="176" height="170" /></span></a></p>
            </div>
            </div>
            </td>
            <td width="30%" class="catheader3">
                <?php if($result->rss){?>
                <a href="<?php echo $ogplcommunitiespath; ?>/download/<?php echo $dataset_id; ?>/rss"><img
                src="<?php print '/'.path_to_theme().'/images/icon-feed.gif' ?>" alt="Feed documents" title="Feed documents"
                width="21" height="21" /></a>
                <?php } else { echo '&nbsp;';} ?>
                </td>
        </tr>
        <tr>
            <td width="70%" class="catheader3"><!--[if lt IE 7]><a href="javascript:popupwid()">Widget<img src="<?php print '/'.path_to_theme().'/images/arrow-black.gif' ?>" alt="" width="7" height="7" /></a><![endif]-->
            <div id="row3">
            <div id="popupdet">
            <p><a href="#">Widget<img src="<?php print '/'.path_to_theme().'/images/arrow-black.gif' ?>" alt=""
                width="7" height="7" /><span><img src="<?php print '/'.path_to_theme().'/images/popup-widget.gif' ?>"
                alt="Interactive virtual tool that provides single-purpose services such as showing the user the latest news, the current weather, the time, a calendar, a dictionary, a map program, a calculator, desktop notes, photo viewers, or even a language translator, among other things."
                width="176" height="179" /></span></a></p>
            </div>
            </div>
            </td>
            <td width="30%" class="catheader3">
                <?php if($result->widget) { ?>
                <a href="<?php echo $ogplcommunitiespath; ?>/download/<?php echo $dataset_id; ?>/widget"><img src="<?php print '/'.path_to_theme().'/images/icon-widget.gif' ?>"
                alt="widget documents" title="widget documents" width="18" height="18" /></a>
                <?php } else { echo '&nbsp;'; } ?>
                </td>
        </tr>
    </tbody>
    <?php } else { // Geodata ?>
    <tbody>
        <tr>
            <td width="70%" class="catheader3"><!--[if lt IE 7]><a href="javascript:popupext()">Data Extraction<img src="<?php print '/'.path_to_theme().'/images/arrow-black.gif' ?>" alt="" width="7" height="7" /></a><![endif]-->
            <div id="row1">
            <div id="popupdet">
            <p><a href="#">Geodata<img src="<?php print '/'.path_to_theme().'/images/arrow-black.gif' ?>"
                alt="" width="7" height="7" /><span><img
                src="<?php print '/'.path_to_theme().'/images/popup-extraction.gif' ?>"
                alt="Allows you to select a databasket full of variables and then recode those variables in a form that the user desires. The user can then develop and customize tables. Selecting the results in a table driven by customer requirements for one-time or continued reuse."
                width="176" height="179" /></span></a></p>
            </div>
            </div>
            </td>
            <td width="30%" class="catheader3">
                <?php if($result->data_extraction){?>
                <a href="<?php echo $ogplcommunitiespath; ?>/download/<?php echo $result->unique_id; ?>/geodata"><img
                src="<?php print '/'.path_to_theme().'/images/icon-geo.png' ?>" alt="Geo-enabled data" title="geodata"
                width="21" height="21" /></a>
                <?php } else if($result->geodata){?>
                <a href="<?php echo $ogplcommunitiespath; ?>/download/<?php echo $result->unique_id; ?>/geodata"><img
                src="<?php print '/'.path_to_theme().'/images/icon-geo.png' ?>" alt="Geo-enabled data" title="geodata"
                width="21" height="21" /></a>
                <?php } else { echo '&nbsp;';} ?>
                </td>
        </tr>
    </tbody>
    <?php } ?>
</table>
&nbsp;<br />
<div class="commentbox">
<?php
/*
$suggest_dataset_url = $ogplcommunitiespath."/suggestdataset/frame?datasetId=".$dataset_id."&datasetType=stg.data.gov&";
<a title='Suggest Other Datasets' href="<?php echo $suggest_dataset_url?>KeepThis=false&TB_iframe=false&height=500&width=500" class='thickbox' id='suggest_dataset_frame'>Cannot find data you are looking for?  Suggest other datasets!</a><br/>
*/
?>
<a title="Suggest Other Datasets" href="http://explore.data.gov/nominate" target="_blank">Cannot find data you are looking for?  Suggest other datasets!</a><br/>
&nbsp;<br/>
</div>
</div>
</div>
</div>

<div style="clear: both;"><div class="small" style="padding:20px; text-align:right;">OMB Control No. 3090-0284</div></div>

  </div>

  <?php if ($node->og_groups && $page) {
          print '<div class="groups">'. t('Groups'). ': ';
          print '<div class="links">'.  $og_links['view']. '</div></div>';
   } ?>

  <?php print $links; ?>
</div>