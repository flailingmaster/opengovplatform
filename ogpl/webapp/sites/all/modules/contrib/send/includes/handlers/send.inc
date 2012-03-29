<?php // $Id$

interface SendProfileInterface {
  // Accessors.
  public function name();
  public function setName($value);

  public function handler();

  public function template();
  public function setTemplate($template = NULL);

  public function title();
  public function setTitle($value = NULL);

  public function url();
  public function setUrl();

  public function subject();
  public function setSubject($subject = NULL);

  public function message();
  public function setMessage($message);

  public function body();
  public function setBody($value = NULL);

  public function content();
  public function setContent($value = NULL);

  public function nodes();
  public function addNode($node);

  public function templates();

  public function sender();
  public function setSender($contact = NULL);

  public function recipients();
  public function setRecipients($contact);
  public function addRecipient($contact);

  public function messages();

  public function editable($action = NULL);

  // Activities.
  public function send();
  public function redirect();
  public function form(&$form, &$form_state);
  public function settings_form(&$form, &$form_state);
  public function access();

  // Housekeeping functions.
  public function save($values = array());
  public function reset();
  public function delete();
  public function setValues($values = array());
  public function drupal_invoke($hook, $values = array());
}

class SendProfile implements SendProfileInterface {
  private $table            = 'send_profile';
  private $key              = 'spid';
  public $spid;
  public $handler          = 'send';
  public $from_element     = 'send_contact';
  public $to_element       = 'send_contact';
  public $message_element  = 'send_message_compose';
  public $template;
  public $subject;
  public $sender;
  public $recipients = array();
  public $content = array();
  public $name;
  public $parent;
  public $uid = 0;

  public $title;
  public $nids = array();

  function __construct($values = NULL) {
    $current = array();
    foreach ($this as $name => $val) $current[$name] = $val;
    if ($values) {
      foreach ((array)$values as $name => $val) {
        if ($name == 'settings' && !empty($val) && is_scalar($val)) {
          $this->__construct(unserialize($val));
        }
        elseif (array_key_exists($name, $current) && !is_null($val)) {
          $func = 'set'. $name;

          // If the variable name is a form element type, just set it.
          if (substr($name, -8) == '_element') {
            $this->$name = check_plain($val);
          }
          elseif (method_exists($this, $func)) {
            $this->$func($val);
          }
          else {
            $this->$name = $val;
          }
          unset($current[$name]);
        }
      }
    }
    // Set defaults if possible.
    foreach ($current as $name => $val) {
      $func = 'set'. $name;
      if (method_exists($this, $func)) {
        $this->$func($this->$name);
      }
    }
  }

  public function name() {
    return $this->name;
  }

  public function setName($value) {
    $this->name = filter_xss($value);
  }

  public function handler() {
    return $this->handler;
  }

  public function url() {
    if (!$this->url) {
      $this->setUrl();
    }
    if ($this->url) {
      if ($nids = $this->nids) return $this->url .'/'. join('+', $nids);
      return $this->url;
    }
  }

  public function setUrl($value = NULL) {
    if (is_null($value)) {
      $this->url = 'send/'. $this->name();
    }
    else $this->url = filter_xss($value);
  }

  public function title() {
    return $this->title;
  }

  public function setTitle($value = NULL) {
    $this->title = filter_xss($value);
  }

  public function subject() {
    if (!$this->subject) $this->setSubject();
    return $this->subject;
  }

  public function setSubject($value = NULL) {
    if ($value && $this->editable('subject')) {
      $this->subject = filter_xss($value);
    }
    else {
      $this->subject = $this->template()->subject;
    }
  }

  public function message() {
    return array(
      'subject' => $this->subject(),
      'body' => $this->body(),
      'content' => $this->content(),
    );
  }

  public function setMessage($value) {
    if (is_string($value)) {
      $this->content['message']['content'] = filter_xss($value);
    }
  }

  public function body() {
    if (!$this->body) $this->setBody();
    return theme('send_body', $this->body, $this);
  }

  public function setBody($value = NULL) {
    if ($value && $this->template()->body_editable) {
      $this->body = filter_xss($value);
    }
    elseif (!$this->body) {
      $this->body = $this->template()->body;
    }
  }

  public function content() {
    return $this->content;
  }

  public function setContent($value = NULL) {
    if ($value) {
      $this->content = $value;
      unset($this->body);
    }
  }

  public function template() {
    if (!isset($this->_template)) {
      module_load_include('template.inc', 'send', 'includes/send');
      $this->_template = send_template_load($this->template);
    }
    return $this->_template;
  }

  public function setTemplate($template = NULL) {
    if ($template) { 
      $this->template = $template;
      unset($this->_template);
    }
    elseif (!isset($this->template)) {
      $this->template = current($this->templates());
      unset($this->_template);
    }
  }

  public function templates() {
    if (!isset($this->_templates)) {
      module_load_include('template.inc', 'send', 'includes/send');
      foreach (send_template_list($this) as $t) {
        $this->_templates[$t->stid] = $t->name;
      }
      reset($this->_templates);
    }
    return $this->_templates;
  }

  public function sender() {
  }

  public function setSender($contact = NULL) {
    if ($contact && $this->editable('sender')) {
      $this->sender = $contact;
    }
  }

  public function recipients() {
    return $this->recipients;
  }

  public function setRecipients($values) {
    static $addresses = array();
    if (isset($values['mail'])) $values = array($values);
    foreach ($values as $contact) {
      // Hack to prevent double-addition of mail addresses.
      if ($mail = $contact['mail']) {
        if (in_array($mail, $addresses)) continue;
        $addresses[] = $mail;
      }
      $this->addRecipient($contact);
    }
  }

  public function addRecipient($contact) {
    $this->recipients[] = $contact;
  }

  public function messages() {
  }

  public function editable($action = NULL) {
    if ($action) {
      $var = $action .'_editable';
      // There's a property on this instance (e.g. sender_editable).
      if (isset($this->$var)) return $this->$var;

      // There's a property on my template (e.g. subject_editable).
      if (isset($this->template()->$var)) return $this->template()->$var;

      // Defaulting to false.
      return FALSE;
    }

    // No action requested - is this profile editable?
    // TODO this should be based on permissions, etc.
    return $this->editable;
  }

  public function nodes() {
    if (!isset($this->_nodes)) {
      $this->_nodes = array();
      foreach ($this->nids as $nid) $this->_nodes[$nid] = node_load($nid);
    }
    return $this->_nodes;
  }

  public function addNode($nid) {
    $nid = is_object($nid) ? $nid->nid : $nid;
    $this->nids[$nid] = $nid;
  }

  public function send() {
    if (!$recipients = $this->recipients()) return FALSE;
    if (!$message    = $this->message()) return FALSE;

    $modes = module_invoke_all('send_mode_info');

    // Keep a running list of contacts.
    $scids = array();

    // Set the delivery mode based on the default and profile settings.
    $mode = isset($this->mode) ? $this->mode : 'mail';

    // Set the sender from the message values.
    $sender = isset($message['sender']) ? $message['sender'] : (object) array(
      'uid' => 1, 
      'mail' => variable_get('site_mail', ''),
      'name' => variable_get('site_name', t('Drupal')),
    );
    // TODO incorrect assumption that sender is "mail".
    $message['sender'] = send_contact('mail', $sender);
    $scids[] = $message['sender']->scid;
  
    // Log the activity.
    $send = (object) array(
      'scid' => $message['sender']->scid,
      'profile' => $this->name(),
      'stid' => $this->template,
      'timestamp' => time(),
      'message' => $message['content']['message']['content'],
      'subject' => $message['subject'],
      'contact_count' => 0,
    );
    drupal_write_record('send', $send);
  
    // Log any nodes that are being sent.
    foreach($this->nids as $nid) {
      $send_node = array('sid' => $send->sid, 'nid' => $nid);
      drupal_write_record('send_node', $send_node);
    }
  
    foreach ($recipients as $r) {
      $r = (object) $r;
      $r_mode = (isset($r->mode)) ? $r->mode : $mode;
  
      // Convert the recipient to a send_contact entry.
      $r = send_contact($r_mode, $r);
      if(!in_array($r->scid, $scids)) $scids[] = $r->scid;
  
      $r_message = $message;
      // Set the message, replacing any tokens, etc.
      //send_set_message($r_message, $profile, $nids, $sender, $r);
  
      // Add a hash identifier to the recipient instance for tracking, etc.
      $r->hash = user_password(10);
  
      // Allow other modules to track or alter this send message/activity.
      drupal_alter('send_message', $r_message, $this, $r, $nids, $r_mode);
  
      // Effect a delivery using the selected sending mechanism.
      if (function_exists($func = $modes[$r_mode]['callback'])) {
        $r_count = (int) $func($this, $r, $nids, $r_message, $r_mode);
      }
      $send->contact_count += $r_count;

      $recipient = (object) array(
        'sid' => $send->sid,
        'scid' => $r->scid,
        'hash' => $r->hash,
        'contact_count' => $r_count,
      );
      drupal_write_record('send_recipient', $recipient);
    }
  
    // Update the send table's contact_count.
    if ($send->contact_count) {
      drupal_write_record('send', $send, 'sid');
    }
  
    // Update the "last used" timestamp on contact entries.
    if ($scids) {
      db_query("UPDATE {send_contact} SET timestamp = %d 
        WHERE scid IN (". join(', ', $scids) .")", $send->timestamp);
    }
  
    // Trigger any action that might want to go out.
    $this->drupal_invoke('send_send', $this, $send);
    return $send->contact_count;
  }

  public function redirect() {
    if (count($this->nids) == 1) {
      return 'node/'. current($this->nids);
    }
    else {
      return '<front>';
    }
  }

  public function form(&$form, &$form_state) {
  }

  public function settings_form(&$form, &$form_state) {
    $group = $this->name();

    module_load_include('inc', 'send', 'includes/send.template');
    $options = array();
    foreach (send_template_list() as $template) {
      $options[$template->stid] = $template->name;
    }

    $form[$group]['#tree'] = TRUE;

    $form[$group]['template'] = array(
      '#type'          => 'select',
      '#title'         => t('Message Template'),
      '#options'       => $options,
      '#default_value' => $this->template,
    );

    $form[$group]['subject'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Subject line'),
      '#default_value' => $this->subject,
      '#size'          => 30,
      '#maxsize'       => 100,
    );
    $form[$group]['content']['message']['content'] = array(
      '#type'          => 'textarea',
      '#title'         => t('Message text'),
      '#default_value' => $this->content['message']['content'],
      '#cols'          => 70,
      '#rows'          => 10,
    );
  }

  function access() {
    return user_access('send nodes');
  }

  function save($values = array()) {
    $this->__construct($values);
    $settings = array();
    foreach ($this as $name => $val) $settings[$name] = $val;
    $exclude = array('table', 'form_values');
    if (isset($this->table)) {
      $schema = drupal_get_schema($this->table);
      foreach ($this as $key => $val) {
        if (isset($schema['fields'][$key]) || in_array($key, $exclude) || $key[0] = '_') {
          unset($settings[$key]);
        }
      }
      $this->settings = $settings;

      $this->new = isset($this->{$this->key}) ? FALSE : TRUE;
      $update = $this->new ? NULL : $this->key;

      // Save this item.
      drupal_write_record($this->table, $this, $update);

      // Invoke a Drupal hook based on the table name, e.g. send_profile_create.
      $hook = $this->new ? '_create' : '_update';
      $this->drupal_invoke($this->table . $hook, $values);
    }
  }

  function reset() {
    foreach ($this as $name => $val) {
      // Unset any variables that may have been changed or overriden.
      if (!in_array($name, array('key', 'spid', 'table', 'name', 'handler'))) {
        unset($this->$name);
      }
    }

    // Reset to default values that were provided by hook_send_profile_info().
    $profiles = send_profiles($this->name);
    $defaults = $profiles[$this->handler];
    $this->save($defaults);
  }

  function delete() {
    $this->drupal_invoke($this->table . '_delete');
    db_query("DELETE FROM {". $this->table ."} WHERE name = '%s'", $this->name);
  }

  function setValues($values = array()) {
    $this->__construct($values);
  }

  /**
   * Execute an named Drupal hook function, passing $this as the first
   * parameter.
   */
  function drupal_invoke($hook, $values = array()) {
    foreach (module_implements($hook) as $name) {
      $func = $name .'_'. $hook;
      $func($this, $values);
    }
  }
}
