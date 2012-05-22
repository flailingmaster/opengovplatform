<div class="comment<?php print ($comment->new) ? ' comment-new' : ''; print ($comment->status == COMMENT_NOT_PUBLISHED) ? ' comment-unpublished' : ''; print ' '. $zebra; ?>">

  <div class="clear-block">
  <?php if ($submitted): ?>
    <div class="author">Submitted by <span class="author_name"><?php print t('!username',array('!username' => theme('username', $comment)));?></span>
    <span class="submitted">On <?php print t('!date', array('!date' => format_date($comment->timestamp))); ?></span></div>
  <?php endif; ?>

  <?php if ($comment->new) : ?>
    <a id="new"></a>
    <span class="new"><?php print drupal_ucfirst($new) ?></span>
  <?php endif; ?>

  <?php print $picture ?>

    <h3><?php print $title ?></h3>

    <div class="content">
      <?php print $content ?>
    </div>

  </div>

  <?php if ($links): ?>
    <div class="links"><?php print $links ?></div>
  <?php endif; ?>
</div>
