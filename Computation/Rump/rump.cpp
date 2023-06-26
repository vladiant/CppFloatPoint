// Something weird is going on
// Section 1.3.2 of “Handbook of floating-Point Arithmetic”
// https://link.springer.com/book/10.1007/978-0-8176-4705-6

#include <iostream>

template <std::floating_point T>
void print_rump() {
  T a = 77617.0;
  T b = 33096.0;
  T b2, b4, b6, b8, a2, firstexpr, f;
  b2 = b * b;
  b4 = b2 * b2;
  b6 = b4 * b2;
  b8 = b4 * b4;
  a2 = a * a;
  firstexpr = 11 * a2 * b2 - b6 - 121 * b4 - 2;
  f = 333.75 * b6 + a2 * firstexpr + 5.5 * b8 + (a / (2.0 * b));

  // Exact result should be -0.8273960599
  std::cout.precision(17);
  std::cout << "result: " << f << '\n';
}

int main() {
  std::cout << "float       ";
  print_rump<float>();

  std::cout << "double      ";
  print_rump<double>();

  std::cout << "long double ";
  print_rump<long double>();

  return 0;
}