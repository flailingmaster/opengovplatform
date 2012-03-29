// $Id$
/**
 * @file
 *
 * Display ajax content in a Dialog window.
 *
 * This javascript relies on the CTools ajax responder and jQueryUI Dialog.
 */

(function ($) {
  // Make sure our objects are defined.
  Drupal.CTools = Drupal.CTools || {};
  Drupal.Dialog = Drupal.Dialog || {};

  /**
   * Display the modal
   */
  Drupal.Dialog.show = function() {
    if (!Drupal.Dialog.dialog) {
      var o = $.extend({modal: true}, Drupal.settings.Dialog.defaults);
      Drupal.Dialog.dialog = $(Drupal.theme('DialogMain')).dialog(o);

      // Completely remove the dialog every time it is closed.  This is the
      // simplest way to get a clean slate on every dialog invokation.
      Drupal.Dialog.dialog.bind('dialogclose', function(event, ui) {
        $(this).remove();
        Drupal.Dialog.dialog = null;
      });
    }

    Drupal.CTools.AJAX.commands.dialog_loading();
  };

  /**
   * Hide the modal
   */
  Drupal.Dialog.dismiss = function() {
    if (Drupal.Dialog.dialog) {
      Drupal.Dialog.dialog.dialog('close');
    }
  };

  /**
   * Provide the HTML to create the modal dialog.
   */
  Drupal.theme.prototype.DialogMain = function () {
    var html = '<div id="dialog-main" />';
    return html;
  }

  /**
   * Provide the HTML to create the throbber.
   */
  Drupal.theme.prototype.DialogThrobber = function () {
    var html = '';
    html += '  <div id="modal-throbber">';
    html += '    <div class="modal-throbber-wrapper">';
    html +=        Drupal.settings.Dialog.throbber;
    html += '    </div>';
    html += '  </div>';

    return html;
  };

  /**
   * Generic replacement click handler to open the modal with the destination
   * specified by the href of the link.
   */
  Drupal.Dialog.clickAjaxLink = function() {
    // show the empty dialog right away.
    Drupal.Dialog.show();
    Drupal.CTools.AJAX.clickAJAXLink.apply(this);
    if (!$(this).hasClass('ctools-ajaxing')) {
      Drupal.Dialog.dismiss();
    }

    return false;
  };

  /**
   * Generic replacement click handler to open the modal with the destination
   * specified by the href of the link.
   */
  Drupal.Dialog.clickAjaxButton = function() {
    if ($(this).hasClass('ctools-ajaxing')) {
      return false;
    }

    Drupal.Dialog.show();
    Drupal.CTools.AJAX.clickAJAXButton.apply(this);
    if (!$(this).hasClass('ctools-ajaxing')) {
      Drupal.Dialog.dismiss();
    }

    return false;
  };

  /**
   * Submit responder to do an AJAX submit on all modal forms.
   */
  Drupal.Dialog.submitAjaxForm = function() {
    if ($(this).hasClass('ctools-ajaxing')) {
      return false;
    }

    url = $(this).attr('action');
    $(this).addClass('ctools-ajaxing');
    var object = $(this);
    try {
      url.replace('/nojs/', '/ajax/');

      var ajaxOptions = {
        type: 'POST',
        url: url,
        data: '',
        global: true,
        success: Drupal.CTools.AJAX.respond,
        error: function() {
          alert("An error occurred while attempting to process " + url);
        },
        complete: function() {
          object.removeClass('ctools-ajaxing');
          $('.ctools-ajaxing', object).removeClass('ctools-ajaxing');
        },
        dataType: 'json'
      };

      // If the form requires uploads, use an iframe instead and add data to
      // the submit to support this and use the proper response.
      if ($(this).attr('enctype') == 'multipart/form-data') {
        $(this).append('<input type="hidden" name="ctools_multipart" value="1">');
        ajaxIframeOptions = {
          success: Drupal.CTools.AJAX.iFrameJsonRespond,
          iframe: true
        };
        ajaxOptions = $.extend(ajaxOptions, ajaxIframeOptions);
      }

      $(this).ajaxSubmit(ajaxOptions);
    }
    catch (err) {
      alert("An error occurred while attempting to process " + url);
      $(this).removeClass('ctools-ajaxing');
      $('div.ctools-ajaxing', this).remove();
      return false;
    }
    return false;
  };

  /**
   * Handle a form button being clicked inside of a dialog.
   */
  Drupal.Dialog.clickFormButton = function() {
    if (Drupal.autocompleteSubmit && !Drupal.autocompleteSubmit()) {
      return false;
    }

    // Make sure it knows our button.
    if (!$(this.form).hasClass('ctools-ajaxing')) {
      this.form.clk = this;
      $(this).after('<div class="ctools-ajaxing"> &nbsp; </div>');

      // Submit the form. Notice the difference between $().submit()
      // which is the ajax submit and form.submit() which is the
      // default browser submit.
      $(this.form).submit();
    }

    return false;
  };

  /**
   * Bind links that will open modals to the appropriate function.
   */
  Drupal.behaviors.Dialog = function(context) {
    // Bind links
    $('a.ctools-use-dialog:not(.ctools-use-dialog-processed)', context)
      .addClass('ctools-use-dialog-processed')
      .click(Drupal.Dialog.clickAjaxLink);

    // Bind buttons
    $('input.ctools-use-dialog:not(.ctools-use-dialog-processed), button.ctools-use-dialog:not(.ctools-use-dialog-processed)', context)
      .addClass('ctools-use-dialog-processed')
      .click(Drupal.Dialog.clickAjaxButton);

    if ($(context).attr('id') == 'dialog-main') {
      // Bind submit links in the modal form.
      $('form:not(.ctools-use-dialog-processed)', context)
        .addClass('ctools-use-dialog-processed')
        .submit(Drupal.Dialog.submitAjaxForm);
      // add click handlers so that we can tell which button was clicked,
      // because the AJAX submit does not set the values properly.

      $('input[type="submit"]:not(.ctools-use-dialog-processed), button:not(.ctools-use-dialog-processed)', context)
        .addClass('ctools-use-dialog-processed')
        .click(Drupal.Dialog.clickFormButton);

      var buttons = {}, buttonsMap = {};
      $('.ctools-dialog-button:not(.ctools-dialog-button-processed)', context)
        .addClass('ctools-dialog-button-processed')
        .hide()
        .each(function() {
          var text = $(this).is('input') ? $(this).attr('value') : $(this).text();
          buttonsMap[text] = this;
          buttons[text] = function(e) {
            var text = $(e.target).text();
            var map = $(this).data('dialogButtonsMap');
            var button = map[text];

            $(button).click();
          };
        });
      $(context).data('dialogButtonsMap', buttonsMap);
      $(context).dialog('option', 'buttons', buttons);
    }
  };

  // The following are implementations of AJAX responder commands.

  /**
   * AJAX responder command to place HTML within the modal.
   */
  Drupal.CTools.AJAX.commands.dialog_display = function(command) {
    var $el = Drupal.Dialog.dialog,
      o = {},
      overrides = {};

    // Ensure that the dialog wasn't closed before the request completed.
    if ($el) {
      $el.html(command.output).dialog('show');

      // Merge all of the options together: defaults, overrides, and options
      // specified by the command, then apply them.
      overrides = {
        // Remove any previously added buttons.
        'buttons': {},
        'title': command.title,
        'maxHeight': Math.floor($(window).height() * .8)
      };
      o = $.extend({}, Drupal.settings.Dialog.defaults, overrides, command.options);
      $.each(o, function (i, v) { $el.dialog('option', i, v); });

      if ($el.height() > o.maxHeight) {
        $el.dialog('option', 'height', o.maxHeight);
        $el.dialog('option', 'position', o.position);
        // This is really ugly, but dialog gives us no way to call _size() in a
        // sane way!
        $el.data('dialog')._size();
      }

      Drupal.attachBehaviors($el);
    }
  };

  /**
   * AJAX responder command to dismiss the modal.
   */
  Drupal.CTools.AJAX.commands.dialog_dismiss = function(command) {
    Drupal.Dialog.dismiss();
  }

  /**
   * Display loading
   */
  Drupal.CTools.AJAX.commands.dialog_loading = function(command) {
    Drupal.CTools.AJAX.commands.dialog_display({
      output: Drupal.theme('DialogThrobber'),
      title: Drupal.t('Loading...')
    });
  }
})(jQuery);
