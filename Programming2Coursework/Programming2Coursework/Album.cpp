#include "Album.h"
#include <algorithm> 
#include <locale>
#include "StringTrimmer.h"
#include <string>

std::ostream& operator<<(std::ostream& out, const Album &a)
{
	std::vector<Track> tracks = a.getTracks();
	out << a.getArtist() << " -> " << a.getTitle()
		<< " (" << a.getNumSongs() << " tracks - "
		<< a.getTotalLength() << ")" << std::endl;
	for (Track track : tracks)
	{
		out << "\t" << track << std::endl;
	}

	return out;
}
std::istream& operator>>(std::istream& in, Album& a)
{
	char line[64], artist[64], title[64];

	// Get Album Meta-Data
	in.getline(artist, 64, ':');
	in.getline(title, 64, '\n');
	std::string str_artist = artist;
	std::string str_title = title;
	TrimSides(str_artist);
	TrimSides(str_title);
	a = Album(str_title, str_artist);

	// Get Tracks
	while (!in.eof()) //Check input stream is not finished
	{
		Track t;
		if (in >> t) //Atempt to read in track
		{
			a.addTrack(t); //Add track to album
		}
		else //Could not read as track
		{
			in.clear(); //Reset failbit to true from track >>
			return in;
		}
	}
	in.clear(std::ios_base::eofbit); //If reached EOF, set eofbit

	return in;
}

Track Album::getLongestTrack() const
{
	Track longest;
	for (Track track : tracks)
	{
		if (track > longest)
		{
			longest = track;
		}
	}
	return longest;
}

Duration Album::getTotalLength() const
{
	Duration d;
	for (Track t : tracks)
	{
		d += t.getDuration();
	}
	return d;
}

bool Album::ascending(const Album& a1, const Album& a2)
{
	if (a1.getArtist() == a2.getArtist())
	{
		return (a1.getTitle() < a2.getTitle());
	}
	return (a1.getArtist() < a2.getArtist());
}

bool Album::descending(const Album& a1, const Album& a2)
{
	if (a1.getArtist() == a2.getArtist())
	{
		return (a1.getTitle() > a2.getTitle());
	}
	return (a1.getArtist() > a2.getArtist());
}
