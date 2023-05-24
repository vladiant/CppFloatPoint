#include <iostream>
#include <limits>
#include <string>
#include <string_view>

int main() {
  float pi_f =
      3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068l;
  double pi_d =
      3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068l;
  long double pi_ld =
      3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068l;

  constexpr std::string_view literal =
      R"lit(3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068)lit";

  std::cout.precision(literal.size());

  // std::numeric_limits<>::digits10 returns the number of base-10 digits that
  // be converted to a value of type T and back to decimal form, without change
  // due to rounding or overflow. For floating-point types, it is the value of
  // digits - 1 multiplied by log10radix and rounded down.
  // The decimal point should also be considered.

  std::cout << "Literal:     " << literal << '\n';

  // 3.1415927410125732421875
  std::cout << "Float:       " << pi_f << '\n';
  std::cout << "             "
            << std::string(std::numeric_limits<float>::digits10 + 2, '-')
            << '\n';

  // 3.141592653589793115997963468544185161590576171875
  std::cout << "Double:      " << pi_d << '\n';
  std::cout << "             "
            << std::string(std::numeric_limits<double>::digits10 + 2, '-')
            << '\n';

  // 3.14159265358979323851280895940618620443274267017841339111328125
  std::cout << "Long Double: " << pi_ld << '\n';
  std::cout << "             "
            << std::string(std::numeric_limits<long double>::digits10 + 2, '-')
            << '\n';

  return 0;
}