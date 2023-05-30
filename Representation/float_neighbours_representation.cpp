#include <cmath>
#include <iostream>
#include <limits>
#include <string_view>

int main() {
  float pi_f = 3.1415926535897932384626433832795;

  constexpr std::string_view literal =
      R"lit(3.1415926535897932384626433832795)lit";

  std::cout.precision(literal.size());

  std::cout << "Literal:             " << literal << '\n';

  // Returns the previous representable value
  // 3.141592502593994140625
  std::cout << "Previous Float:      "
            << std::nextafter(pi_f, -std::numeric_limits<float>::infinity())
            << '\n';

  // 3.1415927410125732421875
  std::cout << "Current Float:       " << pi_f << '\n';

  // Returns the next representable value
  // 3.14159297943115234375
  std::cout << "Next Float:          "
            << std::nextafter(pi_f, std::numeric_limits<float>::infinity())
            << '\n';

  return 0;
}