<?php

/**
 * Implementation of hook_default_panels_mini().
 */
function home_page_panels_default_panels_mini() {
  $export = array();

  $mini = new stdClass;
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'home_panel';
  $mini->category = '';
  $mini->admin_title = 'Front End Home Panels';
  $mini->admin_description = '<p>Panels on home page.</p>
';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display;
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
        'class' => '',
        'column_class' => '',
        'row_class' => '',
        'region_class' => '',
        'no_scale' => FALSE,
        'fixed_width' => '',
        'column_separation' => '0.5em',
        'region_separation' => '0em',
        'row_separation' => '1em',
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'gallery_box',
        ),
        'parent' => 'main',
        'class' => 'bottomPanel',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Welcome Block',
        'width' => '33.33962026908085',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'left',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'block1',
          1 => 'block2',
          2 => 'block3',
        ),
        'parent' => 'main',
        'class' => 'topPanel',
      ),
      'block1' => array(
        'type' => 'region',
        'title' => 'Block1',
        'width' => '33.420668796376695',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'blocks one alpha',
      ),
      'block2' => array(
        'type' => 'region',
        'title' => 'Block2',
        'width' => '31.380175841523062',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'blocks',
      ),
      'block3' => array(
        'type' => 'region',
        'title' => 'Block3',
        'width' => '35.19915536210024',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'blocks',
      ),
      'gallery_box' => array(
        'type' => 'region',
        'title' => 'Gallery Box',
        'width' => '66.66037973091915',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'right',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'block1' => NULL,
      'block2' => NULL,
      'block3' => NULL,
      'gallery_box' => NULL,
    ),
    'block1' => array(
      'style' => 'default',
    ),
    'block2' => array(
      'style' => 'default',
    ),
    'block3' => array(
      'style' => 'default',
    ),
    'center' => array(
      'style' => 'default',
    ),
    'gallery_box' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'block1';
    $pane->type = 'block';
    $pane->subtype = 'nodeblock-424';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['block1'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'block1';
    $pane->type = 'block';
    $pane->subtype = 'nodeblock-423';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['block1'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'block1';
    $pane->type = 'block';
    $pane->subtype = 'block-19';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-3'] = $pane;
    $display->panels['block1'][2] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'block1';
    $pane->type = 'block';
    $pane->subtype = 'block-18';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-4'] = $pane;
    $display->panels['block1'][3] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'block2';
    $pane->type = 'block';
    $pane->subtype = 'nodeblock-418';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-5'] = $pane;
    $display->panels['block2'][0] = 'new-5';
    $pane = new stdClass;
    $pane->pid = 'new-6';
    $pane->panel = 'block2';
    $pane->type = 'block';
    $pane->subtype = 'nodeblock-419';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-6'] = $pane;
    $display->panels['block2'][1] = 'new-6';
    $pane = new stdClass;
    $pane->pid = 'new-7';
    $pane->panel = 'block2';
    $pane->type = 'block';
    $pane->subtype = 'block-15';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-7'] = $pane;
    $display->panels['block2'][2] = 'new-7';
    $pane = new stdClass;
    $pane->pid = 'new-8';
    $pane->panel = 'block2';
    $pane->type = 'block';
    $pane->subtype = 'block-14';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-8'] = $pane;
    $display->panels['block2'][3] = 'new-8';
    $pane = new stdClass;
    $pane->pid = 'new-9';
    $pane->panel = 'block3';
    $pane->type = 'block';
    $pane->subtype = 'nodeblock-420';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-9'] = $pane;
    $display->panels['block3'][0] = 'new-9';
    $pane = new stdClass;
    $pane->pid = 'new-10';
    $pane->panel = 'block3';
    $pane->type = 'block';
    $pane->subtype = 'nodeblock-421';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-10'] = $pane;
    $display->panels['block3'][1] = 'new-10';
    $pane = new stdClass;
    $pane->pid = 'new-11';
    $pane->panel = 'block3';
    $pane->type = 'block';
    $pane->subtype = 'block-17';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-11'] = $pane;
    $display->panels['block3'][2] = 'new-11';
    $pane = new stdClass;
    $pane->pid = 'new-12';
    $pane->panel = 'block3';
    $pane->type = 'block';
    $pane->subtype = 'block-16';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-12'] = $pane;
    $display->panels['block3'][3] = 'new-12';
    $pane = new stdClass;
    $pane->pid = 'new-13';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'nodeblock-432';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'ideasPan',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-13'] = $pane;
    $display->panels['center'][0] = 'new-13';
    $pane = new stdClass;
    $pane->pid = 'new-14';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'block-22';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'ideasPan',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-14'] = $pane;
    $display->panels['center'][1] = 'new-14';
    $pane = new stdClass;
    $pane->pid = 'new-15';
    $pane->panel = 'gallery_box';
    $pane->type = 'block';
    $pane->subtype = 'nodeblock-425';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'galleryPan gallery',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-15'] = $pane;
    $display->panels['gallery_box'][0] = 'new-15';
    $pane = new stdClass;
    $pane->pid = 'new-16';
    $pane->panel = 'gallery_box';
    $pane->type = 'block';
    $pane->subtype = 'block-20';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'galleryPan gallery',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-16'] = $pane;
    $display->panels['gallery_box'][1] = 'new-16';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['home_panel'] = $mini;

  return $export;
}
