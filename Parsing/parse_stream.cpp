#include <clocale>
#include <iostream>
#include <sstream>

float parseString(const std::string& input) {
  std::istringstream os{input};
  float value{};
  os >> value;

  return value;
}

int main() {
  constexpr float number = 1.5;
  constexpr auto numberString = "1.5";

  // On startup the std::setlocale(LC_ALL, "C") is executed
  // before any other code

  // On startup, the global locale for C++ is the "C" locale
  // and global locale is obtained by std::locale()

  // *** 1. Use default locale ***

  // Current locale: C
  std::cout << "Current C functions locale: "
            << std::setlocale(LC_NUMERIC, nullptr) << '\n';
  // Current locale: C
  std::cout << "Current C++ functions locale: " << std::locale().name() << '\n';

  // String: 1.5  Parsed float: 1.5
  std::cout << "String: " << numberString
            << "  Parsed float: " << parseString(numberString) << '\n';
  std::cout << '\n';

  // *** 2. Change locale for C functions ***

  // Set new C locale
  // If bg_BG.UTF-8 is not found then defaults to C
  std::setlocale(LC_NUMERIC, "bg_BG.UTF-8");

  // Current locale: bg_BG.UTF-8
  std::cout << "Current C functions locale: "
            << std::setlocale(LC_NUMERIC, nullptr) << '\n';
  // Current locale: C
  std::cout << "Current C++ functions locale: " << std::locale().name() << '\n';

  // String: 1.5  Parsed float: 1.5
  std::cout << "String: " << numberString
            << "  Parsed float: " << parseString(numberString) << '\n';
  std::cout << '\n';

  // *** 3. Change locale for C++ functions, restore the locale for C functions
  // ***

  // Set the global C++ locale
  // If bg_BG.UTF-8 is not found then throws exception
  // 'std::runtime_error'
  // locale::facet::_S_create_c_locale name not valid
  std::locale::global(std::locale("bg_BG.UTF-8"));
  // Default C locale
  std::setlocale(LC_NUMERIC, "C");

  // Current locale: C
  std::cout << "Current C functions locale: "
            << std::setlocale(LC_NUMERIC, nullptr) << '\n';

  // Current locale: bg_BG.UTF-8
  std::cout << "Current C++ functions locale: " << std::locale().name() << '\n';

  // String: 1.5  Parsed float: 1
  std::cout << "String: " << numberString
            << "  Parsed float: " << parseString(numberString) << '\n';
  std::cout << '\n';

  // *** 4. Use custom locale for stream ***
  std::istringstream customStream(numberString);
  // If bg_BG.UTF-8 is not found then throws exception
  // 'std::runtime_error'
  // locale::facet::_S_create_c_locale name not valid
  customStream.imbue(std::locale("C"));

  float value{};
  customStream >> value;

  // Current locale: C
  std::cout << "Current C functions locale: "
            << std::setlocale(LC_NUMERIC, nullptr) << '\n';

  // Current locale: bg_BG.UTF-8
  std::cout << "Current C++ functions locale: " << std::locale().name() << '\n';

  // String: 1.5  Parsed float: 1
  std::cout << "String: " << numberString << "  Parsed float: " << value
            << '\n';

  return 0;
}
