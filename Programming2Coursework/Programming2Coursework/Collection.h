#ifndef Collection_H
#define Collection_H

#include <vector>
#include "Album.h"

class Collection
{
	std::vector<Album*> albums;

public:
	Collection();
	Collection(std::vector<Album*> albs);
	~Collection();

	std::vector<Album*> getAlbums() const;
	void addAlbum(Album *a);

	void sortAlbums(bool(*f)(const Album* a1, const Album* a2)); //f == compare function
	void displayAlbums(bool(*f)(const Album* a1, const Album* a2)); //f == compare function
	Duration getTotalArtistPlayTime(std::string artist); //works
	Album getAlbumWithMostTracks();
	Track getLongestTrack();

};

//------------------- Constructors -----------------------
inline Collection::Collection()
{
	albums = std::vector<Album*>();
}
inline Collection::Collection(std::vector<Album*> albs)
{
	albums = albs;
}
inline Collection::~Collection() {
	for (Album* a : albums) {
		delete a;
	}
	albums.clear();
}


//--------------- Getters and Setters ------------------
inline std::vector<Album*> Collection::getAlbums() const {
	return albums;
}

inline void Collection::addAlbum(Album *a)
{
	albums.push_back(a);
}


std::ostream& operator<<(std::ostream& out, const Collection &c);
std::istream& operator>>(std::istream& in, Collection &c);
#endif /*Collection_H*/