#pragma once
#ifndef _RUNTASKS_H_
#define _RUNTASKS_H_

#include "task.h"
#include <utility>
#include <vector>
#include <ctime>

class RunTasks {

public:

	RunTasks();

	void exec();

private:

	//date time holding variables
	std::time_t now;
	tm *ltm;

	std::vector<Task> allTasks;

	int menu(std::pair<int, int>& __minmax);

	void createNewTask(void);

	void createNewTask(std::vector<Task> &inctasks);

	void viewAllTasks(void);

	void viewHighestPriorityTask(void);

	void printCurrentTime(void);

	//To build...
	void markTaskComplete(const std::size_t loc);

	void cleanTaskList(void);  //prompt removal of all out of date tasks

	void removeTask(const std::string taskname);

	void loadTasklist(const std::string filename);

	void saveTasklist(const std::string filename);



};

#endif
