<?php
// $Id: page.tpl.php,v 1.1.2.1 2009/02/24 15:34:45 dvessel Exp $
?>
<?php
    /**
     * Put community specific information into variables
     */
    $logotitle = '';
    $commpath = '';
    $commcss = '';
    $group_node = og_get_group_context();
    if ($group_node) {
        $logotitle = $group_node->title;
        $commpath = strtolower(str_replace(' ', '', $logotitle));
        $commcss = base_path() . path_to_theme() . '/styles/' . $commpath . '.css';
    }
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
  <!--[if IE 6]>
	<link type="text/css" rel="stylesheet" media="all" href="<?php print '/'.path_to_theme().'/styles/ie6.css' ?>">
  <![endif]-->
  <?php print $scripts; ?>
</head>
<body class="<?php print $body_classes; ?> show-grid">
	<!-- for 508 compliance -->
	<h1 class="element-invisible element-focusable">OGPL Communities</h1>
	<a href="#nav" class="element-invisible element-focusable" title="Skip to navigation">Skip to navigation</a>
	<a href="#maincontent" class="element-invisible element-focusable" title="Skip to main content">Skip to main content</a>
	<?php /*
	<a href="#search" class="element-invisible element-focusable" title="Skip to search">Skip to search</a>
	*/ ?>
	<a href="#login" class="element-invisible element-focusable" title="Skip to login">Skip to login</a>
	<div id="content-container" class="container-12 clear-block"><!--for white background-->
	<!-- logo and site search -->
	<div class="container-12 pad-top-5">
		<div class="grid-12 logo-container">
			<div class="grid-6 alpha logo-left">
					<span id="logo"><a href="<?php print base_path(); ?>"><img src="<?php print '/'.path_to_theme().'/images/logo.gif' ?>" title="Go to OGPL Communities Home" alt="OGPL Communities" /></a></span>
			</div><!--logo, grid-6-->
			<!-- admin links, login/register links, and user info -->
					<?php if ($adminlinks):?>
						<div class="admin-links grid-3">
							<?php print($adminlinks); ?>
						</div>
					<?php endif; ?>
					<?php if ($userlogin && $adminlinks): ?>
						<div id="login-block" class="grid-3 omega">
							<?php print ($userlogin) ?>
						</div>
					<?php elseif ($userlogin): ?>
						<div id="login-block"class="grid-3 omega push-3">
							<?php print ($userlogin) ?>
						</div>
					<?php endif;?>
		</div><!--end grid-12"-->
	<div class="clear"></div>
	</div><!--end container-12 (logo container)-->
	<!--Primary Links Menu -->
	<div class="container-12">
		<div class="grid-12 nav-container">
			<span style="position:absolute;"><a name="nav">&nbsp;</a></span><!--508 nav target-->
	<?php
		if (in_array('nice_menus', module_list())) {
			print theme_nice_menus_primary_links($primary_links);
		}
		else {
			print theme('links', $primary_links);
		}
	?>
		</div><!-- end nav grid 12-->
	</div><!--end nav container 12-->
	<!--Title & Title Image-->
	<div id="container-12">
		<div class="title-container grid-12 display-inline">
			<!--add community image region-->
			<?php if ($title): ?>
					<?php if ($community_image): ?>
						<div class="grid-1 alpha">
							<div class="community-image">
								<?php print $community_image; ?>
							</div>
						</div>
					<?php endif?>
				<div class="page-title <?php if (empty($community_image)): print ' grid-8 omega'; else: print ' grid-7 omega'; endif; ?>">
					<div class="title-inner">
						<h1 class="white uppercase normal display-inline" id="page-title"><?php print $title; ?></h1>
					</div>
				</div>
      		<?php endif; ?>
			<?php /* if ($search_box): ?>
				<div class="search-container grid-4 alpha omega<?php if (empty($title)): print' push-8 alpha'; endif;?>">
					<div id= "search-wrapper">
						<?php print $search_box; ?>
					</div><!--end search-wrapper, grid-4-->
				</div><!--end grid-6 omega-->
			<?php endif; */ ?>
		</div><!--end grid-12-->
		<div class="clear"></div>
		</div><!--end container-12 (nav)-->
	<div class="container-12">
		<div class="container-12">
			<div id="breadcrumb-wrapper"class="grid-12">
				<?php if ($breadcrumb): ?>
					<div id="breadcrumb" class="grid-8 omega">
						<?php print $breadcrumb ?>
					</div><!--breadcrumb-->
				<?php endif;?>
			</div><!--breadcrumb-wrapper-->
		</div><!--grid-12-->
		<?print ($tabs)?>
		<!-- main content-->
	<span style="position:absolute;"><a name="maincontent">&nbsp;</a></span>
	<div id= "main-container" class="container-12 clear-block">
		<div id="main" class="column <?php print ns('grid-12', $left, 2, $right, 3) . ' ' . ns('push-2', !$left, 3); ?>">
		<?php print $messages; ?>
		<?php print $help; ?>
        <?php print $content; ?>
      	</div>
      	<?php print $feed_icons; ?>
    </div>
  <?php if ($left): ?>
    <div id="sidebar-left" class="column sidebar region grid-2 <?php print ns('pull-10', $right, 3); ?>">
      <?php print $left; ?>
    </div>
  <?php endif; ?>
  <?php if ($right): ?>
    <div id="sidebar-right" class="column sidebar region grid-3">
      <?php print $right; ?>
    </div>
  <?php endif; ?>
  <div id="footer-container" class="prefix-2 suffix-2">
    <?php if ($footer): ?>
      <div id="footer-region" class="region grid-8 clear-block">
        <?php print $footer; ?>
      </div>
    <?php endif; ?>
    <?php if ($footer_message): ?>
      <div id="footer-message" class="grid-8 align-center">
        <?php print $footer_message; ?>
      </div>
    <?php endif; ?>
  </div><!--footer container-->
		</div><!--main-->
	</div><!--main-container container-12-->
	<div class="bottom-links container-12">
        <?php if ($secondary_links): ?>
                      <div class="bottom-links-inner grid-8 prefix-2 suffix-2 align-center valign-middle">
                          <?php print $secondary_links; ?>
              		</div>
                      <?php endif; ?>
	</div>
     <?php print $closure; ?>
</body>
</html>