<?php
// $Id$

/**
 * @file dialog-content.tpl.php
 *
 * Theme implementation to display the content section of a dialog.
 *
 * Available variables:
 *
 * - $help: Dynamic help text.
 * - $messages: HTML for status and error messages. Should be displayed prominently.
 * - $content: The main content of the current dialog.
 *
 * @see template_preprocess_dialog_content()
 */
?>

<?php if (!empty($messages)): print $messages; endif; ?>
<?php if (!empty($help)): print $help; endif; ?>

<?php print $content; ?>
