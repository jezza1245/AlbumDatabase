#include "Album.h"
#include <algorithm> 
#include <locale>
#include <string>

std::ostream& operator<<(std::ostream& out, const Album &a) //Output
{
	std::vector<Track*> tracks = a.getTracks();

	/*
		-> artist : title
			track
			track
			track
			...
	*/

	out << a.getArtist() << " -> " << a.getTitle()
		<< " (" << a.getNumSongs() << " tracks - "
		<< a.getTotalLength() << ")" << std::endl;

	for (Track* track : tracks)
	{
		out << "\t" << *track << std::endl;
	}

	return out;
}
std::istream& operator>>(std::istream& in, Album& a) //Input
{
	char line[64], artist[64], title[64];

	// Get Album Meta-Data
	in.getline(artist, 64, ':');
	in.getline(title, 64, '\n');
	a = Album(title, artist);

	/* 
		-> artist : title
			track
			track
			track
			...
	*/

	// Get Tracks
	while (!in.eof()) //Check input stream is not finished
	{
		Track *t = new Track();
		if (in >> *t) //Atempt to read in track
		{
			a.addTrack(t); //Add track to album
		}
		else //Could not read as track
		{
			in.clear(); //Reset failbit to true from track >>
			delete t;
			return in;
		}
	}
	in.clear(std::ios_base::eofbit); //If reached EOF, set eofbit

	return in;
}
 /*
	Returns a pointer to the longest track that appears in the album
 */
Track* Album::getLongestTrack() const
{
	Track* longest = tracks.at(0); //Point to first track
	for (Track* track : tracks)
	{
		if (*track > *longest) //If track is longer than current largest
		{
			longest = track; //Re-direct pointer
		}
	}
	return longest;	//return pointer to longest track
}

/*
	Returns length of album as a Duration
*/
Duration Album::getTotalLength() const
{
	Duration d; //Default duration of 00:00:00
	for (Track* t : tracks) //Add all track durations to d
	{
		d += t->getDuration();
	}
	return d;
}

bool Album::ascending(const Album* a1, const Album* a2) //Alphabetically asc
{
	if (a1->getArtist() == a2->getArtist()) //If same artist
	{
		return (a1->getTitle() < a2->getTitle()); //Return difference in title
	}
	return (a1->getArtist() < a2->getArtist()); // else Return difference in artist
}

bool Album::descending(const Album* a1, const Album* a2) //Alphabetically desc
{
	if (a1->getArtist() == a2->getArtist()) //If same artist
	{
		return (a1->getTitle() > a2->getTitle()); //Return difference in title
	}
	return (a1->getArtist() > a2->getArtist());  // else Return difference in artist
}
