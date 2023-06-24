#include <bit>
#include <cfenv>
#include <cstdint>
#include <iomanip>
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

  float valueInf = std::numeric_limits<float>::infinity();

  show_env();

  std::cout << "Positive zero operation\n";
  float valuePosZero = 1.0f / valueInf;
  std::cout << valuePosZero << " " << std::hex
            << std::bit_cast<std::uint32_t>(valuePosZero) << '\n';

  show_env();

  std::cout << "Negative zero operation\n";
  float valueNegZero = -1.0f / valueInf;
  std::cout << valueNegZero << " " << std::hex
            << std::bit_cast<std::uint32_t>(valueNegZero) << '\n';

  // std::fetestexcept(FE_INVALID) is true

  std::cout << "-0.0f + 0.0f = " << -0.0f + 0.0f << '\n';
  std::cout << "-0.0f * 0.0f = " << -0.0f * 0.0f << '\n';

  show_env();

  return 0;
}
