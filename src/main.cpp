#include "runtask.h"
int main(const int argv, const char argc[][]) {
	bool runtimestatus = true;

	RunTask run;
	runtimestatus = run.exec();

	return runtimestatus;
}
