#include <algorithm>
#include <chrono>
#include <execution>
#include <functional>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include <boost/multiprecision/cpp_dec_float.hpp>

// Based on:
// "A refresher on the floating-point computations and the standard library."
// Boguslaw Cyganek https://www.youtube.com/watch?v=7aZbYJ5UTC8
//
// P = [v, -v]*[w, w] = v.w - v.w = 0
// * Dot product - Multiply and add method
// * Computes elementwise producst, sorts them and does summation
// * Kahan summation method
// * Sequential
// * Parallel

// Compile under Linux (TBB should be installed)
// g++ summation.cpp -std=c++20 -ltbb

using boost::multiprecision::cpp_dec_float_50;

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

template <typename T>
auto calcDotProductStdAlg(const std::vector<T>& v, const std::vector<T>& w) {
  // The last argument is an initial value
  return std::inner_product(std::begin(v), std::end(v), std::begin(w), T{});
}

template <typename T>
auto calcDotProductSortAlg(const std::vector<T>& v, const std::vector<T>& w) {
  std::vector<T> z;  // Stores element-wise products

  {
    TimeInterval t{"  transform  "};
    std::transform(std::begin(v), std::end(v), std::begin(w),
                   std::back_inserter(z), std::multiplies{});
  }

  {
    TimeInterval t{"  sort       "};
    // Sort in descending order
    std::sort(std::begin(z), std::end(z), [](const auto& lhs, const auto& rhs) {
      return abs(lhs) < abs(rhs);
    });
  }

  T result{};
  {
    TimeInterval t{"  accumulate "};
    result = std::accumulate(std::begin(z), std::end(z), T{});
  }

  return result;
}

template <typename T>
auto calcDotProductKahanAlg(const std::vector<T>& v, const std::vector<T>& w) {
  T theSum{};
  T c{};  // a "correction" coefficient
  const auto kElems = std::min(v.size(), w.size());

  for (size_t i = 0; i < kElems; i++) {
    const T y = v[i] * w[i] - c;  // From y subtracts the correction factor

    const T t = theSum + y;  // Add corrected summand to the running sum theSum
    // Lower bits will be lost (theSum >> y)

    c = (t - theSum) - y;
    // High order bits are computed in (t - theSum)
    // When y is subtracted then lower bits are recovered

    theSum = t;
  }

  return theSum;
}

// Result may be different on each execution
// due to the parallel computation implementation
template <typename T>
auto calcDotProductStdAlgPar(const std::vector<T>& v, const std::vector<T>& w) {
  return std::transform_reduce(std::execution::par, std::begin(v), std::end(v),
                               std::begin(w), T{});
}

template <typename T>
auto calcDotProductSortAlgPar(const std::vector<T>& v,
                              const std::vector<T>& w) {
  std::vector<T> z;  // Stores element-wise products

  {
    TimeInterval t{"  set storage"};
    z.resize(std::min(v.size(), w.size()));
  }

  {
    TimeInterval t{"  transform  "};
    std::transform(std::execution::par, std::begin(v), std::end(v),
                   std::begin(w), std::begin(z), std::multiplies{});
  }

  {
    TimeInterval t{"  sort       "};
    // Sort in descending order
    std::sort(
        std::execution::par, std::begin(z), std::end(z),
        [](const auto& lhs, const auto& rhs) { return abs(lhs) < abs(rhs); });
  }

  T result{};
  {
    TimeInterval t{"  accumulate "};
    // The last argument is an initial value
    result = std::accumulate(std::begin(z), std::end(z), T{});
  }

  return result;
}

template <typename T>
void fillNumericalData(std::vector<T>& dataContainer, size_t dataSize,
                       long double dataBorder) {
  dataContainer.resize(dataSize);

  std::random_device rd{};
  std::mt19937 rand_gen{rd()};  // Random Mersenne twister

  // Seed value set to guarantee results reproducibility
  rand_gen.seed(4321);

  std::uniform_real_distribution<long double> dist(-dataBorder, +dataBorder);
  std::generate(std::begin(dataContainer), std::end(dataContainer),
                [&dist, &rand_gen]() { return dist(rand_gen); });
}

template <typename T>
void duplicate(std::vector<T>& dataContainer, T multFactor) {
  const auto kElems = dataContainer.size();
  dataContainer.resize(2 * kElems);

  auto inIterator = std::begin(dataContainer);
  auto outBeginIterator = inIterator;
  std::advance(outBeginIterator, kElems);

  std::generate(outBeginIterator, std::end(dataContainer),
                [&inIterator, &dataContainer, multFactor]() mutable {
                  return (*inIterator++) * multFactor;
                });
}

template <typename T>
void benchmarckDotProduct() {
  constexpr auto N = 500000;
  std::vector<T> v, w;

  auto dExp = 10;  // 10, 30, 50, 100, 300, 500

  fillNumericalData(v, N, std::pow(2.0, dExp));
  duplicate(v, static_cast<T>(+1.0));

  fillNumericalData(w, N, std::pow(2.0, dExp));
  duplicate(w, static_cast<T>(-1.0));

  std::cout.precision(30);

  {
    TimeInterval t{"Std          "};
    std::cout << t.getName() << " value: " << calcDotProductStdAlg(v, w)
              << '\n';
  }

  {
    TimeInterval t{"Sort         "};
    std::cout << t.getName() << '\n';
    const auto value = calcDotProductSortAlg(v, w);
    std::cout << "              value: " << value << '\n';
  }

  {
    TimeInterval t{"Kahan        "};
    std::cout << t.getName() << " value: " << calcDotProductKahanAlg(v, w)
              << '\n';
  }

  {
    TimeInterval t{"Std Parallel "};
    std::cout << t.getName() << " value: " << calcDotProductStdAlgPar(v, w)
              << '\n';
  }

  {
    TimeInterval t{"Sort Parallel"};
    std::cout << t.getName() << '\n';
    const auto value = calcDotProductSortAlgPar(v, w);
    std::cout << "              value: " << value << '\n';
  }
}

int main() {
  std::cout << "cpp_dec_float_50:\n";
  benchmarckDotProduct<cpp_dec_float_50>();

  return 0;
}