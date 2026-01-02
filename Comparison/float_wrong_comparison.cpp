#include <cstdint>
#include <iostream>
#include <limits>

auto floatToInt(float value) {
  static_assert(sizeof(value) == sizeof(uint32_t),
                "sizeof(float) == sizeof(uint32_t)");
  auto intValue = *reinterpret_cast<uint32_t*>(&value);
  return intValue;
}

auto floatToInt(double value) {
  static_assert(sizeof(value) == sizeof(uint64_t),
                "sizeof(double) == sizeof(uint64_t)");
  auto intValue = *reinterpret_cast<uint64_t*>(&value);
  return intValue;
}

int main() {
  float a_f = 0.1f;
  float b_f = 0.2f;
  float c_f = 0.3f;

  std::cout << "a_f       " << a_f << " " << std::hex << floatToInt(a_f)
            << '\n';
  std::cout << "b_f       " << b_f << " " << std::hex << floatToInt(b_f)
            << '\n';
  std::cout << "c_f       " << c_f << " " << std::hex << floatToInt(c_f)
            << '\n';
  std::cout << "a_f + b_f " << a_f + b_f << " " << std::hex
            << floatToInt(a_f + b_f) << '\n';

  // true
  std::cout << "(a_f + b_f == c_f) : " << std::boolalpha << (a_f + b_f == c_f)
            << '\n';

  std::cout << '\n';

  double a_d = 0.1;
  double b_d = 0.2;
  double c_d = 0.3;

  std::cout << "a_d       " << a_d << " " << std::hex << floatToInt(a_d)
            << '\n';
  std::cout << "b_d       " << b_d << " " << std::hex << floatToInt(b_d)
            << '\n';
  std::cout << "c_d       " << c_d << " " << std::hex << floatToInt(c_d)
            << '\n';
  std::cout << "a_d + b_d " << a_d + b_d << " " << std::hex
            << floatToInt(a_d + b_d) << '\n';

  // false
  std::cout << "(a_d + b_d == c_d) : " << std::boolalpha << (a_d + b_d == c_d)
            << '\n';

  std::cout << '\n';

  std::cout << "Sufficient type precision" << '\n';

  std::cout.precision(std::numeric_limits<float>::digits10 + 2);
  std::cout << "a_f       " << a_f << '\n';
  std::cout << "b_f       " << b_f << '\n';
  std::cout << "c_f       " << c_f << '\n';
  std::cout << "a_f + b_f " << a_f + b_f << '\n';

  std::cout << '\n';

  std::cout.precision(std::numeric_limits<double>::digits10 + 2);
  std::cout << "a_d       " << a_d << '\n';
  std::cout << "b_d       " << b_d << '\n';
  std::cout << "c_d       " << c_d << '\n';
  std::cout << "a_d + b_d " << a_d + b_d << '\n';

  std::cout << '\n';

  std::cout.precision(30);
  std::cout << "Maximal type precision" << '\n';

  std::cout << "a_f       " << a_f << '\n';
  std::cout << "b_f       " << b_f << '\n';
  std::cout << "c_f       " << c_f << '\n';
  std::cout << "a_f + b_f " << a_f + b_f << '\n';

  std::cout << '\n';

  std::cout << "a_d       " << a_d << '\n';
  std::cout << "b_d       " << b_d << '\n';
  std::cout << "c_d       " << c_d << '\n';
  std::cout << "a_d + b_d " << a_d + b_d << '\n';

  return 0;
}
