import BaseHTTPServer, socket;

class RequestHandler(BaseHTTPServer.BaseHTTPRequestHandler):
  dsFiles = {
    "/": "proxy.html",
  }
  def __init__(self, *txArgs, **dxArgs):
    BaseHTTPServer.BaseHTTPRequestHandler.__init__(self, *txArgs, **dxArgs);
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
      if self.path in self.dsFiles:
        self.__sendFileResponse(200, self.dsFiles[self.path]);
      elif self.path == "/sploit":
        print repr(sBody);
        self.send_response(200);
        self.send_header("\xff", "x");
        self.end_headers();
      else:
        self.__sendResponse(404, "Not found");
    except:
      oHTTPServer.server_close();
      raise;

if __name__ == "__main__":
  txAddress = ("localhost", 28876);
  oHTTPServer = BaseHTTPServer.HTTPServer(txAddress, RequestHandler);
  print "Serving at: http://%s:%d" % txAddress;
  try:
    oHTTPServer.serve_forever();
  except KeyboardInterrupt:
    pass;
  oHTTPServer.server_close();

