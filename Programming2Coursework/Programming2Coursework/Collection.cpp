#include "collection.h"
#include <algorithm>

std::ostream& operator<<(std::ostream& out, const Collection &c)
{
	std::vector<Album> albs = c.getAlbums();
	for (Album album : albs)
	{
		out << album;
	}
	return out;
}
std::istream& operator>>(std::istream& in, Collection &c)
{
	char line[256];

	Album a;
	while (!in.eof())
	{
		if (in >> a)
		{
			c.addAlbum(a);
		}
		else
		{
			in.clear();
			return in;
		}
	}
	return in;
}

Duration Collection::totalArtistPlayTime(std::string artist)
{
	Duration totalDuration;
	for (Album a : albums)
	{
		std::cout << a.getArtist() << a.getArtist().length() << " : " << artist << std::endl;
		if (a.getArtist() == artist)
		{
			std::cout << "MATCH!" << std::endl;
			totalDuration += a.getTotalLength();
		}
	}
	return totalDuration;
}


void Collection::sortAlbums()//F compare
{
	std::sort(albums.begin(), albums.end(), Album::ascending);
}


void Collection::displayAlbums()
{
	sortAlbums();
	std::cout << *this;
}


