<?php
$q=$_GET["q"];
require_onnce('fusioncharts.module');

function fusioncharts_example2($q) {
  $info->data = array(
                  array('Potentially Actionable', 35),
                  array('actionable', 26),
                  array('Already Published', 16),
     		  array('Not actionable(unclear)', 7),
                  array('Not actionable(regular)', 2),
                  array('Not actionable(other)', 4),
                   array('Not actionable(Not Request for Executive Branch)', 5),
                   array('Not actionable(Not Requests for Machine Readable)', 4),
                    array('Alreeady Published', 16),



	          );
if($q==1)
  $info->chart_type = 'Pie 3D';
if($q==2)
  $info->chart_type = 'Column 3D';
  $info->settings = array('Caption' => 'Agency Determinations Of Site Suggestion');
  $info->attributes = array('color' => array('DC143C','FF00FF','000080','00FF00','FFD700'), //no # in front of color
                             'showName' => array('Potentially Actionable' => 'Potentially Actionable','actionable'=>'actionable','Already Published'=>'Already Published','Not actionable(unclear)'=>'Not actionable(unclear)','Not actionable(regular)'=>'Not actionable(regular)','Not actionable(other)'=>'Not actionable(other)','Not actionable(Not Request for Executive Branch)'=>'Not actionable(Not Request for Executive Branch)','Not actionable(Not Requests for Machine Readable)'=>'Not actionable(Not Requests for Machine Readable)','Alreeady Published'=>'Alreeady Published')); 
  $info->width = 1000;
  $info->height =700;
  return theme('fusionchart', $info);
}
echo fusioncharts_example2($q);
?>