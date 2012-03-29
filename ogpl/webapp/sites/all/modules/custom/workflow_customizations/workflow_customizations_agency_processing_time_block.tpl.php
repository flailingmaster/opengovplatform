<?php
$matrix = array();
unset($state_order['Published']);

//Populate agencies with correct workflow order and default values
foreach ($report as $key => $val) {
  if(!empty($val['Agency']) && !isset($matrix[$val['Agency']])){
    $matrix[$val['Agency']] = array('agency' => $val['Agency']) + $state_order;
  }
}

//Populate agencies with actual count
foreach ($report as $key => $val) {
  if(!empty($val['Agency'])){
    $matrix[$val['Agency']][$val['Source']] = $val['Processing Time'];
  }
}

if (!empty($matrix)) {
  echo '<div class="workflow-summary-table">' . theme_table(array('agency' => 'Agency') + array_keys($state_order), $matrix) . '</div>';
}
else {
  echo t('Processing time could not be generated. The system expects content within the workflow to generate the report.');
}
