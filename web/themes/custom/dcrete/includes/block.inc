<?php

/**
 * @file
 * Theme and preprocess functions for blocks.
 */
/**
 * Implements hook_theme_suggestions_HOOK_alter().
 */
function dcrete_theme_suggestions_block_alter(array &$suggestions, array $variables) {
  $block = $variables['elements'];
  $blockType = $block['#configuration']['provider'];
  if ($blockType == "block_content") {
    $bundle = $block['content']['#block_content']->bundle();
    $suggestions[] = 'block__' . $blockType . '__' . $bundle;
    if (isset($variables['elements']['content']['field_block_layout'])) {
      $suggestions[] = 'block__' . $blockType . '__' . $bundle . '__' . $variables['elements']['content']['field_block_layout'][0]['#markup'];
    }
  }
}

/**
 * Implements template_preprocess_block().
 */
function dcrete_preprocess_block(&$variables) {

  if (isset($variables['elements']['content']['field_block_layout'])) {
    $variables['attributes']['class'][] =
      'block-custom--' . str_replace('_', '--', $variables['elements']['content']['field_block_layout'][0]['#markup']);
  }
}
