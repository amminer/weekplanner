#pragma once

#include "EventList.h"
#include <math.h> //pow()
#include <list> //have to use something other than vector for asgmt2.
//In reality using a list here is kind of silly; internally it's
//implemented as a DLL, so you get constant time insertion and removal
//but slow lookup. We barely ever have to add or remove elements (weeks)
//to the planner compared to how often we have to look them up,
//so something with constant time lookup like a dynamic array
//might make more sense; vector is implemented as a dynamic array,

/* Amelia Miner
 * 05/08/2022
 * cs 202 section 003
 * PROGRAM #:	2
 * FILE:		Planner.h
 * PURPOSE: 	Uses std::list to maintain a collection 
 *				of EventLists representing consecutive weeks.
 *				Handles basic user I/O,
 *				scheduling conflicts are handled on a weekly
 *				basis inside class EventList.
 */

class Planner
{
	public:
		Planner(void); //called by main loop
		//default destructor and cpy constr are ok, no dyn mem

		size_t size(void) const;		//returns number of weeks in planner
		void add_weeks(const size_t);	 		//add pages to the planner
		void print_week(const size_t); 		//print week specified by number
		void add_event(const size_t);	 		//adds an event to the week specified
		void remove_event(const size_t); 		//user prompted for name of event to remove

	private:
		list<EventList> weeks;

		EventList* week(const size_t); //access by weeknum
};
