<?php
// $Id: twocol_30-70.tpl.php 7510 2010-06-15 19:09:36Z sheena $
/**
 * @file
 * Template for a 2 column panel layout. Using a 12 column 960 grid.
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['left']: Content in the left column.
 *   - $content['right']: Content in the right column.
 */
?>
<div class="panel-display grid-12 alpha omega" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
    <div class="grid-8 alpha"><?php print $content['left']; ?></div>
    <div class="grid-4 omega"><?php print $content['right']; ?></div>
</div>