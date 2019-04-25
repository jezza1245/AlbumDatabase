#include "collection.h"
#include <algorithm>

std::ostream& operator<<(std::ostream& out, const Collection &c) //Output
{
	std::vector<Album*> albs = c.getAlbums();
	for (Album *album : albs)
	{
		out << *album;
	}
	return out;
}
std::istream& operator>>(std::istream& in, Collection &c) //Input
{
	char line[256];

	while (!in.eof())
	{
		Album *a = new Album();
		if (in >> *a)
		{
			c.addAlbum(a);
		}
		else
		{
			in.clear();
			delete a;
			return in;
		}
	}
	return in;
}

/*
	Get total duration of all tracks of a given artist, in this collection
*/
Duration Collection::getTotalArtistPlayTime(std::string artist)
{
	Duration totalDuration;
	for (Album *a : albums) //For all albums
	{
		if (a->getArtist() == artist) //If artist is parameter add album length
		{
			totalDuration += a->getTotalLength();
		}
	}
	return totalDuration;
}

/*
	Returns a copy of the album with the most tracks
*/
Album Collection::getAlbumWithMostTracks() {
	Album *largestAlbum = albums.at(0);
	for (Album *album : albums){ 
		if (*album > *largestAlbum) {
			largestAlbum = album;
		}
	}
	return Album(*largestAlbum); //Create and Return copy of largest album
}

/*
	Return copy of the longest track in the collection
*/
Track Collection::getLongestTrack() {
	Track* longestTrack = albums.at(0)->getLongestTrack();
	for (Album *album : albums) {
		Track* t;
		if (*(t = album->getLongestTrack()) > *longestTrack) {
			longestTrack = t;
		}
	}
	return Track(*longestTrack);
}

/*
	Calls stl sort function for vector with function f
	f -> bool function that compares two albums
*/
void Collection::sortAlbums(bool (*f)(const Album* a1, const Album* a2))
{
	std::sort(albums.begin(), albums.end(), f);
}

/*
	Calls collection sort method, passing on f, which denotes how to sort,
	therefore how to display (order)
*/
void Collection::displayAlbums(bool(*f)(const Album* a1, const Album* a2))
{
	sortAlbums(f);
	std::cout << *this;
}


