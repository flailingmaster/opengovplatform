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
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
<head>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <?php print $styles; ?>
    <!--[if IE 6]>
    	<link type="text/css" rel="stylesheet" media="all" href="<?php print base_path() . path_to_theme(); ?>/styles/ie6.css" />
      <![endif]-->
        <!--[if IE 7]>
      	<link type="text/css" rel="stylesheet" media="all" href="<?php print base_path() . path_to_theme(); ?>/styles/ie7.css" />
        <![endif]-->
  <?php if (($commcss) && file_exists($_SERVER['DOCUMENT_ROOT'] . $commcss)): ?>
    <link type="text/css" rel="stylesheet" media="all" href="<?php print $commcss; ?>">    
  <?php endif; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $body_classes; ?> show-grid">
	<!-- for 508 compliance -->
	<h1 class="element-invisible element-focusable">OGPL Communities</h1>
	<a href="#nav" class="element-invisible element-focusable" title="Skip to navigation">Skip to navigation</a>
	<a href="#maincontent" class="element-invisible element-focusable" title="Skip to main content">Skip to main content</a>
	<a href="#search" class="element-invisible element-focusable" title="Skip to search">Skip to search</a>
	<a href="#login" class="element-invisible element-focusable" title="Skip to login">Skip to login</a>
	<!-- logo-->
	<div class="container-12 logo-container">
		<div class="grid-5 alpha logo-left">
            <span id="logo"><a href="<?php print base_path(); ?>"><img src="<?php print base_path() . path_to_theme(); ?>/images/logo.png" title="OGPL Communities" alt="OGPL Communities" /></a></span>
		</div><!--logo, grid-6-->
		<!-- admin links, login/register links, and user info -->
				<?php if ($userlogin): ?>
					<div id="login-block"class="grid-3 omega">
						<?php print ($userlogin) ?>
					</div>
				<?php endif;?>

        	<?php if ($search_box): ?>
                <div class="search-bg grid-4 alpha omega">
        	    <?php print $search_box;?>
                </div>
        	<?php endif;?>

	</div><!--end container-12"-->
	<div id="content-container" class="container-12 clear-block"><!--for white background-->
	<div class="clearblock"></div>
		<div class="header header-main grid-12">
			<span style="position:absolute;"><a name="nav">&nbsp;</a></span>
			<div class="grid-12 alpha omega">
				<?php if (in_array('og', module_list())) : ?>
					<div class="community-nav community-nav-page clear-block">
						<ul class="clear-block grid-12"><?php
							$ctools_tab = ctools_menu_local_tasks();
							if(empty($ctools_tab)) {
 								$query_url_arr = split("/", $_REQUEST['q']);
								$gid=$_GET["gids"];
								$gids=$gid[0];
								$type='';
								if($query_url_arr[2]=='forum')
									$type='forums';
								else if($query_url_arr[2]=='blog')
									$type='blogs';
								else if($query_url_arr[2]=='other-datasites')
									$type='other_datasites';
								else if($query_url_arr[2]=='data_tools')
								{
									$gids=$query_url_arr[1];
									$type='data_tools';
								}

								if($type!='')
									$pathgroup = "node/".$gids."/".$type;
								else
									$pathgroup ="node/".$gids;

   								$ctools_tab = custom_ctools_menu_local_tasks(0,FALSE,$pathgroup);
 							}
							print $ctools_tab;

						?></ul>
					</div>
				<?php else: ?>
					<?print ($tabs)?>
				<?php endif;?>
			</div><!--end grid-12"-->
		</div><!--showcase-->
		<div class="clear"></div>
	<div class="container-12">

        <?php if ($tabs2): ?>
        		<div id="secondary-tabs-wrapper"class="grid-12">
        			<div id="secondary-tabs" class="grid-12 alpha omega">
        				<ul id="secondary-tabs-ul"><?php print $tabs2; ?></ul>
        			</div><!--secondary tabs-->
        		</div><!--secondary-tabs-wrapper-->
        <?php endif; ?>

        <?php if ($breadcrumb): ?>
		<div id="breadcrumb-wrapper"class="grid-12">
			<div id="breadcrumb" class="grid-8 omega">
				<?php print $breadcrumb; ?>
			</div><!--breadcrumb-->
		</div><!--breadcrumb-wrapper-->
		<?php endif; ?>
		<!-- main content-->
	<span style="position:absolute;"><a name="maincontent">&nbsp;</a></span>
	<div id= "main-container" class="container-12 clear-block">
		<div id="main" class="column <?php print ns('grid-12', $left, 2, $right, 3) . ' ' . ns('push-2', !$left, 3); ?>">
		<?php if ($title && $title!=$logotitle): ?>
			<h1 class="community-title"><?php print $title;?></h1>
		<?php  endif;?>
		<?php print $messages; ?>
		<?php print $help; ?>
        <?php print $content; ?>
      	</div>
      	<?php print $feed_icons; ?>
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
  </div>
  <div id="footer-container" class="container-12 clear-block">
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
<div id="tb_external" style="display: none" align="center">
	<h2>You are exiting the OGPL Communities website.</h2>
	<div class="graybox">
<p>
Please click on the link below to continue.<br />
You will automatically forwarded in <span id="tb_timer"></span> second(s).
</p>
<p id="tb_external_thelink"></p>
	</div>
</div>
</body>
</html>