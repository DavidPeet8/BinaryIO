#include "transform.h"

#include <iostream>

class AsciiToBinTransform final : public Transform
{
public:
	AsciiToBinTransform(std::istream &in, std::ostream &out, bool formatted):
	Transform(in, out, formatted) {}

private:
	void getAndWriteByte() override;
};