#ifndef ASCII_AS_HEX_TO_BIN_TRANSFORM_H
#define ASCII_AS_HEX_TO_BIN_TRANSFORM_H

#include <iostream>

#include "transform.h"

class AsciiAsHexToBinTransform final : public Transform {
 public:
  AsciiAsHexToBinTransform(std::istream &in, std::ostream &out, bool formatted)
      : Transform(in, out, formatted) {}

 private:
  void getAndWriteByte() override;
};
#endif
