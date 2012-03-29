<?php
// $Id: template.php,v 1.1.2.3 2009/07/18 17:48:55 dvessel Exp $

//Add explanation field to user login form

function phptemplate_user_login_block($form) {
	$form['intro']['#value'] = t('<label><span class="form-required">*</span> denotes required fields.</label>');
	$form['intro']['#weight'] = -9999;
	return drupal_render($form);
}
function custom_ctools_menu_local_tasks($level = 0, $return_root = FALSE,$pathgroup) {
	static $tabs;
	static $root_path;

	if (!isset($tabs)) {
		$tabs = array();

		$router_item = menu_get_item($pathgroup,Null);
		if (!$router_item || !$router_item['access']) {
			return '';
		}
		// Get all tabs and the root page.
		$result = db_query("SELECT * FROM {menu_router} WHERE tab_root = '%s' ORDER BY weight, title", $router_item['tab_root']);
		$map = arg(NULL,$pathgroup);
		$children = array();
		$tasks = array();
		$root_path = $router_item['path'];

		while ($item = db_fetch_array($result)) {
			_menu_translate($item, $map, TRUE);
			if ($item['tab_parent']) {
				// All tabs, but not the root page.
				$children[$item['tab_parent']][$item['path']] = $item;
			}
			// Store the translated item for later use.
			$tasks[$item['path']] = $item;
		}

		// Find all tabs below the current path.
		$path = $router_item['path'];

		_ctools_menu_add_dynamic_items($children[$path]);
		// Tab parenting may skip levels, so the number of parts in the path may not
		// equal the depth. Thus we use the $depth counter (offset by 1000 for ksort).
		$depth = 1001;
		while (isset($children[$path])) {
			$tabs_current = '';
			$next_path = '';
			$count = 0;
			foreach ($children[$path] as $item) {
				if ($item['access']) {
					$count++;
					// The default task is always active.
					if ($item['type'] == MENU_DEFAULT_LOCAL_TASK) {
						// Find the first parent which is not a default local task.
						if (isset($item['tab_parent'])) {
							for ($p = $item['tab_parent']; $tasks[$p]['type'] == MENU_DEFAULT_LOCAL_TASK; $p = $tasks[$p]['tab_parent']);
							$href = $tasks[$p]['href'];
							$next_path = $item['path'];
						}
						else {
							$href = $item['href'];
						}
						$link = theme('menu_item_link', array('href' => $href) + $item);
						$tabs_current .= theme('menu_local_task', $link, TRUE);
					}
					else {
						$link = theme('menu_item_link', $item);
						$tabs_current .= theme('menu_local_task', $link);
					}
				}
			}
			$path = $next_path;
			$tabs[$depth]['count'] = $count;
			$tabs[$depth]['output'] = $tabs_current;
			$depth++;
		}

		// Find all tabs at the same level or above the current one.
		$parent = $router_item['tab_parent'];
		$path = $router_item['path'];
		$current = $router_item;
		$depth = 1000;
		while (isset($children[$parent])) {
			$tabs_current = '';
			$next_path = '';
			$next_parent = '';
			$count = 0;
			foreach ($children[$parent] as $item) {
				if ($item['access']) {
					$count++;
					if ($item['type'] == MENU_DEFAULT_LOCAL_TASK) {
						// Find the first parent which is not a default local task.
						for ($p = $item['tab_parent']; $tasks[$p]['type'] == MENU_DEFAULT_LOCAL_TASK; $p = $tasks[$p]['tab_parent']);
						$link = theme('menu_item_link', array('href' => $tasks[$p]['href']) + $item);
						if ($item['path'] == $router_item['path']) {
							$root_path = $tasks[$p]['path'];
						}
					}
					else {
						$link = theme('menu_item_link', $item);
					}
					// We check for the active tab.
					if ($item['path'] == $path) {
						$tabs_current .= theme('menu_local_task', $link, TRUE);
						$next_path = $item['tab_parent'];
						if (isset($tasks[$next_path])) {
							$next_parent = $tasks[$next_path]['tab_parent'];
						}
					}
					else {
						$tabs_current .= theme('menu_local_task', $link);
					}
				}
			}
			$path = $next_path;
			$parent = $next_parent;
			$tabs[$depth]['count'] = $count;
			$tabs[$depth]['output'] = $tabs_current;
			$depth--;
		}
		// Sort by depth.
		ksort($tabs);
		// Remove the depth, we are interested only in their relative placement.
		$tabs = array_values($tabs);
	}
	if ($return_root) {
		return $root_path;
	}
	else {
		// We do not display single tabs.
		return (isset($tabs[$level]) && $tabs[$level]['count'] > 1) ? $tabs[$level]['output'] : '';
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

//modify the pagination for views

function ogplcommunities_pager($tags = array(), $limit = 25, $element = 0, $parameters = array(), $quantity = 5){

global $pager_page_array, $pager_total;
  $tags = array("", "< prev", "", "next >", "");

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;
  // first is the first page listed by this pager piece (re quantity)
  $pager_first = $pager_current - $pager_middle + 1;
  // last is the last page listed by this pager piece (re quantity)
  $pager_last = $pager_current + $quantity - $pager_middle;
  // max is the maximum page number
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
    $pager_first = $i;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }

  // End of generation loop preparation.

 
   $currentPage = $_REQUEST['page']+1;
 
  
  // start calculation    
  $start = ($itemsPerPage * $currentPage) - ($itemsPerPage-1);
  $end = $itemsPerPage * $currentPage;
 
  if ($end>$total) $end = $total;
   
  // return html
//  $x =  "<b>Displaying $start - $end of $total</b>";
  $li_previous = theme('pager_previous', (isset($tags[1]) ? $tags[1] : t('� previous')), $limit, $element, 1, $parameters);
  $li_next = theme('pager_next', (isset($tags[3]) ? $tags[3] : t('next �')), $limit, $element, 1, $parameters);

  if ($pager_total[$element] >= 1) {
 $items[] = array(
                                 'class' => 'pager',
                                 'data' => $x,
                                );
    global $pager_page_array, $pager_total, $pager_total_items;
    
    $page = $pager_page_array[0] + 1;
    $first_no = $limit * $pager_page_array[0] + 1;
    $last_no = ($limit * $page) > $pager_total_items[0] ? $pager_total_items[0] : $limit * $page;
    $li_text = 'Showing '.$first_no.'-'.$last_no.' of '. $pager_total_items[0];
    if ($li_text) {
      $items[] = array(
        'class' => 'pager-text',
        'data' => $li_text,
      );
    }
    if ($li_previous) {
	
	
      $items[] = array(
        'class' => 'pager-previous',
        'data' => $li_previous,
      );
    }
	

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
                     if ($pager_first > 1 && $i == $pager_first) {
                                               $output = '...'.$i;
                                               $stopPreEllipsis = true;
                                } else {
                                               $output = $i;
                                }
          $items[] = array(
            'class' => 'pager-item',
            'data' => theme('pager_previous', $output, $limit, $element, ($pager_current - $i), $parameters),
          );
        }
        if ($i == $pager_current) {
		  
          $items[] = array(
            'class' => 'pager-current',
            'data' => $i,
          );
        }
        if ($i > $pager_current) {

                     if ($pager_last < $pager_max && $i == $pager_last) {
                                               $output = $i.'...';
                                } else {
                                               $output = $i;
                                }
 
          $items[] = array(
            'class' => 'pager-item',
            'data' => theme('pager_next', $output, $limit, $element, ($i - $pager_current), $parameters),
          );

        }
      }
    }
	
	
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => 'pager-next',
        'data' => $li_next,
      );
    }
    /* moved above
    global $pager_page_array, $pager_total, $pager_total_items;
    
    $page = $pager_page_array[0] + 1;
    $first_no = $limit * $pager_page_array[0] + 1;
    $last_no = ($limit * $page) > $pager_total_items[0] ? $pager_total_items[0] : $limit * $page;
    */
    $next_no = $pager_total_items[0] - ($page * $limit) > $limit ? 50 : $pager_total_items[0] - ($page * $limit);
    $previous_no = $limit;

    //$li_text = 'Showing '.$first_no.'-'.$last_no.' of '. $pager_total_items[0];
    $li_previous = theme('pager_previous', t('� previous @no',array('@no'=>$previous_no)), $limit, $element, 1, $parameters);
    $li_next = theme('pager_next', t('next @no �',array('@no'=>$next_no)), $limit, $element, 1, $parameters);

    if ($li_previous) {
    $items[] = array(
      'class' => 'pager-previous',
      'data' => $li_previous,
    );
  }
  /* moved above
  if ($li_text) {
    $items[] = array(
      'class' => 'pager-text',
      'data' => $li_text,
    );
  }
  */
    
  if ($li_next) {
    $items[] = array(
      'class' => 'pager-next',
      'data' => $li_next,
    );
  }
    return theme('item_list', $items, NULL, 'ul', array('class' => 'pager'));
  }  
  }  



// Override Text Re-Sizer
function ogplcommunities_text_resize_block() {
  if (_get_text_resize_reset_button() == TRUE) {
    $output = t('Text:&nbsp;<a href="javascript:;" class="changer" id="text_resize_decrease">A<sup>-</sup></a><a href="javascript:;" class="changer" id="text_resize_increase">&nbsp;A<sup>+</sup></a><a href="javascript:;" class="changer" id="text_resize_reset">A</a><div id="text_resize_clear"></div>');
  }
  else {
    $output = t('<a href="javascript:;" class="changer" id="text_resize_decrease">A<sup>-</sup></a><a href="javascript:;" class="changer" id="text_resize_increase">&nbsp;A<sup>+</sup></a><div id="text_resize_clear"></div>');
  }
  return $output;
}
//unsets the reply link from comments
function phptemplate_links($links, $attributes = array('class' => 'links')) {

  if (isset($links['comment_reply'])) {
    unset($links['comment_reply']);
  }

  return theme_links($links, $attributes);
}

//Override Add This Button//
function ogplcommunities_addthis_button($node, $teaser) {
  global $_addthis_counter;

  // Fix IE's bug.
  if (strpos($_SERVER['HTTP_USER_AGENT'], 'MSIE') !== FALSE) {
    drupal_add_link(array(
      'rel' => 'stylesheet',
      'type' => 'text/css',
      'href' => "http://s7.addthis.com/static/r07/widget02.css",
    ));
  }

  if (variable_get('addthis_dropdown_disabled', '0')) {
    $button = sprintf('
      <a class="addthis-button" href="http://www.addthis.com/bookmark.php"
        onclick="addthis_url   = location.href; addthis_title = document.title; return addthis_click(this);">
      <img src="%s" width="%d" height="%d" %s /></a>',
      $_SERVER['HTTPS'] == 'on' ? addslashes(check_plain(variable_get('addthis_image_secure', 'https://secure.addthis.com/button1-share.gif'))) : addslashes(check_plain(variable_get('addthis_image', 'http://s9.addthis.com/button1-share.gif'))),
      variable_get('addthis_image_width', '125'),
      variable_get('addthis_image_height', '16'),
      addslashes(filter_xss(variable_get('addthis_image_attributes', 'alt=""')))
    );
  }
  else {
    $button = sprintf('
      <a class="addthis-button" href="http://www.addthis.com/bookmark.php"
        onmouseover="return addthis_open(this, \'\', \'%s\', \'%s\')"
        onmouseout="addthis_close()"
        onclick="return addthis_sendto()"><img src="%s" width="%d" height="%d" %s /></a>',
      $teaser ? url('node/'. $node->nid, array('absolute' => 1) ) : '[URL]',
      $teaser ? addslashes($node->title) : '[TITLE]',
      $_SERVER['HTTPS'] == 'on' ? addslashes(check_plain(variable_get('addthis_image_secure', 'https://secure.addthis.com/button1-share.gif'))) : addslashes(check_plain(variable_get('addthis_image', 'http://s9.addthis.com/button1-share.gif'))),
      variable_get('addthis_image_width', '125'),
      variable_get('addthis_image_height', '16'),
      check_plain(variable_get('addthis_image_attributes', 'alt=""'))
    );
    if ($_addthis_counter == 1) {
      $button .= sprintf('<script type="text/javascript" src="%s/js/%d/addthis_widget.js">',
        $_SERVER['HTTPS'] == 'on' ? 'https://secure.addthis.com' : 'http://s7.addthis.com',
        variable_get('addthis_widget_version', '152')
      );
    }
    $button .= '</script>';
  }
  return $button;
}

function _ogplcommunities_get_search_alternatives() {
  /* Get query string from URL */
  $query_params = explode('/apachesolr_search/', $_GET['q'], 2);
  $query_string = explode('?', $query_params[1], 1);
  $query_string = urlencode(urldecode($query_string[0]));
    
  /* Customization - Adding additional links at the bottom of search pages for Ocean community */
  $html = '';
  $local_gid = '';
  $filter_vars = split(' ', $_GET['filters']);
  foreach($filter_vars as $filter) {
    $vars = split(':', $filter);
    if ($vars[0] == 'im_og_gid') {
      $local_gid = $vars[1];
    }
  }
  if ($local_gid == 237) {
    $html .= '<div class="search-additional-links">' . "\n";
    $html .= '<p>Did not find what you are looking for? &nbsp;'. "\n";
    $html .= '<a href="/communities/node/237/forums/2201">Suggest a Dataset</a> or'. "\n";
    $html .= '</div>' . "\n";
  }
  return $html;
}

/* Override theme_box to modify search page with no results */
function ogplcommunities_box($title, $content, $region = 'main') {
  $output = '<h2 class="title">' . $title . '</h2><div>' . $content . '</div>';
  if ($title == 'Your search yielded no results') {
    $output .= _ogplcommunities_get_search_alternatives();
  }
  return $output;
}

/* Pre-process for Search Results*/
function ogplcommunities_preprocess_search_results(&$variables) {
  $variables['additional_links'] = _ogplcommunities_get_search_alternatives();
}

/* Pre-process for Comment*/
function ogplcommunities_preprocess_comment(&$vars) {
 	$vars['formatted_date'] =$vars['date'];
 	$vars['author']=strip_tags($vars['author'],'<>');
  }

/* Pre-process for Forum*/
function ogplcommunities_preprocess_forums(&$variables) {
   global $user;
   $group_roles = og_user_roles_get_roles_by_group($variables['links']['forum']['query']['gids[]'],$user->uid);
   $variables['forumname']=$variables['parents'][1]->name;
   if(!in_array(ROLEID_COMMUNITY_USR, $group_roles))
   {
   		unset($variables['links']['forum']);
   }
}

 /* Pre-process for Page*/
function ogplcommunities_preprocess_page(&$vars, $hook) {
  // For easy printing of variables.
  $vars['logo_img']         = $vars['logo'] ? theme('image', substr($vars['logo'], strlen(base_path())), t('Home'), t('Home')) : '';
  $vars['linked_logo_img']  = $vars['logo_img'] ? l($vars['logo_img'], '<front>', array('attributes' => array('rel' => 'home'), 'title' => t('Home'), 'html' => TRUE)) : '';
  $vars['linked_site_name'] = $vars['site_name'] ? l($vars['site_name'], '<front>', array('attributes' => array('rel' => 'home'), 'title' => t('Home'))) : '';
  $vars['main_menu_links']      = theme('links', $vars['primary_links'], array('class' => 'links main-menu'));
  $vars['secondary_menu_links'] = theme('links', $vars['secondary_links'], array('class' => 'links secondary-menu'));

  // Make sure framework styles are placed above all others.
  $vars['css_alt'] = ogplcommunities_css_reorder($vars['css']);
  $vars['styles'] = drupal_get_css($vars['css_alt']);

 // Allow Drupal to discover page templates named with path aliases
if (module_exists('path')) {
    $alias = drupal_get_path_alias(str_replace('/edit','',$_GET['q']));
    if ($alias != $_GET['q']) {
      $template_filename = 'page';
      foreach (explode('/', $alias) as $path_part) {
        $template_filename = $template_filename . '-' . $path_part;
        $vars['template_files'][] = $template_filename;
      }
    }
  }

}

/*Pre-process for breadcrumb */

function ogplcommunities_breadcrumb($breadcrumb) {
  // following line needs improvement - array list of items to exclude, as they are added by Solr
  $community_labels = array('Open Data', 'Semantic Web', 'Health', 'Law', 'Energy', 'Ocean');

  $modified_breadcrumb = array();
  $modified_breadcrumb[] = l('All Communities',NULL);
  if (!empty($breadcrumb)) {
    if ($group_node = og_get_group_context()){
    	if(drupal_get_path_alias($_REQUEST['q']) != $group_node->path) {
    		$modified_breadcrumb[] = l($group_node->title,$group_node->path);
    	}
    }

    foreach($breadcrumb as $key=>$value){
    	if (array_search($value,$modified_breadcrumb) || ($key < 2)) continue;

    	if (($value != l('Groups','og')) && ($value != l('Groups','groups')) && (!in_array($value, $community_labels))) {
    		$modified_breadcrumb[] = $value;
    	}
    }
  }
    return implode(' &raquo; ', $modified_breadcrumb);

}



/**
 * Contextually adds 960 Grid System classes.
 *
 * The first parameter passed is the *default class*. All other parameters must
 * be set in pairs like so: "$variable, 3". The variable can be anything available
 * within a template file and the integer is the width set for the adjacent box
 * containing that variable.
 *
 *  class="<?php print ns('grid-16', $var_a, 6); ?>"
 *
 * If $var_a contains data, the next parameter (integer) will be subtracted from
 * the default class. See the README.txt file.
 */
function ns() {
  $args = func_get_args();
  $default = array_shift($args);
  // Get the type of class, i.e., 'grid', 'pull', 'push', etc.
  // Also get the default unit for the type to be procesed and returned.
  list($type, $return_unit) = explode('-', $default);

  // Process the conditions.
  $flip_states = array('var' => 'int', 'int' => 'var');
  $state = 'var';
  foreach ($args as $arg) {
    if ($state == 'var') {
      $var_state = !empty($arg);
    }
    elseif ($var_state) {
      $return_unit = $return_unit - $arg;
    }
    $state = $flip_states[$state];
  }

  $output = '';
  // Anything below a value of 1 is not needed.
  if ($return_unit > 0) {
    $output = $type . '-' . $return_unit;
  }
  return $output;
}

/**
 * This rearranges how the style sheets are included so the framework styles
 * are included first.
 *
 * Sub-themes can override the framework styles when it contains css files with
 * the same name as a framework style. This can be removed once Drupal supports
 * weighted styles.
 */
function ogplcommunities_css_reorder($css) {
  global $theme_info, $base_theme_info;

  // Dig into the framework .info data.
  $framework = !empty($base_theme_info) ? $base_theme_info[0]->info : $theme_info->info;

  // Pull framework styles from the themes .info file and place them above all stylesheets.
  if (isset($framework['stylesheets'])) {
    foreach ($framework['stylesheets'] as $media => $styles_from_960) {
      // Setup framework group.
      if (isset($css[$media])) {
        $css[$media] = array_merge(array('framework' => array()), $css[$media]);
      }
      else {
        $css[$media]['framework'] = array();
      }
      foreach ($styles_from_960 as $style_from_960) {
        // Force framework styles to come first.
        if (strpos($style_from_960, 'framework') !== FALSE) {
          $framework_shift = $style_from_960;
          $remove_styles = array($style_from_960);
          // Handle styles that may be overridden from sub-themes.
          foreach ($css[$media]['theme'] as $style_from_var => $preprocess) {
            if ($style_from_960 != $style_from_var && basename($style_from_960) == basename($style_from_var)) {
              $framework_shift = $style_from_var;
              $remove_styles[] = $style_from_var;
              break;
            }
          }
          $css[$media]['framework'][$framework_shift] = TRUE;
          foreach ($remove_styles as $remove_style) {
            unset($css[$media]['theme'][$remove_style]);
          }
        }
      }
    }
  }

  return $css;
}

/*
 * Overwriting the theme_tagadelic_weighted function since we wanted tags on blogs to specifically search
 * the blog listings. The rest of the tag functionalities works as expected.
 */
function ogplcommunities_tagadelic_weighted($terms) {
  $output = '';
  $node = og_get_group_context();
  $item = menu_get_item();
  foreach ($terms as $term) {
  switch($item['path']){
  	case "node/%/blogs" :
		$output .= l($term->name, "node/{$node->nid}/blogs", array('attributes' => array('class' => "tagadelic level$term->weight", 'rel' => 'tag'),'query'=>array('tid'=>$term->name))) ." \n";
		break;
  	case "node/%/data_tools" :
		$output .= l($term->name, "node/{$node->nid}/data_tools", array('attributes' => array('class' => "tagadelic level$term->weight", 'rel' => 'tag'),'query'=>array('tid'=>$term->name))) ." \n";
		break;
	default :
		$output .= l($term->name, taxonomy_term_path($term), array('attributes' => array('class' => "tagadelic level$term->weight", 'rel' => 'tag'))) ." \n";
		break;
	  }
  }
  return $output;
}


function ogplcommunities_username($object) {
   // Load profile data
  profile_load_profile($object);

  if ($object->profile_anonymous==0 && $object->uid && $object->profile_display_name) {
    // Shorten the name when it is too long or it will break many tables.
    /*
    if (drupal_strlen($object->profile_display_name) > 20) {
      $name = drupal_substr($object->profile_display_name, 0, 15) .'...';
    }
    else {*/
      $name = $object->profile_display_name;
    /*}*/

    if (user_access('access user profiles')) {
      $output = l($name, 'user/'. $object->uid, array('title' => t('View user profile.')));
    }
    else {
      $output = check_plain($name);
    }
  }
  else {
    $output = variable_get('anonymous', t('Anonymous'));
  }

  return $output;

}

/*
// Theme Define template for user/register screen.
*/
/*
function ogplcommunities_theme($existing, $type, $theme, $path) {
  return array(
    // tell Drupal what template to use for the user register form
    'user_register' => array(
      'arguments' => array('form' => NULL),
      'template' => 'user-register', // this is the name of the template
    ),
  );
}*/