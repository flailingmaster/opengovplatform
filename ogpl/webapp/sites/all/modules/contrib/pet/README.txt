The Previewable Email Template (PET) module lets you create email templates,
with token substitution, which can be previewed by the user before sending.
The emails can be sent to one or many email addresses in a flexible way,
and the recipients may or may not be Drupal account holders (users).

PET stores templates in a db table, not the variables table, so there is
none of the memory usage which goes with the latter.


Required Modules
-------------------
- Token


Installation
------------
1) Copy the pet directory to the modules folder in your installation.

2) Enable the module using Administer -> Modules (/admin/build/modules)


Configuration
-------------
Configure (create, edit, delete) the templates for your site at Administer -> Site Building -> Previewable email templates (/admin/build/pets)
  
  Name - Machine name for the template. This is used when adding the template to your code.
  
  Title - A descriptive title for the template.
  
  Subject - The email subject.  May contain tokens (see below).
  
  Body - The email body.  May contain tokens (see below).
  
  Recipient callback - The name of a function which is called to retrieve a list of email recipients, if
  the uid argument is 0 (not missing, but the number 0).  This is a function that you provide.  If there
  is a nid argument, the node is loaded and passed to this function.
  
  Custom tokens - The standard 'node', 'user', and 'global' tokens are provided.  Replacements are made for
  'node' and 'user' if the nid and uid arguments, respectively, are non-empty.  If you have custom token
  handlers which expect an object of type 'node' or 'user', list them here.  TODO: add general support for 
  other token types, including comments.


Usage Via Links
---------------
To invoke a PET, use the path /pet/[pet_name].  In this simple form, with no arguments provided, the user
will be required to enter a single email address.  No user or node substitution will be available, although
global substitutions will be made.

To invoke a PET for a single user include the uid in the arguments, e.g. /pet/[pet_name]?uid=17.  This will
provide token substitution for user 17.

To invoke a PET for a custom list of users, set uid to 0 in the arguments, e.g. /pet/[pet_name]?uid=0.  The
recipient callback function will be invoked to return an array of users in the form [uid]|[email].  If the 
uid is present, token substitution will be done.  If there is no uid, leave it out (but leave the pipe in).

To invoke a PET with node substitution, add the node id to the arguments, e.g. /pet/[pet_name]?uid=17&nid=244.
Token substitution will be done on both user 17 and node 244.


Usage From Code
---------------
pet_send_mail() sends email to multiple recipients.  pet_send_one_mail() sends email to one recipient.  See
these function headers for documentation.


CCK and Views Integration
-------
Supports the CCK field type "PET Reference", which is available when you enable the petreference module.  This
field lets you stores templates specific to certain content with that content.

The petreference module also includes basic Views support, including a Views type PET, which can be used to
create Views of PETs, and support for displaying PET Reference fields in Node type Views.


Ubercart Integration
-------
PET offers a conditional action which lets you send PET-based emails instead of Ubercart action emails.
The Ubercart order tokens are available to your templates.  Using PETs in this way can be useful if
a) you want a unified entry point to all your configurable email templates, or b) you send the PET email
outside the context of an Ubercart order as well as within one, and don't want to replicate your templates.


Preview
-------
When Preview is clicked, token substitution is made for the first recipient, and the email displayed.  This
allows error checking.  It also allows the template to be customized on a one-off basis for a send, without
altering the stored template.

To send the email(s) click Send email(s).


API
-------
pet_send_mail() can be called from code to generate email.
pet_insert() can be called from code to insert a template into the db (e.g. from an install function).

