#ifndef BIN_TO_BIN_AS_ASCII_TRANSFORM_H
#define BIN_TO_BIN_AS_ASCII_TRANSFORM_H

#include <iostream>

#include "transform.h"

class BinToBinAsAsciiTransform final : public Transform {
 public:
  BinToBinAsAsciiTransform(std::istream &in, std::ostream &out, bool formatted)
      : Transform(in, out, formatted) {}

  ~BinToBinAsAsciiTransform() { Out() << '\n'; }

 private:
  void getAndWriteByte() override;
};
#endif
