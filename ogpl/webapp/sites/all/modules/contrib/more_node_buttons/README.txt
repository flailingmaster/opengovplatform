// $Id: README.txt,v 1.1.4.9 2010/11/04 15:08:23 quiptime Exp $
================================================================================

The More node buttons (Mnb) module allow to add the following buttons to node
edit forms:

- "Cancel"
- "Save and continue"
- "Save and create new"

Furthermore, a "Create new" tab can be used.

Requirements
--------------------------------------------------------------------------------
This module is written for Drupal 6.0+.

Installation
--------------------------------------------------------------------------------
Copy the Mnb module folder to your module directory and then enable on the admin
modules page.

Administration
--------------------------------------------------------------------------------
1. Go to administer content types admin/content/node-type and edit an content 
   type.
   In the section "Button settings" please choose the options to use
   the "Cancel" and/or the "Save and continue" and/or "Save and create new"
   button and/or the "Create new" tab.
2. Go to administer Mnb admin/settings/more-node-buttons to see an overview to
   configure the settings for all content types.

Limitations
--------------------------------------------------------------------------------
- For the content type Panel no settings can be made with Mnb.
- The "Save and create new" button is not available if you edit an node from
  the content management page admin/content/node.
- Add new content via the "Create new" tab or the "Save and create new" button.
  The "Cancel" redirect to the node page, not to the edit page.

Implementations
--------------------------------------------------------------------------------
The Mnb module implement the functions of the following modules:

- Submit Again, http://drupal.org/project/submitagain
  The "Save and create new" button.

- Add another, http://drupal.org/project/addanother
  The "Create new" tab.

Thanks to the maintainers of these modules for the inspiration.

FAQ
--------------------------------------------------------------------------------
- What is "referer redirection"?

  The referer redirection allows the redirection to the page was started the
  action to create or edit a node if this action is canceled.
  This function is needed for node lists with edit link to nodes or if are used
  the link to create new content not on the default page "Create content".

Module developers
--------------------------------------------------------------------------------
You can interact with the Mnb module. You can use the button and tab values,
defined by the Mnb module.
For more informations please read the code included comments of the function
more_node_buttons_get_values().

Example to get the "Save and continue" button value:

$value = module_invoke('more_node_buttons', 'get_values', 'sac');

Author
--------------------------------------------------------------------------------
Quiptime Group
Siegfried Neumann
www.quiptime.com
quiptime [ at ] gmail [ dot ] com
