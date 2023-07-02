#include <iostream>
#include <limits>
#include <stdfloat>

int main() {
    std::cout << "float          : " << std::numeric_limits<float>::digits10
              << '\n';
    std::cout << "double         : " << std::numeric_limits<double>::digits10
              << '\n';
    std::cout << "long double    : "
              << std::numeric_limits<long double>::digits10 << '\n';

    std::cout << "std::bfloat16_t: "
              << std::numeric_limits<std::bfloat16_t>::digits10 << '\n';
    std::cout << "std::float16_t : "
              << std::numeric_limits<std::float16_t>::digits10 << '\n';
    std::cout << "std::float32_t : "
              << std::numeric_limits<std::float32_t>::digits10 << '\n';
    std::cout << "std::float64_t : "
              << std::numeric_limits<std::float64_t>::digits10 << '\n';
    std::cout << "std::float128_t: "
              << std::numeric_limits<std::float128_t>::digits10 << '\n';

    return 0;
}
