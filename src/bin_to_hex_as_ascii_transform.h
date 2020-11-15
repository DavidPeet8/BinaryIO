#ifndef BIN_TO_HEX_AS_ASCII_TRANSFORM_H
#define BIN_TO_HEX_AS_ASCII_TRANSFORM_H

#include <iostream>

#include "transform.h"

class BinToHexAsAsciiTransform final : public Transform {
 public:
  BinToHexAsAsciiTransform(std::istream &in, std::ostream &out, bool formatted)
      : Transform(in, out, formatted) {}

  ~BinToHexAsAsciiTransform() { Out() << '\n'; }

 private:
  void getAndWriteByte() override;
};
#endif
