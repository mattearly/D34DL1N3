#include "task.h"

	Task::Task(std::string taskname, Date due_date){
		
		
	}
	Task::operator< (Task & compare){
		this.due_date < compare.due_date ? true : false;
	}