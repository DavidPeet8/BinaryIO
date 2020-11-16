#ifndef ASCII_AS_BIN_TO_BIN_TRANSFORM_H
#define ASCII_AS_BIN_TO_BIN_TRANSFORM_H

#include <iostream>

#include "binary_writer_transform.h"

class AsciiAsBinToBinTransform final : public BinaryWriterTransform {
 public:
  AsciiAsBinToBinTransform(std::istream &in, std::ostream &out, bool formatted)
      : BinaryWriterTransform(in, out, formatted) {}

 private:
  void getAndWriteByte() override;
};
#endif
