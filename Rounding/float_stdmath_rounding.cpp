#include <cfenv>
#include <cmath>
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

int main() {
  std::cout.precision(30);

  for (const int round_policy :
       {FE_DOWNWARD, FE_UPWARD, FE_TONEAREST, FE_TOWARDZERO}) {
    std::fesetround(round_policy);

    std::cout << getRoundPolicy(round_policy) << '\n';

    std::cout << " std::sqrt(2) =  " << std::sqrt(2.0f) << '\n';

    std::cout << '\n';
  }

  return 0;
}