<?php
$base_url = base_path();
?>
<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">
    <?php print $picture ?>
    <div class="content open-data-sites">
    <?php //print $content ?>
    <?php if (!empty($node->field_union_government_name[0]['value'])){ ?>
        <div class="open-data-sites-name"><?php echo $node->field_union_government_name[0]['value']; ?></div>
    <?php } ?>
    <div class="open-data-site-content">
        <?php if (!empty($node->field_open_data_site_flag[0]['filepath'])){ ?>
        <div class="country-image fLeft">
            <img src="<?php echo $base_url.$node->field_open_data_site_flag[0]['filepath']; ?>" alt="<?php echo $node->title; ?>" title="<?php echo $node->title; ?>" width="289" height="145" />
        </div>
        <?php } ?>
        <div class="country-links fLeft">
            <div class="portal-link link"><a title="<?php echo $node->field_country_portal_link[0]['title']; ?>" href="<?php echo $node->field_country_portal_link[0]['url']; ?>"><?php echo $node->field_country_portal_link[0]['url']; ?></a></div>
            <div class="dataset-link link"><a title="<?php echo $node->field_country_data_site_link[0]['title']; ?>" href="<?php echo $node->field_country_data_site_link[0]['url']; ?>"><?php echo $node->field_country_data_site_link[0]['url']; ?></a></div>
            <?php if (!empty($node->field_country_datasets[0]['value'])){ ?>
            <div class="datasets link">No of Dataset count: <?php echo $node->field_country_datasets[0]['value']; ?></div>
            <?php } ?>
        </div>
        <div class="cBoth"></div>
    </div>
    </div>
</div>