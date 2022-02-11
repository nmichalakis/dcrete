<?php

use Drupal\Core\Render\Markup;

/**
 * @file
 * Theme and preprocess functions for forms.
 */
function dcrete_preprocess_form(&$variables) {
  global $base_url;
  $theme = \Drupal::theme()->getActiveTheme();
  $variables['user_login_img'] = $base_url . '/' . $theme->getPath() . '/assets/css/images/user_login.png';
  $variables['user_login_top'] =  $base_url . '/' . $theme->getPath() . '/assets/css/images/user_login_top_icon.png';
}


function dcrete_form_alter(&$form, \Drupal\Core\Form\FormStateInterface $form_state, $form_id) {


  if ($form_id === 'user_register_form') {

    $form['account']['name']['#placeholder'] = 'Ονοματεπώνυμο*';
    $form['account']['mail']['#placeholder'] = 'Email*';
    //Disable title and descriptions
    unset($form['account']['name']['#title']);
    unset($form['account']['mail']['#title']);
    unset($form['account']['pass1']['#title']);

    unset($form['account']['name']['#description']);
    unset($form['account']['mail']['#description']);
    unset($form['account']['pass1']['#description']);

    $form['account']['pass']['#description'] = t('Υποχρεωτικά πεδία *');

    $form['actions']['submit']['#value'] = t('Εγγραφή');
  }


  if ($form_id === 'user_login_form') {

    $form['name']['#placeholder'] = t('Email');
    $form['pass']['#placeholder'] = t('Κωδικός πρόσβασης');

    unset($form['name']['#title']);
    unset($form['pass']['#title']);
    unset($form['name']['#description']);
    unset($form['pass']['#description']);

    $form['actions']['submit']['#value'] = Markup::create('ΣΥΝΔΕΣΗ');
    ////Disable title and descriptions
    //unset($form['account']['name']['#title']);
    //unset($form['account']['mail']['#title']);
    //unset($form['account']['name']['#description']);
    //unset($form['account']['mail']['#description']);
  }
}


function dcrcete_form_element__password_confirm__user_register_form__pass(&$variables) {
  ksm('i am in');
  ksm($variables);
}
