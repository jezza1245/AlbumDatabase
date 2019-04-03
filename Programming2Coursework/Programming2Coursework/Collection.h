#ifndef Collection_H
#define Collection_H

#include <vector>
#include "Album.h"

class Collection
{
	std::vector<Album> albums;

public:
	Collection();
	Collection(std::vector<Album> albs);

	std::vector<Album> getAlbums() const;
	void addAlbum(Album a);

	void sortAlbums();
	void displayAlbums();
	Duration totalArtistPlayTime(std::string artist);

};

inline Collection::Collection()
{
	this->albums = std::vector<Album>();
}

inline Collection::Collection(std::vector<Album> albs)
{
	this->albums = albs;
}

inline std::vector<Album> Collection::getAlbums() const {
	return this->albums;
}

inline void Collection::addAlbum(Album a)
{
	this->albums.push_back(a);
}


std::ostream& operator<<(std::ostream& out, const Collection &c);
std::istream& operator>>(std::istream& in, Collection &c);
#endif /*Collection_H*/