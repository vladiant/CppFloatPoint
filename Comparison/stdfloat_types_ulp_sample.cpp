// Adapted from std::nextafter sample

// print std::float128_t
// -std=c++23 -lquadmath
#include <quadmath.h>

#include <cmath>
#include <concepts>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdfloat>

template <std::floating_point Fp>
void print_ulp(const Fp start) {
    for (Fp current_value = start, next_value, dist_to_next;
         (dist_to_next =
              (next_value = std::nextafter(
                   current_value, std::numeric_limits<Fp>::infinity())) -
              current_value) < static_cast<Fp>(10.0f);
         current_value *= static_cast<Fp>(10.0)) {
        std::cout << "nextafter(" << std::scientific << std::setprecision(0)
                  << current_value << ", INF) gives " << std::fixed
                  << std::setprecision(6) << next_value
                  << "; dist_to_next = " << dist_to_next << '\n';
    }
}

// Special printing for std::float128_t
template <>
void print_ulp(const std::float128_t start) {
    for (std::float128_t current_value = start, next_value, dist_to_next;
         (dist_to_next =
              (next_value = std::nextafter(
                   current_value,
                   std::numeric_limits<std::float128_t>::infinity())) -
              current_value) < static_cast<std::float128_t>(10.0f);
         current_value *= static_cast<std::float128_t>(10.0)) {
        int width = 46;
        char buf_current_value[128]{};
        quadmath_snprintf(buf_current_value, sizeof(buf_current_value), "%.0Qe",
                          width, current_value);

        char buf_next_value[128]{};
        quadmath_snprintf(buf_next_value, sizeof(buf_next_value), "%.14Qf",
                          width, next_value);

        char buf_dist_to_next[128]{};
        quadmath_snprintf(buf_dist_to_next, sizeof(buf_dist_to_next), "%.14Qf",
                          width, dist_to_next);

        std::cout << "nextafter(" << buf_current_value << ", INF) gives "
                  << std::fixed << buf_next_value
                  << "; dist_to_next = " << buf_dist_to_next << '\n';
    }
}

int main() {
    // std::nextafter not defined for:
    // std::bfloat16_t, std::float16_t

    std::cout << "std::float32_t:\n";
    print_ulp<std::float32_t>(10.0f);

    std::cout << "std::float64_t:\n";
    print_ulp<std::float64_t>(10.0e9);

    std::cout << "std::float128_t:\n";
    print_ulp<std::float128_t>(10.0e19L);

    return 0;
}
