#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>

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
  std::cout << "+0.0f : " << " " << floatToInt(+0.0f) << '\n';
  std::cout << " 0.0f : " << " " << floatToInt(0.0f) << '\n';

  float valueCNaN = NAN;
  std::cout << " NAN != NAN                 : " << std::boolalpha
            << (valueCNaN != valueCNaN) << '\n';
  std::cout << " NAN                        : " << std::hex
            << floatToInt(valueCNaN) << '\n';

  float valueQuietNaN = std::numeric_limits<float>::quiet_NaN();
  std::cout << " quiet_NaN                  : " << std::hex
            << floatToInt(valueQuietNaN) << '\n';

  float valueSignalNaN = std::numeric_limits<float>::signaling_NaN();
  std::cout << " signaling_NaN              : " << std::hex
            << floatToInt(valueSignalNaN) << '\n';

  std::cout << " signaling_NaN != quiet_NaN : " << std::boolalpha
            << (valueSignalNaN != valueQuietNaN) << '\n';
  std::cout << " quiet_NaN != quiet_NaN     : " << std::boolalpha
            << (valueQuietNaN != valueQuietNaN) << '\n';

  return 0;
}