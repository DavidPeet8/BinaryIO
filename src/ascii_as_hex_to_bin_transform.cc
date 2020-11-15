#include "ascii_as_hex_to_bin_transform.h"

#include "streamer.h"

namespace {
unsigned getHexDigit(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  } else if (c >= 'A' && c <= 'F') {
    return c - 'A' + 10;
  } else {
    return 0;
  }
}

void addHexSequence(char c, char &res) {
  res <<= 4;
  res += getHexDigit(c);
}

}  // namespace

void AsciiAsHexToBinTransform::getAndWriteByte() {
  char res = 0;
  char c = 0;

  for (int i = 0; i < 2;) {
    if (In().fail()) {
      res <<= 4;
      i++;
      continue;
    }

    In() >> c;
    if (!isspace(c)) {
      addHexSequence(c, res);
      i++;
    }
  }
  Out() << res;
}
