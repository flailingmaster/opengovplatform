<?php
$matrix = array();;

//Populate agencies with correct workflow order and default values
foreach ($report as $key => $val) {
  if(!empty($val['Agency']) && !isset($matrix[$val['Agency']])){
    $matrix[$val['Agency']] = array('agency' => $val['Agency']) + $state_order;
  }
}

//Populate agencies with actual count
foreach ($report as $key => $val) {
  if(!empty($val['Agency'])){
    $matrix[$val['Agency']][$val['Workflow State']] = $val['Count'];
  }
}

if (!empty($matrix)) {
  echo '<div class="workflow-summary-table">' . theme_table(array('agency' => 'Agency') + array_keys($state_order), $matrix) . '</div>';
}
else {
  echo t('Processing time could not be generated. The system expects content within the workflow to generate the report.');
}
