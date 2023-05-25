#include <iostream>
#include <string_view>
#include <charconv>

int main() {
  constexpr std::string_view literal =
      R"lit(3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068)lit";

  float pi_f{};
  std::from_chars(literal.begin(), literal.end(), pi_f);

  double pi_d{};
   std::from_chars(literal.begin(), literal.end(), pi_d);

  long double pi_ld{};
  std::from_chars(literal.begin(), literal.end(), pi_ld);

  std::cout.precision(literal.size());

  std::cout << "Literal:     " << literal << '\n';

  // 3.1415927410125732421875
  std::cout << "Float:       " << pi_f << '\n';

  // 3.141592653589793115997963468544185161590576171875
  std::cout << "Double:      " << pi_d << '\n';

  // 3.14159265358979323851280895940618620443274267017841339111328125
  std::cout << "Long Double: " << pi_ld << '\n';

  return 0;
}