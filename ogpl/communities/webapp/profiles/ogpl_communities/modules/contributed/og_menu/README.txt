$Id: README.txt,v 1.5 2010/09/08 11:53:41 jide Exp $

DESCRIPTION
-----------
Enable users to manage menus inside Organic Groups.

REQUIREMENTS
------------
- Organic Groups module (http://drupal.org/project/og).
- Menu module.

INSTALLATION
------------
- Enable the module.
- Give "administer og menu" permission to the desired roles.

USAGE
-----
- Administrators can create OG menus through the regular menu interface at admin/build/menu/add. Choose a group to associate with the menu.
- Organic group members with the right permission can also manage menus at node/[nid]/og_menu.
- For content types that can be published in groups, users can add a menu link directly from the node creation form.
- For groups content types, users can create an associated menu by checking "Enable menu for this group".
- The menu will be appended to the "Group details" block by default. You can disable this by configuring the block and unchecking "Show group menus".
- You can also enable the "OG Menu : single" and the "OG Menu : multiple" blocks at admin/build/block.
  - OG Menu : single will display the first available menu for the first available group in the context.
  - OG Menu : multiple will display all available menus for all available groups in the context.
  - To theme the block, use the block-og_menu-0.tpl.php and the block-og_menu-1.tpl.php files, respectively.

NOTES
-----
Be aware that since menu administration forms are mostly duplicated, if a contrib module adds functionality to menu administration
forms without additional permissions, these additions may be available for OG menu users with 'administer og menu' permission. 
This could allow these users to be able to do things you don't want them to. Please report these modules if you catch one.

TODO/BUGS/FEATURE REQUESTS
--------------------------
- See http://drupal.org/project/issues/og_menu. Please search before filing issues in order to prevent duplicates.

UPGRADING FROM 6.1.x TO 6.2.x
-----------------------------
- Visit update.php to update the database.

CREDITS
-------
Originaly authored and maintained by Scott Ash (ashsc).
New maintainer for 6.2.x version : Julien De Luca (jide).
