<?php if ($sender):?>
  <?php print theme('table', array(t('From'), t('To')), array(array('data' => array($sender, $recipients), 'valign' => 'top')), array('width' => '100%'))?>
<?php else: ?>
  <?php print $recipients ?>
<?php endif?>

<br class="clear" />
<?php if ($extra):?>
  <?php print $extra ?>'<br class="clear" />
<?php endif?>

<?php print $content ?>
