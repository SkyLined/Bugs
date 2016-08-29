582 std::string HttpUtil::AssembleRawHeaders(const char* input_begin,
583                                          int input_len) {
584   std::string raw_headers;
585   raw_headers.reserve(input_len);
586 
587   const char* input_end = input_begin + input_len;
588 
589   // Skip any leading slop, since the consumers of this output
590   // (HttpResponseHeaders) don't deal with it.
591   int status_begin_offset = LocateStartOfStatusLine(input_begin, input_len);
592   if (status_begin_offset != -1)
593     input_begin += status_begin_offset;
594 
595   // Copy the status line.
596   const char* status_line_end = FindStatusLineEnd(input_begin, input_end);
597   raw_headers.append(input_begin, status_line_end);
598 
599   // After the status line, every subsequent line is a header line segment.
600   // Should a segment start with LWS, it is a continuation of the previous
601   // line's field-value.
602 
603   // TODO(ericroman): is this too permissive? (delimits on [\r\n]+)
604   base::CStringTokenizer lines(status_line_end, input_end, "\r\n");
605 
606   // This variable is true when the previous line was continuable.
607   bool prev_line_continuable = false;
608 
609*  while (lines.GetNext()) {
610     const char* line_begin = lines.token_begin();
611     const char* line_end = lines.token_end();
612 
613     if (prev_line_continuable && IsLWS(*line_begin)) {
614       // Join continuation; reduce the leading LWS to a single SP.
615       raw_headers.push_back(' ');
616       raw_headers.append(FindFirstNonLWS(line_begin, line_end), line_end);
617     } else {
618       // Terminate the previous line.
619       raw_headers.push_back('\n');
620 
621       // Copy the raw data to output.
622       raw_headers.append(line_begin, line_end);
623 
624       // Check if the current line can be continued.
625       prev_line_continuable = IsLineSegmentContinuable(line_begin, line_end);
626     }
627   }
628 
629   raw_headers.append("\n\n", 2);
630 
631   // Use '\0' as the canonical line terminator. If the input already contained
632   // any embeded '\0' characters we will strip them first to avoid interpreting
633   // them as line breaks.
634   raw_headers.erase(std::remove(raw_headers.begin(), raw_headers.end(), '\0'),
635                     raw_headers.end());
636   std::replace(raw_headers.begin(), raw_headers.end(), '\n', '\0');
637 
638   return raw_headers;
639 }