<?php

class IP2Location
{
    private $db, $request_data;

    function __construct($request_vars, $db)
    {
        $this->request_data = $request_vars;
        $this->db = $db;
    }

    public function _handle_request()
    {
        $this->_validate_request();
        return $this->_process_request();
    }

    private function _validate_request()
    {
        if (!is_array($this->request_data)) {
            $this->request_data = array($this->request_data);
        }

        foreach ($this->request_data as $id => &$ip_address) {
            $ip_address = explode('.', $ip_address);
            if (!($ip_address[0] <= 255 && is_numeric($ip_address[0]))) unset($this->request_data[$id]);
        }
    }

    private function _process_request()
    {
        $mask_arr = array();
        foreach ($this->request_data as $ip)
            $mask_arr[implode('.', $ip)] = $this->_locate_ip_details($ip[0], $ip[1], $ip[2]);
        return $mask_arr;
    }

    private function _locate_ip_details($ip_table, $ip_mask, $ip_mask2)
    {
        $query = "SELECT c.name AS country, if(cc.name!='',cc.name,'Others') AS city
                    FROM {$this->db}.ip4_{$ip_table} ip
                    LEFT JOIN {$this->db}.cityByCountry cc
                      ON ip.country = cc.country
                     AND ip.city = cc.city
               LEFT JOIN {$this->db}.countries c
                      ON ip.country = c.id
                   WHERE b = '$ip_mask'
                     AND c = '$ip_mask2'";
        $loc = db_fetch_array(db_query($query));
        return $loc ? $loc : array('country' => 'Others', 'city' => 'Others');
    }
}
