#include <cfenv>
#include <iostream>
#include <string>

void parseFloat(std::string literal, float& value) {
  value = std::stof(literal);
}

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
  const std::string v1_literal = R"lit(3.1415926218032810268709908996243)lit";

  const std::string v2_literal = R"lit(3.14159262657165250232083053560928)lit";

  const std::string v3_literal = R"lit(3.14159273624421819803842481633183)lit";

  const std::string v4_literal = R"lit(3.1415927410125679131169817992486)lit";

  const std::string v5_literal = R"lit(3.14159274101259011757747430237942)lit";

  const std::string v6_literal = R"lit(3.14159274578093938856682143523357)lit";

  const std::string v7_literal = R"lit(3.14159286022185479936297269887291)lit";

  const std::string v8_literal = R"lit(3.14159286499022627481281233485788)lit";

  std::cout.precision(30);

  for (const int round_policy :
       {FE_DOWNWARD, FE_UPWARD, FE_TONEAREST, FE_TOWARDZERO}) {
    std::fesetround(round_policy);

    float v1{};
    parseFloat(v1_literal, v1);

    float v2{};
    parseFloat(v2_literal, v2);

    float v3{};
    parseFloat(v3_literal, v3);

    float v4{};
    parseFloat(v4_literal, v4);

    float v5{};
    parseFloat(v5_literal, v5);

    float v6{};
    parseFloat(v6_literal, v6);

    float v7{};
    parseFloat(v7_literal, v7);

    float v8{};
    parseFloat(v8_literal, v8);

    std::cout << getRoundPolicy(round_policy) << '\n';

    std::cout << v1 << '\n';

    std::cout << v2 << '\n';

    std::cout << v3 << '\n';

    std::cout << v4 << '\n';

    std::cout << v5 << '\n';

    std::cout << v6 << '\n';

    std::cout << v7 << '\n';

    std::cout << v8 << '\n';

    std::cout << '\n';
  }

  return 0;
}