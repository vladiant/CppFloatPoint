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
  for (float current_value = 1e-3f, next_value;
       ((next_value = std::nextafter(current_value, +INFINITY)) -
        current_value) < float(1.0f);
       current_value *= float(10.0f)) {
    std::cout << std::fixed << std::setprecision(10) << std::setw(18)
              << current_value << " to " << std::setw(18) << next_value << " : "
              << std::boolalpha << "margin_comparison "
              << margin_comparison(current_value, next_value) << " "
              << "relative_comparison "
              << relative_comparison(current_value, next_value) << " " << '\n';
  }

  return 0;
}