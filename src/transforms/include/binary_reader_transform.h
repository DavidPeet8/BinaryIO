#ifndef BINARY_READER_TRANSFORM_H
#define BINARY_READER_TRANSFORM_H

#include "transform.h"

class BinaryReaderTransform : public Transform {
 public:
  BinaryReaderTransform(std::istream &in, std::ostream &out, bool formatted)
      : Transform(in, out, formatted) {}
  virtual ~BinaryReaderTransform() { Out() << '\n'; }
};
#endif
