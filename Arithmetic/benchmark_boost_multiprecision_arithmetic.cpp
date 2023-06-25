#include <boost/multiprecision/cpp_dec_float.hpp>
#include <chrono>
#include <iostream>
#include <random>
#include <string>

class TimeInterval {
 public:
  TimeInterval(std::string name) : mName{std::move(name)} {}
  ~TimeInterval() {
    std::chrono::duration<float, std::milli> elapsed_seconds =
        std::chrono::steady_clock::now() - mStart;
    std::cout << mName << " elapsed time: " << elapsed_seconds.count()
              << "ms\n";
  }

  std::string getName() const { return mName; }

 private:
  const std::string mName;
  const std::chrono::time_point<std::chrono::steady_clock> mStart =
      std::chrono::steady_clock::now();
};

template <typename Type>
void benchmarkArithmetic(const std::string& name) {
  constexpr auto numIterations = 1000000;
  std::cout << name << '\n';

  Type v = 0;

  std::random_device rd{};
  std::mt19937 rand_gen{rd()};  // Random Mersenne twister

  // Seed value set to guarantee results reproducibility
  rand_gen.seed(4321);

  std::uniform_int_distribution<> dist(0, 256);

  // Do not use constants or repeating values
  // to avoid loop unroll optimizations.
  // All values > 0 to avoid division by 0
  Type v0 = static_cast<Type>(dist(rand_gen)) / 16 + 1;
  Type v1 = static_cast<Type>(dist(rand_gen)) / 16 + 1;
  Type v2 = static_cast<Type>(dist(rand_gen)) / 16 + 1;
  Type v3 = static_cast<Type>(dist(rand_gen)) / 16 + 1;
  Type v4 = static_cast<Type>(dist(rand_gen)) / 16 + 1;
  Type v5 = static_cast<Type>(dist(rand_gen)) / 16 + 1;
  Type v6 = static_cast<Type>(dist(rand_gen)) / 16 + 1;
  Type v7 = static_cast<Type>(dist(rand_gen)) / 16 + 1;

  {
    TimeInterval t{"  Add         "};
    for (size_t i = 0; i < numIterations; ++i) {
      v += v0;
      v += v2;
      v += v4;
      v += v6;
    }
  }

  {
    TimeInterval t{"  Subtract    "};
    for (size_t i = 0; i < numIterations; ++i) {
      v -= v1;
      v -= v3;
      v -= v5;
      v -= v7;
    }
  }

  {
    TimeInterval t{"  Multiply    "};
    for (size_t i = 0; i < numIterations; ++i) {
      v *= v0;
      v *= v2;
      v *= v4;
      v *= v6;
    }
  }

  {
    TimeInterval t{"  Divide      "};
    for (size_t i = 0; i < numIterations; ++i) {
      v /= v1;
      v /= v3;
      v /= v5;
      v /= v7;
    }
  }

  std::cout << '\n';
}

int main() {
  benchmarkArithmetic<float>("float");
  benchmarkArithmetic<double>("double");
  benchmarkArithmetic<long double>("long double");

  benchmarkArithmetic<boost::multiprecision::cpp_dec_float_50>(
      "cpp_dec_float_50");
  benchmarkArithmetic<boost::multiprecision::cpp_dec_float_100>(
      "cpp_dec_float_100");

  return 0;
}
