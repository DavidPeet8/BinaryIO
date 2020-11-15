#ifndef ASCII_AS_BIN_TO_BIN_TRANSFORM_H
#define ASCII_AS_BIN_TO_BIN_TRANSFORM_H

#include <iostream>

#include "transform.h"

class AsciiAsBinToBinTransform final : public Transform {
 public:
  AsciiAsBinToBinTransform(std::istream &in, std::ostream &out, bool formatted)
      : Transform(in, out, formatted) {}

 private:
  void getAndWriteByte() override;
};
#endif
