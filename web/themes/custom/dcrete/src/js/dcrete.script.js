import 'popper.js';
import 'bootstrap';

(function($, Drupal, drupalSettings) {
  "use strict";

  Drupal.behaviors.themejs = {
    attach: function(context, drupalSettings) {
      console.log(
        $('[data-drupal-selector="password-match-status-text"]')
      );

      $("input.password-field").on("input", function(e) {
        console.log('i am in');
      });

      $("input.password-confirm").on("input", function(e) {
        let this_pass = $(this).val();
        let other_pass = $("input.password-field").val();

        if (this_pass == other_pass) {
          $(".pass-status--graphic").html("✔");
            $(".pass-status--graphic").addClass('text-success');
            $(".pass-status--graphic").removeClass("text-danger");

        }
        else {
          console.log('not OK!');
          $(".pass-status--graphic").html("x");
          $(".pass-status--graphic").removeClass("text-success");
          $(".pass-status--graphic").addClass("text-danger");
        }

      });
      //$(
      //  "#edit-field-tracking-direction-wrapper .form-checkbox",
      //  context,
      //  drupalSettings
      //)
      //  .once("direction-checkbox-container")
      //  .each(function() {
      //    $(this).on("click", function(e) {
      //      console.log($(this).val());
      //    });
      //  });
    }
  };
})(jQuery, Drupal);
