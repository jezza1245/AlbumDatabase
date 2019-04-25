#include "Track.h"


std::istream& operator>>(std::istream& in, Track& t) //Input
{
	char delimiter;
	Duration d;
	char title[256];

	// -> duration - title  eg. 00:12:42 - titleHere

	//Read input stream into duration and delimiter
	if (in >> d >> delimiter)
	{
		if (delimiter == '-') //If correct delimiter,assume rest of line it title
		{
			in.getline(title, 256, '\n'); //Get rest of line as title
			std::string str_title = title;
			t = Track(str_title, d);
		}
		else //Not correct format for track, set failbit
		{
			in.clear(std::ios_base::failbit);
		}
	}

	return in;
}
