<?php

function send_theme_theme() {
  $path = drupal_get_path('module', 'send') .'/theme';
  return array(
    'send' => array(
      'arguments' => array( 'element' => NULL ),
      'file' => 'send.theme.inc',
      'template' => 'send',
      'path' => $path,
    ),
    'send_element' => array(
      'arguments' => array( 'element' => NULL ),
      'file' => 'send.theme.inc',
      'path' => $path,
    ),
    'send_message_compose_element' => array(
      'arguments' => array( 'element' => array() ),
      'file' => 'send.theme.inc',
      'path' => $path,
    ),
    'send_subject' => array(
      'arguments' => array(),
      'file' => 'send.theme.inc',
      'path' => $path,
    ),
    'send_body' => array(
      'arguments' => array( 'values' => array() ),
      'file' => 'send.theme.inc',
      'path' => $path,
    ),
    'send_draggable' => array(
      'arguments' => array( 'element' => array() ),
      'file' => 'send.theme.inc',
      'path' => $path,
    ),
  );
}

function send_preprocess(&$variables, $hook) {
  $variables['sender']    = $variables['element']['sender']['#children'];
  $variables['recipients']      = $variables['element']['recipients']['#children'];
  $variables['buttons'] = $variables['element']['buttons']['#children'];
  $variables['content'] = $variables['element']['content']['#children'];
  //$variables['extra']   = drupal_render($variables['element']);
}

/**
 * The default theme function any other "send" element.
 */
function theme_send_element(&$element) {
  if ($output = drupal_render($element)) {
    return theme('form_element', $element, $output);
  }
}

function theme_send_message_compose_element(&$element) {
  $admin   = drupal_render($element['admin']);
  $content = drupal_render($element['content']);
  $extra = drupal_render($element); 

  $output = '';
  if ($content || $extra) {
    $output .= '<div id="message-content" style="width:70%; float: left; margin-right: 20px;">'.
       $extra . $content 
      .'</div>';
  }
  if ($admin) {
    $output .= $admin;
  }
  if ($output) {
    $output .= '<br clear="all" />';
  }
  return $output;
}

function theme_send_subject($subject, $profile, $template, $values) {
  if ($template && !$template->subject_editable) {
    return $template->subject;
  }
  return $subject;
}

function theme_send_body($body, $profile, $values = array()) {
  /*
    TODO:
      build_mode  should be implemented in SendProfile
      body_format should be implemented in SendProfile
  */
  $build_mode = isset($profile->build_mode) ? $profile->build_mode : 'teaser';

  $tokens = $replace = array();

  // The content may have been supplied. If not, generate!
  if ($profile->content()) {
    $content = '';
    foreach ($profile->content() as $name => $data) {
      // Special-case the 'message' element.
      if ($name == 'message') {
        $values[$name] = $data['content'];
        continue;
      }
      elseif (isset($data['nid'])) {
        $delta = $i+1;
        $node = node_load($data['nid']);
        if (!isset($data['content'])) {
          $node->build_mode = isset($data['build_mode']) ? $data['build_mode'] : $build_mode;
          $teaser = $node->build_mode == 'teaser';
          $data['content'] = node_view($node, $teaser);
        }

        if (module_exists('token')) {
          $tok = token_get_values('node', $node);
          foreach ($tok->tokens as $k => $v) {
            $tok->tokens[$k] = '['. $v .']';
          }

          // Use unqualified tokens for the first node.
          if ($delta == 1) {
            $tokens = array_merge($tokens, $tok->tokens);
            $replace = array_merge($replace, $tok->values);
          }

          // Create a set of tokens for each included node.
          foreach ($tok->tokens as $k => $v) {
            $tok->tokens[$k] = '[node'. $delta .'-'. substr($v, 1);
          }
          $tokens = array_merge($tokens, $tok->tokens);
          $replace = array_merge($replace, $tok->values);
        }
      }
      if (isset($data['content'])) {
        $content .= $data['content'];
      }
    }
    $values['body'] = $content;
  }

  foreach ($values as $key => $value) {
    if ($key && is_scalar($value)) {
      $tokens[] = '%'. $key;
      $replace[] = $value;
    }
  }

  // Set some global tokens.
  if (module_exists('token')) {
    $tok = token_get_values('global');
    $tokens = array_merge($tokens, $tok->tokens);
    $replace = array_merge($replace, $tok->values);
  }

  $body = str_replace($tokens, $replace, $body);
  if (isset($profile->body_format)) {
    $body = check_markup($body, $profile->body_format);
  }
  return $body;
}

function theme_send_draggable($element) {
  $id = $element['#id'] .'-table';
  $weight_class = $element['#id'] .'-weight';

  $rows = array();
  foreach (element_children($element) as $key) {
    $weight = "";
    if (isset($element[$key]['weight'])) {
      $element[$key]['weight']['#attributes']['class'] = $weight_class;
      $weight = drupal_render($element[$key]['weight']);
    }
    $content = drupal_render($element[$key]);

    if ($weight) {
      $rows[] = array(
        'data' => array($content, $weight),
        'class' => 'draggable',
      );
    }
    else {
      $rows[] = array($content);
    }
  }

  drupal_add_tabledrag($id, 'order', 'sibling', $weight);

  $output = theme('table', array(), $rows, array('id' => $id));
  return $output;
}
