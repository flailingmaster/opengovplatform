<div class="panel-display grid-12 alpha omega" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
	<div class="grid-12 top-banner alpha omega"><?php print $content['top'];?></div>
    <div class="grid-4 alpha"><?php print $content['left']; ?></div>
    <div class="grid-4"><?php print $content['center']; ?></div>
	<div class="grid-4 omega"><?php print $content['right']; ?></div>
	<div class="grid-12 alpha omega"><?php print $content['bottom'];?></div>
</div>