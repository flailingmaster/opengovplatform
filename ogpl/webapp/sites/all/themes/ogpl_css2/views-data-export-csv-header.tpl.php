<?php

// Print out header row, if option was selected.

$view = views_get_current_view();

if($view->name == 'agency_datasets' || $view->name == 'datasets_by_agency_per_month' || $view->name == 'datasets_per_month_and_year') {
	$agency = $view->args[0];
	$node = node_load($agency);
	$name = $node->title;
	$data = array('Agency', $name);
}


if($view->name == 'agency_datasets') {

	$catalog_type = $view->args[2];	
	
	switch($catalog_type) {
		case '1': $catalog = array('Catalog Type', 'Raw Dataset Catalogs'); break;
		case '2': $catalog = array('Catalog Type', 'Document Catalogs'); break;
		case '3': $catalog = array('Catalog Type', 'App Catalogs'); break;
		case '4': $catalog = array('Catalog Type', 'Tool Catalogs'); break;
		case '5': $catalog = array('Catalog Type', 'Service Catalogs'); break;
	}
	
	if ($options['header']) {
		print implode($separator, $data) . "\r\n";
		if($catalog)
			print implode($separator , $catalog)."\r\n\n";
		print implode($separator, $header) . "\r\n";
	}
} else if($view->name == 'datasets_by_agency_per_month') {

	$date = $view->args[1];

	$month=''; $year='';

	if($date!='13') {
		$month = date('F', mktime(0, 0, 0, date('m'), 1, date('Y')) - ($view->args[1])*30*3600*24); ;
		$year = date('Y', mktime(0, 0, 0, date('m'), 1, date('Y')) - ($view->args[1])*30*3600*24);
	} else if($date=='13') 
		$year = date('Y', mktime(0, 0, 0, date('m'), 1, $view->args[2]));
	
	if($month)
		$month_data = array('Month of Publication',$month);
	$year_data = array('Year of publication',$year);

	$default = 1;	
	switch($view->args[3]) {
		case 1: $arg0 = $view->args[0];
				$arg1 = $view->args[1];
				$arg2 = $view->args[2];
				if($arg1<13){
					$start=mktime(0,0,0,date('m'),1,date('Y'))-$arg1*30*24*3600;
					$end=mktime(0,0,0,date('m'),1,date('Y'))-($arg1-1)*30*24*3600;
				}
				else
				{
					$start=mktime(0,0,0,date('m'),1,date('Y'))-12*30*24*3600;
					$end=mktime(0,0,0,date('m'),1,date('Y'));
				}
				if(!strlen(strstr($view->args[2], "main_"))>0 )
					$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type='catalog_type_raw_data' AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_name_value='$arg2' AND wf.stamp between $start AND $end"));
				else
					$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type='catalog_type_raw_data' AND field_ds_agency_name_nid=$arg0 AND wf.stamp between $start AND $end "));

				if($raw && $default!=0 ) { $catalog="Raw Dataset Catalogs"; $default=0; }

				if(!strlen(strstr($view->args[2], "main_"))>0 )
					$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type='catalog_type_document' AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_name_value='$arg2' AND wf.stamp between $start AND $end"));
				else
					$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type='catalog_type_document' AND field_ds_agency_name_nid=$arg0 AND wf.stamp between $start AND $end "));

				if($doc && $default!=0) { $catalog="Document Catalogs"; $default=0; }

				if(!strlen(strstr($view->args[2], "main_"))>0 )
					$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type IN('catalog_type_data_apps') AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_name_value='$arg2' AND wf.stamp between $start AND $end"));
				else
					$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type IN('catalog_type_data_apps' ) AND field_ds_agency_name_nid=$arg0 AND wf.stamp between $start AND $end "));

				if($apps && $default!=0) { $catalog="App Catalogs"; $default=0;}

				if(!strlen(strstr($view->args[2], "main_"))>0 )
					$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type IN('catalog_type_data_tools') AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_name_value='$arg2' AND wf.stamp between $start AND $end"));
				else
					$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type IN('catalog_type_data_tools' ) AND field_ds_agency_name_nid=$arg0 AND wf.stamp between $start AND $end "));

				if($tool && $default!=0) { $catalog="Tool Catalogs"; $default=0; }

				if(!strlen(strstr($view->args[2], "main_"))>0 )
					$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type IN('catalog_type_data_service') AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_name_value='$arg2' AND wf.stamp between $start AND $end"));
				else
					$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type IN('catalog_type_data_service' ) AND field_ds_agency_name_nid=$arg0 AND wf.stamp between $start AND $end "));

				if($ser && $default!=0)
					$catalog = "Service Catalogs";
				break;
		case 2: $catalog = "Document Catalogs"; break;
		case 3: $catalog = "App Catalogs"; break;
		case 4: $catalog = "Tool Catalogs"; break;
		case 5: $catalog = "Service Catalogs"; break;		
	}
	$catalog_type = array('Catalog Type',$catalog);	
	if ($options['header']) {
		print implode($separator, $data) . "\r\n";
		if($date != 13) { 
			print implode($separator,$month_data). "\r\n";
			print implode($separator,$year_data). "\r\n";
		} else  {
			$past = array('Published in','Past 12 months');
			print implode($separator,$past). "\r\n";
		}
		print implode($separator, $catalog_type)."\r\n\n";
		print implode($separator, $header) . "\r\n";
	} 
} else if($view->name == 'datasets_per_month_and_year') {
	
	$date = $view->args[1];
	$yr = $view->args[2];
	$month = '';
	$year = '';

	if($date!='13') {
		$month=date('F', mktime(0, 0, 0, $date, 1, $yr)) ;
		$year=date('Y', mktime(0, 0, 0, $date, 1, $yr));
	} else if($date=='13') {
		$year=date('Y', mktime(0, 0, 0, 2, 1, $yr));
	}
	if($month) { $month_data=array('Month of Publication',$month); }
	
	$year_data=array('Year of publication',$year);

	$default=1;
	switch($view->args[4]) {
		case 1: $arg0 = $view->args[0];
				$arg1 = $view->args[1];
				$arg2 = $view->args[2];
				$arg3 = $view->args[3];
				$arg4 = $view->args[4];
				if($arg1<13){
					$start=mktime(0,0,0,$arg1,1,$arg2);
					$end=mktime(0,0,0,$arg1+1,1,$arg2);
				}
				else
				{
					$start= mktime(0, 0, 0, 1, 1, $view->args[2]) ;
					$end= mktime(23, 59, 59, 12, 31, $view->args[2]);
				}
				if(!strlen(strstr($view->args[3], "main_"))>0 )
					$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type='catalog_type_raw_data' AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_name_value='$arg3' AND wf.stamp between $start AND $end"));
				else
					$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type='catalog_type_raw_data' AND field_ds_agency_name_nid=$arg0 AND wf.stamp between $start AND $end "));

				if($raw && $default!=0) { $catalog="Raw Dataset Catalogs"; $default=0; }

				if(!strlen(strstr($view->args[3], "main_"))>0 )
					$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type='catalog_type_document' AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_name_value='$arg3' AND wf.stamp between $start AND $end"));
				else
					$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type='catalog_type_document' AND field_ds_agency_name_nid=$arg0 AND wf.stamp between $start AND $end "));

				if($doc && $default!=0) { $catalog="Document Catalogs";  $default=0; }

				if(!strlen(strstr($view->args[3], "main_"))>0 )
					$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type IN('catalog_type_data_apps') AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_name_value='$arg3' AND wf.stamp between $start AND $end"));
				else
					$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type IN('catalog_type_data_apps') AND field_ds_agency_name_nid=$arg0 AND wf.stamp between $start AND $end "));
				
				if($apps && $default!=0) { $catalog="App Catalogs"; $default=0; }

				if(!strlen(strstr($view->args[3], "main_"))>0 )
					$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type IN('catalog_type_data_tools' ) AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_name_value='$arg3' AND wf.stamp between $start AND $end"));
				else
					$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type IN('catalog_type_data_tools') AND field_ds_agency_name_nid=$arg0 AND wf.stamp between $start AND $end "));
				
				if($tool && $default!=0) { $catalog="Tool Catalogs"; $default=0; }

				if(!strlen(strstr($view->args[3], "main_"))>0 )
					$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type IN('catalog_type_data_service' ) AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_name_value='$arg3' AND wf.stamp between $start AND $end"));
				else
					$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid where wf.sid=10 and field_ds_catlog_type_type IN('catalog_type_data_service' ) AND field_ds_agency_name_nid=$arg0 AND wf.stamp between $start AND $end "));
				
				if($ser && $default!=0) { $catalog="Service Catalogs"; $default=0; }
				break;		
		case 2: $catalog="Document Catalogs"; break;
		case 3:	$catalog="App Catalogs"; break;
		case 4:	$catalog="Tool Catalogs"; break;
		case 5: $catalog="Service Catalogs"; break;
	}
	$catalog_type = array('Catalog Type',$catalog);

	if ($options['header']) {
		print implode($separator, $data) . "\r\n";
		if($month)
			print implode($separator,$month_data). "\r\n";
		print implode($separator,$year_data). "\r\n";
		print implode($separator,$catalog_type)."\r\n\n";
		print implode($separator, $header) . "\r\n";
	}
} else if($view->name == 'month_wise_agency_report') {	
	
	$months = array();
	$months[0]='Agency Name';
	$months[1]='Sub Agency Name';
	$k=12;
	for($i=2;$i<14;$i++) {
		$date=date('M-Y',mktime(0,0,0,date('m'),1,date('Y'))-$k*3600*24*30);
		$months[$i]=$date;
		$k--;
	}
	$months[14]='Total in the past 12 months';

	if ($options['header']) {
		print implode($separator, $months) . "\r\n";
	}
} else if($view->name == 'month_wise_report_per_year') {

	$year = $view->args[0];
	$months = array(0=>'Agency Name', 1=>'Jan-'.$year,2=>'Feb-'.$year,3=>'Mar-'.$year,4=>'Apr-'.$year,5=>'May-'.$year,6=>'Jun-'.$year,7=>'Jul-'.$year,8=>'Aug-'.$year,9=>'Sep-'.$year,10=>'Oct-'.$year,11=>'Nov-'.$year,12=>'Dec-'.$year);

	$months[13] = 'Total in '.$year;

	if ($options['header']) {
		print implode($separator, $months) . "\r\n";
	}

} else { 
 
	if ($options['header']) {
	  print implode($separator, $header) . "\r\n";
	}
}

