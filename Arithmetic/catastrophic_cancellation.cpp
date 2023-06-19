#include <cmath>
#include <iostream>

int main() {
  float a = 2.0f;
  float b = -2000.0f;
  float c = -1.0f;

  float d = 4.0f * a * c / (b * b);

  // Catastrophic cancellation d << 1

  // -2e-06
  std::cout << "d = " << d << '\n';

  float x_plus = -(b / (2.0f * a)) * (1.0f - std::sqrt(1.0f - d));

  // -0.000476837
  std::cout << "x_plus = " << x_plus << '\n';

  // Catastrophic cancellation avoided
  float x_plus_ok = -(2.0f * c / b) / (1 + std::sqrt(1.0f - d));

  // -0.0005
  std::cout << "x_plus = " << x_plus_ok << '\n';

  return 0;
}
