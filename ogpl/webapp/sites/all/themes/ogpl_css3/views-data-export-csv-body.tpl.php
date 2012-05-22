<?php
$view = views_get_current_view();
// Print out exported items.
if($view->name == 'agency_wise_report') {	
	foreach ($themed_rows as $count => $item_row):
		$row=implode($separator, $item_row) . "\r\n";
		if(!strlen(strstr($row,"1970"))>0)
			print implode($separator, $item_row) . "\r\n";
	endforeach;	
} else if($view->name == 'most_rated_datasets') {	
	
	for($i=0;$i<count($themed_rows);$i++) {
		for($j=$i+1;$j<count($themed_rows);$j++) {
			if($themed_rows[$i][phpcode_1]<$themed_rows[$j][phpcode_1]) {   
				$tmp=$themed_rows[$i];
				$themed_rows[$i]=$themed_rows[$j];
				$themed_rows[$j]=$tmp;
			}
		}
	}

	for($i=0;$i<count($themed_rows);$i++) {
		$themed_rows[$i][rownumber]=$i+1;
	}
	$themed_rows=array_slice($themed_rows,0,10);
	
	foreach ($themed_rows as $count => $item_row):
	  print implode($separator, $item_row) . "\r\n";
	endforeach;
	
} else if($view->name == 'month_wise_agency_report')
{
   foreach ($themed_rows as $count => $item_row):
   if(!strlen(strstr($item_row['phpcode_12'],"--")))
	  print implode($separator, $item_row) . "\r\n";
	endforeach;
}else {

	foreach ($themed_rows as $count => $item_row):
	  print implode($separator, $item_row) . "\r\n";
	endforeach;
}
