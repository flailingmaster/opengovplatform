<?php

/**
 * @file
 * Contains the views handler for download_count to correct file name and filepath links
 * for files protected by the private_upload module. It should really be part of the
 * private_upload module, but private_upload does not currently provide views 2 integration.
 */

/**
 * Fix node title field to reflect correct private_upload path.
 */
class download_count_views_handler_field_file extends views_handler_field_file {

  /**
   * Constructor to provide additional field info.
   */
  function init(&$view, &$options) {
    parent::init($view, $options);
    if (!empty($options['link_to_file'])) {
      $this->additional_fields['filename'] = 'filename';
      $this->additional_fields['fid'] = 'fid';
    }
  }


  /**
   * Render whatever the data is as a link to the file.
   *
   * Data should be made XSS safe prior to calling this function.
   */
  function render_private($data, $values) {
    if (!empty($this->options['link_to_file']) && $data !== NULL && $data !== '') {
      global $base_url;
      $file->fid = $values->{$this->aliases['fid']};
      $file->filename = $values->{$this->aliases['filename']};
      $file->filepath = $values->{$this->aliases['filepath']};

      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = function_exists('_private_upload_create_url') ? _private_upload_create_url($file) : file_create_url($values->{$this->aliases['filepath']});
      if ($data == $file->filepath) {
        $data = drupal_substr($this->options['alter']['path'], drupal_strlen($base_url) + 1);
      }
    }
    return $data;
  }

  function render($values) {
    return $this->render_private(check_plain($values->{$this->field_alias}), $values);
  }

}
