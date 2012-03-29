<?php
// $Id: moderation.moderation.inc,v 1.1.2.8 2009/08/04 11:54:24 sanduhrs Exp $

/**
 * @file
 * Moderation - nodes and comments queue
 *
 * @author
 * Stefan Auditor <stefan.auditor@erdfisch.de>
 */

/*
 * Menu callback: content administration.
 */
function moderation_node_queue() {
  drupal_add_css(drupal_get_path('module', 'moderation') .'/moderation.css');
  $settings = array('moderationType' => 'node');
  drupal_add_js('jQuery.extend(Drupal.settings, '. drupal_to_js($settings) .')', 'inline');
  drupal_add_js(drupal_get_path('module', 'moderation') .'/moderation.js');

  $query = "SELECT n.*, u.name, u.uid, mm.status as moderate FROM {node} n
              INNER JOIN {users} u ON n.uid = u.uid
              LEFT JOIN {moderation_moderation} mm ON n.nid = mm.obj_id
                WHERE mm.obj_type = 'node'
                  AND (mm.status IS NULL OR mm.status=0)
                  AND n.type IN ('" . implode('\' ,\'', variable_get('moderation_moderated_types', array())) ."')
                ORDER BY n.created DESC, n.title ASC";
  $result = pager_query(db_rewrite_sql($query), 50);

  $destination = drupal_get_destination();

  while ($node = db_fetch_object($result)) {
    $query = "SELECT m.*, u.name FROM {moderation} m
                LEFT JOIN {users} u ON m.uid = u.uid
                WHERE m.obj_id=%d
                  AND m.obj_type='node'
                ORDER BY m.created DESC
                LIMIT 1";
    $moderation = db_fetch_object(db_query($query, $node->nid));
    $token = drupal_get_token('node-'. $node->nid);

    $item = '<div id="moderation-content-'. $node->nid .'" class="moderation-content clear-block container-inline">';
    $item .= '<div id="moderation-title-'. $node->nid .'" class="moderation-title title">';
    $item .= format_date($node->created, 'small') .' ';
    $item .= l($node->title, 'moderation/node/'. $node->nid .'/get/preview');
    $item .= theme('mark', node_mark($node->nid, $node->changed));
    if ($moderation) {
      $item .= ' <div class="moderation-moderation" title="'. t('Last status change') .'">'. t('(!user - !action - !date)', array('!user' => theme('username', (object) array('uid' => $moderation->uid, 'name' => $moderation->name)), '!action' => moderation_log_message($moderation->attribute, $moderation->status, $moderation->obj_type), '!date' => format_date($moderation->created, 'small'))) .'</div>';
    }
    $item .= '</div>';
    $item .= '</div>';

    $item .= '<div id="moderation-info-'. $node->nid .'" class="moderation-info clear-block">';
    $item .= '  <span id="moderation-operations-'. $node->nid .'" class="moderation-attribute moderation-operations">'. l(t('edit'), 'node/'. $node->nid .'/edit', array('query' => drupal_get_destination())) .'</span>';
    $item .= '  <span id="moderation-username-'. $node->nid .'" class="moderation-attribute moderation-username">'. t('By !user', array('!user' => theme('username', $node))) .'</span>';
    $item .= '  <span id="moderation-name-'. $node->nid .'" class="moderation-attribute moderation-name">'. check_plain(node_get_types('name', $node)) .'</span>';
    $item .= '  <span class="moderation-attribute moderation-status">'. l(($node->status   ? t('Unpublish') : t('Publish')), 'moderation/node/'. $node->nid .'/set/status', array('query' => drupal_get_destination() .'&token='. $token, 'attributes' => array('id' => 'moderation-status-link-'. $node->nid, 'class' => 'moderation-status-link'))) .'</span>';
    $item .= '  <span class="moderation-attribute moderation-promote">'. l(($node->promote  ? t('Demote')  : t('Promote')), 'moderation/node/'. $node->nid .'/set/promote', array('query' => drupal_get_destination() .'&token='. $token, 'attributes' => array('id' => 'moderation-promote-link-'. $node->nid, 'class' => 'moderation-promote-link'))) .'</span>';
    $item .= '  <span class="moderation-attribute moderation-sticky">'. l(($node->sticky   ? t('Remove stickiness')    : t('Make sticky')), 'moderation/node/'. $node->nid .'/set/sticky', array('query' => drupal_get_destination() .'&token='. $token, 'attributes' => array('id' => 'moderation-sticky-link-'. $node->nid, 'class' => 'moderation-sticky-link'))) .'</span>';
    $item .= '  <span class="moderation-attribute moderation-moderate">'. l(($node->moderate ? t('Unmoderate') : t('Moderate')), 'moderation/node/'. $node->nid .'/set/moderate', array('query' => drupal_get_destination() .'&token='. $token, 'attributes' => array('id' => 'moderation-moderate-link-'. $node->nid, 'class' => 'moderation-moderate-link'))) .'</span>';
    $item .= '</div>';

    $rows[] = array('data' =>
      array(
        array(
          'data' => $item,
        ),
      )
    );
  }

  if (!$rows) {
    $output = t('No posts available.');
  }

  $output .= theme('table', array(), $rows);
  $output .= theme('pager', NULL, 50);

  return $output;
}

/**
 * Menu callback; present an administrative comment listing.
 */
function moderation_comment_queue() {
  drupal_add_css(drupal_get_path('module', 'moderation') .'/moderation.css');
  $settings = array('moderationType' => 'comment');
  drupal_add_js('jQuery.extend(Drupal.settings, '. drupal_to_js($settings) .')', 'inline');
  drupal_add_js(drupal_get_path('module', 'moderation') .'/moderation.js');

  $query = "SELECT c.*, mm.status as moderate FROM {comments} c
           LEFT JOIN {moderation_moderation} mm ON c.cid = mm.obj_id
           WHERE mm.obj_type = 'comment'
             AND (mm.status IS NULL OR mm.status=0)
           ORDER BY c.timestamp DESC, c.subject ASC";
  $result = pager_query(db_rewrite_sql($query), 50);
  $destination = drupal_get_destination();

  while ($comment = db_fetch_object($result)) {
    $query = "SELECT m.*, u.name FROM {moderation} m
                LEFT JOIN {users} u ON m.uid = u.uid
                WHERE m.obj_id=%d
                  AND m.obj_type='comment'
                ORDER BY m.created DESC
                LIMIT 1";
    $moderation = db_fetch_object(db_query($query, $comment->cid));
    $token = drupal_get_token('comment-'. $comment->cid);
    $node_title = db_result(db_query("SELECT title FROM {node} WHERE nid = %d", $comment->nid));

    $item = '<div id="moderation-content-'. $comment->cid .'" class="moderation-content clear-block container-inline">';
    $item .= '<div id="moderation-title-'. $comment->cid .'" class="moderation-title title">';
    $item .= format_date($comment->timestamp, 'small') .' ';
    $item .= l($comment->subject, 'moderation/comment/'. $comment->cid .'/get/preview', array('attributes' => array('title' => t('Show preview'))));
    $item .= theme('mark', node_mark($comment->cid, $comment->changed));
    if ($moderation) {
      $item .= ' <div class="moderation-moderation" title="'. t('Last status change') .'">'. t('(!user - !action - !date)', array('!user' => theme('username', (object) array('uid' => $moderation->uid, 'name' => $moderation->name)), '!action' => moderation_log_message($moderation->attribute, $moderation->status, $moderation->obj_type), '!date' => format_date($moderation->created, 'small'))) .'</div>';
    }
    $item .= '</div>';
    $item .= '</div>';

    $item .= '<div id="moderation-info-'. $comment->cid .'" class="moderation-info clear-block">';
    $item .= '  <span id="moderation-operations-'. $comment->cid .'" class="moderation-attribute moderation-operations">'. l(t('edit'), 'comment/edit/'. $comment->cid, array('query' => drupal_get_destination())) .'</span>';
    $item .= '  <span id="moderation-username-'. $comment->cid .'" class="moderation-attribute moderation-username">'. t('By !user', array('!user' => theme('username', $comment))) .'</span>';
    $item .= '  <span id="moderation-parent-'. $comment->cid .'" class="moderation-attribute moderation-parent">'. t('Show !node', array('!node' => l('Node', 'node/'. $comment->nid, array('attributes' => array('title' => check_plain($node_title)))))) .'</span>';
    $item .= '  <span class="moderation-attribute moderation-moderate">'. l(($comment->moderate ? t('Unmoderate') : t('Moderate')), 'moderation/comment/'. $comment->cid .'/set/moderate', array('query' => drupal_get_destination() .'&token='. $token, 'attributes' => array('id' => 'moderation-moderate-link-'. $comment->cid, 'class' => 'moderation-moderate-link'))) .'</span>';
    $item .= '  <span class="moderation-attribute moderation-status">'. l(($comment->status ? t('Publish') : t('Unpublish')), 'moderation/comment/'. $comment->cid .'/set/status', array('query' => drupal_get_destination() .'&token='. $token, 'attributes' => array('id' => 'moderation-status-link-'. $comment->cid, 'class' => 'moderation-status-link'))) .'</span>';
    $item .= '</div>';

    $rows[] = array('data' =>
      array(
        array(
          'data' => $item,
        ),
      )
    );
  }

  if (!$rows) {
    $output = t('No comments available.');
  }

  $output .= theme('table', array(), $rows);
  $output .= theme('pager', NULL, 50);
  return $output;
}

function moderation_log($type = 'node', $obj_id = NULL) {

  switch ($type) {
    case 'comment':
      $sql = "SELECT m.*, c.nid, c.cid, c.subject, u.uid, u.name FROM {moderation} m
                LEFT JOIN {comments} c ON c.cid = m.obj_id
                LEFT JOIN {users} u ON u.uid = m.uid
                WHERE m.obj_type = 'comment' ". ($obj_id ? 'AND m.obj_id = '. $obj_id : '') ." ORDER BY m.created DESC";
      break;
    case 'node':
      $sql = "SELECT m.*, n.title, n.nid, u.uid, u.name FROM {moderation} m
                LEFT JOIN {node} n ON n.nid = m.obj_id
                LEFT JOIN {users} u ON u.uid = m.uid
                WHERE m.obj_type = 'node' ". ($obj_id ? 'AND m.obj_id = '. $obj_id : '') ." ORDER BY m.created DESC";
      break;
  }

  $result = pager_query($sql, 25, 0, NULL);
  while ($moderation = db_fetch_object($result)) {
    $title = $moderation->subject ? $moderation->subject : $moderation->title;
    $fragment = $moderation->cid ? 'comment-'. $moderation->cid : NULL;

    $user->uid = $moderation->uid;
    $user->name = $moderation->name;

    $moderations[] = array(
      l($title, 'node/'. $moderation->nid, array('fragment' => $fragment)),
      theme('username', $user),
      moderation_log_message($moderation->attribute, $moderation->status, $type),
      format_date($moderation->created),
    );
  }

  $header = array(
    t('Title'), t('User'), t('Action'), t('Date'),
  );
  $output = theme('table', $header, $moderations);
  $output .= theme('pager');
  return $output;
}

function moderation_log_message($attribute, $status, $type) {
  switch ($attribute) {
    case 'status':
      $message = $status ? t('Published') : t('Unpublished');
      break;
    case 'moderate':
      $message = $status ? t('Moderated') : t('Unmoderated');
      break;
    case 'sticky':
      $message = $status ? t('Made sticky') : t('Removed stickiness');
      break;
    case 'promote':
      $message = $status ? t('Promoted') : t('Not promoted');
      break;
  }
  return $message;
}
