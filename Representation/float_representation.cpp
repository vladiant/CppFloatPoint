#include <iostream>
#include <string_view>

int main() {
  float pi_f =
      3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068l;
  double pi_d =
      3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068l;
  long double pi_ld =
      3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068l;

  constexpr std::string_view literal =
      R"lit(3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117068)lit";


  std::cout << "Default precision:\n";

  // 3.14159
  std::cout << "Float:       " << pi_f << '\n';

  // 3.14159
  std::cout << "Double:      " << pi_d << '\n';

  // 3.14159
  std::cout << "Long Double: " << pi_ld << '\n';

  std::cout << "Maximal precision:\n";
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