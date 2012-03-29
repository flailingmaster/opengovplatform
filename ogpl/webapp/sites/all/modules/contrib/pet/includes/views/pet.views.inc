<?php

/**
 * @file
 * This file provides metadata to the Views 2 API for views integration.
 *
 */

/**
 * hook_views_handlers()
 */
function pet_views_handlers() {
  return array(
    'info' => array(
      'path' => PET_VIEWS_DIR . '/handlers',
    ),
    'handlers' => array(
      // Fields
      'pet_views_handler_field_pid' => array(
        'parent' => 'views_handler_field',
      ),
      'pet_views_handler_field_title' => array(
        'parent' => 'views_handler_field',
      ),
      'pet_views_handler_field_name' => array(
        'parent' => 'views_handler_field',
      ),
      // Filters
      'pet_views_handler_filter_name' => array(
        'parent' => 'views_handler_filter',
      ),
      // Arguments
      'pet_views_handler_argument_pet_nid' => array(
        'parent' => 'views_handler_argument_numeric',
      ),
      'pet_views_handler_argument_pet_name' => array(
        'parent' => 'views_handler_argument',
      ),      
    ),
  );
}

/**
 * Implementation of hook_views_data().
 */
function pet_views_data() {
  $data = array();
  $data['pets'] = array(

    // Table Definition
    'table' => array(
      'group' => t('PET'),
      // Base tables:
      'base' => array(
        'field' => 'pid',
        'title' => t('PET'),
        'help' => t('PETS are Previewable Email Templates.'),
        'weight' => 0,
      ),
    ),

    // Field definitions
    'pid' => array(
      'title' => t('PET pid'),
      'help' => t('The pid of the pet template.'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'argument' => array(
        'handler' => 'pet_views_handler_argument_pet_nid',
        'name field' => 'pet template',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array('handler' => 'views_handler_sort'),
    ),
    'name' => array(
      'title' => t('PET name'),
      'help' => t('The name of the pet template.'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'argument' => array(
        'handler' => 'pet_views_handler_field_name',
        'name field' => 'pet template',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter',
      ),
      'sort' => array('handler' => 'views_handler_sort'),
    ),
    'title' => array(
      'title' => t('PET title'),
      'help' => t('The title of the pet template.'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array('handler' => 'views_handler_sort'),
    ),

  ); 
  return $data;
}