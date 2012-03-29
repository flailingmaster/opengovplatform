<?php

/**
 * @file
 * Default print module template
 *
 * @ingroup print
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $print['language']; ?>" xml:lang="<?php print $print['language']; ?>">
<head>
    <?php print $print['head']; ?>
    <?php print $print['base_href']; ?>
    <title>Feedback Details</title>
    <?php print $print['scripts']; ?>
    <?php print $print['sendtoprinter']; ?>
    <?php print $print['robots_meta']; ?>
    <?php print $print['favicon']; ?>
    <?php print $print['css']; ?>
</head>
<body>
<?php if (!empty($print['message'])) {
    print '<div class="print-message">'. $print['message'] .'</div><p />';
} ?>
<script>
    $(document).ready(function() {
        $(".print-feedback").remove();
        $("#comment-form").remove();
        $(".terms").remove();
        var print_content = "<html><body style='margin:10px; padding:10px;'>";
        var div_content = $("#print-feedback-content").html();
        print_content+=div_content+"</body></html>";
        var printWin = window.open('','_self','toolbar=0,scrollbars=yes,width=auto,height=auto');
        printWin.document.write(print_content);
        printWin.document.close();
        printWin.focus();
        printWin.print();
        printWin.close();
    });
</script>
<div class="print-logo"><?php print $print['logo']; ?></div>
<p />
<hr class="print-hr" />
<!-- div class="print-breadcrumb"><?php print $print['breadcrumb']; ?></div-->
<div id="print-feedback-content">
    <h1 class="print-title">Feedback Details<!--?php print $print['title']; ?--></h1>
    <div class="print-content"><?php print $print['content']; ?></div>
    <div class="print-footer"><?php print $print['footer_message']; ?></div>
    <hr class="print-hr" />
</div>
</body>
</html>
