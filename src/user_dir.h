#pragma once
#include <cstdlib> // for getenv
#include <string>

#ifdef WIN32

std::string GetUserHomeDirectory() {
  const char *userProfile = std::getenv("USERPROFILE");
  return userProfile ? std::string(userProfile) : std::string();
}

#elif LINUX

std::string GetUserHomeDirectory() {
  const char *home = std::getenv("HOME");
  return home ? std::string(home) : std::string();
}
#endif