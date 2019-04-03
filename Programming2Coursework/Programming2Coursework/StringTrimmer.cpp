#include <string>
#include "StringTrimmer.h"
#include <iostream>

void TrimSides(std::string& str)
{
	int i = 0;

	while (str.at(i) == ' ')
		i++;

	int j = str.length() - 1;

	while (str.at(j) == ' ')
		j--;

	str = str.substr(i, j - i + 1);

}

