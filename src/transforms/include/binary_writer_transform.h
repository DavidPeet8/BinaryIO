#ifndef BINARY_WRITER_TRANSFORM_H
#define BINARY_WRITER_TRANSFORM_H

#include "transform.h"

class BinaryWriterTransform : public Transform {
 public:
  BinaryWriterTransform(std::istream &in, std::ostream &out, bool formatted)
      : Transform(in, out, formatted) {}
  virtual ~BinaryWriterTransform() {}
};
#endif
