#include <charconv>
#include <iostream>
#include <stdfloat>
#include <string_view>

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

    // 3.140625
    std::cout << "std::bfloat16_t:    " << pi_bf16 << '\n';

    // 3.140625
    std::cout << "std::float16_t:     " << pi_f16 << '\n';

    // 3.1415927410125732421875
    std::cout << "std::float32_t:     " << pi_f32 << '\n';

    // 3.141592653589793115997963468544185161590576171875
    std::cout << "std::float64_t:     " << pi_f64 << '\n';

    // ?
    std::cout << "std::float128_t:    " /* << pi_f128 */ << '\n';

    return 0;
}