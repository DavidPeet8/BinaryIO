#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "streamer.h"

#include <iostream>

class Transform 
{
	Streamer streamer;
public:
	Transform(std::istream &in, std::ostream &out, bool formatted):
	streamer(in, out, formatted) {}

	void process()
	{
		while (!streamer.fail())
		{
			getAndWriteByte();
		}
	}

	virtual ~Transform() {};

protected:
	Streamer &Out() { return streamer; }
	Streamer &In() { return streamer; }

private:
	virtual void getAndWriteByte() = 0;
};

#endif