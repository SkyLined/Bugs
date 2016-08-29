505 // Find the "http" substring in a status line. This allows for
506 // some slop at the start. If the "http" string could not be found
507 // then returns -1.
508 // static
509 int HttpUtil::LocateStartOfStatusLine(const char* buf, int buf_len) {
510   const int slop = 4;
511   const int http_len = 4;
512 
513   if (buf_len >= http_len) {
514     int i_max = std::min(buf_len - http_len, slop);
515     for (int i = 0; i <= i_max; ++i) {
516       if (LowerCaseEqualsASCII(buf + i, buf + i + http_len, "http"))
517         return i;
518     }
519   }
520   return -1;  // Not found
521 }