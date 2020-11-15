#include <iostream>

#include "transform.h"

class BinToBinAsAsciiTransform final : public Transform {
 public:
  BinToBinAsAsciiTransform(std::istream &in, std::ostream &out, bool formatted)
      : Transform(in, out, formatted) {}

 private:
  void getAndWriteByte() override;
};
