#include "ascii_as_hex_to_bin_transform.h"

#include "bin_utils.h"
#include "streamer.h"

namespace
{
void addHexSequence(char c, char &res)
{
  res <<= 4;
  res += BinUtils::getHexDigit(c);
}

}  // namespace

void AsciiAsHexToBinTransform::getAndWriteByte(bool InRange)
{
  char res = 0;
  char c   = 0;

  for (int i = 0; i < 2;) {
    if (In().fail()) {
      return;  // Truncate the byte where error occurred
    }

    In() >> c;
    if (!isspace(c)) {
      addHexSequence(c, res);
      i++;
    }
  }

  if (InRange) Out() << res;
}
