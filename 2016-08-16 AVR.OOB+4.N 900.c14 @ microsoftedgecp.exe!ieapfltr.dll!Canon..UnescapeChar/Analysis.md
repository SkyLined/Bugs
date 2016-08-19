Microsoft Edge ieapfltr.dll Canon::UnescapeChar<unsigned short> OOB read
=====================================

Synopsis
--------
Specially crafted HTML can cause an OOB read in 
`Canon::UnescapeChar<unsigned short>` in `ieapfltr.dll` in the latest version
of Microsoft Edge.

Repro
-----
```HTML
<iframe src="javascript:">
```

Description
-----------
Though I did not investigate thoroughly, I did find out the following:
* The string "javascript:" is stored in a NULL terminated WCHAR string buffer
  and the OOB read happens immediately after the end of the buffer, so after
  the NULL terminator that follows ':'
* This does not result in a crash on 64-bit systems, potentially because of
  alignment differences between these architectures, but I did not investigate.
* The crash happens in code that appears to be checking if the URL should be
  blocked/filtered. This suggests that it may not be easy to exfiltrate data
  from beyond the buffer using this issue. However, it may be possible that
  this filtering can be triggered or not based on the data that follows the
  buffer, and if this triggering can be detected, it might be possible to
  gather information about this data that way, but I am speculating wildly here.
