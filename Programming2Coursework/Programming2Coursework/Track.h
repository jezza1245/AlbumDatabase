#ifndef TRACK_H
#define TRACK_H

#include <string>
#include "Duration.h"

class Track
{
	std::string title;
	Duration duration;

public:
	Track(std::string p_title, Duration p_duration);
	Track();

	std::string getTitle() const;
	Duration getDuration() const;

};

//---------------- Constructors ---------------------------
inline Track::Track(std::string p_title, Duration p_duration)
{
	this->title = p_title;
	this->duration = p_duration;
}
inline Track::Track()
{
	this->title = "N/A";
	this->duration = Duration(0, 0, 0);
}

//------------ Getters and Setters ----------------
inline std::string Track::getTitle() const {
	return this->title;
}
inline Duration Track::getDuration() const {
	return this->duration;
}

// -------------- Class Methods ------------------


// ------------- Operator Overloading -------------
inline std::ostream& operator<<(std::ostream& out, const Track& t)
{
	return out << t.getTitle() << "[" << t.getDuration() << "]";
}

std::istream& operator>>(std::istream& in, Track& t);

#endif /*TRACK_H*/


