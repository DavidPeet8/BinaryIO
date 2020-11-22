#ifndef ASCII_AS_HEX_TO_BIN_TRANSFORM_H
#define ASCII_AS_HEX_TO_BIN_TRANSFORM_H

#include <iostream>

#include "binary_writer_transform.h"

class AsciiAsHexToBinTransform final : public BinaryWriterTransform
{
public:
  AsciiAsHexToBinTransform(std::istream &in, std::ostream &out, bool formatted) :
      BinaryWriterTransform(in, out, formatted)
  {}

private:
  void getAndWriteByte(bool inRange) override;
};
#endif
