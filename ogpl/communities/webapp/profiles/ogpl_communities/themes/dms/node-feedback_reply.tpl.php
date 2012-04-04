<div id="node-<?php print $node->nid; ?>" class="node <?php print $node_classes; ?>">
    <div class="inner">
        <?php print $picture ?>

        <?php if ($page == 0): ?>
        <h2 class="title"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
        <?php endif; ?>

        <?php if ($submitted): ?>
        <div class="meta">
            <span class="submitted"><?php print $submitted ?></span>
        </div>
        <?php endif; ?>
        <div class="print-feedback">
            <?php
			global $base_url;
            global $user;
            if ($user->uid && $node->type == "feedback") { ?>
                <a href="<?php print $base_url; ?>/print/<?php print $node->nid; ?>" target="_blank"><img src="<?php print $base_url; ?>/sites/all/themes/dms/printer_icon.png" width="20px" height="30px"/></a>
                <?php } ?>
            <!--a href="#notes" onclick="showNotes(<?php print $node->nid ?>);">Notes</a-->
        </div>
        <?php if ($node_top && !$teaser): ?>
        <div id="node-top" class="node-top row nested">
            <div id="node-top-inner" class="node-top-inner inner">
                <?php print $node_top; ?>
            </div><!-- /node-top-inner -->
        </div><!-- /node-top -->
        <?php endif; ?>

        <div class="content clearfix">
            <span style="font-weight: bold;">Comments: </span>
            <?php print str_replace($field_feedback_reply_body[0]['safe'], nl2br($field_feedback_reply_body[0]['safe']), $content); ?>
        </div>

        <?php if ($terms): ?>
        <div class="terms">
            <?php print $terms; ?>
        </div>
        <?php endif;?>
        <?php //if ($links): ?>
        <!--div class="links">
      <?php //print $links; ?>
    </div-->
        <?php // endif; ?>
    </div><!-- /inner -->

    <?php if ($node_bottom && !$teaser): ?>
    <div id="node-bottom" class="node-bottom row nested">
        <div id="node-bottom-inner" class="node-bottom-inner inner">
            <?php print $node_bottom; ?>
        </div><!-- /node-bottom-inner -->
    </div><!-- /node-bottom -->
    <?php endif; ?>

</div><!-- /node-<?php print $node->nid; ?> -->
<div class="feedback-comment">
    <?php
    module_load_include('inc', 'comment','comment.admin');
    print drupal_get_form('comment_form', array('nid' => $node->nid));
    ?>
</div>
