/* $Id:

Description
===========
After a given timeout has passed, users are given a configurable session expired prompt. They can reset the timeout, logout, or ignore it in which case they'll be logged out after a the padding time has elapsed. This is all backed up by a server side logout if js is disable or bypassed.

Features
========
* Configurable timeout and timeout padding. The latter determines how much time a user has to respond to the prompt and when the server side timeout will occur.
* Configurable messaging.
* Configurable redirect url, with the destination automatically appended.
* Configure which roles will be automatically logged out.
* Configure if a logout will occur on admin pages.
* Integration with jquery_ui if available. This makes for attractive and more functional dialogs.