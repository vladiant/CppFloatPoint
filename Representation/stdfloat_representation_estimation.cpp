#include <iostream>
#include <limits>
#include <stdfloat>
#include <string>
#include <string_view>

int main() {
  std::bfloat16_t pi_bf16 =
      3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068bf16;
  std::float16_t pi_f16 =
      3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068f16;
  std::float32_t pi_f32 =
      3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068f32;
  std::float64_t pi_f64 =
      3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068f64;
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

  // 3.140625
  std::cout << "std::bfloat16_t:     " << pi_bf16 << '\n';
  std::cout << "                     "
            << std::string(std::numeric_limits<std::bfloat16_t>::digits10 + 2,
                           '-')
            << '\n';

  // 3.140625
  std::cout << "std::float16_t:      " << pi_f16 << '\n';
  std::cout << "                     "
            << std::string(std::numeric_limits<std::float16_t>::digits10 + 2,
                           '-')
            << '\n';

  // 3.1415927410125732421875
  std::cout << "std::float32_t:      " << pi_f32 << '\n';
  std::cout << "                     "
            << std::string(std::numeric_limits<std::float32_t>::digits10 + 2,
                           '-')
            << '\n';

  // 3.141592653589793115997963468544185161590576171875
  std::cout << "std::float64_t:      " << pi_f64 << '\n';
  std::cout << "                     "
            << std::string(std::numeric_limits<std::float64_t>::digits10 + 2,
                           '-')
            << '\n';

  std::cout << "std::float128_t:     " << /*pi_f128 <<*/ '\n';
  std::cout << "                     "
            << std::string(std::numeric_limits<std::float128_t>::digits10 + 2,
                           '-')
            << '\n';

  return 0;
}