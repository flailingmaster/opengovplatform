; $Id: README.txt,v 1.3 2010/09/18 17:05:02 richardp Exp $
=======================
Safer Login
=======================
Richard Peacock (richard@richardpeacock.com)

This module encrypts the user's password when they type it in
during login, so a 3rd party up to no good can't view the user's
password in plain text (as is currently the case for Drupal sites
not protected by an SSL certificate).

Encryption is accomplished by replacing what the user enters for their
password with a uniquely-salted MD5 hash of the MD5 hash of what they typed (so
it is 2-layers deep).  If the user does not have javascript enabled,
then the default Drupal behavior (no hashing) still works.

Of course, this is no substitute for an SSL certificate on your server,
but if you cannot afford an SSL certificate (or only require basic
protection from hackers) this module is for you.

Requires: the jQuery MD5 plugin, available here: 
        http://plugins.jquery.com/files/jquery.md5.js.txt
        or here: http://plugins.jquery.com/project/md5

There are two methods for installation:
        
===================
Basic Installation:
===================

- Unpack this module's files into /modules/safer_login.

- Download the jquery MD5 plugin and copy it to 
  /modules/safer_login/jquery_md5/.  
  
- *** Rename the file to "jquery.md5.js" ***
  
- Enable the module and visit "admin/settings/safer-login"
  for configuration options.

  
====================================
Optional Libraries API Installation:
====================================

The Libraries API module (http://drupal.org/project/libraries)
lets users install 3rd party plugins in a special /libraries/
directory under sites/all.  This way, modules which require
those libraries do not require re-downloading the plugin when
the user upgrades.  This method is not required to install
Safer Login, but does make upgrading easier in the future.

If using the Libraries API module:

    1. Install the Safer Login and Libraries API modules in your site's modules directory.
 
    2. Download the jQuery MD5 plugin. Rename it to jquery.md5.js. If
       you compress it, name it either jquery.md5.min.js or
       jquery.md5.packed.js depending on the compression method you
       employ. 
 
    3. Copy the jQuery MD5 plugin to sites/all/libraries/jquery_md5
       (or sites/<sitename>/libraries/jquery_md5 if you have a
       multisite install). 
       
       Your final location should be one of the following:
 
       + source: sites/all/libraries/jquery_md5/jquery.md5.js
 
       + minified: sites/all/libraries/jquery_md5/jquery.md5.min.js
 
       + packed: sites/all/libraries/jquery_md5/jquery.md5.packed.js
 

 To help with installation, Safer Login will report onscreen and under
 admin/reports/status if the jQuery MD5 plugin cannot be found.
 
 jQuery MD5 plugin: http://plugins.jquery.com/project/md5
 Libraries API: http://drupal.org/project/libraries
 




