#include "runtasks.h"
#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

void RunTasks::saveTasklist(const string filename){
	//open specified file
	ofstream out(("/home/mje/.dtpriority/" + filename).c_str());
	if (!out) {
		cout << "Could not open " << filename << ". Check code or file.\n\n";
		return;
	} else {
		if (allTasks.size() < 1) {
			cout << "No Tasks on list(nothing to save).";
			return;
		}
		for (auto & it : allTasks) {  //output to file in 2 lines, name then date+time
			out << it.getName() << "\n"
				 << it.getMonth() << " " << it.getDay() << " " << it.getYear()
				 << " " << it.getHour() << " " << it.getMinute()
				 << "\n";
		}
		out.close();
	}
}

void RunTasks::loadTasklist(const string filename){
	//open specified file
	ifstream in("/home/mje/.dtpriority/" + filename);
	if (!in) {
		cout << "Error opening " << filename << ". Check code or file.\n\n";
		return;
	} else {
		string tmpname;
		int tmpmonth, tmpday, tmpyear, tmphour, tmpmin;
		while (getline(in, tmpname)) {
			in >> tmpmonth >> tmpday >> tmpyear >> tmphour >> tmpmin;
			Date tmpdate(tmpmonth, tmpday, tmpyear, tmphour, tmpmin);
			Task tmptask(tmpname, tmpdate);
			allTasks.push_back(tmptask);
			in.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}
