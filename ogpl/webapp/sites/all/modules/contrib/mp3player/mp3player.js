/**
* Implemetation of Drupal Behavior
*/
Drupal.behaviors.mp3players = function(context) {
  // Render MP3Players
  $('.mp3player:not(.mp3player-processed)').each(function() {
    var $thisPlayer = $(this);
    var playerID = $thisPlayer.attr('id');
    var playerData = $thisPlayer.attr('data');
    $thisPlayer.addClass('mp3player-processed');
    
    var playerSettings = new Array();
    
    var playerSettingParts = playerData.split("&");
    
    for ( var i in playerSettingParts) {
      var parts = playerSettingParts[i].split("=");
      playerSettings[parts[0]] = parts[1];
    }
    
    // Create new player and add code
    var newPlayer = AudioPlayer.embed(playerID, playerSettings);
  });
}