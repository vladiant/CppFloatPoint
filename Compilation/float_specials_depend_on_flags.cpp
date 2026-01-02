#include <cmath>
#include <iostream>
#include <limits>

int main() {
  std::cout << std::boolalpha;

  std::cout << "NaN != NaN : " << (NAN != NAN) << '\n';

  // GCC - all false with -ffast-math
  std::cout << "isnan(NaN) = " << std::isnan(NAN) << '\n';
  std::cout << "isnan(quiet_NaN) = "
            << std::isnan(std::numeric_limits<float>::quiet_NaN()) << '\n';
  std::cout << "isnan(signaling_NaN) = "
            << std::isnan(std::numeric_limits<float>::signaling_NaN()) << '\n';
  std::cout << "isinf(INFINITY) = " << std::isinf(INFINITY) << '\n';
  std::cout << "isinf(infinity()) = "
            << std::isinf(std::numeric_limits<float>::infinity()) << '\n';

  return 0;
}
