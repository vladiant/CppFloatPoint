// Run at https://godbolt.org/
// -lpthread
// Link to Google Benchmark

#include <benchmark/benchmark.h>

#include <array>
#include <charconv>
#include <cstdio>
#include <sstream>

static void FloatToSprintf(benchmark::State& state) {
  static constexpr float value = 3.14159262180328102687099089962;

  for (auto _ : state) {
    std::array<char, 33> str{};
    snprintf(str.data(), str.size(), "%.29f", value);
    benchmark::DoNotOptimize(str);
  }
}
BENCHMARK(FloatToSprintf);

static void FloatToSprintfToString(benchmark::State& state) {
  static constexpr float value = 3.14159262180328102687099089962;

  for (auto _ : state) {
    std::array<char, 33> str{};
    snprintf(str.data(), str.size(), "%.29f", value);
    std::string stringValue{str.data()};
    benchmark::DoNotOptimize(stringValue);
  }
}
BENCHMARK(FloatToSprintfToString);

static void FloatToStream(benchmark::State& state) {
  static constexpr float value = 3.14159262180328102687099089962;

  for (auto _ : state) {
    std::ostringstream os;
    os << value;
    const std::string& stringValue = os.str();
    benchmark::DoNotOptimize(stringValue);
  }
}
BENCHMARK(FloatToStream);

static void FloatToChars(benchmark::State& state) {
  static constexpr float value = 3.14159262180328102687099089962;

  for (auto _ : state) {
    std::array<char, 33> str{};
    std::to_chars(str.begin(), str.end(), value, std::chars_format::fixed, 29);
    benchmark::DoNotOptimize(str);
  }
}
BENCHMARK(FloatToChars);

static void FloatToCharsToString(benchmark::State& state) {
  static constexpr float value = 3.14159262180328102687099089962;

  for (auto _ : state) {
    std::array<char, 33> str{};
    std::to_chars(str.begin(), str.end(), value, std::chars_format::fixed, 29);
    std::string stringValue{str.data()};
    benchmark::DoNotOptimize(stringValue);
  }
}
BENCHMARK(FloatToCharsToString);

BENCHMARK_MAIN();
