require 'rubygems'
require 'test/unit'
#Load WATIR
require "selenium_support"
require 'fileutils'
# Load WIN32OLE library
require 'win32ole' 
require 'Win32API'
gem "selenium-client"
require "selenium/client"


class Usamp_lib 
  
  # Method to delete browser cookies
  # No parameters passed to this method
  
  def Delete_cookies
              
    $cookie_Dir= "C:\\Documents and Settings\\#{ENV['USERNAME']}\\Local Settings\\Temporary Internet Files"
    $flash_cookie_Dir="C:\\Documents and Settings\\#{ENV['USERNAME']}\\Application Data\\Macromedia\\Flash Player\\#SharedObjects"
    $flash_cookie_Dir_sys="C:\\Documents and Settings\\#{ENV['USERNAME']}\\Application Data\\Macromedia\\Flash Player"
    #Delete the cookies
    FileUtils.rm_rf $cookie_Dir
    FileUtils.rm_rf $flash_cookie_Dir
    FileUtils.rm_rf $flash_cookie_Dir_sys
              
  end
  
  #Method to close all the IE windows.
            
  def Close_all_windows

  end
                
  def Close_all_windows_ff
    loop do
      begin
        FireWatir::Firefox.attach(:url, /http(s)?:\/\/(.)*/).close
      rescue FireWatir::Exception::NoMatchingWindowFoundException
        break
      rescue
        next
      end
    end
  end

 
  #Method to write to the html report
  #Parameter passed to the method:
  #test description string
  #Opening the HTML report file to append a table containing the result of various check points during the execution of this script
  #The table contains:
  #1. Heading - explaining the purpose of the script and
  #2. Three columns namely, TEST ID(an identification of each check point),
  #    TEST CASE DESCRIPTION(Description of each check point), TEST RESULT(Result of each check point)
           
  def Test_report(test_description)
    $myfile = File.open($out_fl_path, 'a')
    $myfile.print "<col span=\"2\" /><col />"
    $myfile.print "<tr>"
    $myfile.print "<th colspan=\"3\" align=\"left\">"
    $myfile.print "<font align=\"left\">"+test_description+"</font></th>"
    $myfile.print "</tr><tr><td class=\"td1\"><strong>Test ID</strong></td>"
    $myfile.print "<td class=\"td2\"><strong>Test Case Description</strong></td>"
    $myfile.print "<td class=\"td3\"><strong>Result</strong></td></tr>"
  end
          
  # Method to login to Usampadmin site
  # Parameters passed : email and password
  # Parameters returned : IE instance
          
  def Usampadmin_login(email,passwd)
                
    #capabilities = Selenium::WebDriver::Remote::Capabilities.firefox #(:javascript_enabled => true, :proxy=> Selenium::WebDriver::Proxy.new(:http => "localhost:5865"))
    #ie = Watir::Browser.new(:remote, :url => "http://127.0.0.1:4444/wd/hub", :desired_capabilities => capabilities)
    driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
    ie = Watir::Browser.new driver
    ie.goto('http://p.usampadmin.com')
    if ie.text.include?('Logout')
      ie.goto("http://p.usampadmin.com/login.php?hdMode=logout")
    end
    # Setting login credentials (email/password)

    ie.text_field(:name,"txtEmail").quick_set email
    ie.text_field(:name,"txtPassword").quick_set passwd

    #Click login button
    ie.button(:value, "Login").click
    # Checkpoint to verify that login was successful

    raise("Sorry! System Failed to login to Usampadmin") unless ie.link(:text,'Logout').exists?
    return ie
  end
  
          
  # Method to login to Surveyhead site
  # Parameters passed : email and password
  # Parameters returned : IE instance
          
  def Surveyhead_login(email,passwd)

   # New IE instance creation
    driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
    ff = Watir::Browser.new driver

    ff.goto('http://www.p.surveyhead.com')
    # Setting login credentials (email/password)
    ff.text_field(:name, "txtEmail").set(email)
    ff.text_field(:name, "txtPassword").set(passwd)

    ff.button(:value,"login").click
    sleep 15

    raise("Sorry! System Failed to login to Usampadmin") unless ff.link(:text,'Logout').exists?
    return ff

  end
        
  # Method to login to sm.p.Surveyhead site
  # Parameters passed : email and password
  # Parameters returned : IE instance
          
  def Surveyhead_sm_login(email,passwd)
                
    # New IE instance creation
    driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
    ff = Watir::Browser.new driver

    # Opening Usampadmin site
    ff.goto('http://www.sm.p.surveyhead.com')

    # Setting login credentials (email/password)
    ff.text_field(:name, "txtEmail").quick_set(email)
    ff.text_field(:name, "txtPassword").quick_set(passwd)
    #Click login button
    ff.button(:value, "Login").click
    sleep 15
    #if ff.text.include?('Logout')
	#sleep 110
     #end

                
    # Checkpoint to verify that login was successful
    raise("Sorry! System Failed to login to Usampadmin") unless ff.link(:text,'Logout').exists?
    return ff
  end
              
              
  #Parameters : IE instance
  def Network_site_login(email,passwd,type)
                
    # New Firefox instance creation
    driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
    ff = Watir::Browser.new driver
    
    #capabilities = Selenium::WebDriver::Remote::Capabilities.firefox #(:javascript_enabled => true, :proxy=> Selenium::WebDriver::Proxy.new(:http => "localhost:5865"))
    #driver = Selenium::WebDriver::Remote::Capabilities.firefox(:profile => "Selenium")
    #ff = Watir::Browser.new(:remote, :url => "http://127.0.0.1:4444/wd/hub", :desired_capabilities => capabilities)
#    ff = Selenium::Client::Driver.new \
#      :host => "localhost",
#      :port => 4444,
#      :browser => "*chrome",
#      :timeout_in_second => 60,
#      :url => "https://p.network.u-samp.com/"
#
#    ff.driver.start_new_browser_session(:captureNetworkTraffic => true)
    #firefox.exe -P Selenium
    #ff = custom C:\Program Files\Mozilla Firefox\firefox.exe -P firefox_browser
    #ff.clear_cookies
    # Opening Usampadmin site
    #capabilities = Selenium::WebDriver::Remote::Capabilities.firefox #(:javascript_enabled => true, :proxy=> Selenium::WebDriver::Proxy.new(:http => "localhost:5865"))
    #ff = Watir::Browser.new(:remote, :url => "http://127.0.0.1:4444/wd/hub", :desired_capabilities => capabilities)
    #ff = Watir::Browser.new(:remote, :url => "http://127.0.0.1:4444/wd/hub", :desired_capabilities => capabilities)
    #ff = Watir::Browser.new(:remote, :desired_capabilities => capabilities)
    #ff = Watir::Browser.start("http://127.0.0.1:4444/wd/hub", :firefox, :remote)
    ff.goto('https://p.network.u-samp.com/login.php')
    #ff.clear_cookies
    # Setting login credentials (email/password)
    if (type == 'Client')
      ff.radio(:value, "Client").set
    else
      ff.radio(:value,"Publisher").set
    end
    ff.text_field(:id, "txtEmail").quick_set(email)
    ff.text_field(:id, "txtPassword").quick_set(passwd)
    #Click login button
    ff.link(:id,"btnLogin").click
    # Checkpoint to verify that login was successful
    #ff.frame(:id,"iframebox").link(:text, "Click Menu Item").click ...
    #iframe id="iframebox"
    #ff.text.should include("welcome")
#    if (ff.contains_text('Welcome'))
#      puts "Logged it to Network site"
#    else
#      puts "Sorry! System Failed to login to Network site"
#    end
    return ff
  end
          
  #Delete a file
  def delete(filename)
    Dir["#{File.dirname(filename)}/*"].each do |file|
      next if File.basename(file) == File.basename(filename)
      FileUtils.rm_rf file, :noop => true, :verbose => true
    end
  end

  # Method to attach URL to ie instance
  #Parameters passed : the title of the page
  #Parameters : IE instance
  def Attach_url(title)
    ie=Watir::IE.attach(:title,title)
    return ie
  end
          
  def Perform_Donation
        
    #until $ie.link(:text,'Rewards').exists? do
    #sleep 0.5
    #puts "Waiting for Rewards link to load"
    # end
    $ie.link(:text,'Rewards').click
        
    $ie.button(:name,'donate_out').click
    sleep(5)
    $ie.select_list(:id,'optRewardDonationIncr').set('$0.50')
    sleep(5)
    until $ie.contains_text("DASH Rescue") do
      $ie.link(:text,'Next').click
      sleep 0.5
      #puts "Waiting for the reward to appear"
      sleep(1)
    end
    $html_contents=$ie.html
    $html_array = $html_contents.split(/\n/)
    # puts $html_array
    0.upto($html_array.size-1) { |index|
          
      if($html_array[index] =~ /DASH Rescue/)
        puts 'paaaaaaaaaa'
        $html_array[index] =/DASH Rescue/
        puts $html_array[index-4]
        puts $html_array[index-3]
        puts $html_array[index-2]
        puts '**************************'
        $id_checkbox=$html_array[index-2][118..132]
        puts $id_checkbox
        puts '****************************'
        sleep(1)
        $id_checkbox.to_s()
        $ie.radio(:name,'rdRewardDonationCashout',$id_checkbox).click
        sleep(2)
        break
      else
        next
      end
    }
        
    #Performing a Donation for 'Dash Rescue'
      
    $ie.button(:name,'btnProceedToCashout').click
    sleep(2)
    $ie.button(:name,'btnCashout').click
        
    $sub_test += 1
    $test_case_no = $test.to_s+"."+$sub_test.to_s
    test_description1 = "Test to confirm a donation"
    $myfile.print "<tr><td class=\"td1\">"+$test_case_no+"</td>"
    $myfile.print "<td class=\"td2\">"+test_description1+"</td>"
        
    if($ie.contains_text("You have successfully donated for the following:")&&$ie.contains_text("DASH Rescue"))
      puts "TEST PASSED 1"
      #Write to the html file
      $myfile.print("<td class=\"td3\"><font color=\"green\">TEST PASSED</font></td></tr>");
    else
      puts 'TEST FAILED'
      $myfile.print "<td class=\"td3\"><font color=\"red\">TEST FAILED</font></td></tr>"
    end
  end

  def Perform_Giftcertificate_Cashout
        
    #File path to store cashout date
    $wd=Dir.pwd
    $Cashout_Date_Path_Write=$wd+"/Output Repository/Cashout_Date_Write.txt"
    sleep 10
    #Performing a Gift certificate cashout for Facebook Credits
    # until $ie.link(:text,'Rewards').exists? do
    # sleep 0.5
    #puts "Waiting for Rewards link to load"
    #end
    $ie.link(:text,'Rewards').click
        
    $ie.button(:name,'btnCashOut').click
    sleep(5)
    $ie.select_list(:id,'optRewardDonationIncr').set('$1.00')
    sleep(3)
            
    until $ie.contains_text("Facebook Credits") do
      $ie.link(:text,'Next').click
      sleep 0.5
      #puts "Waiting for the reward to appear"
      sleep(1)
    end
            
    $html_contents=$ie.html
    $html_array = $html_contents.split(/\n/)
         
 
    0.upto($html_array.size-1) { |index|
          
      if($html_array[index] =~ /Facebook Credits/)
          
        $html_array[index] =/Facebook Credits/
        puts '**************************'
        $id_checkbox=$html_array[index-2][118..131]
        puts $id_checkbox
        puts '****************************'
        sleep(1)
        $id_checkbox.to_s()
        $ie.radio(:name,'rdRewardDonationCashout',$id_checkbox).click
            
        sleep(2)
        break
         
      else
        next
      end
    }
    $ie.button(:name,'btnProceedToCashout').click
    $ie.button(:name,'btnCashout').click
        
    $sub_test += 1
    $test_case_no = $test.to_s+"."+$sub_test.to_s
    test_description2 = "Test to confirm a gift certificate cashout"
    $myfile.print "<tr><td class=\"td1\">"+$test_case_no+"</td>"
    $myfile.print "<td class=\"td2\">"+test_description2+"</td>"
        
    if($ie.contains_text("You have successfully cashed out for the following:")&&$ie.contains_text("Facebook Credits"))
      puts "TEST PASSED 2"
      #Write to the html file
      $myfile.print("<td class=\"td3\"><font color=\"green\">TEST PASSED</font></td></tr>");
    else
      puts 'TEST FAILED'
      $myfile.print "<td class=\"td3\"><font color=\"red\">TEST FAILED</font></td></tr>"
    end
        
    $date=Time.now.strftime("%m-%d-%y")
                        
    File.open($Cashout_Date_Path_Write, 'w') do |f1|
      f1.puts  $date
    end
  end
          
  def Perform_Paypal_Cashout(email)
       
    #Performing a paypal cashout of 25$
       
    # $ie=$obj.Surveyhead_login($Surveyhead_Login_Username,$Surveyhead_Login_Password)
    #until $ie.link(:text,'Rewards').exists? do
    #sleep 0.5
    #puts "Waiting for Rewards link to load"
    #end
    sleep 10
    $ie.link(:text,'Rewards').click
    sleep(2)
    $ie.button(:name,'btnCashOut').click
        
    $ie.select_list(:id,'optRewardDonationIncr').set('$25.00')
    sleep(5)
    until $ie.contains_text("PayPal") do
      $ie.link(:text,'Next').click
      sleep 0.5
      #puts "Waiting for the reward to appear"
      sleep(1)
    end
    $html_contents=$ie.html
    $html_array = $html_contents.split(/\n/)
    $flag=0
    $I=0
    0.upto($html_array.size-1) { |index|
      
      if($html_array[index] =~ /PayPal/)
          
        $html_array[index] =/PayPal/
        puts $I
        if($flag==1)
          puts $html_array[index-4]
          puts '**************************'
          $id_checkbox=$html_array[index-4][118..133]
          puts $id_checkbox
          puts '****************************'
          sleep(1)
          $id_checkbox.to_s()
          $ie.radio(:name,'rdRewardDonationCashout',$id_checkbox).click
            
          sleep(2)
          break
        end
        $flag=1
      else
        next
      end
    }
       
    sleep(3)
    # $ie.radio(:name,'rdRewardDonationCashout','Cashout;25.00;6').click
    $ie.button(:name,'btnProceedToCashout').click
    sleep(5)
    $ie.text_field(:name,"txtPaypalId").set($Paypal_Email_id)
    $ie.text_field(:name,"txtConfirmPaypal").set($Paypal_Email_id)
    $ie.checkbox(:name,"chkAgree").click
    $ie.button(:name,'btnCashout').click
        
    # $ie.goto("http://www.p.surveyhead.com/reward_catalog.php?type=reward&incr=25.00&order=9&msgCashout=success")&&$ie.contains_text("PayPal")
    sleep(2)
        
    $sub_test += 1
    $test_case_no = $test.to_s+"."+$sub_test.to_s
    test_description3 = "Test to confirm a paypal cashout"
    $myfile.print "<tr><td class=\"td1\">"+$test_case_no+"</td>"
    $myfile.print "<td class=\"td2\">"+test_description3+"</td>"
        
    if($ie.contains_text("You have successfully cashed out for the following:")&&$ie.contains_text("PayPal"))
      puts "TEST PASSED"
      #Write to the html file
      $myfile.print("<td class=\"td3\"><font color=\"green\">TEST PASSED</font></td></tr>");
    else
      puts 'TEST FAILED'
      $myfile.print "<td class=\"td3\"><font color=\"red\">TEST FAILED</font></td></tr>"
    end
  end
          
  #Method to get the test data from the file
  #parameters passed to the method:text file containing the test data in array format
  #Parameter returned: test data from the text file
  def Extract_data(arr)
    #regular expression ie to be matched with the array elements
    reg=/#(.)*#|^\n$|^\t$|^\s$/
    #Create a new array
    data = Array.new
    j=0
    
    #Access each element of the array
    #each element of array is each line of the txt file which is a string.
    #variable i is array index
    arr.each_index do |i|
      #match the regular expression with each element of the array
      if reg =~ arr[i]
        next
      else
        #Delete the last character of each element of array which is a string.
        line= arr[i].chomp
        #Extract the required data
        value = line.sub(/^([A-Z]|[a-z])+.*\s*::|(\s)*::/, '')
        #eliminate space and tab's from the data
        data[j]= value.strip
        j+= 1
      end
    end 
    
    return data
    
  end

  def getFilepath(purpose)
    #get the filepath to save the screen shots or to upload/download 
    $filepath = Dir.pwd
    #get the file purpose
    value = purpose.strip
    #convert the file purpose to lowercase
    file_purpose = value.downcase 
    
    #the file purpose is matched and the appropriate path is retrieved into variable "path" 
    case file_purpose
      
    when "snapshot": path = $filepath+"/ScreenShots/"
    when /upload|download/: path = $filepath+"/TestFiles/"
    when /test(\s)*data/: path = $filepath+"/automation_txtfiles/"
    else path = $filepath+"/"
      
    end
    path.gsub!('/','\\')
    
    #Return the file path
    return path
    
  end
  
  def window_closer
    
    $ie=FireWatir::Firefox.attach(:url,/http/)
    $i=1
    while($ie)
      
      $ie.close
      #begin
      $ie=FireWatir::Firefox.attach(:url,/http/)
      # rescue
      # break
      # end
      #$closed = "Closed"+$i.to_s
      #puts $closed 
      puts $ie
      # $i +=1
    
    end
  
  
  end

  def member_creation
    $mail_address=$MAIL
    puts $mail_address
    $extension = Time.new
    $extension = $extension.to_s
    $extension = $extension.slice(13..18)
    $mail_address1=$MAIL+$extension
    $mail_address=$MAIL+$extension+"@mailop.com"
    $mail_address = $mail_address.gsub(/:/, "")
    $mail_address1 = $mail_address1.gsub(/:/, "")
        
    #ff = Watir::IE.start($file_data[0])
    ff = FireWatir::Firefox.new
    #Maximizing the window
    ff.maximize
    # Opening p.surveyhead.com site
    ff.goto("http://sm.p.surveyhead.com")
    #$myfile.print "<tr><td class=\"td1\">"+$test_case_no+"</td>"
    #$myfile.print "<td class=\"td2\">"+test_description+"</td>"
    if ff.contains_text('Logout')
      ff.link(:text,'Logout').click
      ff.goto("http://sm.p.surveyhead.com")
    end
    #Opening the registration page
    ff.link(:text, "Free Registration").click
    #Entering the users First Name
    ff.text_field(:name, "txtFname").set($FNAME)
    #Entering the users Last Name
    ff.text_field(:name, "txtLname").set($LNAME)
    #Entering the users Country Name
    ff.select_list(:name, "optCountryId").set($COUNTRY)
    #Entering the users Language
    ff.select_list(:name, "optLanguageId").set($LANGUAGE)
    #Need to wait for the states to get generated
    sleep 5
    #Entering the users state
    ff.select_list(:name, "optStateId").set($STATE)
    sleep 5
    #Entering zip code
    ff.text_field(:name, "txtZipPostal").set($Zip_code)
      
    #Entering the users Date of birth
    ff.select_list(:name, "optMonthId").set($MONTH)
    #Entering the users Month of Birth
    ff.select_list(:name, "optDayId").set($DATE)
    #Entering the users Year of birth
    ff.select_list(:name, "optYearId").set($YEAR)
    #Entering the users gender
    ff.radio(:value, "Male").set
    #Entering the users Email id
    ff.text_field(:name, "txtEmail").set($mail_address)
    #need to wait for a while as same data is being used 2 times
    sleep 5
    #Confirming the users Email id
    ff.text_field(:name, "txtConfirmEmail").set($mail_address)
    #Entering the users password
    ff.text_field(:name, "txtPassword").set($mail_address)
    #Confirming the users password
    ff.text_field(:name, "txtConfirmPassword").set($mail_address)
    #Accepting the terms and conditions
    ff.checkbox(:name, "chbTermsAndConditions").set
    #Clicking on submit
    ff.button(:value, "Submit").click
    sleep 5
    #Entering the users income
    ff.select_list(:name, "optAnnualHouseholdIncomeId").set($INCOME)
    #Entering the users Education status
    ff.select_list(:name, "optEducationLevelId").set($EDUCATION)
    #Entering the users employment status
    ff.select_list(:name, "optEmploymentStatusId").set($EMPLOYMENT)
    #Entering the users industry id
    ff.select_list(:name, "optIndustryId").set($INDUSTRY)
    #Entering the users role
    ff.select_list(:name, "optRoleId").set($ROLE)
    #waiting for the job title to be generated
    sleep 8
    #Entering the users job title
    ff.select_list(:name, "optJobTitleId").set($JOB_TITLE)
    #Entering the users maritial status
    ff.select_list(:name, "optMaritalStatusId").set($MARITIAL_STATUS)
      
    ff.select_list(:name, "optEthnicityId").set($ETHNICITY)
      
    #Entering the users Nationality
    ff.select_list(:name, "optNationalityId").set($COUNTRY_ORIGIN)
    #Setting the radio button to N
    ff.radio(:value, $CHILDREN).set
    #Setting the radio button to I do not have a preference in the maximum number of emails I receive each week.
    #ff.radio(:value, $INVITE).set
    sleep 3
    ff.button(:value, "NEXT").click
    sleep 5
    return ff
  end


  def snapshot(filename, active_window_only=false) 
=begin    
    keybd_event = Win32API.new("user32", "keybd_event", ['I','I','L','L'], 'V') 
    openClipboard = Win32API.new('user32', 'OpenClipboard', ['L'], 'I') 
    setClipboardData = Win32API.new('user32', 'SetClipboardData', ['I', 'I'], 'I') 
    closeClipboard = Win32API.new('user32', 'CloseClipboard', [], 'I') 
    globalAlloc = Win32API.new('kernel32', 'GlobalAlloc', ['I', 'I'], 'I') 
    globalLock = Win32API.new('kernel32', 'GlobalLock', ['I'], 'I') 
    globalUnlock = Win32API.new('kernel32', 'GlobalUnlock', ['I'], 'I') 
    memcpy = Win32API.new('msvcrt', 'memcpy', ['I', 'P', 'I'], 'I') 
    
    wsh = WIN32OLE.new('Wscript.Shell') 
    
    if not active_window_only 
      keybd_event.Call(0x2C,0,0,0)   # Print Screen 
    else 
      keybd_event.Call(0x2C,1,0,0)   # Alt+Print Screen 
    end 
    
    exec = wsh.Exec('mspaint.exe') 
    wsh.AppActivate(exec.ProcessID) 
    sleep(1) 
    # Ctrl + V  : Paste 
    wsh.SendKeys("^v") 
    sleep(1) 
    # Alt F + A : Save As 
    wsh.SendKeys("%fa") 
    # copy filename to clipboard 
    hmem = globalAlloc.Call(0x0002, filename.length+1) 
    mem = globalLock.Call(hmem) 
    memcpy.Call(mem, filename, filename.length+1) 
    globalUnlock.Call(hmem) 
    openClipboard.Call(0) 
    setClipboardData.Call(1, hmem) 
    closeClipboard.Call 
    sleep(1) 
    
    # Ctrl + V  : Paste 
    wsh.SendKeys("^v") 
    
    if filename[/\.gif/i] 
      wsh.SendKeys("{TAB}g") 
    elsif filename[/\.jpg/i] 
      wsh.SendKeys("{TAB}j") 
    else 
      wsh.SendKeys("{TAB}j") 
    end 
    wsh.SendKeys("~")  # enter 
    sleep(1) 
    
    #wsh.SendKeys("yy") 
    sleep(4) 
    exec.Terminate 
=end    
  end 
  
end