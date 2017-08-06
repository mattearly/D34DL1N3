#include "runtasks.h"
#include "helper.h"
#include <iomanip>
#include <iostream>
#include <stdlib.h>

using namespace std;

RunTasks::RunTasks() {  //set local system time at initial run
	now = time(0);
	ltm = localtime(&now);
	user_dir = getenv("HOME");
	loadTasklist("testsave1");
}

void RunTasks::exec() {
	int choice = 0;
	pair<int, int> choice_minmax(0,9);
	do {
		choice = menu(choice_minmax);
		latestMessage = "\n";

		switch (choice) {
		case 1:
			createNewTask();
			latestMessage.insert(0, "New Task Created!");
			break;
		case 2:
			removeTask();
			break;
		case 3:
			viewAllTasks();
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			saveTasklist("testsave1");
			latestMessage.insert(0, "State Saved!");
		case 0:
			cout << "\n\nGoodBye\n";
			break;
		default:
			cout << "\nInvalid Choice\n";
			break;
		}
	} while (choice != 0);
}


int RunTasks::menu(pair<int, int>& __minmax) {
	clearTerminalScreen();
	viewHighestPriorityTask();
	cout << endl;
	printCurrentTime();
	cout << endl;
	cout << latestMessage
		 << "_____________Main Menu_____________\n"  << left
		 << setw(16) << "1. Add Task"      << " | " << "6. [placeholder]" << endl
		 << setw(16) << "2. Remove Task"   << " | " << "7. [placeholder]" << endl
		 << setw(16) << "3. See Tasks"     << " | " << "8. [placeholder]" << endl
		 << setw(16) << "4. [placeholder]" << " | " << "9. Save State" << endl
		 << setw(16) << "5. [placeholder]" << " | " << "0. Quit Program" << endl;
	return (getNumber("\n   Choice:  ", __minmax.first, __minmax.second));
}

//prompt user via the terminal for a new task entry
void RunTasks::createNewTask() {
	//update time
	now = time(0);
	tm *ltm = localtime(&now);

	clearTerminalScreen();
	string tmpname = "";
	int tmpmonth, tmpday, tmpyear, tmphour, tmpmin;

	do {
		cout << "\nEnter a task name: ";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, tmpname);
		tmpname = reduce(tmpname);  //tighen her up
	} while (tmpname.size() <= 1);  //cant imagine 1 character being enough to desribe a task...

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
			 << setw(2) << std::setfill('0') << right << it.getHour()
			 << ":"
			 << setw(2) << std::setfill('0') << right << it.getMinute()
			 << endl;
	}
	pressEnterToContinue();
}


void RunTasks::viewHighestPriorityTask() {
	cout << endl;
	if (allTasks.size() < 1) {
		cout << "No Tasks on list.\n";
		return;
	} else if (allTasks.size() == 1) {
		cout << "__________Priority Task__________\n" << allTasks[0].getName()
			 << "\n  Due: " << allTasks[0].getMonth() << "/"
			 << allTasks[0].getDay() << "/" << allTasks[0].getYear()
			 << " @ ";
		string AM_PM = "AM";
		int hour = allTasks[0].getHour();
		if (hour > 12) { hour = hour - 12; AM_PM = "PM"; }
		cout << hour << ":"
			 << setw(2) << std::setfill('0') << right << allTasks[0].getMinute()
			 << AM_PM << endl;
		return;
	} else {
		int highestpri = 0;  //vector location of highest priority task found
		for (size_t i = 0; i < allTasks.size()-1; i++) {
			if (i == 0 && !(allTasks[i].getRawDate() < allTasks[i+1].getRawDate())) {
				highestpri = i+1;
			} else if (!(allTasks[highestpri].getRawDate() < allTasks[i+1].getRawDate())) {
				highestpri = i+1;
			}
		}
		cout << "___________Priority Task___________\n1. "
			 << allTasks[highestpri].getName()
			 << "\n   Due: " << allTasks[highestpri].getMonth() << "/"
			 << allTasks[highestpri].getDay()
			 << "/" << allTasks[highestpri].getYear()
			 << " @ ";
		string AM_PM = "AM";
		int hour = allTasks[highestpri].getHour();
		if (hour > 12) { hour = hour - 12; AM_PM = "PM"; }
		cout << hour << ":"
			 << setw(2) << std::setfill('0') << right << allTasks[highestpri].getMinute()
			 << AM_PM << endl;
	}
}

void RunTasks::printCurrentTime() {
	//update time
	now = time(0);
	tm *ltm = localtime(&now);
	// print time to screen
	cout << "___________Current Time____________\n";
	// print local time
	int hour = ltm->tm_hour;
	string AM_PM = "AM";
	if (hour > 12) { hour = hour - 12; AM_PM = "PM"; }
	cout << std::setfill('0');
	cout << "   ";
	cout << setw(2) << right << hour << ":"
		 << setw(2) << right << ltm->tm_min
		 << AM_PM << "  ";
	//		 << setw(2) << 1 + ltm->tm_sec << " ";  //no seconds
	// print date
	cout << setw(2) << right << 1 + ltm->tm_mon << "/"
		 << setw(2) << right << ltm->tm_mday << "/"
		 << setw(4) << 1900 + ltm->tm_year << endl;
	cout << std::setfill(' ');
}

void RunTasks::removeTask() {
	clearTerminalScreen();
	if (allTasks.size() < 1) {
		cout << "No Tasks on list.";
		pressEnterToContinue();
		return;
	}
	int _count(0);
	int _choice(0);
	cout << "All your Tasks:";
	for (auto & it : allTasks) {
		_count++;
		cout << "\n" << _count << ". "
			 << it.getName() << "\n    Due: "
			 << it.getMonth() << "/" << it.getDay() << "/" << it.getYear()
			 << " @ "
			 << setw(2) << std::setfill('0') << right << it.getHour()
			 << ":"
			 << setw(2) << std::setfill('0') << right << it.getMinute()
			 << endl;
	}
	cout << "\nWhich would you like to remove (by number): ";
	_choice = getNumber(1, _count);
	allTasks.erase(allTasks.begin() - 1 + _choice);
	cout << "\nRemoval complete\n";
	pressEnterToContinue();
}


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


