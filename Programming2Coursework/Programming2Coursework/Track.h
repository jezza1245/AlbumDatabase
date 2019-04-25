#ifndef TRACK_H
#define TRACK_H

#include <string>
#include "Duration.h"
#include "StringTrimmer.h"
/*
	Stores title and duration 
*/
class Track
{
	std::string title;
	Duration duration;

public:
	Track(std::string p_title, Duration p_duration);
	Track(const Track& t); //Copy Constructor
	Track();

	std::string getTitle() const;
	Duration getDuration() const;
	void setTitle(std::string newTitle);
	void setDuration(Duration newDuration);

	Track& operator=(const Track &t) { //Copy assignment operator
		if (this != &t) {
			title = t.title;
			duration = t.duration;
		}
		return *this;
	} 

};

//---------------- Constructors ---------------------------
inline Track::Track(std::string p_title, Duration p_duration)
{
	title = p_title;
	TrimSides(title); //Removes any un-necessary whitespace from either side of string
	duration = p_duration;
}
inline Track::Track(const Track & t) //Copy Constructor
{
	title = t.title;
	duration = t.duration;
}
inline Track::Track() //Default Constructor
{
	title = "N/A";
	duration = Duration();
}

//------------ Getters and Setters ----------------
inline std::string Track::getTitle() const {
	return title;
}
inline Duration Track::getDuration() const {
	return duration;
}
inline void Track::setTitle(std::string newTitle) {
	title = newTitle;
}
inline void Track::setDuration(Duration newDuration){
	duration = newDuration;
}

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
inline bool operator==(const Track& t1, const Track& t2) { // ==
	return (t1.getTitle() == t2.getTitle() && t1.getDuration() == t2.getDuration());
}
inline bool operator!=(const Track& t1, const Track& t2) { // !=
	return !(t1 == t2);
}
inline std::ostream& operator<<(std::ostream& out, const Track& t) // Output
{
	// -> hh:mm:ss - theTitle
	return out << t.getDuration() << " - " << t.getTitle();
}

std::istream& operator>>(std::istream& in, Track& t);

#endif /*TRACK_H*/


