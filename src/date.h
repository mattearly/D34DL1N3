#pragma once
#ifndef _DATE_H_
#define _DATE_H_

#include <string>

class Date {
public:
	Date(int mm, int dd, int yyyy) : month(mm), day(dd), year(yyyy) {}
	Date() : month(-1), day(-1), year(-1) {}
	~Date(){}

	//mutators
	void set_month(int mm);
	void set_day(int dd);
	void set_year(int yyyy);

	//accessors
	int getMonth(void) const { return month; }
	int getDay(void) const { return day; }
	int getYear(void) const { return year; }

	friend bool operator< (const Date& lhs, const Date& rhs);

private:

	int month, day, year;

protected:

};



#endif

