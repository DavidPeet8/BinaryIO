#include "transform.h"

#include <iostream>

class BinToAsciiTransform final : public Transform
{
public:
	BinToAsciiTransform(std::istream &in, std::ostream &out, bool formatted): 
	Transform(in, out, formatted) {}

private:
	void getAndWriteByte() override;
};