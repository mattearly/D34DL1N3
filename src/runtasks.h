#pragma once
#ifndef _RUNTASKS_H_
#define _RUNTASKS_H_

#include "task.h"
#include <utility>
#include <vector>

class RunTasks {

public:

	void exec(bool &);

private:

	std::vector<Task> allTasks;

	int menu(std::pair<int, int>& __minmax);
	void createNewTask();
	void viewAllTasks();
	void viewHighestPriorityTask();

};

#endif
