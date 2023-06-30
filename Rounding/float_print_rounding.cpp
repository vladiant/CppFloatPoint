#include <array>
#include <cfenv>
#include <charconv>
#include <iomanip>
#include <iostream>
#include <cstdint>

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

void printDouble(double value) {
  uint64_t int_bits = *((uint64_t*)&value);

  std::cout << "std::cout     " << std::setw(32) << std::showpos << std::left
            << std::setfill('0') << value << " " << std::hex << int_bits
            << std::dec << '\n';

  printf("printf        %+.29f %lx\n", value, int_bits);

  std::array<char, 33> str{};
  std::to_chars(str.begin(), str.end(), value, std::chars_format::fixed, 29);
  std::cout << "std::to_chars " << (value > 0 ? "+" : "") << str.data() << " "
            << std::hex << int_bits << std::dec << '\n';
}

int main() {
  std::cout.precision(30);

  static constexpr double kV1 = 3.14159262180328102687099089962;
  static constexpr double kV2 = 3.14159262657165250232083053561;
  static constexpr double kV3 = -3.14159262180328102687099089962;
  static constexpr double kV4 = -3.14159262657165250232083053561;

  for (const int round_policy :
       {FE_DOWNWARD, FE_UPWARD, FE_TONEAREST, FE_TOWARDZERO}) {
    std::fesetround(round_policy);

    std::cout << getRoundPolicy(round_policy) << '\n';

    printDouble(kV1);
    std::cout << '\n';

    printDouble(kV2);
    std::cout << '\n';

    printDouble(kV3);
    std::cout << '\n';

    printDouble(kV4);
    std::cout << '\n';
  }

  return 0;
}