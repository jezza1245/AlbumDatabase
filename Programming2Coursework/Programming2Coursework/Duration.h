#ifndef DURATION_H
#define DURATION_H

#include <exception>
#include <iomanip>

class Duration {

	int hours, minutes, seconds;

public:
	Duration(int hours, int minutes, int seconds);
	Duration(int totalSeconds);
	Duration();

	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;

	operator int() const;

	void print();

	struct DurationConstructorException;
};

/*-------------- Constructor Exception Class-----------------
	Called if incorrect values entered in constructor eg. negative numbers
*/
struct Duration::DurationConstructorException : public std::exception {
	const char* what() const throw () {
		return "Invalid Constructor Parameters";
	}
};

//---------------- Constructors ---------------------------

inline Duration::Duration(int p_hours, int p_minutes, int p_seconds) {
	if (p_hours < 0 || p_minutes < 0 || p_seconds < 0) { //If negative duration field, throw exception
		throw DurationConstructorException();
	}

	int totalSeconds = p_hours * 3600 + p_minutes * 60 + p_seconds; //Get as seconds
	this->hours = totalSeconds / 3600; // Set hours
	int remainder = totalSeconds % 3600; // Keep track of seconds not accounted for
	this->minutes = remainder / 60; // Set minutes
	remainder = remainder % 60; // Update remainder
	this->seconds = remainder; // Set seconds
}


inline Duration::Duration(int totalSeconds) {
	if (totalSeconds < 0) { //If negative duration field, throw exception
		throw DurationConstructorException();
	}
	if (totalSeconds == 0)
	{
		Duration();
	}
	else
	{
		this->hours = totalSeconds / 3600; // Set hours
		int remainder = totalSeconds % 3600; // Keep track of seconds not accounted for
		this->minutes = remainder / 60; // Set minutes
		remainder = remainder % 60; // Update remainder
		this->seconds = remainder; // Set seconds
	}
}

inline Duration::Duration()
{
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
}

//------------ Getters and Setters ----------------

inline int Duration::getHours() const {
	return hours;
}
inline int Duration::getMinutes() const {
	return minutes;
}
inline int Duration::getSeconds() const {
	return seconds;
}


// -------------- Class Methods ------------------



// ------------- Operator Overloading -------------
inline bool operator==(const Duration& d1, const Duration& d2) { // ==
	return static_cast<int>(d1) == static_cast<int>(d2);
}
inline bool operator!=(const Duration& d1, const Duration& d2) { // !=
	return !(d1 == d2);
}
inline int operator-(const Duration& d1, const Duration& d2) { // -
	return static_cast<int>(d1) - static_cast<int>(d2);
}
inline int operator+(const Duration& d1, const Duration& d2) { // +
	return static_cast<int>(d1) + static_cast<int>(d2);
}
inline void operator-=(Duration& d1, const Duration& d2) { // -=
	d1 = Duration(static_cast<int>(d1) - static_cast<int>(d2));
}
inline void operator+=(Duration& d1, const Duration& d2) { // +=
	d1 = Duration(static_cast<int>(d1) + static_cast<int>(d2));
}
inline int operator<(const Duration& d1, const Duration& d2) { // <
	return static_cast<int>(d1) < static_cast<int>(d2);
}
inline int operator>(const Duration& d1, const Duration& d2) { // >
	return static_cast<int>(d1) > static_cast<int>(d2);
}
inline int operator>=(const Duration& d1, const Duration& d2) { // >=
	return !(d1 < d2);
}
inline int operator<=(const Duration& d1, const Duration& d2) { // <=
	return !(d1 > d2);
}

inline std::ostream& operator<<(std::ostream& out, const Duration &d)
{
	// Output -> hh:mm:ss
	return out << std::setfill('0') << std::setw(2) << d.getHours() << ":" <<
		std::setfill('0') << std::setw(2) << d.getMinutes() << ":" <<
		std::setfill('0') << std::setw(2) << d.getSeconds();
}
std::istream& operator>>(std::istream& is, Duration& d);

#endif /*DURATION_H*/
