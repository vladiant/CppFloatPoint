#include <cfenv>
#include <charconv>
#include <iostream>
#include <string_view>

void parseFloat(std::string_view literal, float& value) {
  std::from_chars(std::begin(literal), std::end(literal), value);
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
  constexpr std::string_view v1_literal =
      R"lit(3.1415926218032810268709908996243)lit";

  constexpr std::string_view v2_literal =
      R"lit(3.14159262657165250232083053560928)lit";

  constexpr std::string_view v3_literal =
      R"lit(3.14159273624421819803842481633183)lit";

  constexpr std::string_view v4_literal =
      R"lit(3.1415927410125679131169817992486)lit";

  constexpr std::string_view v5_literal =
      R"lit(3.14159274101259011757747430237942)lit";

  constexpr std::string_view v6_literal =
      R"lit(3.14159274578093938856682143523357)lit";

  constexpr std::string_view v7_literal =
      R"lit(3.14159286022185479936297269887291)lit";

  constexpr std::string_view v8_literal =
      R"lit(3.14159286499022627481281233485788)lit";

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

    // std::from_chars always follows FE_TONEAREST

    std::cout << getRoundPolicy(round_policy) << '\n';

    // 3.141592502593994140625
    std::cout << v1 << '\n';

    // 3.1415927410125732421875
    std::cout << v2 << '\n';

    // 3.1415927410125732421875
    std::cout << v3 << '\n';

    // 3.1415927410125732421875
    std::cout << v4 << '\n';

    // 3.1415927410125732421875
    std::cout << v5 << '\n';

    // 3.1415927410125732421875
    std::cout << v6 << '\n';

    // 3.1415927410125732421875
    std::cout << v7 << '\n';

    // 3.14159297943115234375
    std::cout << v8 << '\n';

    std::cout << '\n';
  }

  return 0;
}