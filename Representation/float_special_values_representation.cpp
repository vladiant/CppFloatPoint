#include <cmath>
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
  std::cout << "Positive infinity" << '\n';

  std::cout << " has_infinity      : " << std::boolalpha
            << std::numeric_limits<float>::has_infinity << '\n';

  float valueInf = std::numeric_limits<float>::infinity();
  std::cout << " positive infinity : " << valueInf << " " << std::hex
            << floatToInt(valueInf) << '\n';

  float valueCInf = INFINITY;
  std::cout << " C        infinity : " << valueInf << " " << std::hex
            << floatToInt(valueInf) << '\n';

  std::cout << "\nNegative infinity" << '\n';
  float valueNegInf = -valueInf;
  std::cout << " negative infinity : " << valueNegInf << " " << std::hex
            << floatToInt(valueNegInf) << '\n';

  float valueNegCInf = -valueCInf;
  std::cout << " C       -infinity : " << valueNegCInf << " " << std::hex
            << floatToInt(valueNegCInf) << '\n';

  std::cout << "\nNegative zero" << '\n';

  float valueNegZero = -0.0f;
  std::cout << " negative zero     : " << valueNegZero << " " << std::hex
            << floatToInt(valueNegZero) << '\n';

  std::cout << "\nPositive zero" << '\n';

  float valuePosZero = 0.0f;
  std::cout << " positive zero     : " << valuePosZero << " " << std::hex
            << floatToInt(valuePosZero) << '\n';

  std::cout << "\nNot a Number" << '\n';

  // IEEE 754 NaN : Any value with all bits of the exponent set and at least one
  // bit of the fraction set
  std::cout << " has_quiet_NaN     : " << std::boolalpha
            << std::numeric_limits<float>::has_quiet_NaN << '\n';
  float valueQuietNaN = std::numeric_limits<float>::quiet_NaN();
  std::cout << " quiet_NaN         : " << valueQuietNaN << " " << std::hex
            << floatToInt(valueQuietNaN) << '\n';

  std::cout << " has_signaling_NaN : " << std::boolalpha
            << std::numeric_limits<float>::has_signaling_NaN << '\n';
  float valueSignalNaN = std::numeric_limits<float>::signaling_NaN();
  std::cout << " signaling_NaN     : " << valueSignalNaN << " " << std::hex
            << floatToInt(valueSignalNaN) << '\n';

  float valueCNaN = NAN;
  std::cout << " C NaN             : " << valueCNaN << " " << std::hex
            << floatToInt(valueCNaN) << '\n';

  return 0;
}