Views Embed Form
================

Version
=======
Compatible with 6.x version of Drupal core

Author
======
Jakub Suchy, <info at jsuchy dotNOSPAM cz>

Examples
========

Every module developer who would like to embed his form in view needs to
create function called MODULENAME_views_embed_form(). Always think about
permissions for the form you want to embed. For example if the form should be
accessible only to an user with "administer content", don't forget to check it.
Example:
  
function testmodule_views_embed_form() {
  if (user_access('administer content')) {
    return array(
        // Key in this array is the name of a form and also the name of a form function.
        'testmodule_form' => t('Form for testing module'),
        // Value in this array is a human-readable name of the form, use t() to allow internationalization.
        'testmodule_basket_form' => t('Add to basket form'),
        );
  }
}

Then edit a view, add a field in group Embedded and select your form name.
Everytime a view is displayed, your form is called for every view row. Row
fields (including node nid) are passed as an argument to the form. Example:

function testmodule_form(&$form_state, $fields) {
  // $fields are from a view, useful when you need to know node id for this row.
  // It should be $fields->nid.
}

More documentation
==================
See handbook page: http://drupal.org/node/329511
