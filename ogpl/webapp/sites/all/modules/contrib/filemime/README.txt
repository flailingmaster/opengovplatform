// $Id: README.txt,v 1.1.2.3 2008/08/15 09:52:48 mfb Exp $

Drupal determines the MIME type of each uploaded file by applying a MIME 
extension mapping to the file name.  The mapping is a hard-coded 
variable in the file_get_mimetype() function: 
http://api.drupal.org/api/function/file_get_mimetype

This module allows site administrators to add additional MIME extension 
mappings or modify the built-in mappings.  For example, you may wish to 
serve FLAC files as audio/x-flac rather than application/x-flac.

Custom mappings can be extracted from the server's mime.types file 
(often available on a path such as /etc/mime.types) and/or a 
site-specific mapping string, both of which must use the standard syntax 
for mime.types files.  For example:

text/html	html htm
text/plain	txt

After installing and enabling this module, the MIME extension mappings 
can be customized by visiting Administer > Site configuration > File 
MIME types (admin/settings/filemime).

Once a custom mapping is configured, the built-in mappings will no 
longer be available, so all desired mappings must be explicitly set, 
either in the mime.types file or in the additional mappings text box.
You cannot simply append extra mappings to the built-in mappings.

Uninstalling this module will delete the mime_extension_mapping 
variable, thus restoring Drupal's built-in mappings.
