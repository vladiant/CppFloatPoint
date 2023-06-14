#include <cfenv>
#include <cmath>
#include <iostream>
#include <limits>

void show_env() {
  const int e = std::fetestexcept(FE_ALL_EXCEPT);
  if (e & FE_DIVBYZERO) std::cout << "division by zero is raised\n";
  if (e & FE_INEXACT) std::cout << "inexact is raised\n";
  if (e & FE_INVALID) std::cout << "invalid is raised\n";
  if (e & FE_UNDERFLOW) std::cout << "underflow is raised\n";
  if (e & FE_OVERFLOW) std::cout << "overflow is raised\n";

  switch (std::fegetround()) {
    case FE_DOWNWARD:
      std::cout << "rounding down\n";
      break;
    case FE_TONEAREST:
      std::cout << "rounding to nearest\n";
      break;
    case FE_TOWARDZERO:
      std::cout << "rounding to zero\n";
      break;
    case FE_UPWARD:
      std::cout << "rounding up\n";
      break;
  }
}

int main() {
  std::feclearexcept(FE_ALL_EXCEPT);

  show_env();
  auto a = std::numeric_limits<float>::denorm_min();

  float result = a / 2.0f;

  std::cout << "denorm_min / 2 = " << result << '\n';

  // std::fetestexcept(FE_UNDERFLOW) is true
  // std::fetestexcept(FE_INEXACT) is true

  show_env();

  return 0;
}
