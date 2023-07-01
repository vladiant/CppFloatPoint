#include <iostream>
#include <limits>
#include <stdfloat>

template <typename T>
constexpr auto print_round_style() {
    const auto frs = std::numeric_limits<T>::round_style;
    switch (frs) {
        case std::round_indeterminate:
            return "Rounding style cannot be determined";
        case std::round_toward_zero:
            return "Rounding toward zero";
        case std::round_to_nearest:
            return "Rounding toward nearest representable value";
        case std::round_toward_infinity:
            return "Rounding toward positive infinity";
        case std::round_toward_neg_infinity:
            return "Rounding toward negative infinity";
    }
    return "unknown round style";
}

int main() {
    std::cout << "float          : " << print_round_style<float>() << '\n';
    std::cout << "double         : " << print_round_style<double>() << '\n';
    std::cout << "long double    : " << print_round_style<long double>()
              << '\n';

    std::cout << "std::bfloat16_t: " << print_round_style<std::bfloat16_t>()
              << '\n';
    std::cout << "std::float16_t : " << print_round_style<std::float16_t>()
              << '\n';
    std::cout << "std::float32_t : " << print_round_style<std::float32_t>()
              << '\n';
    std::cout << "std::float64_t : " << print_round_style<std::float64_t>()
              << '\n';
    std::cout << "std::float128_t: " << print_round_style<std::float128_t>()
              << '\n';

    return 0;
}
