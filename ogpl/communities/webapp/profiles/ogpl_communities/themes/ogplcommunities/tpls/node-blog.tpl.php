<?php
// $Id: node.tpl.php,v 1.4.2.1 2009/08/10 10:48:33 goba Exp $

/**
 * @file node.tpl.php
 *
 * Theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: Node body or teaser depending on $teaser flag.
 * - $picture: The authors picture of the node output from
 *   theme_user_picture().
 * - $date: Formatted creation date (use $created to reformat with
 *   format_date()).
 * - $links: Themed links like "Read more", "Add new comment", etc. output
 *   from theme_links().
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $submitted: themed submission information output from
 *   theme_node_submitted().
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $teaser: Flag for the teaser state.
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 */
?>
<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clear-block">
<?php if ($teaser): ?>
<div class="blog-post-container">
<?php else: ?>
<div>
<?php endif; ?>
	<?php $gid=array_keys($node->og_groups); if (!$page): ?>
		<h4><a href="<?php print "/communities/node/".$gid[0]."/blogs/".$node->nid; ?>"><?php print $title ?></a></h4>
	<?php else:?>
		<h2><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
	<?php endif; ?>
	<div class="meta">
		<div class="smaller">
		<?php
		$co_authored_str = '';
		if($node->field_co_author[0]['uid']!= NULL){
			$co_author = user_load($node->field_co_author[0]['uid']);
			$co_authored_str = ' and '.theme('username',$co_author);
		}
		?>
		<?php print 'Posted on '.$date.' by '.$name.' '.$co_authored_str ?>
		</div>
	</div>
	<?php if (!$teaser): ?>
	<!-- AddThis Button BEGIN -->
	<a class="addthis_button exempt" href="http://www.addthis.com/bookmark.php?v=250&pub=xa-4a53a8c7029120ed"><img src="http://s7.addthis.com/static/btn/v2/lg-share-en.gif" width="125" height="16" alt="Bookmark and Share" style="border:0"/></a>
	<script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js?pub=xa-4a53a8c7029120ed"></script>
	<!-- AddThis Button END -->
	<?php endif; ?>
	<div class="pad-top-10 pad-bottom-10">
		<?php print $content ?>
	</div>
	<?php if (!$teaser): ?>
	<!-- AddThis Button BEGIN -->
	<a class="addthis_button exempt" href="http://www.addthis.com/bookmark.php?v=250&pub=xa-4a53a8c7029120ed"><img src="http://s7.addthis.com/static/btn/v2/lg-share-en.gif" width="125" height="16" alt="Bookmark and Share" style="border:0"/></a>
	<script type="text/javascript" src="http://s7.addthis.com/js/250/addthis_widget.js?pub=xa-4a53a8c7029120ed"></script>
	<!-- AddThis Button END -->
	<?php endif; ?>
	<?php if ($teaser) :?>
		<div class="blog-post-comments-container small">
			<div class="grid_4 push_4 alpha">
				<a href="<?php print "/communities/node/".$gid[0]."/blogs/".$node->nid; ?>" class="btn-readmore float-right">Read More</a>
			</div>
			<div class="grid_4 pull_4 omega">
				<div class="comment-bubble-container">
					<?php print l($node->comment_count,"/communities/node/".$gid[0]."/blogs/".$node->nid,array('fragment' => 'comments', 'external' => TRUE));?>
				</div>
				comment(s) |
				<?php if (user_is_logged_in()==true): ?>
					<?php print l("Add Comment","/communities/node/".$gid[0]."/blogs/".$node->nid,array('fragment' => 'commentform', 'external' => TRUE)); ?>
				<?php else: print  l("Login to Comment", "/user",
												array('fragment' => 'commentform', 
													  'external' => TRUE,
													  'query'=>array('destination'=>"node/".$gid[0]."/blogs/".$node->nid))); ?>	
				<?php endif ;?>
				<?php echo $links; ?>
			</div><!--end grid_4-->
			<div class="clear"></div>
		</div><!-- end comment container -->
			<div class="clear"></div>
	<?php endif ?>

 </div> <!--blog post container-->
</div>
