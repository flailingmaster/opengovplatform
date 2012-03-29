<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  </head>
  <body>
    <table>
    <?php
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
			case '1': $catalog = 'Raw Dataset Catalogs'; break;
			case '2': $catalog = 'Document Catalogs'; break;
			case '3': $catalog = 'App Catalogs'; break;
			case '4': $catalog = 'Tool Catalogs'; break;
			case '5': $catalog = 'Service Catalogs'; break;
		}
		?>
			<tr><td style="font-weight:bold;">Agency</td><td><?php print $name; ?></td></tr>
			<tr><td style="font-weight:bold;">Catalog Type</td><td><?php print $catalog; ?></td></tr>
			<tr><td></td></tr>
			<?php print $header_row; 
			
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
		?>			
			<tr><td style="font-weight:bold;">Agency</td><td><?php print $name; ?></td></tr>
			<?php 
			if($date!='13') { 
				print '<tr><td style="font-weight:bold;">Month of Publication</td><td>'.$month.'</td></tr>';
				print '<tr><td style="font-weight:bold;">Year of Publication</td><td>'.$year.'</td></tr>';
			}
			else{
				print '<tr><td style="font-weight:bold;">Published in</td><td>Past 12 months</td></tr>';
			}
			?>
			<tr><td style="font-weight:bold;">Catalog Type</td><td><?php print $catalog; ?></td></tr>
			<tr><td></td></tr>
			<?php print $header_row;			
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
		?>
			<tr><td style="font-weight:bold;">Agency</td><td><?php print $name; ?></td></tr>
			<tr><td style="font-weight:bold;">Month of Publication</td><td><?php print $month; ?></td></tr>
			<tr><td style="font-weight:bold;">Year of Publication</td><td><?php print $year; ?></td></tr>
			<tr><td style="font-weight:bold;">Catalog Type</td><td><?php print $catalog; ?></td></tr>
			<tr><td></td></tr>
			<?php print $header_row;	
			
	} else if($view->name == 'month_wise_agency_report') {
		
		$months='';
		$months='<tr><td style="font-weight:bold;">Agency Name</td>';
		$months.='<td style="font-weight:bold;">Sub Agency Name</td>';
		$k=12;
		for($i=2;$i<14;$i++) {
			$date=date('M-Y',mktime(0,0,0,date('m'),1,date('Y'))-$k*3600*24*30);
			 if(date('m')=='3' && $k==1)
			{
			  $yr=date('Y',mktime(0,0,0,date('m'),1,date('Y'))-$k*3600*24*30);
			  $date='Feb-'.$yr;
			}
			$months.='<td style="font-weight:bold;">'.$date.'</td>';
			$k--;
		}
		$months.='<td style="font-weight:bold;">Total in the past 12 months</td></tr>';
		print $months;
 
	} else if($view->name == 'month_wise_report_per_year') {
 
		$year=$view->args[0];
		$months=array(0=>'Agency Name', 1=>'Jan-'.$year,2=>'Feb-'.$year,3=>'Mar-'.$year,4=>'Apr-'.$year,5=>'May-'.$year,6=>'Jun-'.$year,7=>'Jul-'.$year,8=>'Aug-'.$year,9=>'Sep-'.$year,10=>'Oct-'.$year,11=>'Nov-'.$year,12=>'Dec-'.$year);

		$months[13]='Total in '.$year;
		$month='';
		$month='<tr><td style="font-weight:bold;">Agency Name</td>';
		$k=12;
		for($i=1;$i<13;$i++)
			$month.='<td style="font-weight:bold;">'.$months[$i].'</td>';
		$month.='<td style="font-weight:bold;">Total in '.$year.'</td></tr>';
		print $month;
 
	} else {	
		print $header_row; 
	}
	?>
    <tbody>
