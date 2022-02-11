<?php

use Drupal\Core\Render\Markup;

/**
 * @file
 * Custom theme hooks.
 */

function dcrete_preprocess_html(&$variables) {

  $route = \Drupal::routeMatch();
  $route_parts = explode('.', $route->getRouteName());
  $route_parts_generic = '';

  foreach ($route_parts as $key => $route_part) {
    if ($key < count($route_parts) - 1) {
      $route_parts_generic .=
        str_replace('_', '-', $route_part) . '-';
    } else {
      $route_parts_generic .= str_replace('_', '-', $route_part);
    }
  }

  $variables['attributes']['class'][] = $route_parts_generic;

  $is_front = \Drupal::service('path.matcher')->isFrontPage();

  $variables['attributes']['class'][] = $is_front ? 'frontpage' : 'not-frontpage';

  if (in_array('taxonomy_term', $route_parts)) {
    $variables['attributes']['class'][] = 'taxonomy-term--page';
  }

  if (in_array('node', $route_parts)) {
    $variables['attributes']['class'][] = 'node--page';
  }
}


/**
 * Implements hook_preprocess_page().
 */
function dcrete_preprocess_page(&$variables) {
}

/**
 * Implements hook_preprocess_page_title().
 */
function dcrete_preprocess_page_title(&$variables) {

  $current_path = \Drupal::service('path.current')->getPath();

  $bottom_border = '<span class="rect-title rect-title--wide position-absolute"></span>';

  if ($current_path === '/user/register') {
    $variables['title'] = 'Εγγραφή στο Destination Crete';
    $variables['#title_suffix']['#markup'] =
      Markup::create($bottom_border);
  }

  if ($current_path === '/user/login') {
    $variables['title'] = 'Σύνδεση στο Destination Crete';
    $variables['#title_suffix']['#markup'] = Markup::create($bottom_border);
  }
}


// Add content type suggestions, e.g. page--node--article.html.twig.
function dcrete_theme_suggestions_page_title_alter(array &$suggestions, array $variables) {

  $current_path = \Drupal::service('path.current')->getPath();
  $cpaths = ['/user/register', '/user/login'];
  if (in_array($current_path, $cpaths)) {
    $suggestion = str_replace('/', '_', $current_path);
    $suggestions[] = 'page_title__' . $suggestion;
  }
}
