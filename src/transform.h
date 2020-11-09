#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <iostream>

class Transform 
{
	std::ostream &out;
	std::istream &in;
public:
	Transform(std::istream & in, std::ostream &out):
	out {out},
	in{in} {}

	void process()
	{
		while (!in.fail())
		{
			getAndWriteByte();
		}
	}

	virtual ~Transform() {};

protected:
	std::ostream &Out() { return out; }
	std::istream &In() { return in; }

private:
	virtual void getAndWriteByte() = 0;
};

#endif