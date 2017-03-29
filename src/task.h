#pragma once
#ifndef _TASK_H_
#define _TASK_H_
#include "date.h"

class Task {
public:
	Task() : taskName(""), dueDate(), complete(false), pastDue(false) {}
	Task(std::string n, Date due) : taskName(n), dueDate(due), complete(false), pastDue(false) {}

	//accessors
	std::string getName(void) { return taskName; }
	Date getRawDate(void) const { return dueDate; }
	int getMonth(void) const { return dueDate.getMonth(); }
	int getDay(void) const { return dueDate.getDay(); }
	int getYear(void) const { return dueDate.getYear(); }
	int getHour(void) const { return dueDate.getHour(); }
	int getMinute(void) const { return dueDate.getMinute(); }
private:
	std::string taskName;
	Date dueDate;
	bool complete;
	bool pastDue;
};


#endif