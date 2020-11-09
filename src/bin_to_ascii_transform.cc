#include "bin_to_ascii_transform.h"
#include "streamer.h"

void BinToAsciiTransform::getAndWriteByte()
{
	char c = 0;
	In() >> c;
	
	for (int i = 0; i < 8; i++)
	{
		Out() << (c % 2 ? '1' : '0');
		c /= 2;
	}
}