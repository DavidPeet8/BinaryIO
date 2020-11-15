#include "ascii_as_bin_to_bin_transform.h"

#include "bin_utils.h"
#include "streamer.h"

namespace {
unsigned getBinDig(char c) { return c == '1' ? 1 : 0; }
}  // namespace

void AsciiAsBinToBinTransform::getAndWriteByte() {
  unsigned char res = 0;
  unsigned char c = 0;

  for (int i = 7; i >= 0;) {
    if (In().fail()) {
      return;  // Truncate the byte where read failed
    }

    In() >> c;
    if (!isspace(c)) {
      res += getBinDig(c) << i;
      i--;
    }
  }

  Out() << res;
}
