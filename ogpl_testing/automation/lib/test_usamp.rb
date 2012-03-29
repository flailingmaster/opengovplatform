require "test/unit"
require "rubygems"
gem "selenium-client"
require "selenium/client"



class Usamp_login < Test::Unit::TestCase

  def setup
    @verification_errors = []
    @selenium = Selenium::Client::Driver.new \
      :host => "localhost",
      :port => 4444,
      :browser => "*chrome",
      :url => "https://p.network.u-samp.com/",
      :timeout_in_second => 60

    @selenium.start_new_browser_session
  end
  
  def teardown
    @selenium.close_current_browser_session
    assert_equal [], @verification_errors
  end
  
  def test_usamp_login
    @selenium.open "/login.php?hdMode=logout"
    assert_equal "uSamp", @selenium.get_title
    begin
        assert @selenium.is_text_present("Account Type Publisher Client")
    rescue Test::Unit::AssertionFailedError
        @verification_errors << $!
      end
    @selenium.type "txtEmail","nitin_kumar@persistent.co.in"
    @selenium.type "txtPassword","test"
    assert_equal "nitin_kumar@persistent.co.in", @selenium.get_value("txtEmail")
    assert_equal "test", @selenium.get_value("txtPassword")
    begin
        assert @selenium.is_element_present("//div[@id='content']/div/div[4]")
    rescue Test::Unit::AssertionFailedError
        @verification_errors << $!
    end
    @selenium.click "//input[@id='affiliateLogin' and @name='rdAffiliateType' and @value='Client']"
    @selenium.click "btnLogin"
    @selenium.wait_for_page_to_load "30000"
    @selenium.click "link=Log Out"
    @selenium.wait_for_page_to_load "30000"
    begin
        assert @selenium.is_text_present("You have successfully logged out.")
    rescue Test::Unit::AssertionFailedError
        @verification_errors << $!
    end
  end
end
