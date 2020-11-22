#ifndef BINARY_READER_TRANSFORM_H
#define BINARY_READER_TRANSFORM_H

#include "transform.h"

class BinaryReaderTransform : public Transform
{
public:
  BinaryReaderTransform(std::istream &in, std::ostream &out, bool formatted) :
      Transform(in, out, formatted)
  {}

  void process() override
  {
    while (!streamer.fail()) {
      readAndTransformByte(inRange());
      addr += read_size;
      if (pastEndAddr()) {
        break;
      }
    }
  }

  virtual ~BinaryReaderTransform()
  {
    Out() << '\n';
  }

private:
  // Read in a single byte and transform it
  virtual void readAndTransformByte(bool inRange) = 0;
};
#endif
