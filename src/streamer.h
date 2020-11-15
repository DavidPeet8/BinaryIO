#ifndef STREAMER_H
#define STREAMER_H

#include <iostream>

class Streamer final {
  std::istream &in;
  std::ostream &out;

  bool formatted;

 public:
  Streamer(std::istream &in, std::ostream &out, bool formatted)
      : in{in}, out{out}, formatted{formatted} {}

  bool fail() {
    in.peek();
    return in.fail();
  }
  bool isFormatted() { return formatted; }
  std::istream &getIStream() { return in; }
  std::ostream &getOStream() { return out; }

  ~Streamer() { out << std::flush; }
};

Streamer &operator<<(Streamer &ostreamer, char t);
Streamer &operator<<(Streamer &ostreamer, unsigned char t);
Streamer &operator>>(Streamer &istreamer, char &t);
Streamer &operator>>(Streamer &istreamer, unsigned char &t);

#endif
