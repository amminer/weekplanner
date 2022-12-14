#pragma once

#include <iostream>
#include <exception>
#include <locale>
#include <sstream>
#include <regex>

using namespace std;
typedef unsigned int uint;

/* Amelia Miner
 * 04/29/22
 * cs 202 section 003
 * PROGRAM #:	2
 * FILE:		WeekdayTime.h
 * PURPOSE: 	Class WeekdayTime is composed of an enum to
 *				represent the day of the week and an int to
 *				represent the minute of the day.
 *				WeekdayTimes are meant to represent only one point
 *				in time, to be used as the start or stop value for
 *				class Event.
 */

/*	exceptions used for I/O handling	*/
//inherit from runtime_error, subtypes all in block below hub exception

//superclass to catch either subclass of error
struct time_exception: public runtime_error
{
	time_exception(const string& new_message="");
};
//inherits time_exception
struct start_greater_than_stop: public time_exception
{
	start_greater_than_stop(const string& new_message="");
};
//inherits time_exception
struct stop_less_than_start: public time_exception
{
	stop_less_than_start(const string& new_message="");
};

struct string_is_not_weekday: public runtime_error
{
	string_is_not_weekday(const string& new_message="");
};

struct string_is_not_time: public runtime_error
{
	string_is_not_time(const string& new_message="");
};

//week starts on Sunday, should maybe change to monday? Going to be important later
enum Weekday{sunday, monday, tuesday, wednesday, thursday, friday, saturday};

//weekday-related functions in global namespace
string weekday_to_string(const Weekday);
Weekday string_to_weekday(const string&);
uint hhmm_to_m(int, int);
string m_to_hhmm(uint, int=0);
uint string_to_min(string);

class WeekdayTime
{
	public:
		WeekdayTime(void);
		WeekdayTime(const string, const int, const int); //this constructor is called with user input;
		WeekdayTime(const string, const int);	   //the following constructors are analogous but
		WeekdayTime(const Weekday, const int, const int);//used internally (in class Event)
		WeekdayTime(const Weekday, const int);

		bool operator==(const WeekdayTime&) const; //check for overlapping times
		bool operator!=(const WeekdayTime&) const; //see above
		bool operator< (const WeekdayTime&) const; //op1 before 
		bool operator<=(const WeekdayTime&) const; //op1 before  with overlap (?)
		bool operator> (const WeekdayTime&) const; //op1 after 
		bool operator>=(const WeekdayTime&) const; //op1 after  with overlap (?)

		friend ostream& operator<<(ostream&, const WeekdayTime&);
		friend istream& operator>>(istream&, WeekdayTime&);

	private:
		Weekday weekday;
		uint minute;
};
