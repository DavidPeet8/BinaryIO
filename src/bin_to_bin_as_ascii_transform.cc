#include "bin_to_bin_as_ascii_transform.h"

#include "streamer.h"

void BinToBinAsAsciiTransform::getAndWriteByte() {
  char c = 0;
  In() >> c;

  for (int i = 0; i < 8; i++) {
    Out() << (c % 2 ? '1' : '0');
    c /= 2;
  }
}
