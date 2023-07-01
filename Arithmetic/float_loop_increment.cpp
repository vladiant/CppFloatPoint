#include <cfenv>
#include <cmath>
#include <iostream>

void show_env() {
    const int e = std::fetestexcept(FE_ALL_EXCEPT);
    if (e & FE_DIVBYZERO) std::cout << "division by zero is raised\n";
    if (e & FE_INEXACT) std::cout << "inexact is raised\n";
    if (e & FE_INVALID) std::cout << "invalid is raised\n";
    if (e & FE_UNDERFLOW) std::cout << "underflow is raised\n";
    if (e & FE_OVERFLOW) std::cout << "overflow is raised\n";
}

int main() {
    std::cout.precision(10);

    for (float x = 0.0f; x < 100000000.0f; x += 1.0f) {
        const int e = std::fetestexcept(FE_ALL_EXCEPT);
        if (x == x + 1) {
            std::cout << "x == x + 1 when x=" << x << '\n';
            show_env();
            break;
        }

        std::feclearexcept(FE_ALL_EXCEPT);
    }

    // Expected result
    // x == x + 1 when x=16777216

    return 0;
}
