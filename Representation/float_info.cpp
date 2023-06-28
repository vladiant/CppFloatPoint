#include <iostream>
#include <limits>

template <typename FP>
void FP_limits() {
    const auto FP_name{typeid(FP).name()};

    std::cout << "FP_name: " << FP_name << '\n';
    std::cout << "---------" << '\n';
    std::cout << "epsilon = " << std::numeric_limits<FP>::epsilon() << '\n';

    std::cout << "radix = " << std::numeric_limits<FP>::radix << '\n';
    std::cout << "mantissa_digits = " << std::numeric_limits<FP>::digits
              << '\n';

    std::cout << "min = " << std::numeric_limits<FP>::min() << '\n';
    std::cout << "max = " << std::numeric_limits<FP>::max() << '\n';

    std::cout << "has_denorm = " << std::numeric_limits<FP>::has_denorm << '\n';
    std::cout << "denorm_min = " << std::numeric_limits<FP>::denorm_min()
              << '\n';
    std::cout << "lowest = " << std::numeric_limits<FP>::lowest() << '\n';
    std::cout << "has_infinity = " << std::numeric_limits<FP>::has_infinity
              << '\n';

    std::cout << "round_style = "
              << (std::numeric_limits<FP>::round_style == std::round_to_nearest
                      ? "round_to_nearest"
                      : "round_toward_zero")
              << '\n';
    std::cout << "round_error = " << std::numeric_limits<FP>::round_error()
              << '\n' << '\n';
}

int main() {
    FP_limits<float>();
    FP_limits<double>();
    FP_limits<long double>();

    return 0;
}

