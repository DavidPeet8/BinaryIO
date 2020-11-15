#include "bin_to_bin_as_ascii_transform.h"

#include "bin_utils.h"
#include "streamer.h"

void BinToBinAsAsciiTransform::getAndWriteByte() {
  unsigned char c = 0;
  In() >> c;
  if (In().fail()) {
    return;
  }
  c = BinUtils::reverseByte(c);

  for (int i = 0; i < 8; i++) {
    Out() << (c % 2 ? '1' : '0');
    c /= 2;
  }
  Out() << ' ';
}
