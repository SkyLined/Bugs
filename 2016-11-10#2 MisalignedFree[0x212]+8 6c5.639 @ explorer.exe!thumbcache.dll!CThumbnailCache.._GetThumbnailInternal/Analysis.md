Windows 10 explorer.exe Misaligned Free
=======================================

Synopsis
--------
When handling long path names on network shares mapped to a drive, explorer.exe
can be made to free a memory block with a pointer that does not actually point
to the start of the memory block, but rather to the start plus a static offset.

Known affected software
-----------------------
  + explorer.exe 10.0.14393.0
    
Repro
-----
From a cmd.exe shell, execute the following commands to reproduce the issue:

    > %SystemDrive%
    > mkdir \test
    > cd \test
    > mkdir _________________________________________________________________________________________________________________________________________________________________________________________________________________________________237_bytes___
    > cd _________________________________________________________________________________________________________________________________________________________________________________________________________________________________237_bytes___
    > ECHO. >x.URL
    > net share test=%SystemDrive%\test
    > explorer.exe %CD%

Now, to prevent explorer.exe crashing prematurely, please set the default view
to `details`:

* Select the `view` tab at the top of the explorer.exe window
* Select `Details` from the list of ways to view the current folder.
* Click on `Options` on the right hand side of the `view` banner.
* Select the `view` tab at the top.
* Click on `Apply to Folders`
* From the list of options, enable `Launch folder windows in a separate
  process`

(The above steps are not required to trigger the issue AFAIK, but they make
debugging easier.)
Now close the explorer.exe window, and go back to the cmd.exe shell:

    > pushd \\localhost\test
    > explorer.exe _________________________________________________________________________________________________________________________________________________________________________________________________________________________________237_bytes___

At this point you may want to attach your debugger to the newly spawned
explorer.exe process. When you are ready to proceed, try to drag and drop the
`x` Internet Shortcut file: this should cause an exception in explorer.exe

Description
-----------
When explorer.exe needs to look up the thumbnail for a file with a long path
name on a mapped network share, it will replace the drive letter in the path of
the file with the network share. For example: when the network share
`\\server\share` is mapped to drive `Z:` and explorer.exe needs to render the
thumbnail for the file  `Z:\__long_path__...__\z.URL`, it will lookup the
thumbnail for `\\server\share\__long_path__...__\x.URL`. When doing so, the
code at some point attempts to free this string. However, the string is part
of a struct and a pointer is located before this string, like so:

struct _ThumbNailStruct {
  PVOID pUnknown;
  WCHAR[] szFilePath;
};

This will cause the code to try to free a memory block using a pointer that is
4 (x86) or 8 (x64) bytes after the start of that block.

The size of the block can be controlled through the name of the server and
share: chaning the length of the name for the server or share results in a 
similar change to the length of the path and thus the memory block.

Exploit
-------
The attacker does not appear to have control over the value in the pointer, so
with my limited knowledge of Windows 10 Heap management, I expect that this is
not exploitable. However, I am not very familiar with the subject, so I am
hoping somebody does know how one might exploit this.

Credit
------
If you can confirm this as a security issue and would like to provide credits
for reporting the issue in your advisory, please credit "SkyLined".

