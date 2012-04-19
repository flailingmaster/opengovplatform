// JavaScript Document
$(document).ready(function() {
	//Main Menu
	$('#navPanel ul ul').parent('li').hover(function() {
	$(this).children('ul').fadeIn('medium');
	},
	function() {
	$(this).children('ul').fadeOut('fast');
	});
	
	$('#navPanel ul li').hover(function() {
	$(this).children('a').addClass('active');
	},
	function() {
	$(this).children('a').removeClass('active');
	});
	});