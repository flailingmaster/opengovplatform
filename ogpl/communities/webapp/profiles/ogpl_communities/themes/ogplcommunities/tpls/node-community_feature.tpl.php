<?php
// $Id: node-community_feature.tpl.php
?>

<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">
  <div class="content clear-block">
    <?php //dsm($node); ?>
	<div style="position:relative;" width="560">
        <p style="position:absolute;top:20px;left:20px;"><span class="special">Special Features</span></p>	
		<div><?php print $node->field_image_info[0][safe]; ?>
		<h2 style="position:absolute; <?php print $node->field_title_position[0][safe]; ?>">
			<?php print $node->title; ?>
		</h2>
		<div style="position:absolute; <?php print $node->field_body_position[0][safe]; ?>">
			<?php print $node->content['body']['#value']; ?>
		</div>
	</div>
  </div>
</div>
