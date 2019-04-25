#ifndef Album_H
#define Album_H

#include <string>
#include <vector>
#include "Track.h"
#include <iostream>
#include "StringTrimmer.h"

class Album
{
	std::string title;
	std::string artist;
	std::vector<Track*> tracks; //Pointers to all tracks in the album

public:
	Album();
	Album(std::string p_title, std::string p_artist);
	Album(std::string p_title, std::string p_artist, std::vector<Track*> p_tracks);
	Album(const Album& album); //Copy Constructor
	~Album();

	std::string getTitle() const;
	std::string getArtist() const;
	std::vector<Track*> getTracks() const;

	void addTrack(Track* t);
	int getNumSongs() const;
	Track* getLongestTrack() const;
	Duration getTotalLength() const;

	static bool ascending(const Album* a1, const Album* a2); //Compare two albums alphabetically ascending
	static bool descending(const Album* a1, const Album* a2); //Compare two albums alphabetically descending

	Album& operator=(const Album &a) { //Copy assignment operator
		if (this != &a) { //Check album passed is a different album
			title = a.title;
			artist = a.artist;

			for (Track* t: tracks) { //Delete pointers in current track-list to prevent memory leak
				delete t;
			}
			tracks.clear(); //Empty vector

			for (Track* t : a.tracks) { //Add all track pointers from other album
				tracks.push_back(t);
			}
		}
		return *this;
	}
};

//------------- Constructors --------------------------------
inline Album::Album()
{
	title = "N/A";
	artist = "N/A";
	tracks = std::vector<Track*>();
}
inline Album::Album(std::string p_title, std::string p_artist)
{
	title = p_title;
	TrimSides(title); //Removes any un-necessary whitespace from either side of string
	artist = p_artist;
	TrimSides(artist);
	tracks = std::vector<Track*>();
}
inline Album::Album(std::string p_title, std::string p_artist, std::vector<Track*> p_tracks)
{
	title = p_title;
	TrimSides(title);
	artist = p_artist;
	TrimSides(artist);
	tracks = p_tracks;
}
inline Album::Album(const Album& album) { //Copy Constructor
	title = album.title;
	artist = album.artist;
	tracks = std::vector<Track*>();
	for (Track* t: album.tracks) { //Create new track in memory and point to
		Track* newT = new Track(*t);
		tracks.push_back(newT);
	}
}
inline Album::~Album() { //Destructor
	for (Track* t: tracks) { //Delete all track pointers
		delete t;
	}
	tracks.clear(); 
}

//------------------- Getters & Setters -------------------------------
inline std::string Album::getTitle() const {
	return title;
}
inline std::string Album::getArtist() const {
	return artist;
}
inline std::vector<Track*> Album::getTracks() const {
	return tracks;
}
inline int Album::getNumSongs() const {
	return (int)tracks.size();
}

//-------------------- General Methods ------------------------------
inline void Album::addTrack(Track *t)
{
	tracks.push_back(t);
}

//--------------------- Operators ------------------------------
inline int operator<(const Album& a1, const Album& a2) { // <
	return a1.getNumSongs() < a2.getNumSongs();
}
inline int operator>(const Album& a1, const Album& a2) { // >
	return a1.getNumSongs() > a2.getNumSongs();
}
inline int operator>=(const Album& a1, const Album& a2) { // >=
	return !(a1 < a2);
}
inline int operator<=(const Album& a1, const Album& a2) { // <=
	return !(a1 > a2);
}
inline bool operator==(const Album& a1, const Album& a2) { // ==
	return (a1.getArtist() == a2.getArtist() && a1.getTitle() == a2.getTitle());
}
inline bool operator!=(const Album& a1, const Album& a2) { // !=
	return !(a1 == a2);
}

std::ostream& operator<<(std::ostream& out, const Album &a);
std::istream& operator>>(std::istream& in, Album &a);



#endif /*Album_H*/