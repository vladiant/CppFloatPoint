// Adapted from std::nextafter sample

#include <cmath>
#include <iomanip>
#include <iostream>

template <std::floating_point Fp>
bool margin_comparison(const Fp lhs, const Fp rhs) {
  return std::abs(lhs - rhs) < std::numeric_limits<Fp>::epsilon();
}

template <std::floating_point Fp>
bool relative_comparison(const Fp lhs, const Fp rhs) {
  return std::abs(lhs - rhs) < std::numeric_limits<Fp>::epsilon() *
                                   std::max(std::abs(lhs), std::abs(rhs));
}

int main() {
  for (float current_value = 1e-45f, next_value;
       ((next_value = std::nextafter(current_value, +INFINITY)) -
        current_value) < float(1e-37f);
       current_value *= float(10.0f)) {
    std::cout << std::scientific << current_value << " to " << next_value
              << " : " << std::boolalpha << "margin_comparison "
              << margin_comparison(current_value, next_value) << "  "
              << "relative_comparison "
              << relative_comparison(current_value, next_value) << '\n';
  }

  std::cout << "minimum positive normalized value: " << std::scientific
            << std::numeric_limits<float>::min() << '\n';
  std::cout << "minimum positive subnormal value: " << std::scientific
            << std::numeric_limits<float>::denorm_min() << '\n';

  return 0;
}