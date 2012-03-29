require 'rubygems'
require "selenium-webdriver"
require "watir-webdriver"
require "watir-webdriver/extensions/wait"
require "text_box_javascript_value_setter"

Watir::TextField.send(:include, TextBoxJavascriptValueSetter) unless Watir::TextField.include?(TextBoxJavascriptValueSetter)