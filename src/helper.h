#pragma once
#ifndef _HELPER_H_
#define _HELPER_H_
#include <iostream>
#include <limits>
#include <sstream>

template<class T>
T getNumber(const T& a, const T& b) {

	T goodn = 0;
	while (!(std::cin >> goodn) || (goodn < a || goodn > b)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid, try again.\n";
	}
	return goodn;
}

void clearTerminalScreen() {
	for (int i=0; i < 45; i++) {
		std::cout << "\n";
	}
	std::cout << std::endl;
}

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
std::string toString(const T& a) {
	std::string tmp = "";
	std::stringstream stringconverter;
	stringconverter << a;
	tmp += stringconverter.str();
	return tmp;
}

#endif
