// Run at https://godbolt.org/
// -lpthread
// Link to Google Benchmark

#include <benchmark/benchmark.h>

#include <charconv>
#include <sstream>

static void ParseStof(benchmark::State& state) {
    constexpr auto numberString = "1.5";

    for (auto _ : state) {
        float value = std::stof(numberString);
        benchmark::DoNotOptimize(value);
    }
}
BENCHMARK(ParseStof);

static void ParseStream(benchmark::State& state) {
    constexpr auto numberString = "1.5";

    for (auto _ : state) {
        std::istringstream os{numberString};
        float value{};
        os >> value;
        benchmark::DoNotOptimize(value);
    }
}
BENCHMARK(ParseStream);

static void ParseFromChars(benchmark::State& state) {
    constexpr std::string_view numberString = "1.5";

    for (auto _ : state) {
        float value{};
        std::from_chars(std::begin(numberString), std::end(numberString),
                        value);
        benchmark::DoNotOptimize(value);
    }
}
BENCHMARK(ParseFromChars);

BENCHMARK_MAIN();
