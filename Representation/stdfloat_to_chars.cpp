#include <array>
#include <charconv>
#include <concepts>
#include <iostream>
#include <limits>
#include <stdfloat>
#include <string_view>

template <std::floating_point Fp>
void printNumber(Fp value) {
  std::array<char, std::numeric_limits<Fp>::digits10 + 3> str{};
  std::to_chars(str.begin(), str.end(), value, std::chars_format::fixed,
                std::numeric_limits<Fp>::digits10);
  std::cout << str.data() << '\n';
}

int main() {
  constexpr std::string_view literal =
      R"lit(3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068)lit";

  std::bfloat16_t pi_bf16{};
  std::from_chars(literal.begin(), literal.end(), pi_bf16);

  std::float16_t pi_f16{};
  std::from_chars(literal.begin(), literal.end(), pi_f16);

  std::float32_t pi_f32{};
  std::from_chars(literal.begin(), literal.end(), pi_f32);

  std::float64_t pi_f64{};
  std::from_chars(literal.begin(), literal.end(), pi_f64);

  std::float128_t pi_f128{};
  std::from_chars(literal.begin(), literal.end(), pi_f128);

  std::cout.precision(literal.size());

  std::cout << "Literal:            " << literal << '\n';

  // 3.14
  std::cout << "std::bfloat16_t:    ";
  printNumber(pi_bf16);

  // 3.141
  std::cout << "std::float16_t:     ";
  printNumber(pi_f16);

  // 3.141593
  std::cout << "std::float32_t:     ";
  printNumber(pi_f32);

  // 3.141592653589793
  std::cout << "std::float64_t:     ";
  printNumber(pi_f64);

  // 3.141592653589793238462643383279503
  std::cout << "std::float128_t:    ";
  printNumber(pi_f128);

  return 0;
}