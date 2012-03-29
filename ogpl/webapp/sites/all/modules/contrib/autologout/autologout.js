// $Id:

Drupal.behaviors.autologout = function (context) {
  var t = setTimeout(init, Drupal.settings.autologout.timeout);
  var paddingTimer;
  
  function init() {
    if (Drupal.settings.autologout.jquery_ui) {
      dialog();
      paddingTimer = setTimeout(logout, Drupal.settings.autologout.timeout_padding);
    } else {
      if (confirm(Drupal.settings.autologout.message) ) {
        refresh();    
      } else {
        logout();
      }
    }    
  }
  
  function dialog() {
    $('<div> ' +  Drupal.settings.autologout.message + '</div>').dialog({
      modal: true,
      closeOnEscape: false,
      width: 'auto',
      buttons: { 
        Reset: function() {
          $(this).dialog("destroy");
          clearTimeout(paddingTimer);
          refresh();
        },
        Logout: function() {
          $(this).dialog("destroy");
          logout();
        }
      },
      title: Drupal.settings.autologout.title,
      close: function(event, ui) {
        logout();
      }
    });
  }

  function refresh() {
    $.ajax({
      url: Drupal.settings.basePath + 'autologout_ahah_set_last',
      type: "POST",
      success: function() {
        t = setTimeout(init, Drupal.settings.autologout.timeout);
      },
      error: function(XMLHttpRequest, textStatus) {
        alert('There has been an error resetting your last access time: ' + textStatus + '.')
      },
    });
  }
  
  function logout() {
    $.ajax({
      url: Drupal.settings.basePath + 'autologout_ahah_logout',
      type: "POST",
      success: function() {
        document.location.href = Drupal.settings.autologout.redirect_url;
      },
      error: function(XMLHttpRequest, textStatus) {
        alert('There has been an error attempting to logout: ' + textStatus + '.')
      },
    });
  }
};
