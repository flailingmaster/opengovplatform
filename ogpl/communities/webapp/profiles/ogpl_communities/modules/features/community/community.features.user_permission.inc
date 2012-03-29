<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function community_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration pages
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: access all views
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
  );

  // Exported permission: access comments
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'moderator',
    ),
  );

  // Exported permission: access content
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'community member',
    ),
  );

  // Exported permission: access site reports
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'moderator',
    ),
  );

  // Exported permission: access site-wide contact form
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'moderator',
    ),
  );

  // Exported permission: access skinr
  $permissions['access skinr'] = array(
    'name' => 'access skinr',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'moderator',
    ),
  );

  // Exported permission: access skinr classes
  $permissions['access skinr classes'] = array(
    'name' => 'access skinr classes',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'moderator',
    ),
  );

  // Exported permission: access user profiles
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: admin own group forums
  $permissions['admin own group forums'] = array(
    'name' => 'admin own group forums',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer actions
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer advanced pane settings
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer blocks
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer comments
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'moderator',
    ),
  );

  // Exported permission: administer content types
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer custom content
  $permissions['administer custom content'] = array(
    'name' => 'administer custom content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer features
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer files
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer filters
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer forums
  $permissions['administer forums'] = array(
    'name' => 'administer forums',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer menu
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer messaging
  $permissions['administer messaging'] = array(
    'name' => 'administer messaging',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer mini panels
  $permissions['administer mini panels'] = array(
    'name' => 'administer mini panels',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer nodes
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer notifications
  $permissions['administer notifications'] = array(
    'name' => 'administer notifications',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer og features
  $permissions['administer og features'] = array(
    'name' => 'administer og features',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer organic groups
  $permissions['administer organic groups'] = array(
    'name' => 'administer organic groups',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer page manager
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer pane access
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer pane visibility
  $permissions['administer pane visibility'] = array(
    'name' => 'administer pane visibility',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer panels layouts
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer pathauto
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer permissions
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer search
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer simplemenu
  $permissions['administer simplemenu'] = array(
    'name' => 'administer simplemenu',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer site configuration
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer site-wide contact form
  $permissions['administer site-wide contact form'] = array(
    'name' => 'administer site-wide contact form',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer skinr
  $permissions['administer skinr'] = array(
    'name' => 'administer skinr',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer stylizer
  $permissions['administer stylizer'] = array(
    'name' => 'administer stylizer',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer taxonomy
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer url aliases
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer users
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: administer views
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: change own username
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(),
  );

  // Exported permission: configure member roles
  $permissions['configure member roles'] = array(
    'name' => 'configure member roles',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'moderator',
    ),
  );

  // Exported permission: create blog entries
  $permissions['create blog entries'] = array(
    'name' => 'create blog entries',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: create community_home content
  $permissions['create community_home content'] = array(
    'name' => 'create community_home content',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: create forum topics
  $permissions['create forum topics'] = array(
    'name' => 'create forum topics',
    'roles' => array(
      '0' => 'community member',
      '1' => 'moderator',
    ),
  );

  // Exported permission: create mini panels
  $permissions['create mini panels'] = array(
    'name' => 'create mini panels',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: create url aliases
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any blog entry
  $permissions['delete any blog entry'] = array(
    'name' => 'delete any blog entry',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: delete any community_home content
  $permissions['delete any community_home content'] = array(
    'name' => 'delete any community_home content',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: delete any forum topic
  $permissions['delete any forum topic'] = array(
    'name' => 'delete any forum topic',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: delete own blog entries
  $permissions['delete own blog entries'] = array(
    'name' => 'delete own blog entries',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: delete own community_home content
  $permissions['delete own community_home content'] = array(
    'name' => 'delete own community_home content',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: delete own forum topics
  $permissions['delete own forum topics'] = array(
    'name' => 'delete own forum topics',
    'roles' => array(
      '0' => 'community member',
      '1' => 'moderator',
    ),
  );

  // Exported permission: delete revisions
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: edit all group features
  $permissions['edit all group features'] = array(
    'name' => 'edit all group features',
    'roles' => array(),
  );

  // Exported permission: edit any blog entry
  $permissions['edit any blog entry'] = array(
    'name' => 'edit any blog entry',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: edit any community_home content
  $permissions['edit any community_home content'] = array(
    'name' => 'edit any community_home content',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: edit any forum topic
  $permissions['edit any forum topic'] = array(
    'name' => 'edit any forum topic',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: edit own blog entries
  $permissions['edit own blog entries'] = array(
    'name' => 'edit own blog entries',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: edit own community_home content
  $permissions['edit own community_home content'] = array(
    'name' => 'edit own community_home content',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: edit own forum topics
  $permissions['edit own forum topics'] = array(
    'name' => 'edit own forum topics',
    'roles' => array(
      '0' => 'community member',
      '1' => 'moderator',
    ),
  );

  // Exported permission: edit own group features
  $permissions['edit own group features'] = array(
    'name' => 'edit own group features',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: edit revisions
  $permissions['edit revisions'] = array(
    'name' => 'edit revisions',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: export nodes
  $permissions['export nodes'] = array(
    'name' => 'export nodes',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'moderator',
    ),
  );

  // Exported permission: export own nodes
  $permissions['export own nodes'] = array(
    'name' => 'export own nodes',
    'roles' => array(),
  );

  // Exported permission: maintain own subscriptions
  $permissions['maintain own subscriptions'] = array(
    'name' => 'maintain own subscriptions',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'community member',
      '2' => 'moderator',
    ),
  );

  // Exported permission: make forums public
  $permissions['make forums public'] = array(
    'name' => 'make forums public',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: manage all subscriptions
  $permissions['manage all subscriptions'] = array(
    'name' => 'manage all subscriptions',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: manage features
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: manage own subscriptions
  $permissions['manage own subscriptions'] = array(
    'name' => 'manage own subscriptions',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'community member',
      '2' => 'moderator',
    ),
  );

  // Exported permission: notify of path changes
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: override group default role
  $permissions['override group default role'] = array(
    'name' => 'override group default role',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: post comments
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      '0' => 'community member',
      '1' => 'moderator',
    ),
  );

  // Exported permission: post comments without approval
  $permissions['post comments without approval'] = array(
    'name' => 'post comments without approval',
    'roles' => array(
      '0' => 'community member',
      '1' => 'moderator',
    ),
  );

  // Exported permission: publish revisions
  $permissions['publish revisions'] = array(
    'name' => 'publish revisions',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: publish revisions of any blog content
  $permissions['publish revisions of any blog content'] = array(
    'name' => 'publish revisions of any blog content',
    'roles' => array(),
  );

  // Exported permission: publish revisions of any community_home content
  $permissions['publish revisions of any community_home content'] = array(
    'name' => 'publish revisions of any community_home content',
    'roles' => array(),
  );

  // Exported permission: publish revisions of any forum content
  $permissions['publish revisions of any forum content'] = array(
    'name' => 'publish revisions of any forum content',
    'roles' => array(),
  );

  // Exported permission: publish revisions of own blog content
  $permissions['publish revisions of own blog content'] = array(
    'name' => 'publish revisions of own blog content',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: publish revisions of own community_home content
  $permissions['publish revisions of own community_home content'] = array(
    'name' => 'publish revisions of own community_home content',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: publish revisions of own forum content
  $permissions['publish revisions of own forum content'] = array(
    'name' => 'publish revisions of own forum content',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: revert revisions
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: search content
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'community member',
      '4' => 'moderator',
    ),
  );

  // Exported permission: select different theme
  $permissions['select different theme'] = array(
    'name' => 'select different theme',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: skip notifications
  $permissions['skip notifications'] = array(
    'name' => 'skip notifications',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: subscribe to author
  $permissions['subscribe to author'] = array(
    'name' => 'subscribe to author',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'community member',
      '2' => 'moderator',
    ),
  );

  // Exported permission: subscribe to content
  $permissions['subscribe to content'] = array(
    'name' => 'subscribe to content',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'community member',
      '2' => 'moderator',
    ),
  );

  // Exported permission: subscribe to content in groups
  $permissions['subscribe to content in groups'] = array(
    'name' => 'subscribe to content in groups',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'community member',
      '2' => 'moderator',
    ),
  );

  // Exported permission: subscribe to content type
  $permissions['subscribe to content type'] = array(
    'name' => 'subscribe to content type',
    'roles' => array(
      '0' => 'authenticated user',
      '1' => 'community member',
      '2' => 'moderator',
    ),
  );

  // Exported permission: unpublish current revision
  $permissions['unpublish current revision'] = array(
    'name' => 'unpublish current revision',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'moderator',
    ),
  );

  // Exported permission: use PHP for block visibility
  $permissions['use PHP for block visibility'] = array(
    'name' => 'use PHP for block visibility',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: use PHP to import nodes
  $permissions['use PHP to import nodes'] = array(
    'name' => 'use PHP to import nodes',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: use advanced search
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      '0' => 'administrator',
      '1' => 'anonymous user',
      '2' => 'authenticated user',
      '3' => 'community member',
      '4' => 'moderator',
    ),
  );

  // Exported permission: use page manager
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: use panels caching features
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: use panels dashboard
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: use panels in place editing
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: view all panes
  $permissions['view all panes'] = array(
    'name' => 'view all panes',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view pane admin links
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: view revision status messages
  $permissions['view revision status messages'] = array(
    'name' => 'view revision status messages',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: view revisions
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: view revisions of any blog content
  $permissions['view revisions of any blog content'] = array(
    'name' => 'view revisions of any blog content',
    'roles' => array(),
  );

  // Exported permission: view revisions of any community_home content
  $permissions['view revisions of any community_home content'] = array(
    'name' => 'view revisions of any community_home content',
    'roles' => array(),
  );

  // Exported permission: view revisions of any forum content
  $permissions['view revisions of any forum content'] = array(
    'name' => 'view revisions of any forum content',
    'roles' => array(),
  );

  // Exported permission: view revisions of own blog content
  $permissions['view revisions of own blog content'] = array(
    'name' => 'view revisions of own blog content',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: view revisions of own community_home content
  $permissions['view revisions of own community_home content'] = array(
    'name' => 'view revisions of own community_home content',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: view revisions of own forum content
  $permissions['view revisions of own forum content'] = array(
    'name' => 'view revisions of own forum content',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  // Exported permission: view simplemenu
  $permissions['view simplemenu'] = array(
    'name' => 'view simplemenu',
    'roles' => array(
      '0' => 'moderator',
    ),
  );

  return $permissions;
}
