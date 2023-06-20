// Adapted from https://en.wikipedia.org/wiki/Floating-point_arithmetic

#include <cmath>
#include <iostream>

int main() {
  float t = 1.0 / std::sqrt(3.0);
  float v = 1.0;

  int max = 30;

  std::cout << "n = " << max << '\n';

  std::cout << "t0 = " << t << '\n';

  std::cout << "Computation from 1 to n:\n";

  std::cout.precision(17);

  for (int i = 1; i <= max; i++) {
    t = t / (std::sqrt(t * t + 1.0) + 1.0);
    v *= 2.0;

    // Should converge to 3.1415926535897931
    std::cout << "u" << i << " = " << 6.0 * t * v << '\n';
  }
  return 0;
}