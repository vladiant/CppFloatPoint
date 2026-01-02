#include <chrono>
#include <iostream>
#include <random>
#include <stdfloat>
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
  benchmarkArithmetic<std::float16_t>("std::float16_t");
  benchmarkArithmetic<std::bfloat16_t>("std::bfloat16_t");
  benchmarkArithmetic<std::float32_t>("std::float32_t");
  benchmarkArithmetic<std::float64_t>("std::float64_t");
  benchmarkArithmetic<std::float128_t>("std::float128_t");

  benchmarkArithmetic<int8_t>("int8_t");
  benchmarkArithmetic<int16_t>("int16_t");
  benchmarkArithmetic<int32_t>("int32_t");
  benchmarkArithmetic<int64_t>("int64_t");

  benchmarkArithmetic<float>("float");
  benchmarkArithmetic<double>("double");
  benchmarkArithmetic<long double>("long double");

  return 0;
}
