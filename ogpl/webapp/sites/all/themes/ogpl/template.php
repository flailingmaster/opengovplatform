<?php
// $Id: template.php,v 1.2 2010/12/28 21:18:31 skounis Exp $

/**
 * Sets the body-tag class attribute.
 *
 * Adds 'sidebar-left', 'sidebar-right' or 'sidebars' classes as needed.
 */
function phptemplate_body_class($sidebar_left, $sidebar_right) {
  if ($sidebar_left != '' && $sidebar_right != '') {
    $class = 'sidebars';
  }
  else {
    if ($sidebar_left != '') {
      $class = 'sidebar-left';
    }
    if ($sidebar_right != '') {
      $class = 'sidebar-right';
    }
  }

  if (isset($class)) {
    print ' class="'. $class .'"';
  }
}

/**
 * Override or insert PHPTemplate variables into the templates.
 */
function phptemplate_preprocess_page(&$vars) {
  $vars['tabs2'] = menu_secondary_local_tasks();

  // Hook into color.module
  if (module_exists('color')) {
    _color_page_alter($vars);
  }
}

/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return a string containing the breadcrumb output.
 */
function phptemplate_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
    return '<div class="breadcrumb">'. implode(' › ', $breadcrumb) .'</div>';
  }
}

/**
 * Allow themable wrapping of all comments.
 */
function phptemplate_comment_wrapper($content, $type = null) {
  static $node_type;
  if (isset($type)) $node_type = $type;

  if (!$content || $node_type == 'forum') {
    return '<div id="comments">'. $content . '</div>';
  }
  else {
    return '<div id="comments"><h2 class="comments">'. t('Comments') .'</h2>'. $content .'</div>';
  }
}

/**
 * Override or insert PHPTemplate variables into the templates.
 */
function _phptemplate_variables($hook, $vars) {
  if ($hook == 'page') {

    if ($secondary = menu_secondary_local_tasks()) {
      $output = '<span class="clear"></span>';
      $output .= "<ul class=\"tabs secondary\">\n". $secondary ."</ul>\n";
      $vars['tabs2'] = $output;
    }

    // Hook into color.module
    if (module_exists('color')) {
      _color_page_alter($vars);
    }
    return $vars;
  }
  return array();
}

/**
 * Returns the rendered local tasks. The default implementation renders
 * them as tabs.
 *
 * @ingroup themeable
 */
function phptemplate_menu_local_tasks() {
  $output = '';

  if ($primary = menu_primary_local_tasks()) {
    $output .= "<ul class=\"tabs primary\">\n". $primary ."</ul>\n";
  }

  return $output;
}

/**
 * Generates IE CSS links for LTR and RTL languages.
 */
function phptemplate_get_ie_styles() {
  global $language;

  $iecss = '<link type="text/css" rel="stylesheet" media="all" href="'. base_path() . path_to_theme() .'/fix-ie.css" />';
  if ($language->direction == LANGUAGE_RTL) {
    $iecss .= '<style type="text/css" media="all">@import "'. base_path() . path_to_theme() .'/fix-ie-rtl.css";</style>';
  }

  return $iecss;
}

/**
 * GT
 * Returns the terms of a specific vocabulary.
 * Paremeters: Node id, Vocabulary id
 *
 */
function skodaxanthifc_print_only_terms_of($node, $vid) {
	$terms = taxonomy_node_get_terms_by_vocabulary($node, $vid);
	if ($terms) {
		$links = array();
		$output .= '';
		foreach ($terms as $term) {
			//$links[] = l($term->name, taxonomy_term_path($term), array('rel' => 'tag', 'title' => strip_tags($term->description)));
			$output .= $term->name;
		}
	//$output .= implode(', ', $links);
	$output .= ' ';
	}
	$output .= '';
	return $output;
}

/**
  * Theme override for search form.
  */
  function skodaxanthifc_search_theme_form($form) {
   
    unset($form['search_theme_form']['#title']);
    //$form['submit']['#value'] = '';
    //$form['search_theme_form']['#value'] = 'Search.';
   // $form['search_theme_form']['#attributes'] = array('onblur' => "if (this.value == '') {this.value = 'Search.';}", 'onfocus' => "if (this.value == 'Search.') {this.value = '';}" );

    $output .= drupal_render($form);
    return $output;
}

function ogpl_preprocess_search_theme_form(&$vars,$hook)
{
 $vars['form']['search_theme_form']['#title'] = t('Search');


$vars['form']['search_theme_form']['#value'] = t('Search the site');


$vars['form']['search_theme_form']['#attributes'] = array( 'onblur' => "if (this.value == '') {this.value = '".$vars['form']['search_theme_form']['#value']."';} ;", 'onfocus' => "if (this.value == '".$vars['form']['search_theme_form']['#value']."') {this.value ='';} ;" );


unset($vars['form']['search_theme_form']['#printed']);
$vars['search']['search_theme_form'] = drupal_render($vars['form']['search_theme_form']);

}
function ogpl_search_form($form)
{
  print_r($form);

}
function ogpl_menu_item_link($link) {
 if ($link['title'] == 'Add To Favorites'){
    return '<a href="javascript:void(0);" onclick="add_to_favourites();">'.$link['title'].'</a>';
}
if ($link['title'] == 'Communities' || $link['title'] == 'Community'){
    return '<a target="blank" href="'.$link['link_path'].'">'.$link['title'].'</a>';
}
 return theme_menu_item_link($link);

}

function ogpl_apachesolr_facet_link($facet_text, $path, $options = array(), $count, $active = FALSE, $num_found = NULL) {
 
  if ($facet_text == 'text/csv') return apachesolr_l("CSV ($count)",  $path, $options); 
  
  if ($facet_text == 'text/plain') return apachesolr_l("TXT ($count)",  $path, $options);
  if ($facet_text == 'text/xml') return apachesolr_l("XML ($count)",  $path, $options);
  if ($facet_text == 'text/html') return apachesolr_l("HTML ($count)",  $path, $options);
  if($facet_text == 'application/pdf') return apachesolr_l("PDF ($count)",  $path, $options);
  if($facet_text == 'application/zip') return apachesolr_l("ZIP ($count)",  $path, $options);
  if($facet_text == 'application/vnd.ms-powerpoint') return apachesolr_l("PPT ($count)",  $path, $options);
  if($facet_text == 'application/vnd.openxmlformats-officedocument.presentationml.presentation') return apachesolr_l("PPTX($count)",  $path, $options);
  if($facet_text=='application/vnd.openxmlformats-officedocument.wordprocessingml.document')return apachesolr_l("DOCX ($count)",  $path, $options);
  if($facet_text=='application/vnd.openxmlformats-officedocument.spreadsheetml.sheet' )    return apachesolr_l("XLSX ($count)",  $path, $options);
  if($facet_text=='application/vnd.ms-document')return apachesolr_l("DOC ($count)",  $path, $options);
  if($facet_text=='application/vnd.ms-excel')return apachesolr_l("XLS ($count)",  $path, $options);
  
  //CATALOG_TYPE_LABELS
  if ($facet_text == 'catalog_type_raw_data') return apachesolr_l("Raw Data ($count)",  $path, $options); 
  if ($facet_text == 'catalog_type_data_apps') return apachesolr_l("Apps ($count)",  $path, $options);
  if ($facet_text == 'catalog_type_document') return apachesolr_l("Documents ($count)",  $path, $options);
  if ($facet_text == 'catalog_type_data_tools') return apachesolr_l("Tools ($count)",  $path, $options);
  if ($facet_text == 'catalog_type_data_service') return apachesolr_l("Services ($count)",  $path, $options);
  
  
  
  $options['attributes']['class'][] = 'apachesolr-facet';
  if ($active) {
    $options['attributes']['class'][] = 'active';
	  }
  $options['attributes']['class'] = implode(' ', $options['attributes']['class']);
  return apachesolr_l($facet_text ." ($count)",  $path, $options);
}

function ogpl_apachesolr_unclick_link($facet_text, $path, $options = array()) {
  //apachesolr_js();
  
  // Determine if we are dealing with ratings output
  if ( $options['delta'] == 'sis_ratings' ) {
    $options['html'] = TRUE;
    $text = theme('fivestar_static', $facet_text, variable_get('fivestar_stars_resource', 5));
  }

  if (empty($options['html'])) {
    $text = check_plain($facet_text);
  }
  else {
    // Don't pass this option as TRUE into apachesolr_l().
    unset($options['html']);
  }
  if ($facet_text == 'text/csv') $text="CSV"; 
  if ($facet_text == 'text/plain')$text="TXT";
  if ($facet_text == 'text/xml')$text="XML";
  if ($facet_text == 'text/html')$text="HTML";
  if($facet_text == 'application/pdf')$text="PDF";
  if($facet_text == 'application/zip')$text="ZIP";
  if($facet_text == 'application/vnd.ms-powerpoint')$text="PPT";
  if($facet_text=='application/vnd.openxmlformats-officedocument.wordprocessingml.document' )$text="DOCX";
  if($facet_text=='application/vnd.openxmlformats-officedocument.spreadsheetml.sheet' ) $text="XLSX";
  if($facet_text == 'application/vnd.openxmlformats-officedocument.presentationml.presentation') $text="PPTX";
  if($facet_text=='application/vnd.ms-document')$text="DOC";
  if($facet_text=='application/vnd.ms-excel')$text="XLS";
  
  
  //CATALOG_TYPE_LABELS
  if ($facet_text == 'catalog_type_raw_data')$text="Raw Data"; 
  if ($facet_text == 'catalog_type_data_apps')$text="Apps";
  if ($facet_text == 'catalog_type_document')$text="Documents";
  if ($facet_text == 'catalog_type_data_tools') $text="Tools";
  if ($facet_text == 'catalog_type_data_service') $text="Services";
  
  
  if (is_numeric($facet_text))
  {
     $nid=(int)$facet_text;
     $node=node_load($nid);
	 $text=$node->title;
  }
  
  $options['attributes']['class'] = 'apachesolr-unclick';
   return apachesolr_l("(-)", $path, $options) . ' '. $text;
}



function ogpl_form_element($element, $value) {
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
      $output .= ' <label for="' . $element['#id'] . '">' . $t('!title !required :', array('!title' => filter_xss_admin($title), '!required' => $required)) . "</label>\n";
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


function phptemplate_username($object) {
 
  if ($object->uid && $object->name) {
    // Shorten the name when it is too long or it will break many tables.
    if (drupal_strlen($object->name) > 20) {
      $name = drupal_substr($object->name, 0, 15) .'...';
    }
    else {
      $name = $object->name;
    }
 
    if (user_access('access user profiles')) {
      $output = l($name, 'user/'. $object->uid, array('title' => t('View user profile.')));
    }
    else {
      $output = check_plain($name);
    }
  }
  else if ($object->name) {
    // Sometimes modules display content composed by people who are
    // not registered members of the site (e.g. mailing list or news
    // aggregator modules). This clause enables modules to display
    // the true author of the content.
    if ($object->homepage) {
      $output = l($object->name, $object->homepage);
    }
    else {
      $output = check_plain($object->name);
    }
 
    //$output .= ' ('. t('not verified') .')';
  }
  else {
    $output = variable_get('anonymous', t('Anonymous'));
  }
 
  return $output;
}


