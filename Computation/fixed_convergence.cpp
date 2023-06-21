// A sequence that seems to converge to a wrong limit
// Section 1.3.2 of “Handbook of floating-Point Arithmetic”
// https://link.springer.com/book/10.1007/978-0-8176-4705-6

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <iostream>

int main() {
    using namespace boost::multiprecision;
    cpp_dec_float_50 u = 2.0;
    cpp_dec_float_50 v = -4;
    cpp_dec_float_50 w;
    int max = 20;

    std::cout << "n = " << max << '\n';

    std::cout << "u0 = " << u << '\n';

    std::cout << "u1 = " << v << '\n';

    std::cout << "Computation from 3 to n:\n";

    std::cout.precision(17);
    for (int i = 3; i <= max; i++) {
        w = 111. - 1130. / v + 3000. / (v * u);
        u = v;
        v = w;

        // Should converge to 6.0
        std::cout << "u" << i << " = " << v << '\n';
    }
    return 0;
}
