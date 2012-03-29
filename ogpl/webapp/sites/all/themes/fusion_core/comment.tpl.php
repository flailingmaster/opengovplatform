<?php
$notes_url = request_uri();

if ($node->type == "feedback" && (strpos($notes_url, '/print/') == FALSE)) {
    $date_to_format = strstr($submitted, ',');
    $date1 = str_replace(",", "", $date_to_format);
    $date = str_replace(".", "", $date1);

    $user1 = str_replace("Submitted by", "", $submitted);
    $arr = explode(" ", $user1);
    $arr1 = explode(">", $arr[5]);
    ?>
<tr class="odd">
    <th><?php print $content ?></th>
    <th><?php echo $arr1[1]; ?></th>
    <th><?php print $date ?></th>
</tr>
<?php } else { ?>
<div class="comment <?php print $comment_classes;?> clear-block">
    <?php print $picture ?>

    <?php if ($comment->new): ?>
    <a id="new"></a>
    <span class="new"><?php print $new ?></span>
    <?php endif; ?>

    <h3 class="title"><?php //print $title ?></h3>

    <div class="submitted">
        <?php print $submitted ?>
    </div>

    <div class="content">
        <?php print $content ?>

        <?php if ($signature): ?>
        <div class="signature">
            <?php print $signature ?>
        </div>
        <?php endif; ?>
    </div>

    <?php if ($links): ?>
    <div class="links">
        <?php print $links ?>
    </div>
    <?php endif; ?>

</div><!-- /comment -->
<?php } ?>
