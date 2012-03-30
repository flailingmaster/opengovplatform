<?php
function dms_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
	global $user;
	$admin_links=array("Site building","Reports","Site configuration","User management","Content management");
    $breadcrumb[] = l(drupal_get_title(), $_GET['q']);
	if(strip_tags($breadcrumb['1']) == 'Administer' && $user->uid != 1 && !in_array('Administrator', $user->roles)) unset($breadcrumb['1']);
	if(in_array(strip_tags($breadcrumb['2']),$admin_links) && $user->uid != 1 && !in_array('Administrator', $user->roles)) unset($breadcrumb['2']);
	if(drupal_get_path_alias($_GET['q'])=='admin/build/block/list/dms') {
		unset($breadcrumb['1']);
		unset($breadcrumb['3']);
		unset($breadcrumb['4']);
		$breadcrumb['2']=l('CMS/VRM/DMS Theme Blocks','admin/build/block/list/dms');
	}
	return '<div class="breadcrumb">'. implode(' » ', $breadcrumb) .'</div>';
  }
}

function dms_preprocess_page(&$vars) {
  // Remove undesired local task tabs.
  // This first example removes the Users tab from the Search page.
  dms_removetab('Workflow', $vars);
}

// Remove undesired local task tabs.
// Related to yourthemename_removetab() in yourthemename_preprocess_page().
function dms_removetab($label, &$vars) {
  $tabs = explode("\n", $vars['tabs']);
  $vars['tabs'] = '';

  foreach ($tabs as $tab) {
    if (strpos($tab, '>' . $label . '<') === FALSE) {
      $vars['tabs'] .= $tab . "\n";
    }
  }
}

function dms_form_element($element, $value) {
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  $output = '<div class="form-item"';
  if (!empty($element['#id'])) {
    $output .= ' id="' . $element['#id'] . '-wrapper"';
  }
  $output .= ">\n";
  $required = !empty($element['#required']) ? '<span class="form-required" title="' . $t('This field is required.') . '">(Required)</span>' : '';

  if (!empty($element['#title'])) {
    $title = $element['#title'];
    if (!empty($element['#id'])) {
      $label = trim(str_replace(":","",$t('!title !required:', array('!title' => filter_xss_admin($title), '!required' => $required)))).":";
      $output .= ' <label for="' . $element['#id'] . '">' .$label. "</label>\n";
    }
    else {
      $output .= ' <label>' . $t('!title: !required', array('!title' => filter_xss_admin($title), '!required' => $required)) . "</label>\n";
    }
  }

  $output .= " $value\n";

  if (!empty($element['#description'])) {
    $output .= ' <div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}
function dms_date_all_day_label() {
  return '';
}
function dms_preprocess_node(&$vars) {
  global $base_url;
  $node = $vars['node'];
  if($node->type == 'feedback') {
  
  foreach($node->field_forwarded_to as $forwardee) {
		$forwardees[] = $forwardee['view'];
  }
  $forwardees = implode(', ', $forwardees);
  if($forwardees !== '') {
  $vars['field_forwarded_to_rendered'] = 
	'<div class="field field-type-userreference field-field-forwarded-to">
		<div class="field-label">Forwarded To:&nbsp;</div>
        <div class="field-items">
            ' . $forwardees . '
        </div>
	</div>';
  }
	
	
  $nonmember_forwardees = str_replace(',' , ', ', $node->field_forwarded_to_nonmembers[0]['safe']);
  if(trim($nonmember_forwardees) !== '') {
  $vars['field_forwarded_to_nonmembers_rendered'] = 
    '<div class="field field-type-text field-field-forwarded-to-nonmembers">
       <div class="field-label">Forwarded To Non-Members:&nbsp;</div>
       <div class="field-items">
         ' . $nonmember_forwardees . '
       </div>
    </div>';
  }
  
  // Show the Workflow state
  if(isset($node->_workflow)) {
	$workflow_state = workflow_get_state($node->_workflow);
	$state = $workflow_state['state'];
	$vars['current_workflow_state'] = 
	'<div class="field field-type-text field-field-workflow-state">
      <div class="field-label">Feedback Status:&nbsp;</div>
        <div class="field-items">
            <div class="field-item odd">
				' . $state . '
        </div>
      </div>
	</div>';
  }

      if(!is_null($node->field_refer_nodeid[0][value]) && $node->field_source[0][view]=="Ratings") {
	    $title=db_query("select title from node where nid=".$node->field_refer_nodeid[0][value]);
		$title_output=db_fetch_object($title);
		if(!empty($title_output->title)){
          $vars['field_refer_nodeid_rendered'] =
              '<div class="field field-type-nodereference field-field-refer-nodeid">
		<div class="field-label">Dataset:&nbsp;</div>
        <div class="field-items">
            <a href="'.$base_url.'/node/'.$node->field_refer_nodeid[0][value].'" >'.$title_output->title.'</a> 
        </div>
	</div>';
  }
  else{
    $vars['field_refer_nodeid_rendered'] =
              '<div class="field field-type-nodereference field-field-refer-nodeid">
		<div class="field-label">Dataset:&nbsp;</div>
        <div class="field-items">
            Dataset associated with the feedback has been deleted.
        </div>
	</div>';
  
  }
  }
  }
}


?>