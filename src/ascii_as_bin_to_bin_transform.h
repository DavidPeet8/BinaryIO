#include <iostream>

#include "transform.h"

class AsciiAsBinToBinTransform final : public Transform {
 public:
  AsciiAsBinToBinTransform(std::istream &in, std::ostream &out, bool formatted)
      : Transform(in, out, formatted) {}

 private:
  void getAndWriteByte() override;
};
