#pragma once
#ifndef _TASK_H_
#define _TASK_H_
#include "date.h"

class Task {
public:
	void New_Task(std::string taskname, Date due_date);
	operator< (Task & compare);
	
private:
	Date due_date;
	Task(){};
}


#endif
