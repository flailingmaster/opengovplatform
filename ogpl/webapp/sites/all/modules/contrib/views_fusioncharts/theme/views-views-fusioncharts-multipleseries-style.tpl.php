<?php
/*
   Copyright 2009-2011 United States Government. 

   This software is licensed under the GNU General Public License
   version 2 (see the file LICENSE for details)
*/
?>

<div id="view-fusioncharts-<?php echo $chartID; ?>"></div>
<script type="text/javascript">
<!--//--><![CDATA[//><!--
var vwFC = new FusionCharts('<?php echo $swf_path; ?>', '<?php echo $chartID; ?>', <?php echo $width; ?>, <?php echo $height; ?>, 0, 1);
vwFC.setTransparent('false');
vwFC.setDataXML('<?php echo $config; ?>');
vwFC.render('view-fusioncharts-<?php echo $chartID; ?>');
//--><!]]>
</script>
