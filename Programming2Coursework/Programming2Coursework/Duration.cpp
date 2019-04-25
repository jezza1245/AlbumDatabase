#include "Duration.h"
#include <iostream>

//Static cast Duration into Integer for use in Operators
Duration::operator int() const {
	return (hours * 3600 + minutes * 60 + seconds);
}

std::istream& operator>>(std::istream& in, Duration& d)//Input
{
	char delimiter; //Expected delimiter
	int hours, minutes, seconds; //Duration Fields

	// -> hours:minutes:seconds eg. 00:12:42

	//Read from inputstream to fields
	if (in >> hours >> delimiter >> minutes >> delimiter >> seconds)
	{
		if (delimiter == ':') //If correct delimiter, Initialise Duration
		{
			d = Duration(hours, minutes, seconds);
		}
		else //Could not read as Duration, set failbit
		{
			in.clear(std::ios_base::failbit);
		}
	}

	return in;
}
