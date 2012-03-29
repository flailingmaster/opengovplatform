require 'rubygems'
require "watir-webdriver"

module TextBoxJavascriptValueSetter

  def quick_set value
    driver.execute_script "arguments[0].value = arguments[1]", element,value
  end
    
end
