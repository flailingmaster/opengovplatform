<?php
$api_key = variable_get('google_map_key','');
//ABQIAAAATjUXEpdkdIMjQBxoSahpVhSo7Vw341OXP0XuFYhKgaD3vqlZNRTGJF0A7dESF1SRO3GKMINo-J6Row
?>
<!--<script src="http://maps.google.com/maps?file=api&amp;v=2&amp;sensor=false&amp;key=ABQIAAAAPDUET0Qt7p2VcSk6JNU1sBSM5jMcmVqUpI7aqV44cW1cEECiThQYkcZUPRJn9vy_TWxWvuLoOfSFBw" type="text/javascript"></script>-->
<!--<script src="http://maps.google.com/maps?file=api&amp;v=2&amp;sensor=true&amp;key=ABQIAAAATjUXEpdkdIMjQBxoSahpVhSo7Vw341OXP0XuFYhKgaD3vqlZNRTGJF0A7dESF1SRO3GKMINo-J6Row" type="text/javascript"></script>
<style>-->
<script src="http://maps.google.com/maps?file=api&amp;v=2&amp;sensor=true&amp;key=<?php echo $api_key; ?>" type="text/javascript"></script>
<?php
$base_url = base_path();
$parent_page_url = $_SERVER['REDIRECT_URL'];

$static_image_map = 'http://maps.googleapis.com/maps/api/staticmap?center=:title&zoom=4&size=372x283&markers=:map_markers&sensor=true';
$map_markers = '';
if(empty($_GET['region'])){
    $static_image_map = str_replace(':title', $node->title, $static_image_map);
} else {
    $static_image_map = str_replace(':title', trim($_GET['region']), $static_image_map);
}
if(empty($_GET['coord'])){
    $static_image_map = str_replace(':map_markers', '', $static_image_map);
} else {
    $static_image_map = str_replace(':map_markers', trim($_GET['coord']), $static_image_map);
}
$state_static_data = '';
$static_html_empty = true;

$states_data = array();
$agency_data = array();
$region_types_array = array('state','city','municipality');
foreach($node->field_state_data as $key => $value){
    
    $region_type = isset($value['value']['field_region_type'][0]['value']) ? strtolower(trim($value['value']['field_region_type'][0]['value'])) : '';
    $state_dataset_link = isset($value['value']['field_state_dataset_link'][0]['url']) ? trim($value['value']['field_state_dataset_link'][0]['url']) : '';
    $state_latitude = isset($value['value']['field_state_latitude'][0]['value']) ? trim($value['value']['field_state_latitude'][0]['value']) : '';
    $state_longitude = isset($value['value']['field_state_longitude'][0]['value']) ? trim($value['value']['field_state_longitude'][0]['value']) : '';
    $state_name = isset($value['value']['field_state_name'][0]['value']) ? trim($value['value']['field_state_name'][0]['value']) : '';
    $state_portal_link = isset($value['value']['field_state_portal_link'][0]['url']) ? trim($value['value']['field_state_portal_link'][0]['url']) : '';
    $sub_region = isset($value['value']['field_sub_region'][0]['value']) ? trim($value['value']['field_sub_region'][0]['value']) : '';
    
    $dimensions = $state_latitude.','.$state_longitude;
    if(!empty($_GET['region'])){
        $region_name = $sub_region;
        if($region_type == 'state' || $region_type == 'agency'){
            $region_name = $state_name;
        }
        if(trim($_GET['region']) == $region_name && trim($_GET['type']) == $region_type && $static_html_empty){
            if(!empty($state_portal_link)){
            $state_static_data .= '<div>State/Province Portal:</div><a href="'.$state_portal_link.'" title="'.$state_portal_link.'" target="_blank">'.$state_portal_link.'</a><br>';
            }
            $dataset_links_html = '';
            if(!empty($state_dataset_link)){
                $dataset_links_html .= '<a href="'.$state_dataset_link.'">'.$state_dataset_link.'</a>';
            }
            if(strlen(trim($dataset_links_html)) > 0){
                $state_static_data .= '<div class="dataset-links"><div>Open Data Sites:</div>'.$dataset_links_html.'</div>';
            }
            $static_html_empty = false;
        }
    }
    $state_details = array();
    $sub_region_details = array();
    if(empty($state_name)){
        continue;
    }
	if($dimensions==','){
		$dimensions=$node->field_country_latitude[0]['value'].','.$node->field_country_longitude[0]['value'];
}

    if(in_array($region_type, $region_types_array)) {
        if(!isset($states_data[$state_name])){
            $states_data[$state_name] = array();
            $states_data[$state_name]['name'] = $state_name;
            $states_data[$state_name]['region_type'] = $region_type;
            $states_data[$state_name]['dataset_link'] = null;
            $states_data[$state_name]['portal_link'] = null;
            $states_data[$state_name]['latitude'] = null;
            $states_data[$state_name]['longitude'] = null;
            $parent_page_url_withparam = $parent_page_url.'?region='.$state_name.'&type='.$region_type.'&coord='.$dimensions;
            $states_data[$state_name]['page_url'] = $parent_page_url_withparam;
            $states_data[$state_name]['sub_regions'] = array();
        }
        if($region_type == 'state'){
            $states_data[$state_name]['name'] = $state_name;
            $states_data[$state_name]['region_type'] = $region_type;
            $states_data[$state_name]['dataset_link'] = $state_dataset_link;
            $states_data[$state_name]['portal_link'] = $state_portal_link;
            $states_data[$state_name]['latitude'] = $state_latitude;
            $states_data[$state_name]['longitude'] = $state_longitude;
            $parent_page_url_withparam = $parent_page_url.'?region='.$state_name.'&type='.$region_type.'&coord='.$dimensions;
            $states_data[$state_name]['page_url'] = $parent_page_url_withparam;
            $states_data[$state_name]['sub_regions'] = array();
        } else {
            $sub_region_details['name'] = $sub_region;
            $sub_region_details['region_type'] = $region_type;
            $sub_region_details['dataset_link'] = $state_dataset_link;
            $sub_region_details['portal_link'] = $state_portal_link;
            $sub_region_details['latitude'] = $state_latitude;
            $sub_region_details['longitude'] = $state_longitude;
            $parent_page_url_withparam = $parent_page_url.'?region='.$sub_region.'&type='.$region_type.'&coord='.$dimensions;
            $sub_region_details['page_url'] = $parent_page_url_withparam;
            $states_data[$state_name]['sub_regions'][] = $sub_region_details;
        }
    } else {
        if(!isset($agency_data[$state_name])){
            $agency_data[$state_name] = array();
            $agency_data[$state_name]['name'] = $state_name;
            $agency_data[$state_name]['region_type'] = $region_type;
            $agency_data[$state_name]['dataset_link'] = null;
            $agency_data[$state_name]['portal_link'] = null;
            $agency_data[$state_name]['latitude'] = null;
            $agency_data[$state_name]['longitude'] = null;
            $parent_page_url_withparam = $parent_page_url.'?region='.$state_name.'&type='.$region_type.'&coord='.$dimensions;
            $agency_data[$state_name]['page_url'] = $parent_page_url_withparam;
            $agency_data[$state_name]['sub_regions'] = array();
        }
        if($region_type == 'agency'){
            $agency_data[$state_name]['name'] = $state_name;
            $agency_data[$state_name]['region_type'] = $region_type;
            $agency_data[$state_name]['dataset_link'] = $state_dataset_link;
            $agency_data[$state_name]['portal_link'] = $state_portal_link;
            $agency_data[$state_name]['latitude'] = $state_latitude;
            $agency_data[$state_name]['longitude'] = $state_longitude;
            $parent_page_url_withparam = $parent_page_url.'?region='.$state_name.'&type='.$region_type.'&coord='.$dimensions;
            $agency_data[$state_name]['page_url'] = $parent_page_url_withparam;
            $agency_data[$state_name]['sub_regions'] = array();
        } else {
            $sub_region_details['name'] = $sub_region;
            $sub_region_details['region_type'] = $region_type;
            $sub_region_details['dataset_link'] = $state_dataset_link;
            $sub_region_details['portal_link'] = $state_portal_link;
            $sub_region_details['latitude'] = $state_latitude;
            $sub_region_details['longitude'] = $state_longitude;
            $parent_page_url_withparam = $parent_page_url.'?region='.$sub_region.'&type='.$region_type.'&coord='.$dimensions;
            $sub_region_details['page_url'] = $parent_page_url_withparam;
            $agency_data[$state_name]['sub_regions'][] = $sub_region_details;
        }
    }
}

$state_html = '';
foreach($states_data as $i=>$m){
    $state_html .= '<div class="ods-state"><div class="state">';
    $sub_html = '';
    $dataset_count = 0;
    $dataset_count_html = '';
    if(!empty($m['dataset_link'])){
        $dataset_count++;
    }
    foreach($m['sub_regions'] as $a=>$b){
        if(!empty($b['dataset_link'])){
            $dataset_count++;
        }
    }
    if($dataset_count > 0){
        $dataset_count_html = '<div class="type">'.$dataset_count.'</div>';
    }
    if(!empty($m['dataset_link']) || !empty($m['portal_link']) || !empty($m['latitude']) || !empty($m['longitude'])){
        $state_html .= '<a class="state-name" href="'.$m['page_url'].'" title="'.$m['name'].'">'.$m['name'].'</a>'.$dataset_count_html;
        $sub_html = '<div class="info display-hide">';
        if(!empty($m['portal_link'])){
            $sub_html .= '<div class="label-text">State/Province Portal:</div><a href="'.$m['portal_link'].'" target="_blank" title="'.$m['portal_link'].'">'.$m['portal_link'].'</a>';
        }
        if(!empty($m['dataset_link'])){
            $sub_html .= '<div class="label-text">Open Data Sites:</div><a href="'.$m['dataset_link'].'" target="_blank" title="'.$m['dataset_link'].'">'.$m['dataset_link'].'</a>';
        }
        $sub_html .= '</div>';
    } else {
        $state_html .= '<span title="'.$m['name'].'">'.$m['name'].'</span>'.$dataset_count_html;
    }
    $state_html .= '<div class="geo display-hide">'.$m['latitude'].','.$m['longitude'].'</div>';
    $state_html .= $sub_html.'</div>';

    if(count($m['sub_regions']) > 0){
        $state_html .= '<div class="sub-states">';
    }
    $cities = array();
    $municipalities = array();
    foreach($m['sub_regions'] as $k=>$v){
        if($v['region_type'] == 'municipality'){
            $municipalities[] = $v;
        } else {
            $cities[] = $v;
        }
    }
	if(count($cities)) {
		$state_html .= '<div class="sub-region" style="font-weight:bold;">Cities:</div>';
    foreach($cities as $k=>$v){
        $state_html .= '<div class="sub-region">';
        $sub_inner_html = '';
        if(!empty($v['dataset_link']) || !empty($v['portal_link']) || !empty($v['latitude']) || !empty($v['longitude'])){
            $state_html .= '<a class="city-name" href="'.$v['page_url'].'" title="'.$v['name'].'">'.$v['name'].'</a>';
            $sub_inner_html = '<div class="info display-hide">';
            if(!empty($v['portal_link'])){
                $sub_inner_html .= '<div class="label-text">City/Municipality/Province Portal:</div><a href="'.$v['portal_link'].'" target="_blank" title="'.$v['portal_link'].'">'.$v['portal_link'].'</a>';
            }
            if(!empty($v['dataset_link'])){
                $sub_inner_html .= '<div class="label-text">Open Data Sites:</div><a href="'.$v['dataset_link'].'" target="_blank" title="'.$v['dataset_link'].'">'.$v['dataset_link'].'</a>';
            }
            $sub_inner_html .= '</div>';
        } else {
            $state_html .= '<span title="'.$v['name'].'">'.$v['name'].'</span>';
        }
        $state_html .= '<div class="geo display-hide">'.$v['latitude'].','.$v['longitude'].'</div>';
        $state_html .= $sub_inner_html.'</div>';
    }
	}
	if(count($municipalities)) {
		$state_html .= '<div class="sub-region" style="font-weight:bold;clear:both;">Municipalities:</div>';
    foreach($municipalities as $k=>$v){
        $state_html .= '<div class="sub-region">';
        $sub_inner_html = '';
        if(!empty($v['dataset_link']) || !empty($v['portal_link']) || !empty($v['latitude']) || !empty($v['longitude'])){
            $state_html .= '<a class="municipality-name" href="'.$v['page_url'].'" title="'.$v['name'].'">'.$v['name'].'</a>';
            $sub_inner_html = '<div class="info display-hide">';
            if(!empty($v['portal_link'])){
                $sub_inner_html .= '<div class="label-text">City/Municipality/Province Portal:</div><a href="'.$v['portal_link'].'" target="_blank" title="'.$v['portal_link'].'">'.$v['portal_link'].'</a>';
            }
            if(!empty($v['dataset_link'])){
                $sub_inner_html .= '<div class="label-text">Open Data Sites:</div><a href="'.$v['dataset_link'].'" target="_blank" title="'.$v['dataset_link'].'">'.$v['dataset_link'].'</a>';
            }
            $sub_inner_html .= '</div>';
        } else {
            $state_html .= '<span title="'.$v['name'].'">'.$v['name'].'</span>';
        }
        $state_html .= '<div class="geo display-hide">'.$v['latitude'].','.$v['longitude'].'</div>';
        $state_html .= $sub_inner_html.'</div>';
    }
	}
    if(count($m['sub_regions']) > 0){
        $state_html .= '</div>';
    }
    $state_html .= '<div class="cBoth"></div></div><div class="div-border"></div>';
}
if(count($states_data) > 0){
    $state_html = '<h2>States/Provinces</h2><div class="ods-list"><div class="ods-states">'.$state_html.'</div></div><div class="cBoth"></div>';
}
    
    
    
$agency_html = '';
foreach($agency_data as $i=>$m){
    $agency_html .= '<div class="ods-state"><div class="state">';
    $sub_html = '';
    $dataset_count = 0;
    $dataset_count_html = '';
    if(!empty($m['dataset_link'])){
        $dataset_count++;
    }
    foreach($m['sub_regions'] as $a=>$b){
        if(!empty($b['dataset_link'])){
            $dataset_count++;
        }
    }
    if($dataset_count > 0){
        $dataset_count_html = '<div class="type">'.$dataset_count.'</div>';
    }
    if(!empty($m['dataset_link']) || !empty($m['portal_link']) || !empty($m['latitude']) || !empty($m['longitude'])){
        $agency_html .= '<a class="agency-name" href="'.$m['page_url'].'" title="'.$m['name'].'">'.$m['name'].'</a>'.$dataset_count_html;
        $sub_html = '<div class="info display-hide">';
        if(!empty($m['portal_link'])){
            $sub_html .= '<div class="label-text">Agency/Province Portal:</div><a href="'.$m['portal_link'].'" target="_blank" title="'.$m['portal_link'].'">'.$m['portal_link'].'</a>';
        }
        if(!empty($m['dataset_link'])){
            $sub_html .= '<div class="label-text">Open Data Sites:</div><a href="'.$m['dataset_link'].'" target="_blank" title="'.$m['dataset_link'].'">'.$m['dataset_link'].'</a>';
        }
        $sub_html .= '</div>';
    } else {
        $agency_html .= '<span title="'.$m['name'].'">'.$m['name'].'</span>'.$dataset_count_html;
    }
    $agency_html .= '<div class="geo display-hide">'.$m['latitude'].','.$m['longitude'].'</div>';
    $agency_html .= $sub_html.'</div>';

    if(count($m['sub_regions']) > 0){
        $agency_html .= '<div class="sub-states">';
    }
	if(count($m['sub_regions'])){
	$agency_html .= '<div class="sub-region" style="font-weight:bold;">Sub-Agencies</div>';
    foreach($m['sub_regions'] as $k=>$v){
        $agency_html .= '<div class="sub-region">';
        $sub_inner_html = '';
        if(!empty($v['dataset_link']) || !empty($v['portal_link']) || !empty($m['latitude']) || !empty($m['longitude'])){
            $agency_html .= '<a class="sub-agency-name" href="'.$v['page_url'].'" title="'.$v['name'].'">'.$v['name'].'</a>';
            $sub_inner_html = '<div class="info display-hide">';
            if(!empty($v['portal_link'])){
                $sub_inner_html .= '<div class="label-text">Sub-Agency/Province Portal:</div><a href="'.$v['portal_link'].'" target="_blank" title="'.$v['portal_link'].'">'.$v['portal_link'].'</a>';
            }
            if(!empty($v['dataset_link'])){
                $sub_inner_html .= '<div class="label-text">Open Data Sites:</div><a href="'.$v['dataset_link'].'" target="_blank" title="'.$v['dataset_link'].'">'.$v['dataset_link'].'</a>';
            }
            $sub_inner_html .= '</div>';
        } else {
            $agency_html .= '<span title="'.$v['name'].'">'.$v['name'].'</span>';
        }
        $agency_html .= '<div class="geo display-hide">'.$v['latitude'].','.$v['longitude'].'</div>';
        $agency_html .= $sub_inner_html.'</div>';
    }
	}
    if(count($m['sub_regions']) > 0){
        $agency_html .= '</div>';
    }
    $agency_html .= '<div class="cBoth"></div></div><div class="div-border"></div>';
}
if(count($agency_data) > 0){
    $agency_html = '<h2>Agencies</h2><div class="ods-list"><div class="ods-states">'.$agency_html.'</div></div><div class="cBoth"></div>';
}

$country_coord = $node->field_country_latitude[0]['value'].','.$node->field_country_longitude[0]['value'];
?>
<script type="text/javascript">
    var map;
    function loadMap() {
        if (GBrowserIsCompatible()) {
            // create the map using the global "map" variable
            map = new GMap2(document.getElementById("map"));
            map.addControl(new GLargeMapControl());
            map.addControl(new GMapTypeControl());
            map.setCenter(new GLatLng(<?php echo $node->field_country_latitude[0]['value']; ?>,<?php echo $node->field_country_longitude[0]['value']; ?>),3);
        }else {
            alert("Sorry, the Google Maps API is not compatible with this browser");
        }
   }
    $(document).ready(function(){
        $('.region-data').empty();
        $('#map').addClass('map-dimension');
        loadMap();

       // $(".ods-leftPanel .ods-list").each(function(index) {
        //    $(this).find('a').removeAttr('href');
        //});
		$(".state-name").removeAttr('href');
		$(".city-name").removeAttr('href');
		$(".municipality-name").removeAttr('href');
		$(".agency-name").removeAttr('href');
		$(".sub-agency-name").removeAttr('href');
	
        $(".country-name").removeAttr('href');
        $(".ods-leftPanel .ods-list a").click(function(){
            //var item_element = $(this).parents().eq(2);
            var item_element = $(this).parent();
            var coord = $(item_element).find('.geo').html();
            var dataSplit = coord.split(",");
            var htmlcont = $(item_element).find('.info').html();
            map = new GMap2(document.getElementById("map"));
            map.setUIToDefault();
            
            var point = new GLatLng(dataSplit[0],dataSplit[1]);
            map.setCenter(point,3);
            var marker = new GMarker(point);
		if(dataSplit[0] && dataSplit[1]){
			map.addOverlay(marker);
			map.setZoom(4);
			   if(htmlcont){
				marker.openInfoWindowHtml("<div class=\"contrast-mode-map\">"+htmlcont+"</div>");
				GEvent.addListener(marker, "click", function() {
				marker.openInfoWindowHtml("<div class=\"contrast-mode-map\">"+htmlcont+"</div>");
            });}}
		else{
				loadMap();
			}
            $('.region-data').html(htmlcont);
            
        });
        $(".country-name").click(function(){
            var coord = $('.country-geo').html();
            var dataSplit = coord.split(",");
            var htmlcont = $('.country-url').html();
            map = new GMap2(document.getElementById("map"));
            map.setUIToDefault();
            
            var point = new GLatLng(dataSplit[0],dataSplit[1]);
            map.setCenter(point,3);
            var marker = new GMarker(point);
            map.addOverlay(marker);
             marker.openInfoWindowHtml("<div class=\"contrast-mode-map\">"+htmlcont+"</div>");
            GEvent.addListener(marker, "click", function() {
               marker.openInfoWindowHtml("<div class=\"contrast-mode-map\">"+htmlcont+"</div>");
            });
            $('.region-data').html(htmlcont);
            map.setZoom(4);
        });
    });
</script>

<?php
$country_dataset_links = '';
foreach($node->field_country_dataset_link as $datasets){
    if(trim($datasets['url']) != ''){
        $country_dataset_links .= '<a href="'.$datasets['url'].'" title="'.$datasets['url'].'" target="_blank">'.$datasets['url'].'</a><br>';
    }
}
if(strlen(trim($country_dataset_links)) > 0){
    $country_dataset_links = substr($country_dataset_links, 0, -4);
}
global $base_url;
if(variable_get('file_downloads','') == 2) {
   //$flag_img = explode('/', $node->field_open_data_site_image[0]['filepath']);
	$flag_img=substr($node->field_open_data_site_image[0]['filepath'],strpos($node->field_open_data_site_image[0]['filepath'],"files/"));
    $image_path = $base_url."/system/".$flag_img;
} else {
    $image_path = $node->field_open_data_site_image[0]['filepath'];
}
?>

<div class="country-details">
    <div class="ods-leftPanel">
        <div>
            <div class="country-flag"><img width="157" height="105" title="<?php echo $node->field_union_govt_name[0]['value']; ?>" alt="<?php echo $node->field_union_govt_name[0]['value']; ?>" src="<?php echo $image_path; ?>" border="0" class="imgflag"/></div>
            <div class="country-info">
                <div class="country-title"><a href="<?php echo $parent_page_url; ?>" class="country-name" title="<?php echo $node->title; ?>"><?php echo $node->title; ?></a></div>
                <?php if(!empty($node->field_country_latitude[0]['value'])){ ?>
                <div class="info-data">Latitude:  <?php echo $node->field_country_latitude[0]['value']; ?> N</div>
                <?php } ?>
                <?php if(!empty($node->field_country_longitude[0]['value'])){ ?>
                <div class="info-data">Longitude: <?php echo $node->field_country_longitude[0]['value']; ?> W</div>
                <?php } ?>
                <div class="info-data country-url">
                    <?php if(!empty($node->field_country_portal_url[0]['url'])){ ?>
                    <div class="label-text">National/Country Portal:</div>
                    <a href="<?php echo $node->field_country_portal_url[0]['url']; ?>" title="<?php echo $node->field_country_portal_url[0]['url']; ?>" target="_blank"><?php echo $node->field_country_portal_url[0]['url']; ?></a><br />
                    <?php } ?>
                    <?php if(!empty($country_dataset_links)){ ?>
                    <div class="label-text">Open Data Sites:</div>
                    <?php print $country_dataset_links ?>
                    <?php } ?>
                </div>
            </div>
            <div class="country-geo display-hide"><?php echo $node->field_country_latitude[0]['value'].','.$node->field_country_longitude[0]['value']; ?></div>
        </div>
        <div class="cBoth"></div>
        <br/><br/>
        <?php print $agency_html; ?>
        <?php print $state_html; ?>
    </div>
    <div class="ods-rightPanel">
        <div><div id="map"></div></div>
        <div id="static-map"><img src="<?php echo $static_image_map; ?>" alt="static-map"/></div>
        <div class="region-data">
<?php print $state_static_data; ?>
        </div>
        <script type="text/javascript">
        $('#static-map').remove();
        </script>
    </div>

</div>
<div class="clear-block clear" style="clear:both;"></div>

