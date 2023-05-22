#include <charconv>
#include <clocale>
#include <cmath>
#include <iostream>
#include <string_view>

float parseString(std::string_view input) {
  // Expects the pattern identical to the one used by std::strtod in the default
  // ("C") locale
  float value{};
  const auto result = std::from_chars(input.begin(), input.end(), value);
  if (result.ec != std::errc()) {
    value = NAN;
  }
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

  // String: 1.5  Parsed float: 1.5
  std::cout << "String: " << numberString
            << "  Parsed float: " << parseString(numberString) << '\n';
  std::cout << '\n';

  return 0;
}
