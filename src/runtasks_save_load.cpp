#include "helper.h"
#include "runtasks.h"
#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

bool RunTasks::saveTasklist(const string filename) {
  std::string user_settings_path = user_dir + "/.D34DL1N3/";
  CreateDirectoryIfNotExists(user_settings_path);
  ofstream out((user_settings_path + filename).c_str());
  if (!out) {
    return false;
  } else {
    if (allTasks.size() < 1) {
      out << "\n";
    } else {
      for (auto &it :
           allTasks) { // output to file in 2 lines, name then date+time
        out << it.getName() << "\n"
            << it.getMonth() << " " << it.getDay() << " " << it.getYear() << " "
            << it.getHour() << " " << it.getMinute() << "\n";
      }
    }
    out.close();
  }
  if (!pendingHistory.empty()) {
    writePendingHistory();
  }
  return true;
}

void RunTasks::writePendingHistory() {
  std::string user_history_path = user_dir + "/.D34DL1N3/history";
  CreateDirectoryIfNotExists(user_history_path);
  ofstream hout;
  hout.open(user_history_path, ios::app);
  if (!hout) {
    cout << "error opening history file\n";
  } else {
    for (auto &it : pendingHistory) {
      hout << it << "\n";
    }
    cout << "history saved\n";
    pendingHistory.clear();
    cout << "pendingHistory cleared\n";
  }
}

bool RunTasks::loadTasklist(const string filename) {
  // open specified file
  std::string home(user_dir);
  ifstream in(home + "/.D34DL1N3/" + filename);
  if (!in) {
    return false;
  } else {
    string tmpname;
    int tmpmonth, tmpday, tmpyear, tmphour, tmpmin;
    while (getline(in, tmpname)) {
      if (tmpname.size() < 1)
        continue;
      in >> tmpmonth >> tmpday >> tmpyear >> tmphour >> tmpmin;
      Date tmpdate(tmpmonth, tmpday, tmpyear, tmphour, tmpmin);
      Task tmptask(tmpname, tmpdate);
      allTasks.push_back(tmptask);
      in.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
  return true;
}
