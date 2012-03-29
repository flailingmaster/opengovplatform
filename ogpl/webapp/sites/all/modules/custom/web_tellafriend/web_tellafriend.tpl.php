<?php

/**
 * This template should only contain the contents of the body
 * of the email, what would be inside of the body tags, and not
 * the header.  You should use tables for layout since Microsoft
 * actually regressed Outlook 2007 to not supporting CSS layout.
 * All styles should be inline.
 *
 * For more information, consult this page:
 * http://www.anandgraves.com/html-email-guide#effective_layout
 *
 * If you are upgrading from an old version of Forward, be sure
 * to visit the Forward settings page to enable use of the new
 * template system.
 */
?>
<html>
  <body>
    <table width="100%" cellspacing="0" cellpadding="10" border="0">
      <thead>
        <tr>
          <td>
            
          </td>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td style="font-family:Arial,Helvetica,sans-serif; font-size:12px;">
            <?php print $forward_message; ?><a href="<?php echo $base_url ?>"><?php echo $site_name ?></a>.<br/><br/>
            <?php if ($message) { ?>
            <?php print t('Your friend\'s Comments : '); ?><br/><?php print $message; ?>
            <?php } ?>
           
            <?php if ($submitted) { ?><p><em><?php print $submitted; ?></em></p><?php } ?>
			<?php print"<br><br>Regards,<br>".$site_name;?>
           
          </td>
        </tr>
        <?php if ($dynamic_content) { ?><tr>
          <td style="font-family:Arial,Helvetica,sans-serif; font-size:12px;">
            <?php print $dynamic_content; ?>
          </td>
        </tr><?php } ?>
        <?php if ($forward_ad_footer) { ?><tr>
          <td style="font-family:Arial,Helvetica,sans-serif; font-size:12px;">
            <?php print $forward_ad_footer; ?>
          </td>
        </tr><?php } ?>
        <?php if ($forward_footer) { ?><tr>
          <td style="font-family:Arial,Helvetica,sans-serif; font-size:12px;">
            <?php print $forward_footer; ?>
          </td>
        </tr><?php } ?>
      </tbody>
    </table>
  </body>
</html>