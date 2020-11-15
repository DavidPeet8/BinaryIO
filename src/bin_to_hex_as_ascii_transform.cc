#include "bin_to_hex_as_ascii_transform.h"

#include "bin_utils.h"
#include "streamer.h"

void BinToHexAsAsciiTransform::getAndWriteByte() {
  unsigned char c = 0;
  In() >> c;
  if (In().fail()) {
    return;
  }
  // reorder groups of 4 bits to put bits in correct order for output
  c = (c << 4) + (c >> 4);

  for (int i = 0; i < 2; i++) {
    Out() << BinUtils::getHexChar(c % 16);
    c /= 16;
  }
  Out() << ' ';
}
