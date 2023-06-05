#include <array>
#include <cfenv>
#include <charconv>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

auto getRoundPolicy(int rount_policy) {
  switch (rount_policy) {
    case FE_DOWNWARD:
      return "FE_DOWNWARD";
      break;
    case FE_UPWARD:
      return "FE_UPWARD";
      break;
    case FE_TONEAREST:
      return "FE_TONEAREST";
      break;
    case FE_TOWARDZERO:
      return "FE_TOWARDZERO";
      break;
  }

  return "UNKNOWN";
}

void printNumber(double value) {
  std::array<char, 15> str{};
  std::to_chars(str.begin(), str.end(), value, std::chars_format::fixed, 11);
  std::cout << "double " << (value > 0 ? "+" : "") << str.data() << " ->";
}

void printNumber(float value) {
  uint64_t int_bits = *((uint32_t*)&value);

  std::array<char, 11> str{};
  std::to_chars(str.begin(), str.end(), value, std::chars_format::fixed, 7);
  std::cout << "single " << (value > 0 ? "+" : "") << str.data() << " "
            << std::hex << int_bits << std::dec;
}

void printNumbers(double fromValue, float toValue) {
  printNumber(fromValue);
  std::cout << "  ";
  printNumber(toValue);
  std::cout << '\n';
}

int main() {
  const double kV1 = -3.14159286499022627481281233486;
  const double kV2 = -3.14159274101259011757747430238;
  const double kV3 = -3.14159273624421819803842481633;
  const double kV4 = -3.14159262657165250232083053561;
  const double kV5 = -3.14159262180328102687099089962;
  const double kV6 = 3.14159262180328102687099089962;
  const double kV7 = 3.14159262657165250232083053561;
  const double kV8 = 3.14159273624421819803842481633;
  const double kV9 = 3.14159274101259011757747430238;
  const double kV10 = 3.14159286499022627481281233486;

  for (const int round_policy :
       {FE_DOWNWARD, FE_UPWARD, FE_TONEAREST, FE_TOWARDZERO}) {
    std::fesetround(round_policy);

    std::cout << getRoundPolicy(round_policy) << '\n';

    // Double precision vvariables / consts can be here too
    // This does not change the outcome

    float v1 = kV1;
    float v2 = kV2;
    float v3 = kV3;
    float v4 = kV4;
    float v5 = kV5;
    float v6 = kV6;
    float v7 = kV7;
    float v8 = kV8;
    float v9 = kV9;
    float v10 = kV10;

    printNumbers(kV1, v1);
    printNumbers(kV2, v2);
    printNumbers(kV3, v3);
    printNumbers(kV4, v4);
    printNumbers(kV5, v5);
    printNumbers(kV6, v6);
    printNumbers(kV7, v7);
    printNumbers(kV8, v8);
    printNumbers(kV9, v9);
    printNumbers(kV10, v10);

    std::cout << '\n';
  }

  return 0;
}