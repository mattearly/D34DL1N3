#pragma once
#ifndef _RUNTASKS_H_
#define _RUNTASKS_H_

#include "task.h"

class RunTasks {
public:
	bool operator< (const Date& lhs, const Date& rhs) {
		if (lhs.year <= rhs.year) {
			if (lhs.year < rhs.year) {
				return true;
			} else {
				if (lhs.month <= rhs.month) {
					if (lhs.month < lhs.month) {
						return true;
					} else {
						if (lhs.day < rhs.day) {
							return true;
						}
					}
				}
			}
		}
		return false;
	}

	bool exec() {


	}
};

#endif
