#ifndef BINARY_WRITER_TRANSFORM_H
#define BINARY_WRITER_TRANSFORM_H

#include "transform.h"

class BinaryWriterTransform : public Transform
{
public:
  BinaryWriterTransform(std::istream &in, std::ostream &out, bool formatted) :
      Transform(in, out, formatted)
  {}

  void process() override
  {
    while (!streamer.fail()) {
      getAndWriteByte(inRange());
      addr += read_size;
      if (pastEndAddr()) {
        break;
      }
    }
  }

  virtual ~BinaryWriterTransform() {}

private:
  // Read enough input data to write a single byte to output
  virtual void getAndWriteByte(bool inRange) = 0;
};
#endif
