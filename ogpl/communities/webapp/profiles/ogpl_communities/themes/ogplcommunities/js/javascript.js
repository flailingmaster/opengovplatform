// $Id: javascript.js,v 1.1.4.2 2009/08/12 23:29:56 add1sun Exp $

// Prefill the search box with Search... text.
$(document).ready(function(){
  $('#search input:text').autofill({
    value: "Search This Community..."
  });
  
   $(':image').click(function(){
      if ($("#search input:text").val() == "Search this community..." || $("#search input:text").val() == ""){
	  alert ("Please enter a search term"); 
	  return false; 
	  }
   if($("#search input:text").val().replace(/ /g,'').length<3){
   alert ("You must include at least one positive keyword with 3 characters or more.");
   return false;
   }	  
	  });
  $('.vote-popup-unauthenticated').click(function(){
  alert('Please login to vote.');
  });
  $(".view-id-og_ogplcommunities_data_tools th.views-field-field-api-link-url:not(.active)").children("a[title^='sort']").attr('href', function() {
  return this.href.replace('asc', 'desc'); 
  });
});