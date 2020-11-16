#include "streamer.h"

Streamer &operator<<(Streamer &ostreamer, char t) {
  return ostreamer << static_cast<unsigned char>(t);
}
Streamer &operator>>(Streamer &istreamer, char &t) {
  return istreamer >> reinterpret_cast<unsigned char &>(t);
}

Streamer &operator<<(Streamer &ostreamer, unsigned char t) {
  ostreamer.getOStream() << t;
  if (ostreamer.isFormatted()) {
    ostreamer.getOStream() << "\n";
  }
  return ostreamer;
}

Streamer &operator>>(Streamer &istreamer, unsigned char &t) {
  istreamer.getIStream() >> t;
  return istreamer;
}
