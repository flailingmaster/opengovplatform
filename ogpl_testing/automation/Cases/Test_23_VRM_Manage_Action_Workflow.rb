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
require 'lib/NIC_Lib.rb'
require 'InputRepository/Config.rb'
require 'InputRepository/Test_23_VRM_Manage_Action_Workflow_Input.rb'

describe "VRM Manage Action Workflow" do

before(:all) do
    `Taskkill /IM firefox.exe /F`
    $obj=NIC_Lib.new
    @browser = $obj.CMS_login($VRM_Admin_User_Email,$VRM_Admin_User_Passwd)
end

	it "To Validate Action Name field in VRM" do
		@browser.link(:text, "Manage Actions").click
		@browser.text.should include("Action List")
		@browser.link(:text, "Add").click
		@browser.text.should include("Add Action")
		@browser.button(:value, "Add").click
		@browser.text.should include("Action Name field is required.")
		puts "***** Validation done"
	end

	it "To Cancel Action Name field" do
		@browser.text_field(:name, "name").set("#{$action_name}")
		@browser.button(:value, "Cancel").click
		@browser.text.should include("Action List")
		puts "***** Action Name Canceled"
	end


	it "To Add Action field " do
		@browser.link(:text, "Manage Actions").click
		@browser.text.should include("Action List")
		@browser.link(:text, "Add").click
		@browser.text.should include("Add Action")
		@browser.text_field(:name, "name").set("#{$action_name}")
		@browser.button(:value, "Add").click
		sleep 5
		@browser.text.should include("Action Saved")
		@browser.text.should include("#{$action_name}")
		sleep 5
		puts "*****Action field added"
	end
	
	it "To verify that newly added action is displayed in the Action status drop down" do
		@browser.link(:id, "quicktabs-tab-vrm_manage_actions-1").click
		sleep 5
		puts " Navigated to list site"
		sleep 5
		#@browser.link(:text, "Edit").click
		@browser.goto("#{$Site_URL}node/1354/edit?destination=")
		sleep 3
		@browser.text.should include("Feedback Details Edit")
		puts " Navigated to Edit site"
		@browser.select_list(:id, "edit-field-action-status-value").select("#{$action_name}")
		@browser.text.should include("#{$action_name}")
		puts "Action Name is displayed"
	end

	it "To Edit Action Name" do
		@browser.goto("#{$Site_URL}vrm_dashboard")
		sleep 5
		puts "navigated to Home"
		@browser.link(:text, "Manage Actions").click
		@browser.text.should include("Action List")
		puts "Action list"
		@browser.link(:text, "edit").click
		@browser.text.should include("Edit Action Status")
		@browser.text_field(:name, "name").set("#{$edit_action_name}")
		@browser.button(:value, "Save").click
		@browser.text.should include("Updated term #{$edit_action_name}")
		sleep 5
		puts "Updated the action name"
	end
	
	it "To verify that edited action name is displayed in the Action status drop down" do
		@browser.link(:id, "quicktabs-tab-vrm_manage_actions-1").click
		sleep 5
		puts " Navigated to list site for edit"
		@browser.goto("#{$Site_URL}node/1359/edit?destination=")
		@browser.select_list(:id, "edit-field-action-status-value").select("#{$edit_action_name}")
		@browser.text.should include("#{$edit_action_name}")
	end

	it "To Cancel Delete action" do
		@browser.goto("#{$Site_URL}vrm_dashboard")
		@browser.link(:text, "Manage Actions").click
		@browser.text.should include("Action List")
		@browser.link(:text, "edit").click
		@browser.text.should include("Edit Action Status")
		@browser.button(:value, "Delete").click
		sleep 3
		@browser.text.should include("Edit Action Status")
		@browser.text.should include("Deleting a term will delete all its children if there are any. This action cannot be undone.")
		@browser.button(:value, "Cancel").click
		sleep 3
		@browser.text.should include("Edit Action Status")
		puts "Not deleted"
	end
	
	it "To Delete Action Name" do
		@browser.button(:id, "edit-delete").click
		@browser.text.should include("Deleting a term will delete all its children if there are any. This action cannot be undone.")
		@browser.button(:id, "edit-submit").click
		@browser.text.should include("Deleted term #{$edit_action_name}")
		@browser.text.should include("Action List")
		puts "Deleted"
		sleep 5
	end
	
	it "To log out" do
		@browser.link(:text, "Log Out").click
		sleep 5
		@browser.text.should include("Welcome to Open Government Platform (OGPL) Control Panel")
		
	end
		
			
after(:all) do

	@browser.close
  `Taskkill /IM firefox.exe /F`
	puts "Test has completed"
end

end