<?php

/**
 * Implementation of hook_user_default_roles().
 */
function community_user_default_roles() {
  $roles = array();

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
  );

  // Exported role: anonymous user
  $roles['anonymous user'] = array(
    'name' => 'anonymous user',
  );

  // Exported role: authenticated user
  $roles['authenticated user'] = array(
    'name' => 'authenticated user',
  );

  // Exported role: community member
  $roles['community member'] = array(
    'name' => 'community member',
  );

  // Exported role: moderator
  $roles['moderator'] = array(
    'name' => 'moderator',
  );

  return $roles;
}
