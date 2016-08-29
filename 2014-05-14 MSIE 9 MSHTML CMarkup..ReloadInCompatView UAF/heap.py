################################################################################
# "#bla".toString() = output "bla"
# "*".toString() = enable heap event reporting
# "~".toString() = terminate debugger
# "!".toString() = break debugger
# Don't forget to add "\r\n" to "bla" if needed.
bDebugHeapDumpBlockContents = False;
bNormalHeapDumpBlockContents = False;

def commands(*tsCommands):
  return ";".join([
    sCommand
    for sCommand in tsCommands
    if sCommand
  ]);

def encodeCommands(*tsCommands):
  return '"%s"' % ";".join([
    "%s" % sCommand.replace("\\", "\\\\").replace('"', '\\"')
    for sCommand in tsCommands
    if sCommand
  ]);

def setFirstChanceEventHandler(sEvent, *tsCommands):
  asCommands = list(tsCommands);
  return "sxe -c %s %s" % (encodeCommands(*asCommands), sEvent);
def setBreakpoint(sLocation, *tsCommands):
  asCommands = list(tsCommands) + ["g"];
  return "bp %s %s" % (sLocation, encodeCommands(*asCommands));
def setOneTimeBreakpoint(sLocation, *tsCommands):
  asCommands = list(tsCommands) + ["g"];
  return "bp /1 %s %s" % (sLocation, encodeCommands(*asCommands));

def masmIf(sCondition, *tsCommands):
  return ".if(@@masm(%s)){%s}" % (sCondition, commands(*tsCommands));
def printf(sFormatString, *tsArguments):
  return ",".join(['.printf "%s"' % sFormatString.replace("\\", "\\\\").replace("\r", "\\r").replace("\n", "\\n").replace('\"', '\\"')] + list(tsArguments));
def setRegs(dsRegs):
  return "r%s" % ",".join(["%s=%s" % (sName, sValue) for sName, sValue in dsRegs.items() ]);
def withIntVar(sName, sValue, *asCommands):
  return '.foreach(%s {.printf "%%p", %s}){%s}' % (sName, sValue, commands(*asCommands));
def dumpHeapInfo(sAddress):
  return "!heap -p -a %s" % sAddress;

sInteractionModule = "jscript9";
sInteractionFunction = "Js::JavascriptString::EntryToString";
sInteractionLocation = "poi(poi(esp+c)+c)";

sCommands = commands(
  setRegs({"$t0": "3E8", "$t1": "3E8", "$t2": "3E8", "$t3": "3E8"}),
  setFirstChanceEventHandler("ld:%s" % sInteractionModule, 
    setBreakpoint("MSHTML!CElement::hasChildNodes", 
      masmIf("$vvalid(poi(@ebp+8),4)",
        printf("    CElement @ %p = %y \r\n", "poi(@ebp+8)", "@@masm(poi(poi(@ebp+8)))"),
        bDebugHeapDumpBlockContents and "dd poi(@ebp+8) L (400-((poi(@ebp+8)>>2)&3ff))",
        bNormalHeapDumpBlockContents and "dd poi(@ebp+8) L 40",
      ),
    ),
    setBreakpoint("%s!%s" % (sInteractionModule, sInteractionFunction), 
      masmIf("wo(%s) == 23" % sInteractionLocation, # "#bla" => output bla.
        printf("*** Log: %mu\r\n", "%s+2" % sInteractionLocation),
      ),
      masmIf("wo(%s) == 7E" % sInteractionLocation, # "~" => terminate MSIE
        printf("*** Quit.\r\n"),
        "q",
      ),
      masmIf("wo(%s) == 21" % sInteractionLocation, # "!" => terminate debugger
        printf("*** Breakpoint.\r\n"),
        "t", # If anybody knows how to stop execution properly, let me know.
      ),
      masmIf("wo(%s) == 2A" % sInteractionLocation, # "*" => enable heap allocation/free logging.
        printf("*** Enabling heap logging\r\n"),
        setBreakpoint("ntdll!RtlAllocateHeap", 
          setRegs({"$t0": "@$t0+1"}),
          withIntVar("counter", "@$t0-3E8", 
            printf("=== Call to RtlAllocateHeap #%d @%X:%X, requesting 0x%X bytes ===\r\n",
                "${counter}", "@$tpid", "@$tid", "@@masm(poi(esp+C))"),
            setOneTimeBreakpoint("@$ra",
              printf("=== Return value for RtlAllocateHeap #%d @%X:%X  : %p ===\r\n",
                  "${counter}", "@$tpid", "@$tid", "@eax"),
              dumpHeapInfo("@eax"),
            ),
          ),
        ),
        setBreakpoint("ntdll!RtlReAllocateHeap", 
          setRegs({"$t1": "@$t1+1"}),
          withIntVar("counter", "@$t1-3E8", 
            withIntVar("address", "@@masm(poi(@esp+C))", 
              printf("=== Call to RtlReAllocateHeap #%d @%X:%X, requesting 0x%X bytes for heap block 0x%p ===\r\n",
                  "${counter}", "@$tpid", "@$tid", "@@masm(poi(esp+10))", "${address}"),
              dumpHeapInfo("${address}"),
              masmIf("$vvalid(${address},4)",
                printf("    VFTable = %y\r\n", "@@masm(poi(${address}))"),
                bDebugHeapDumpBlockContents and "dd ${address} L (400-((${address}>>2)&3ff))",
                bDebugHeapDumpBlockContents and "dd ${address} L 40",
              ),
              setOneTimeBreakpoint("@$ra",
                printf("=== Return value for RtlReAllocateHeap #%d @%X:%X : %p ===\r\n",
                    "${counter}", "@$tpid", "@$tid", "@eax"),
                dumpHeapInfo("${address}"),
                dumpHeapInfo("@eax"),
              ),
            ),
          ),
        ),
        setBreakpoint("ntdll!RtlFreeHeap",
          setRegs({"$t2": "@$t2+1"}),
          withIntVar("counter", "@$t2-3E8", 
            withIntVar("address", "@@masm(poi(@esp+C))", 
              printf("=== Call to RtlFreeHeap #%d @%X:%X, freeing heap block 0x%p ===\r\n",
                  "@$t2-3E8", "@$tpid", "@$tid", "${address}"),
              dumpHeapInfo("${address}"),
              masmIf("$vvalid(${address},4)",
                printf("    VFTable = %y\r\n", "@@masm(poi(${address}))"),
                bDebugHeapDumpBlockContents and "dd ${address} L (400-((${address}>>2)&3ff))",
                bDebugHeapDumpBlockContents and "dd ${address} L 40",
              ),
              setOneTimeBreakpoint("@$ra",
                printf("=== Return value for RtlFreeHeap #%d @%X:%X : %X ===\r\n",
                    "${counter}", "@$tpid", "@$tid", "@eax"),
                dumpHeapInfo("${address}"),
                "g",
              ),
            ),
          ),
        ),
      ),
    ),
    "g",
  ),
  setFirstChanceEventHandler("cce",
    printf("=== User break ===\r\n"),
    "q",
  ),
  setFirstChanceEventHandler("av",
    printf("=== Exception ===\r\n"),
    ".exr -1",
    printf("=== Disassembly ===\r\n"),
    "ub",
    "u",
    printf("=== Stack ===\r\n"),
    "k",
    printf("=== End ===\r\n"),
    "q",
  ),
  printf("=== Start ===\r\n"),
  "sxn ibp", # Ignore initial breakpoint events
  "sxn cpr", # Ignore create process events
  "sxn epr", # Ignore end process events
  "g"
);

import os, random, sys, subprocess;
sTempFilePath = os.path.join(os.environ["TMP"], "debug-%X.cdb" % random.randint(0, 1 << 32));
oTempFile = open(sTempFilePath, "wb");
oTempFile.write(sCommands.replace("\n", ""));
oTempFile.close();
asCommand = [
  "C:\Tools\Debugging Tools for Windows (x86)\cdb.exe",
  "-o", "-G",
  "-sflags", "0x000B0B37",
  "-c", "$><%s" % sTempFilePath,
  "C:\Program Files\Internet Explorer\iexplore.exe",
  "http://%s:28876/heap.html" % os.environ["COMPUTERNAME"],
];
oOutFile = open(os.path.join(os.path.dirname(__file__), "heap.log"), "wb");
oCDB = subprocess.Popen(asCommand, stdout=subprocess.PIPE);
sLine = "";
while 1:
  sChar = oCDB.stdout.read(1);
  if not sChar:
    break;
  if sChar == "\r":
    pass;
  else:
    sLine += sChar;
    print "\r%s" % sLine,;
    if sChar == "\n":
      sLine = "";
  oOutFile.write(sChar);
oOutFile.close();