<?php
/**
 * @file
 * oj_default_seetings_for_token_purchases.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function oj_default_seetings_for_token_purchases_user_default_roles() {
  $roles = array();

  // Exported role: member.
  $roles['member'] = array(
    'name' => 'member',
    'weight' => '4',
  );

  return $roles;
}
