/* $Id: README.txt,v 1.9.2.4 2010/07/07 13:01:27 smk Exp $ */

-- SUMMARY --

Adds SMTP support for sending e-mails using the PHPMailer library.

For a full description of the module, visit the project page:
  http://drupal.org/project/phpmailer
To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/phpmailer


-- REQUIREMENTS --

* Access to an SMTP server

* PHPMailer for PHP5/6
  http://phpmailer.codeworxtech.com

Optional:

* To connect to an SMTP server using SSL, your PHP installation needs to have
  OpenSSL support.

* Mime Mail module to send HTML e-mails
  http://drupal.org/project/mimemail

* Personalized E-mails module to adjust the displayed sender name
  http://drupal.org/project/pmail


-- INSTALLATION --

1. Download PHPMailer for PHP5/6 from

     http://sourceforge.net/projects/phpmailer/files/phpmailer%20for%20php5_6/

   and extract the the following files to the subdirectory 'phpmailer' of this
   module:

     class.phpmailer.php
     class.smtp.php
 
   Be careful NOT to extract the path names contained in the archive.

2. Install as usual, see http://drupal.org/node/70151 for further information.


-- CONFIGURATION --

* Configure user permissions at Administer >> User management >> Access control
  >> phpmailer module.

  Only users with the "administer phpmailer settings" permission will gain
  access to the module configuration page.

* When not using the optional Mime Mail module, customize module settings at
  Administer >> Site configuration >> PHPMailer.

  If used in conjunction with Mime Mail, PHPMailer will show up as an e-mail
  engine in the Mime Mail module settings.  Note that there will be no separate
  PHPMailer configuration page in this case.

* Using Google Mail as SMTP server

  To send e-mails with Google Mail use the following settings:

    SMTP server:     smtp.gmail.com
    SMTP port:       465
    Secure protocol: SSL
    Username:        your_google_mail_name@gmail.com
    Password:        your_google_mail_password

  In Advanced SMTP settings:
    Enable 'Always set "Reply-To" address' checkbox.

  Also note the sending limits for Google Mail accounts:
  http://mail.google.com/support/bin/answer.py?hl=en&answer=22839

* Errors when trying to send a test email

  If you see the following error messages when trying to send a test email from
  the settings page:

    SMTP -> ERROR: Failed to connect to server: Connection timed out (110)
    SMTP Error: Could not connect to SMTP host. 

  it means the mail server can not be reached, usually because your hosting
  provider is blocking the port by a firewall. The solution is to ask your
  provider to allow outgoing connections to your mail server.

* Debug settings

  PHPMailer supports rerouting all e-mails for debugging purposes, to prevent
  you from accidentally sending out e-mails to real users from a development
  site.  To enable this feature, add the following lines to the end of your
  settings.php (usually located in sites/default):

    $conf['phpmailer_debug_email'] = 'your_debug_email@yoursite.com';

  This will change the recipient of all e-mails to the configured address.


-- CREDITS --

Authors:
* Stefan M. Kudwien (smk-ka) - http://drupal.org/user/48898
* Daniel F. Kudwien (sun) - http://drupal.org/user/54136

This project has been sponsored by UNLEASHED MIND
Specialized in consulting and planning of Drupal powered sites, UNLEASHED
MIND offers installation, development, theming, customization, and hosting
to get you started. Visit http://www.unleashedmind.com for more information.

