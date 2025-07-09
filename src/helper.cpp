#include "helper.h"


void clearTerminalScreen(void) {
  for (int i = 0; i < 45; i++) {
    std::cout << "\n";
  }
  std::cout << std::endl;
}

void pressEnterToContinue(void) {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "\n\nPress Enter to Continue...\n\n\n";
  std::cin.get();
}

// Trims whitespace - from
// http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
std::string trim(const std::string &str,
                 const std::string &whitespace) {
  const auto strBegin = str.find_first_not_of(whitespace);

  if (strBegin == std::string::npos)
    return ""; // no content

  const auto strEnd = str.find_last_not_of(whitespace);
  const auto strRange = strEnd - strBegin + 1;

  return str.substr(strBegin, strRange);
}

// Reduces whitespace - from
// http://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string
std::string reduce(const std::string &str, const std::string &fill,
                   const std::string &whitespace) {
  // trim first
  auto result = trim(str, whitespace);

  // replace sub ranges
  auto beginSpace = result.find_first_of(whitespace);
  while (beginSpace != std::string::npos) {
    const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
    const auto range = endSpace - beginSpace;

    result.replace(beginSpace, range, fill);

    const auto newStart = beginSpace + fill.length();
    beginSpace = result.find_first_of(whitespace, newStart);
  }

  return result;
}


bool CreateDirectoryIfNotExists(const std::string& path) {
    std::error_code ec;
    if (!std::filesystem::exists(path, ec)) {
        return std::filesystem::create_directories(path, ec); // Creates intermediate dirs too
    }
    return true; // Already exists
}
