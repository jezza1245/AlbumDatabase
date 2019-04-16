#ifndef TRACK_H
#define TRACK_H

#include <string>
#include "Duration.h"
/*
	Stores title and duration 
*/
class Track
{
	std::string title;
	Duration duration;

public:
	Track(std::string p_title, Duration p_duration);
	Track();

	std::string getTitle() const;
	Duration getDuration() const;
	void setTitle(std::string newTitle);
	void setDuration(Duration newDuration);

};

//---------------- Constructors ---------------------------
inline Track::Track(std::string p_title, Duration p_duration)
{
	this->title = p_title;
	this->duration = p_duration;
}
inline Track::Track() //Default Constructor
{
	this->title = "N/A";
	this->duration = Duration();
}

//------------ Getters and Setters ----------------
inline std::string Track::getTitle() const {
	return this->title;
}
inline Duration Track::getDuration() const {
	return this->duration;
}
inline void Track::setTitle(std::string newTitle) {
	this->title = newTitle;
}
inline void Track::setDuration(Duration newDuration){
	this->duration = newDuration;
}

// -------------- Class Methods ------------------


// ------------- Operator Overloading -------------
inline int operator<(const Track& t1, const Track& t2) { // <
	return t1.getDuration() < t2.getDuration();
}
inline int operator>(const Track& t1, const Track& t2) { // >
	return t1.getDuration() > t2.getDuration();
}
inline int operator>=(const Track& t1, const Track& t2) { // >=
	return !(t1 < t2);
}
inline int operator<=(const Track& t1, const Track& t2) { // <=
	return !(t1 > t2);
}
inline bool operator==(const Track& t1, const Track& t2) { // <=
	return (t1.getTitle() == t2.getTitle() && t1.getDuration() == t2.getDuration());
}
inline bool operator!=(const Track& t1, const Track& t2) { // <=
	return !(t1 == t2);
}
inline std::ostream& operator<<(std::ostream& out, const Track& t)
{
	return out << t.getTitle() << "[" << t.getDuration() << "]";
}

std::istream& operator>>(std::istream& in, Track& t);

#endif /*TRACK_H*/


