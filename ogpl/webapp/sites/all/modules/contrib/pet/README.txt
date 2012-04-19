The Previewable Email Template (PET) module lets you create email templates, with token substitution, 
which can be previewed by the user before sending.  The emails can be sent to one or many email addresses 
in a flexible way, and the recipients may or may not be Drupal account holders (users).

PET stores templates in a db table, not the variables table, so there is none of the memory usage which 
goes with the latter.


Required Modules
-------------------
- Token


Installation
------------
1) Copy the pet directory to the modules folder in your installation.

2) Enable the module using Administer -> Modules (/admin/build/modules)


Template Configuration
-------------
Configure (create, edit, delete) the templates for your site at Administer -> Site Building -> Previewable email templates (/admin/build/pets)
  
  Name (required) - Machine name for the template. This is useful if you want to refer to your template from code.
  
  Title (required) - A descriptive title for the template.  Neither this nor Name appear anywhere in the email itself.
  
  Subject (required) - The email subject.  May contain tokens for value substitution (see below).
  
  Body (optional but obviously common) - The email body.  Like Subject, may contain tokens (see below).
  
  From override (optional) - An alternative From address for emails originating from this template.  If not provided
  the site default is used.
  
  CC default (optional) - One or more emails to be cc'd on every email sent using this template.

  BCC default (optional) - One or more emails to be blind cc'd on every email sent using this template.
  
  Recipient callback (optional) - The name of a function which is called to retrieve a list of email recipients, if
  the uid argument is 0 (not missing, but the number 0).  This is a function that you provide.  If there
  is a nid argument, the node is loaded and passed to this function.
  
  Custom tokens (optional) - The standard 'node', 'user', and 'global' tokens are provided.  Replacements are made for
  'node' and 'user' if the nid and uid arguments, respectively, are positive integers.  If you have custom token
  handlers which expect an object of type 'node' or 'user', list them here.  


Template Usage Via Links / UI
---------------
To invoke a PET, use the path /pet/[pet_name].  In this simple form, with no arguments provided, the user
will be required to enter one or more email addresses.  User token substitutions will be made for every email
that has a corresponding user in the site.  Global token substitutions will also be made.

You can provide a default user in the To field by including uid=[uid] in the query, e.g. /pet/[pet_name]?uid=17.  
This will provide token substitution for user 17.  Additional email recipients can be added.

To invoke a PET for a custom list of users, specify "recipient_callback=true" in the query, for example
/pet/[pet_name]?recipient_callback=true. If the PET is set up to support user token substitution then for each
email with a corresponding user the substitution will take place.

To invoke a PET with node substitution, add the node id to the arguments, e.g. /pet/[pet_name]?uid=17&nid=244.  
Token substitution will be done on both user 17 and node 244.  Recipient callback could be used as well, as in /pet/[pet_name]?recipient_callback=true&nid=244.


Template Usage From Code
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

