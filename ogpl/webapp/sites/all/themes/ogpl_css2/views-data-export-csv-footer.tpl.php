<?php

/**
 * CSV files don't really have a footer.
 */

$view = views_get_current_view();

if($view->name == 'agency_wise_report') {
	$footer='';
	$footer.='Total,,,,'; 
	
	$cat=array('catalog_type_raw_data','catalog_type_document','catalog_type_data_apps','catalog_type_data_tools','catalog_type_data_service');
	for($i=0;$i<5;$i++) {
		$footer.='';
		$result=db_query("SELECT count(distinct ds.nid) as cnt FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE ds.field_ds_catlog_type_type ='$cat[$i]' AND WF.sid=10");
		$val=db_query("SELECT count(distinct ds.nid) as cnt  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid  where ( ds.field_ds_catlog_type_type ='$cat[$i]')  AND ppog.field_ppog_high_value_dataset_value='Yes' AND WF.sid=10 ");
		if($row=mysql_fetch_object($result))
			$total=$row->cnt;
		if($high=mysql_fetch_object($val))
			$val=$high->cnt;

		if($val!=0)
			$footer.= $total.'('.$val.')';
		else 
		$footer.= $total;

		$footer.= ',';	        
	}
	$footer.='';
	
	$result=db_query("SELECT count(distinct ds.nid) as cnt FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid where ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10");
	$val=db_query("SELECT count(distinct ds.nid) as cnt  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid where ppog.field_ppog_high_value_dataset_value='Yes' AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10");
	
	if($row=mysql_fetch_object($result))
		$total=$row->cnt;
	if($high=mysql_fetch_object($val))
		$val=$high->cnt;

	if($val!=0)
		$footer.= $total.'('.$val.')';
	else 
		$footer.=$total;

	$footer.= ',';
	
	$total=db_query("SELECT max(wf.stamp) as date FROM content_type_dataset ds INNER JOIN workflow_node wf on wf.nid=ds.nid WHERE  ds.field_ds_catlog_type_type IS NOT NULL AND wf.sid=10");
	if($row=mysql_fetch_object($total))
		$date=$row->date;
	$footer.=''.format_date($date,'custom',variable_get('date_format_front_date_format',''),NULL,NULL).',';
	
	$footer.=''; 
	print $footer;
} else if($view->name == 'month_wise_agency_report') {
	
	print 'Total Datasets published per month, ,';
	for($i=12;$i>0;$i--) {
		$starttime = mktime(0, 0, 0, date('m'), 1, date('Y')) -$i*30*3600*24;    
		$endtime = mktime(0, 0, 0, date('m'), 1, date('Y'))-($i-1)*30*3600*24; 
		
		$result=db_query("SELECT count(*) as  cnt FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime");
		if($row=mysql_fetch_object($result))
			$total=$row->cnt;
		if($total==0)
			print '-';
		else
			print $total;
		print ',';
	}
	$starttime = mktime(0, 0, 0, date('m'), 1, date('Y')) -12*30*3600*24;    
	$endtime = mktime(0, 0, 0, date('m'), 1, date('Y')); 
	
	$result=db_query("SELECT count(*) as  cnt FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime");
	if($row=mysql_fetch_object($result))
		$total = $row->cnt;
	$totalvalue = ($total == 0)? '-':$total; 
	print $totalvalue;
} else if($view->name == 'month_wise_report_per_year') {

	$cur_year=$view->args[0];
    print 'Total Datasets published per month,';
 	$days=array(1=>31,28,31,30,31,30,31,31,30,31,30,31);
	for($i=1;$i<13;$i++)
	{
		$starttime = mktime(0, 0, 0, $i, 1, $cur_year);    
		$endtime = $starttime+ $days[$i]*24*3600;

		$result=db_query("SELECT count(*) as  cnt FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime");
		if($row=mysql_fetch_object($result))
			$total=$row->cnt;
		$totalvalue = ($total == 0) ? '-':$total; 
		print $totalvalue;
		print ',';
	}
	$starttime = mktime(0, 0, 0, 1, 1, $cur_year);    
	$endtime =mktime(0, 0, 0, 1, 1, $cur_year+1);

	$result=db_query("SELECT count(*) as  cnt FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime");

	if($row=mysql_fetch_object($result))
		$total=$row->cnt;
	$totalvalue = ($total == 0)? '-':$total; 
	print $totalvalue;
	print ',';
}
