#include "streamer.h"

Streamer &operator<<(Streamer &ostreamer, char t)
{
	ostreamer.getOStream() << t;
	if (ostreamer.isFormatted())
	{
		ostreamer.getOStream() << "\n";
	}
	return ostreamer;
}

Streamer &operator>>(Streamer &istreamer, char &t)
{
	istreamer.getIStream() >> t;
	return istreamer;
}