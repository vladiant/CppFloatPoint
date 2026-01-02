// -std=c++23 -lquadmath

#include <quadmath.h>

#include <iostream>
#include <limits>
#include <stdfloat>
#include <string>
#include <string_view>

int main() {
  std::float128_t pi_f128 =
      3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068f128;

  constexpr std::string_view literal =
      R"lit(3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068)lit";

  std::cout.precision(literal.size());

  // std::numeric_limits<>::digits10 returns the number of base-10 digits that
  // be converted to a value of type T and back to decimal form, without
  // change due to rounding or overflow. For floating-point types, it is the
  // value of digits - 1 multiplied by log10radix and rounded down. The
  // decimal point should also be considered.

  std::cout << "Literal:             " << literal << '\n';

  int prec = 20;
  int width = 46;
  char buf[128]{};
  quadmath_snprintf(buf, sizeof(buf), "%.128Qf", width, pi_f128);
  // 3.1415926535897932384626433832795027974790680981372955730045043318742967186629755360627314075827598572
  std::cout << "std::float128_t:     " << buf << '\n';
  std::cout << "                     "
            << std::string(std::numeric_limits<std::float128_t>::digits10 + 2,
                           '-')
            << '\n';

  return 0;
}
