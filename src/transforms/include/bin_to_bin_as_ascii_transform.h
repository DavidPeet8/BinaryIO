#ifndef BIN_TO_BIN_AS_ASCII_TRANSFORM_H
#define BIN_TO_BIN_AS_ASCII_TRANSFORM_H

#include <iostream>

#include "binary_reader_transform.h"

class BinToBinAsAsciiTransform final : public BinaryReaderTransform {
 public:
  BinToBinAsAsciiTransform(std::istream &in, std::ostream &out, bool formatted)
      : BinaryReaderTransform(in, out, formatted) {}

 private:
  void getAndWriteByte() override;
};
#endif
