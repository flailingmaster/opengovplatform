require 'rubygems'
#Load WATIR
require 'fileutils'
require 'lib/selenium_support'
# Load WIN32OLE library
require 'win32ole'
require 'Win32API'
#Load the win32 library
require 'win32/clipboard'
include Win32
require 'InputRepository/Config.rb'


class NIC_Lib

      def CMS_login(uname,passwd)

          driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
          @bwsr = Watir::Browser.new driver
          @bwsr.goto("#{$CMS_Site_URL}")
          @bwsr.text_field(:id,"edit-name").set(uname)
          @bwsr.text_field(:id,"edit-pass").set(passwd)
          @bwsr.button(:id, "edit-submit").click
          return(@bwsr)
      end

end
