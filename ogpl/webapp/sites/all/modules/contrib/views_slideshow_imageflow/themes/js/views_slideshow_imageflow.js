
/**
 *  @file
 *  This will initiate any ImageFlow browsers we have set up.
 */


(function ($) {
  var viewsSlideshowImageFlowPlayers = new Array();

  Drupal.behaviors.viewsSlideshowImageFlow = function (context) {
    $('.views-slideshow-imageflow-images:not(.viewsSlideshowImageFlow-processed)', context).addClass('viewsSlideshowImageFlow-processed').each(function () {
	
      var imageflow = new ImageFlow();
      var id = $(this).attr('id');
      var flow = Drupal.settings.viewsSlideshowImageFlow[id];
      if (!flow['slider']) {
        flow['slider'] = false;
      }
      if (!flow['captions']) {
        flow['captions'] = false;
      }
	 if(flow['circular']) {
       // can't have an imageFocusMax if you want circular
       flow['imageFocusMax'] = undefined;
     }
	  
	  //alert(id);
      var _settings = {
        ImageFlowID: id,
        reflections: false,
        imagesHeight: flow['imagesHeight'],
        aspectRatio: flow['aspectRatio'],
        imageCursor: flow['imageCursor'],
        startID: flow['startID'],
        slider: flow['slider'],
        sliderCursor: flow['sliderCursor'],
        captions: flow['captions'],
        imageFocusM : flow['imageFocusM'],
        scrollbarP : flow['scrollbarP'],
        imageFocusMax : flow['imageFocusMax'],
		buttons: flow['buttons'],
		 circular: flow['circular'],
		//buttons:true,
		//circular:true,
		//glideToStartID:true,           /* Toggle glide animation to start ID */
		//startAnimation:true
		
      };

      if (flow['onClick']) {
        eval("_settings['onClick'] = " + flow['onClick']);
      }

      imageflow.init(_settings);
      viewsSlideshowImageFlowPlayers[id] = imageflow;
    });
  };

  viewsSlideshowImageFlowPlayer = function (id) {
    return viewsSlideshowImageFlowPlayers[id];
  }
})(jQuery);
