#include <cmath>
#include <iomanip>
#include <iostream>

auto floatToInt(float value) {
  static_assert(sizeof(value) == sizeof(uint32_t),
                "sizeof(float) == sizeof(uint32_t)");
  auto intValue = *reinterpret_cast<uint32_t*>(&value);
  return intValue;
}

int main() {
  std::cout << "-0.0f == +0.0f : " << std::boolalpha << (-0.0f == +0.0f)
            << '\n';
  std::cout << "-0.0f : " << std::hex << floatToInt(-0.0f) << '\n';
  std::cout << "+0.0f : "
            << " " << floatToInt(+0.0f) << '\n';
  std::cout << " 0.0f : "
            << " " << floatToInt(0.0f) << '\n';

  std::cout << "NAN != NAN : " << std::boolalpha << (NAN != NAN) << '\n';
  std::cout << " NAN : " << std::hex << floatToInt(NAN) << '\n';

  return 0;
}