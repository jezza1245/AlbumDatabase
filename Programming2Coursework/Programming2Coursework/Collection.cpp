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

Duration Collection::getTotalArtistPlayTime(std::string artist)
{
	Duration totalDuration;
	for (Album a : albums)
	{
		//std::cout << a.getArtist() << a.getArtist().length() << " : " << artist << std::endl;
		if (a.getArtist() == artist)
		{
			//std::cout << "MATCH!" << std::endl;
			totalDuration += a.getTotalLength();
		}
	}
	return totalDuration;
}

Album Collection::getAlbumWithMostTracks() {
	Album largestAlbum = albums.at(0);
	for (Album album : albums) {
		//std::cout << album << std::endl;
		if (album > largestAlbum) {
			largestAlbum = album;
		}
	}

	return largestAlbum;
}


void Collection::sortAlbums(bool (*f)(const Album& a1, const Album& a2))//F compare
{
	std::sort(albums.begin(), albums.end(), f);
}


void Collection::displayAlbums(bool(*f)(const Album& a1, const Album& a2))
{
	sortAlbums(f);
	std::cout << *this;
}


