#pragma once
#ifndef _TASK_H_
#define _TASK_H_
#include "date.h"


class Task {
public:
	Task() : taskName(""), dueDate(), complete(false), pastDue(false) {}
	Task(std::string n, Date due) : taskName(n), dueDate(due), complete(false), pastDue(false) {}

	//mutators
	void setName(std::string newname) { taskName = newname; }
	void setMonth(int mm) { dueDate.set_month(mm); }
	void setDay(int dd) { dueDate.set_day(dd); }
	void setYear(int yyyy) { dueDate.set_year(yyyy); }
	void setHour(int hh) { dueDate.set_hour(hh); }
	void setMinute(int mi) { dueDate.set_minute(mi); }

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
