#pragma once
#include <filesystem>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <type_traits>

// CLAMPED NUMBER TERMINAL INPUT
template <class T> T getNumber(const T &a, const T &b) {
  T goodn = 0;
  while (!(std::cin >> goodn) || (goodn < a || goodn > b)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid, try again.\n";
  }
  return goodn;
};

// CLAMPED NUMBER TERMINAL INPUT W/ REPEATING MESSAGE
template <class T>
T getNumber(const std::string &message, const T &a, const T &b) {
  T goodn = 0;
  while ((std::cout << message && !(std::cin >> goodn)) ||
         (goodn < a || goodn > b)) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid, try again.\n";
  }
  return goodn;
};

void clearTerminalScreen(void);
void pressEnterToContinue(void);

// CONVERTS A VALUE TYPE INTO A STRING
template <typename T, typename = typename std::enable_if<
                          std::is_arithmetic<T>::value, T>::type>
std::string toString(const T &a) {
  std::string tmp = "";
  std::stringstream stringconverter;
  stringconverter << a;
  tmp += stringconverter.str();
  return tmp;
};

std::string trim(const std::string &str, const std::string &whitespace = " \t");
std::string reduce(const std::string &str, const std::string &fill = " ",
                   const std::string &whitespace = " \t");
bool CreateDirectoryIfNotExists(const std::string &path);