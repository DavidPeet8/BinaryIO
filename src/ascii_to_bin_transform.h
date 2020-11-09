#include "transform.h"

#include <iostream>

class AsciiToBinTransform final : public Transform
{
public:
	AsciiToBinTransform(std::istream &in, std::ostream &out):
	Transform(in, out) {}

private:
	void getAndWriteByte() override;
};