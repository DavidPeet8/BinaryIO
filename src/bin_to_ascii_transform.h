#include "transform.h"

#include <iostream>

class BinToAsciiTransform final : public Transform
{
public:
	BinToAsciiTransform(std::istream &in, std::ostream &out): 
	Transform(in, out) {}

private:
	void getAndWriteByte() override;
};