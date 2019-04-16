#include <string>
#include "StringTrimmer.h"
#include <iostream>

void TrimSides(std::string& str) //Removes whitespace from outsides of a string
{
	int i = 0;

	while (str.at(i) == ' ') // i = first non ' ' character in string
		i++;

	int j = str.length() - 1; 

	while (str.at(j) == ' ') // j = last non ' ' character in string
		j--;

	str = str.substr(i, j - i + 1); //get substring between i and j

}

