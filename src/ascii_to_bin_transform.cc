#include "ascii_to_bin_transform.h"

void AsciiToBinTransform::getAndWriteByte()
{
	char c;
	for (int i = 0; i < 8;)
	{
		In() >> c;
		if (!isspace(c))
		{
			Out() << (c == '0' ? '0' : '1');
			i++;
		}
	}
	Out() << "\n";
}