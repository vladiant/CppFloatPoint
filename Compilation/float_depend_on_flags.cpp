// Based on https://pvs-studio.com/en/blog/posts/cpp/0074/

// #include <iostream>

// Flags have no effect in GCC, Clang
// MSVC x64 and x86 v19.latest
// /fp:fast fails fValue1 == 40.01674652099609375 fValue2
// == 40.016742706298828125

int main() {
  float fConst = 1.4318620f;
  float fValue1 = 40.598053f * (1.f - 1.4318620f / 100.f);
  float fValue2 = 40.598053f * (1.f - fConst / 100.f);

  // 40.016742706298828125 (fValue1 40.01674652099609375 icc -fp-model fast)
  // std::cout.precision(30);
  // std::cout << fValue1 << '\n';
  // std::cout << fValue2 << '\n';

  return (fValue1 == fValue2);
}
