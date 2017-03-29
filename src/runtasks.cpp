#include "runtasks.h"
#include "helper.h"
#include <iomanip>
#include <iostream>

using namespace std;


bool operator< (const Date& lhs, const Date& rhs) {
	if (lhs.year <= rhs.year) {
		if (lhs.year < rhs.year) {
			return true;  //year of left hand side is less
		} else {  //years are equal, check month
			if (lhs.month <= rhs.month) {
				if (lhs.month < rhs.month) {
					return true;  //month of left hand side is less
				} else if (lhs.day <= rhs.day) {  //months are equal check day
					if (lhs.day < rhs.day) {
						return true;  //left hand side day is sooner
					} else { //days are equal, check hours
						if (lhs.hour <= rhs.hour) {
							if (lhs.hour < rhs.hour) {
								return true;  //lhs is sooner
							} else {  //hours are the same, check minutes
								if (lhs.minute <= rhs.minute) {
									return true;  //lhs is sooner
								}
							}
						}
					}
				}
			}
		}
	}
	return false;  //rhs is less or lhs == rhs
}

RunTasks::RunTasks() {  //set local system time at initial run
	now = time(0);
	ltm = localtime(&now);

}

void RunTasks::exec() {
	int choice = 0;
	pair<int, int> choice_minmax(0,5);
	do {
		choice = menu(choice_minmax);
		switch (choice) {
		case 0:
			createNewTask();
			break;
		case 1:
			viewAllTasks();
			break;
		case 2:
			viewHighestPriorityTask();
			break;
		case 3:
			saveTasklist("testsave1");
			break;
		case 4:
			loadTasklist("testsave1");
			break;
		case 5:
			cout << "\n\nGoodBye" << endl;
			break;
		default: break;
		}
	} while (choice != choice_minmax.second);
}


int RunTasks::menu(pair<int, int>& __minmax) {
	clearTerminalScreen();
	printCurrentTime();
	cout << endl;
	cout << "Main Menu\n"
		 << "0. New Task " << endl
		 << "1. View Tasks" << endl
		 << "2. Highest Priority Task" << endl
		 << "3. Save" << endl
		 << "4. Load" << endl
		 << "5. Quit" << endl
		 << "  Choice: ";
	return (getNumber(__minmax.first, __minmax.second));
}

//prompt user via the terminal for a new task entry
void RunTasks::createNewTask() {
	//update time
	now = time(0);
	tm *ltm = localtime(&now);

	clearTerminalScreen();
	string tmpname;
	int tmpmonth, tmpday, tmpyear, tmphour, tmpmin;

	cout << "\nEnter a task name: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, tmpname);

	cout << "\nTask Due Date";

	cout << "\nEnter year: ";
	tmpyear = getNumber(1900 + ltm->tm_year, 9999);

	cout << "\nEnter month: ";
	if (tmpyear == 1900 + ltm->tm_year) tmpmonth = getNumber(1 + ltm->tm_mon,12);
	else tmpmonth = getNumber(1, 12);

	cout << "\nEnter day: ";
	tmpday = getNumber(1,31);

	cout << "\nEnter Hour (24h format): ";
	tmphour = getNumber(0, 23);

	cout << "\nEnter Minute: ";
	tmpmin = getNumber(0, 59);

	Date tmpdate(tmpmonth, tmpday, tmpyear, tmphour, tmpmin);
	Task tmptask(tmpname, tmpdate);
	allTasks.push_back(tmptask);
}

//overloaded version to copy a full vector of already constructed tasks
void RunTasks::createNewTask(vector<Task> &inctasks) {
	allTasks = inctasks;
}


void RunTasks::viewAllTasks() {
	cout << endl;
	if (allTasks.size() < 1) {
		cout << "No Tasks on list.";
		pressEnterToContinue();
		return;
	}
	for (auto & it : allTasks) {
		cout << it.getName() << "\n   Due: "
			 << it.getMonth() << "/" << it.getDay() << "/" << it.getYear()
			 << " @ "
			 << setw(2) << std::setfill('0') << it.getHour()
			 << ":"
			 << setw(2) << std::setfill('0') << it.getMinute()
			 << endl;
	}
	pressEnterToContinue();
}


void RunTasks::viewHighestPriorityTask() {
	cout << endl;
	if (allTasks.size() < 1) {
		cout << "No Tasks on list.";
		pressEnterToContinue();
		return;
	} else if (allTasks.size() == 1) {
		cout << allTasks[0].getName() << "\n   Due: "
			 << allTasks[0].getMonth() << "/" << allTasks[0].getDay() << "/" << allTasks[0].getYear()
			 << " @ "
			 << setw(2) << std::setfill('0') << allTasks[0].getHour()
			 << ":"
			 << setw(2) << std::setfill('0') << allTasks[0].getMinute()
			 << endl;
		pressEnterToContinue();
		return;
	}

	int highestpri = 0;  //vector location of highest priority task found

	for (size_t i = 0; i < allTasks.size()-1; i++) {
		if (i == 0 && !(allTasks[i].getRawDate() < allTasks[i+1].getRawDate())) {
			highestpri = i+1;
		} else if (!(allTasks[highestpri].getRawDate() < allTasks[i+1].getRawDate())) {
			highestpri = i+1;
		}
	}
	cout << "Highest Priority: " << allTasks[highestpri].getName() << " "
		 << "Due: " << allTasks[highestpri].getMonth() << "/"
		 << allTasks[highestpri].getDay()
		 << "/" << allTasks[highestpri].getYear()
		 << " @ "
		 << setw(2) << std::setfill('0') << allTasks[highestpri].getHour()
		 << ":"
		 << setw(2) << std::setfill('0') << allTasks[highestpri].getMinute()
		 << endl;
	pressEnterToContinue();

}

void RunTasks::printCurrentTime() {
	//update time
	now = time(0);
	tm *ltm = localtime(&now);
	// print date
	cout << "system date: ";
	cout << setw(2) << std::setfill('0') << 1 + ltm->tm_mon << "/"
		 << setw(2) << std::setfill('0') << ltm->tm_mday << "/"
		 << setw(4) << std::setfill('0') << 1900 + ltm->tm_year << endl;
	// print local time
	cout << "system time: ";
	cout << setw(2) << std::setfill('0') << 1 + ltm->tm_hour << ":"
		 << setw(2) << std::setfill('0') << 1 + ltm->tm_min << ":"
		 << setw(2) << std::setfill('0') << 1 + ltm->tm_sec << endl;
}
