// Something weird is going on
// Section 1.3.2 of “Handbook of floating-Point Arithmetic”
// https://link.springer.com/book/10.1007/978-0-8176-4705-6
// -std=c++23

#include <array>
#include <charconv>
#include <iostream>
#include <limits>
#include <stdfloat>

template <std::floating_point T>
void printNumber(T value) {
  std::array<char, std::numeric_limits<T>::digits10 + 20> str{};
  std::to_chars(str.begin(), str.end(), value, std::chars_format::scientific);
  std::cout << str.data() << '\n';
}

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
  std::cout << "result: ";
  printNumber(f);
}

int main() {
  std::cout << "std::bfloat16_t   ";
  print_rump<std::bfloat16_t>();

  std::cout << "std::float16_t    ";
  print_rump<std::float16_t>();

  std::cout << "std::float32_t    ";
  print_rump<std::float32_t>();

  std::cout << "std::float64_t    ";
  print_rump<std::float64_t>();

  std::cout << "std::float128_t   ";
  print_rump<std::float128_t>();

  return 0;
}