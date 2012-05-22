<?php
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php
    $v = views_get_current_view();
    $query = db_prefix_tables(vsprintf($v->build_info['query'], $v->build_info['query_args']));
    $replacements = module_invoke_all('views_query_substitutions', $v);
    $query = str_replace(array_keys($replacements), $replacements, $query);
    $drupal_base_path = base_path();
    $country_list = db_query($query);
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="country-list">
    <div class="ods-list">
<?php $count = 0; ?>
<?php while ($row = db_fetch_object($country_list)){ ?>
  <?php if($count%4 == 0 || $count == 0){ ?>
  <div class="ods-list-item">
  <?php } ?>
    <?php
    $node_data = node_load($row->nid);
    $country_dataset_count = 0;
    foreach($node_data->field_country_dataset_link as $key => $country_dataset_links){
        if(!empty($country_dataset_links['url'])){
            $country_dataset_count++;
        }
    }
	if(!$country_dataset_count) continue;
    foreach($node_data->field_state_data as $key => $state_data){
        if(isset($state_data['value']['field_state_dataset_link'])){
            foreach($state_data['value']['field_state_dataset_link'] as $k => $state_data_links){
                $state_data_links['url'] = trim($state_data_links['url']);
                /*$state_links_array = explode(",", $state_data_links['value']);
                foreach($state_links_array as $state_link){
                    if(!empty($state_link)){
                        $country_dataset_count++;
                    }
                }*/
                if(!empty($state_data_links['url'])){
                    $country_dataset_count++;
                }
            }
        }
    }	
	global $base_url;
	//var_dump($base_url);die();
    $country_path = $drupal_base_path.$node_data->path;
    $country_title = trim($row->node_title);
    $country_union_name = trim($row->node_data_field_website_header_image_field_union_govt_name_value);
    $flag_image = field_file_load($row->node_data_field_website_header_image_field_website_header_image_fid);
	if(variable_get('file_downloads','') == 2) {
		//$flag_img = explode('/', $flag_image['filepath']);
		$flag_img=substr($flag_image['filepath'],strpos($flag_image['filepath'],"files/"));
		$country_header_image = $base_url."/system/".$flag_img;
		//$country_header_image = $base_url."/system/files/".$flag_image['filename'];
	} else {
		$country_header_image = trim($drupal_base_path.$flag_image['filepath']);
	}
    //$country_dataset_count = trim($row->flexifield_items_node_data_field_state_data_node_data_field_state_dataset_count_field_state_dataset_count_value);
    if($country_dataset_count > 0){
        $country_dataset_count_html = '<div class="type">'.$country_dataset_count.'</div>';
    } else {
        $country_dataset_count_html = '';
    }
    print '<div class="item"><ul><li><img alt="'.$country_union_name.'" title="'.$country_union_name.'" src="'.$country_header_image.'" border="0" class="imgflag" width="38" height="24"/></li><li class="countryname"><a title="'.$country_title.'" href="'.$country_path.'">'.$country_title.'</a>'.$country_dataset_count_html.'</li></ul></div>';
    ?>
  <?php if(($count+1)%4 == 0 && $count != 0){ ?>
  </div>
  <?php } ?>
<?php $count++; ?>
<?php } ?>
  <?php if($count%4 != 0){ ?>
  </div>
  <?php } ?>
  </div>
</div>
