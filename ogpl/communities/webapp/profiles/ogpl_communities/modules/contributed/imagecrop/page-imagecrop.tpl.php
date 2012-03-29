<?php
// $Id: page-imagecrop.tpl.php,v 1.1.4.3 2010/08/16 08:35:17 zuuperman Exp $
/**
 * @file
 * Imagecrop template file.
 */

header("Cache-Control: no-cache, must-revalidate"); // HTTP/1.1
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language ?>" xml:lang="<?php print $language->language ?>">
<?php
  print $head;
  print $scripts;
  print $styles;
?>
<body>
<?php print $content; ?>
</body>
</html>