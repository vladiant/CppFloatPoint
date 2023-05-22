#include <clocale>
#include <iostream>
#include <string>

int main() {
  constexpr double number = 1.5;
  constexpr auto numberString = "1.5";

  // On startup the std::setlocale(LC_ALL, "C") is executed
  // before any other code

  // Current locale: C
  std::cout << "Current locale: " << std::setlocale(LC_NUMERIC, nullptr)
            << '\n';

  // String: 1.5  Parsed float: 1.5
  std::cout << "String: " << numberString
            << "  Parsed float: " << std::stof(numberString) << '\n';

  // Set new C locale
  // If bg_BG.UTF-8 is not found then defaults to C
  std::setlocale(LC_NUMERIC, "bg_BG.UTF-8");

  // Current locale: bg_BG.UTF-8
  std::cout << "Current locale: " << std::setlocale(LC_NUMERIC, nullptr)
            << '\n';

  // String: 1.5  Parsed float: 1
  std::cout << "String: " << numberString
            << "  Parsed float: " << std::stof(numberString) << '\n';

  return 0;
}
