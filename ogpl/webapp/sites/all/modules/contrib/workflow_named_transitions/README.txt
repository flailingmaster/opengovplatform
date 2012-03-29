ABOUT
-----

This module modifies the workflow form items so specific workflow transitions
can have their own labels which the admin can describe relative
to the beginning and ending states. Rather than showing the user a
workflow box containing options like "review required" as a state in the
workflow, it could say "move to the editing department for grammar review".


INSTALL
-------

Nothing special.

1. Download and install
   http://drupal.org/project/workflow

2. Install Workflow Named Transitions


BUGS/FEATURE REQUESTS
---------------------

http://drupal.org/project/issues/workflow_named_transitions


NOTES
-----

Since workflow modifies forms to add its options for workflow
state changes to existing forms, and then this module modifies
those form additions, this module must execute its form alterations
after workflow module. In more technical terms, the hook_form_alter()
in this module needs to run after the hook_form_alter() in workflow.
The installer automatically weights this module to execute after
workflow, but should you need more advanced configuration, install
something like Utility:

  http://drupal.org/project/util


AUTHOR
------
David Kent Norman (http://deekayen.net/)

Amazon Honor System donation:
http://zme.amazon.com/exec/varzea/pay/T2EOCSRRDQ9CL2

Paypal donation:
https://www.paypal.com/us/cgi-bin/webscr?cmd=_xclick&business=paypal@deekayen.net&item_name=Drupal%20contribution&currency_code=USD&amount=20.00

$Id: README.txt,v 1.2 2008/12/23 06:11:02 deekayen Exp $