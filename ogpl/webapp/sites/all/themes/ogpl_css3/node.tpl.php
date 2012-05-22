<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">

  <?php print $picture ?>
  <?php /*if (arg(0) != 'node' or arg(1) != 25): ?>
    <?php if ((arg(0)=="taxonomy" && arg(1)=="term") || $page==0): ?>
    <h2 class="page-title"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
	<div class="page-title-border">&nbsp;</div>
    <?php endif; ?>
    
    <?php if (!((arg(0)=="taxonomy" && arg(1)=="term") || $page==0)): ?>
    <h2 class="page-title"><?php print $title?></h2>
	<div class="page-title-border">&nbsp;</div>
	<?php else: ?>
	<h2 class="page-title"><?php print $title?></h2>
	<div class="page-title-border">&nbsp;</div>
    <?php endif; ?>
    <?php endif; */ ?>


  <?php if ($submitted): ?>
  <span class="submitted"><?php print $submitted; //print format_date($node->created, 'custom', "d.m.Y"); ?></span>
  <?php endif; ?>

  <div class="content">
    <?php print $content ?>
  </div>
</div>