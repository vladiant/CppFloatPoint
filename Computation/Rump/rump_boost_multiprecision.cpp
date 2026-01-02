// Something weird is going on
// Section 1.3.2 of “Handbook of floating-Point Arithmetic”
// https://link.springer.com/book/10.1007/978-0-8176-4705-6

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <iostream>

int main() {
  using namespace boost::multiprecision;

  cpp_dec_float_50 a = 77617.0;
  cpp_dec_float_50 b = 33096.0;
  cpp_dec_float_50 b2, b4, b6, b8, a2, firstexpr, f;
  b2 = b * b;
  b4 = b2 * b2;
  b6 = b4 * b2;
  b8 = b4 * b4;
  a2 = a * a;
  firstexpr = 11 * a2 * b2 - b6 - 121 * b4 - 2;
  f = 333.75 * b6 + a2 * firstexpr + 5.5 * b8 + (a / (2.0 * b));

  // Exact result should be -0.8273960599
  std::cout.precision(17);

  // -0.82739605994682137
  std::cout << "result: " << f << '\n';

  return 0;
}