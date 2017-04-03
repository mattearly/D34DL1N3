#pragma once
#ifndef _HELPER_H_
#define _HELPER_H_
#include <iostream>
#include <limits>
#include <sstream>
#include <type_traits>
#include <string>

//CLAMPED NUMBER TERMINAL INPUT
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

//CLAMPED NUMBER TERMINAL INPUT W/ REPEATING MESSAGE
template<class T>
T getNumber(const std::string& message, const T& a, const T& b) {
	T goodn = 0;
	while ((std::cout << message && !(std::cin >> goodn)) || (goodn < a || goodn > b)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid, try again.\n";
	}
	return goodn;
};

void clearTerminalScreen(void) {
	for (int i=0; i < 45; i++) {
		std::cout << "\n";
	}
	std::cout << std::endl;
}

void pressEnterToContinue(void) {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "\n\nPress Enter to Continue...\n\n\n";
	std::cin.get();
}

//CONVERTS A VALUE TYPE INTO A STRING
template<typename T,
		 typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
std::string toString(const T& a) {
	std::string tmp = "";
	std::stringstream stringconverter;
	stringconverter << a;
	tmp += stringconverter.str();
	return tmp;
}

//Trims whitespace - from http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
std::string trim(const std::string& str,
				 const std::string& whitespace = " \t")
{
	const auto strBegin = str.find_first_not_of(whitespace);

	if (strBegin == std::string::npos)
		return ""; // no content

	const auto strEnd = str.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return str.substr(strBegin, strRange);
}

//Reduces whitespace - from http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
std::string reduce(const std::string& str,
				   const std::string& fill = " ",
				   const std::string& whitespace = " \t")
{
	// trim first
	auto result = trim(str, whitespace);

	// replace sub ranges
	auto beginSpace = result.find_first_of(whitespace);
	while (beginSpace != std::string::npos)
	{
		const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
		const auto range = endSpace - beginSpace;

		result.replace(beginSpace, range, fill);

		const auto newStart = beginSpace + fill.length();
		beginSpace = result.find_first_of(whitespace, newStart);
	}

	return result;
}

#endif  //_HELPER_H_
