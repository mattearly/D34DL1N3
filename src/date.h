#pragma once
#ifndef _DATE_H_
#define _DATE_H_

#include <string>

class Date {
public:

	//compare dates
	friend bool operator< (const Date& lhs, const Date& rhs);

	//Valid clamping assumed to be done by input module
	Date(int mm, int dd, int yyyy) : month(mm), day(dd), year(yyyy), hour(0), minute(1) {}
	Date(int mm, int dd, int yyyy, int hh, int mi) : month(mm), day(dd), year(yyyy), hour(hh), minute(mi) {}

	//Non-initilized version
	Date() : month(-1), day(-1), year(-1) {}
	~Date(){}

	//mutators
	//Valid clamping assumed to be done by input module
	void set_month(int mm) { month = mm; }
	void set_day(int dd) { day = dd; }
	void set_year(int yyyy) { year = yyyy; }
	void set_hour(int hh) { hour = hh; }
	void set_minute(int mi) { minute = mi; }

	//accessors
	int getMonth(void) const { return month; }
	int getDay(void) const { return day; }
	int getYear(void) const { return year; }
	int getHour(void) const { return hour; }
	int getMinute(void) const { return minute; }

private:

	int month, day, year;
	int hour, minute;

protected:

};




#endif

