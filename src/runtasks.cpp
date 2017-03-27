#include "runtasks.h"
#include "helper.h"
#include <fstream>
#include <iomanip>

using namespace std;

bool operator< (const Date& lhs, const Date& rhs) {
	if (lhs.year <= rhs.year) {
		if (lhs.year < rhs.year) {
			return true;  //year of left hand side is less
		} else {  //years are equal, check month
			if (lhs.month <= rhs.month) {
				if (lhs.month < lhs.month) {
					return true;  //month of left hand side is less
				} else if (lhs.day < rhs.day) {  //months are equal check day
					return true;
				}
			}
		}
	}
	return false;
}

RunTasks::RunTasks() {
	now = time(0);
	ltm = localtime(&now);

}

void RunTasks::exec() {
	int choice = 0;
	pair<int, int> choice_minmax(0,3);
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
			cout << "GoodBye" << endl;
			break;
		default: break;
		}
	} while (choice != choice_minmax.second);
}


int RunTasks::menu(pair<int, int>& __minmax) {
	clearTerminalScreen();
//	cout << "   /DATE\\\n    \\TIME/   \n";
	printCurrentTime();
	cout << endl;
//	cout << "   /Main\\\n   \\Menu/\n"
	cout << "Main Menu\n"
		 << "0. New Task " << endl
		 << "1. View Tasks" << endl
		 << "2. Highest Priority Task" << endl
		 << "3. Quit" << endl
		 << "  Choice: ";
	return (getNumber(__minmax.first, __minmax.second));
}

//prompt user via the terminal for a new task entry
void RunTasks::createNewTask() {
	clearTerminalScreen();
	string tmpname;
	int tmpmonth, tmpday, tmpyear;
	cout << "\nEnter a task name: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, tmpname);
	cout << "\nTask Due Date";
	cout << "\nEnter month: ";
	tmpmonth = getNumber(1,12);
	cout << "\nEnter day: ";
	tmpday = getNumber(1,31);
	cout << "\nEnter year: ";
	tmpyear = getNumber(2017, 2040);
	Date tmpdate(tmpmonth, tmpday, tmpyear);
	Task tmptask(tmpname, tmpdate);
	allTasks.push_back(tmptask);
}

//overloaded version to copy a full vector of already constructed tasks
void RunTasks::createNewTask(vector<Task> &inctasks) {
	allTasks = inctasks;
}


void RunTasks::viewAllTasks() {
	if (allTasks.size() < 1) {
		cout << "No Tasks on list.";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin.get();
		return;
	}
	for (auto & it : allTasks) {
		cout << it.getName() << " Due: "
			 << it.getMonth() << "/" << it.getDay() << "/" << it.getYear()
			 << endl;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();
}


void RunTasks::viewHighestPriorityTask() {

	if (allTasks.size() < 1) {
		cout << "No Tasks on list.";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin.get();
		return;
	} else if (allTasks.size() == 1) {
		cout << "Highest Priority: " << allTasks[0].getName() << " "
			 << "Due: " << allTasks[0].getMonth() << "/" << allTasks[0].getDay()
			 << "/" << allTasks[0].getYear()
			 << endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin.get();
		return;
	}

	int highestpri = 0;  //vector location of highest priority found

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
		 << endl;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();

}


void RunTasks::printCurrentTime() {
	//update time
	now = time(0);
	tm *ltm = localtime(&now);
	// print date
	cout << setw(2) << std::setfill('0') << 1 + ltm->tm_mon << "/"
		 << setw(2) << std::setfill('0') << ltm->tm_mday << "/"
		 << setw(4) << std::setfill('0') << 1900 + ltm->tm_year << endl;
	// print local time
	cout << setw(2) << std::setfill('0') << 1 + ltm->tm_hour << ":"
		 << setw(2) << std::setfill('0') << 1 + ltm->tm_min << ":"
		 << setw(2) << std::setfill('0') << 1 + ltm->tm_sec << endl;
}
