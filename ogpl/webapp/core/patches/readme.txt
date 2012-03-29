aggregator_26.patch
-------------------
This patch has been applied to hide aggregator messages to anonymous user 
e.g:
drupal_set_message(t('There is new syndicated content from %site.', array('%site' => $feed['title'])));

The patch aggregator_26.patch has been applied to resolve this.

how to apply:
Install patch: patch -p0 < <patch_path>/aggregator_26.patch
uninstall: patch -p0 -R < <patch_path>/aggregator_26.patch

content_node_form_320313.patch
------------------------------
This patch has been applied to display one field for the flexi field module 

The patch content_node_form_320313.patch has been applied to resolve this.

recaptcha_verification_msg.patch
--------------------------------
This patch has been applied to display verification required message to the user along with captcha 

quicktabs_tab_html.patch
-----------------------
This patch has been applied to add <span> tag to the tab text so that UI can be formatted as per requirement.

how to apply:
------------
Install patch: patch -p0 < <patch_path>/content_node_form_320313.patch
uninstall: patch -p0 -R < <patch_path>/content_node_form_320313.patch

