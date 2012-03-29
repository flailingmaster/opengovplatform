<?php
// $Id: views_embed_form.views.inc,v 1.1.2.1 2009/01/07 15:05:09 meba Exp $

/**
 * Implementation of hook_views_data().
 */
function views_embed_form_views_data() {
  // Table definition.
  $data['views_embed_form']['table']['group'] = t('Embedded');
  $data['views_embed_form']['table']['join'] = array(
      '#global' => array(),
      );
  // Fields.
  $data['views_embed_form']['null'] = array(
      'title' => t('Form'),
      'help' => t("Form embedded with a row display of this view."),
      'field' => array(
        'handler' => 'views_handler_field_views_embed_form',
        ),
      );

  return $data;
}
