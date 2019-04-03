#include "Duration.h"
#include <iostream>

//Static cast Duration into Integer for use in Operators
Duration::operator int() const {
	return (hours * 3600 + minutes * 60 + seconds);
}

//Output Stream operator
std::istream& operator>>(std::istream& in, Duration& d)
{
	char delimiter; //Expected delimiter
	int hours, minutes, seconds; //Duration Fields

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
