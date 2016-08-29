565 // Helper used by AssembleRawHeaders, to find the end of the status line.
566 static const char* FindStatusLineEnd(const char* begin, const char* end) {
567   size_t i = base::StringPiece(begin, end - begin).find_first_of("\r\n");
568   if (i == base::StringPiece::npos)
569     return end;
570   return begin + i;
571 }