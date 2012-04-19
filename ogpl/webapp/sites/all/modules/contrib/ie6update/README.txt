
------------------
IE 6 UPDATE MODULE
------------------

SUMMARY
-------

This module integrates the IE6 Update JavaScript file (ie6update.com) with
Drupal, unobtrusively encouraging site users to upgrade.


FEATURES
--------

* Mimics the IE information bar to suggest to the user to upgrade their browser.
* Links to the IE 8 update page so the user can upgrade their browser.
* The message in the information bar is configurable.
* The page linked to from the information bar is configurable.


INSTALLATION
------------

* Enable the module
* Modify settings as appropriate at /admin/settings/ie6update.
* Follow translation instructions below if appropriate.


HOW TO TRANSLATE
----------------

You can translate the message in the information bar and link to a non-English
version of IE if you have the i18n module installed.

To do this, add the following variables to the $conf['i18n_variables'] array
in your settings.php file:

* ie6update_destination_url
* ie6update_update_bar_message

Once this is complete, switch to each language and visit the ie6update settings
page using the appropriate language version of the site, enter an appropriate
translation, and save the page. The settings for each language will then be
saved independently.

For more information on i18n variables and translations, please see
http://drupal.org/node/313272
