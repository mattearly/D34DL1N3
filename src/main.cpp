#include "runtasks.h"

int main() {

	bool runtimestatus = true;

	RunTasks run;
	run.exec(runtimestatus);

	return runtimestatus;

}
