#include "ascii_as_bin_to_bin_transform.h"

#include "streamer.h"

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
      res *= 2;
      res += (c == '0' ? 0 : 1);
      i++;
    }
  }
  Out() << res;
}
