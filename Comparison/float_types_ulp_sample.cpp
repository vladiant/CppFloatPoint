// Adapted from std::nextafter sample

#include <cmath>
#include <concepts>
#include <iomanip>
#include <iostream>
#include <limits>

template <std::floating_point Fp>
void print_ulp(const Fp start) {
  for (Fp current_value = start, next_value, dist_to_next;
       (dist_to_next =
            (next_value = std::nextafter(current_value,
                                         std::numeric_limits<Fp>::infinity())) -
            current_value) < static_cast<Fp>(10.0f);
       current_value *= static_cast<Fp>(10.0)) {
    std::cout << "nextafter(" << std::scientific << std::setprecision(0)
              << current_value << ", INF) gives " << std::fixed
              << std::setprecision(6) << next_value
              << "; dist_to_next = " << dist_to_next << '\n';
  }
}

int main() {
  std::cout << "float:\n";
  print_ulp<float>(10.0);

  std::cout << "double:\n";
  print_ulp<double>(10.0e9);

  std::cout << "long double:\n";
  print_ulp<long double>(10.0e17L);

  return 0;
}