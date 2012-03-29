<?php // $Id$

class sendNodeProfile extends sendProfile {
  public $handler = 'send_node';
  public $linktext;
  public $enabled;
  public $default;


  public function access() {
    if (!parent::access()) return FALSE;

    // Check against threshold.
    $limit = variable_get('send_node_limit', 5);
    if ($limit && !flood_is_allowed("send node", $limit)) return FALSE;

    // Check whether we're sending valid nodes for this profile
    foreach ($this->nids as $nid) {
      // Invalid or inaccessible node.
      if (!$node = node_load($nid)) return FALSE;

      // "Send to friend" not enabled for this node type.
      if (!variable_get('send_enabled_'. $node->type, FALSE)) return FALSE;

      // TODO limit for incorrect nid/type matchups with this profile.
    }

    return TRUE;
  }

  public function setEnabled($enabled) {
    $this->enabled = (bool) $enabled;
  }

  public function setDefault($default) {
    $this->default = (bool) $default;
  }

  public function linktext() {
    return $this->linktext;
  }

  public function setLinktext($value) {
    $this->linktext = ($value == '<none>') ? $value : filter_xss($value);
  }

  function settings_form(&$form, &$form_state) {
    parent::settings_form($form, $form_state);
    $group = $this->name();

    $form[$group]['linktext'] = array(
      '#type'          => 'textfield',
      '#title'         => t("Link text"),
      '#default_value' => $this->linktext,
      '#size'          => 30,
      '#maxsize'       => 100,
      '#description'   => t('The text for the link to the email form. Use <em>&lt;none&gt;</em> to hide this link.'),
    );
  }

  function send() {
    // Rely on the main "send" functionality, but register it against limits. 
    if (parent::send()) flood_register_event("send node");
  }
}
