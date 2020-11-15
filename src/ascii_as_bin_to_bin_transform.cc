#include "ascii_as_bin_to_bin_transform.h"

#include "streamer.h"

namespace {
unsigned getBinDig(char c) { return c == '1' ? '1' : '0'; }
}  // namespace

void AsciiAsBinToBinTransform::getAndWriteByte() {
  char res = 0;
  char c = 0;
  for (int i = 0; i < 8;) {
    if (In().fail()) {
      res *= 2;
      i++;
    }

    In() >> c;
    if (!isspace(c)) {
      res <<= 1;
      res += getBinDig(c);
      i++;
    }
  }
  Out() << res;
}
