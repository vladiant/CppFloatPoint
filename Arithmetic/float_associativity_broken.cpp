#include <cfenv>
#include <cmath>
#include <iostream>

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
  std::cout.precision(10);
  float a = 20000000.0f;
  float b = 1.0f;
  float c = 1.0f;

  std::cout << "a = " << a << '\n';
  std::cout << "b = " << b << '\n';
  std::cout << "c = " << c << '\n';

  std::feclearexcept(FE_ALL_EXCEPT);

  show_env();

  float result_abc = a + b + c;

  std::cout << "a + b + c = " << result_abc << '\n';

  // std::fetestexcept(FE_INEXACT) is true

  show_env();

  std::feclearexcept(FE_ALL_EXCEPT);

  float result_bca = b + c + a;

  std::cout << "b + c + a = " << result_bca << '\n';

  show_env();

  return 0;
}
