168   // Implementation of GetNext() for when we have no quote characters. We have
169   // two separate implementations because AdvanceOne() is a hot spot in large
170   // text files with large tokens.
171   bool QuickGetNext() {
172     token_is_delim_ = false;
173     for (;;) {
174       token_begin_ = token_end_;
175       if (token_end_ == end_)
176         return false;
177       ++token_end_;
178       if (delims_.find(*token_begin_) == str::npos)
179         break;
180       // else skip over delimiter.
181     }
182     while (token_end_ != end_ && delims_.find(*token_end_) == str::npos)
183       ++token_end_;
184     return true;
185   }