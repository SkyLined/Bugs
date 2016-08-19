1267v - Microsoft Edge Tree::ANode::IsInTree use-after-free
=====================================

Synopsis
--------
A specially crafted HTML page that causes a loop by setting a "DOMNodeRemoved"
event handler which replaces a DOM node can cause a use-after-free in Microsoft
Edge.

Known affected software, attack vectors and mitigations
-------------------------------------------------------
  + Microsoft Edge 11.0.10240.16384

    An attacker would need to get a target user to open a specially crafted
    webpage. Disabling JavaScript should prevent an attacker from triggering the
    vulnerable code path.

Repro
-----
### repro.html
    <iframe src="target.xhtml"></iframe>

### target.xhtml:
    <x xmlns='http://www.w3.org/1999/xhtml'>
    <script type="text/javascript">
      <![CDATA[
        function main(){
          document.firstChild.textContent = "x";
        };
        document.addEventListener("DOMNodeRemoved", main, true);
        main();
      ]]>
    </script>

Description
-----------
The repro can trigger a use-after-free in Tree::ANode::IsInTree, or a breakpoint
in Abandonment::CheckHRESULT. While the original repro reliably triggered the
use-after-free (>90% of the time), during minification the reliability dropped.
The current repro triggers the breakpoint more often than not for me. I have no
idea what is causing this to trigger two different exceptions nor how to make
it reliably trigger one over the other. Furthermore, I have not idea what
a breakpoint in Abandonment::CheckHRESULT signifies. I would venture to guess it
is some form of assertion check, but I have not attempted to determine if this
is true. If you have any information that you're willing to share about the
Abandonment class in Edge, please let me know!

I've used [EdgeDbg](https://github.com/SkyLined/EdgeDbg) together with [BugId]
(https://github.com/SkyLined/BugId) to repeatedly run the repro in Edge until it
triggered the use-after-free. This can be done using the `EdgeBugId.cmd` script.
I asked it to save a full dump whenever it detected an exception, which allowed
me to create one for debugging the use-after-free. If you are having as much
trouble as I was in reproducing the issue, you may want to do the same. If you
would like a copy of my dump, please let me know.

Exploit
-------
I've not attempted to find a root cause or exploit this issue

Credit
------
If you can confirm this as a security issue and would like to provide credits
for reporting the issue in your advisory, please credit "SkyLined".
