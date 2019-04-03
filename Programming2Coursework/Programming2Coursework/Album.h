#ifndef Album_H
#define Album_H

#include <string>
#include <vector>
#include "Track.h"
#include <iostream>

class Album
{
	std::string title;
	std::string artist;
	std::vector<Track> tracks;

public:
	Album();
	Album(std::string p_title, std::string p_artist);
	Album(std::string p_title, std::string p_artist, std::vector<Track> p_tracks);

	std::string getTitle() const;
	std::string getArtist() const;
	std::vector<Track> getTracks() const;

	void addTrack(Track& t);
	int getNumSongs() const;
	Track *getLongestTrack() const;
	Duration getTotalLength() const;

	static bool ascending(const Album& a1, const Album& a2);
	static bool descending(const Album& a1, const Album& a2);
};

//------------- Constructors --------------------------------
inline Album::Album()
{
	this->title = "N/A";
	this->artist = "N/A";
	this->tracks = std::vector<Track>();
}
inline Album::Album(std::string p_title, std::string p_artist)
{
	this->title = p_title;
	this->artist = p_artist;
	this->tracks = std::vector<Track>();
}
inline Album::Album(std::string p_title, std::string p_artist, std::vector<Track> p_tracks)
{
	this->title = p_title;
	this->artist = p_artist;
	this->tracks = p_tracks;
}

//------------------- Getters & Setters -------------------------------
inline std::string Album::getTitle() const {
	return title;
}
inline std::string Album::getArtist() const {
	return artist;
}
inline std::vector<Track> Album::getTracks() const {
	return tracks;
}
inline int Album::getNumSongs() const {
	return (int)tracks.size();
}

//-------------------- General Methods ------------------------------
inline void Album::addTrack(Track &t)
{
	this->tracks.push_back(t);
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
inline bool operator==(const Album& a1, const Album& a2) { // <=
	return a1.getNumSongs() == a2.getNumSongs();
}
inline bool operator!=(const Album& a1, const Album& a2) { // <=
	return !(a1 == a2);
}

std::ostream& operator<<(std::ostream& out, const Album &a);
std::istream& operator>>(std::istream& in, Album &a);



#endif /*Album_H*/