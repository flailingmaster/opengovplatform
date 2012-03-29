<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">
	<?php print $picture ?>
	<div class="content">
	<div class="feedback"><div class="fieldgroup">
		<div class="field">
			<div class="field-label">Submitted On: </div>
			<div class="field-items"><div class="field-item"><?php print format_date($node->created, 'small'); ?></div></div>
		</div>
		
		
		<div class="field">
			<div class="field-label">Sender Name: </div> 
			<?php if($node->field_sender_name[0]['safe']) : ?>
				<div class="field-items"><div class="field-item"><?php print $node->field_sender_name[0]['safe']; ?></div></div>
			<?php else :?>
				<div class="field-items"><div class="field-item">Anonymous</div></div>
			<?php endif;?>	
		</div>
		
		
		<?php if($node->field_email[0]['safe']) : ?>
			<div class="field">
				<div class="field-label">Sender Email: </div>
				<div class="field-items"><div class="field-item"><?php print $node->field_email[0]['safe']; ?></div></div>
			</div>
		<?php endif;?>
		
		<?php if($node->field_feedback_body[0]['view']) : ?>
			<div class="field">
				<div class="field-label">Suggestion: </div>
				<div class="field-items"><div class="field-item"><?php print nl2br($node->field_feedback_body[0]['view']); ?></div></div>
			</div>
		<?php endif;?>
	</div></div>
		<?php if($node->content['fivestar_widget']['#value']) : ?>
			<div class="feedback-fivestar">
				<?php print $node->content['fivestar_widget']['#value']; ?>
			</div>
		<?php endif;?>
		
		<?php 
			$delay_time_seconds = variable_get('votingapi_anonymous_window', 86400);
			if($delay_time_seconds > 0 ){ 
		?>
				<div class="fivestar-note"> 
					<?php $map = drupal_map_assoc(array(300, 900, 1800, 3600, 10800, 21600, 32400, 43200, 86400, 172800, 345600, 604800), 'format_interval');
						print "Note: There must be a minimum interval of " . $map[$delay_time_seconds] . " between two consecutive rating events.";
					?>
				</div>
		<?php
			} else if ($delay_time_seconds == -1) { ?>
				<div class="fivestar-note"> 
					<?php 
						print "Note: You are allowed to rate this content only once.";
					?>
				</div>
			
		<?php }?>
    </div>
</div>