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
}

int main() {
  std::cout.precision(10);

  // Never becomes equal to 1.0f
  // Closest value is 1.000000119
  for (float x = 0.0f; x < 1.0f; x += 0.1f) {
    show_env();

    std::cout << "counter: " << x << '\n';

    // std::fetestexcept(FE_INEXACT) becomes true

    std::feclearexcept(FE_ALL_EXCEPT);
  }

  // Expected result
  // counter: 0
  // counter: 0.1000000015
  // counter: 0.200000003
  // inexact is raised
  // counter: 0.3000000119
  // inexact is raised
  // counter: 0.400000006
  // inexact is raised
  // counter: 0.5
  // inexact is raised
  // counter: 0.6000000238
  // inexact is raised
  // counter: 0.7000000477
  // inexact is raised
  // counter: 0.8000000715
  // inexact is raised
  // counter: 0.9000000954

  return 0;
}
