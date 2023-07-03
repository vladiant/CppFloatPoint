# Floating point arithmetic

## Special values

### Infinity
* `inf + x = inf` when `x > -inf`
* `inf - inf = NaN`
* `inf * 0 = NaN`
* `0 / 0 = NaN`
* `inf / inf = NaN`

### NaN
* Result of every arithmetic with NaN is NaN

### Positive and negative zero or infinity
* `-0` and `0`
* Difference by sign bit only
* `1/0 = inf` 
* `1/-0 = inf`

## Exceptions
* Overflow
* Underflow
* Invalid
* Inexact
* Divide by zero

## Catastrophic cancellation
* Occurs when subtracting two nearly equal positive numbers gives a number with much less precision.
* The calculations should be rearranged.
* When `x^2 - y^2` it may be better to use `(x+y)(x-y)`

## Binary Fused Multiply-Add (FMA)
* Computes `x * y + z` as if to infinite precision and rounded only once to fit the result type.
* This operation is commonly implemented in hardware as fused multiply-add CPU instruction.
* Infinite intermediate precision like [std::sqrt](https://en.cppreference.com/w/cpp/numeric/math/sqrt)
* When `x` is close `y` for `x*x - y*y` the `std::fma(x, x, -y*y)` can be very accurate.
* Similarly for `1 - x*x` when `x` is close to `1` then `std::fma(x, x, -1.0)` is very accurate.

## Multiprecision

## Online samples
* [float_special_zeroes.cpp](https://godbolt.org/z/bo7Eex53r)
* [float_associativity_broken.cpp](https://godbolt.org/z/scqreac3P)
* [float_inexact.cpp](https://godbolt.org/z/b14EWcqr6)
* [float_loop_counter.cpp](https://godbolt.org/z/WexqK1Moa)
* [float_div_to_zero.cpp](https://godbolt.org/z/b487K4537)
* [float_invalid.cpp](https://godbolt.org/z/GPG9qa835)
* [float_nan_set.cpp](https://godbolt.org/z/dnxq1rTEh)
* [float_overflow.cpp](https://godbolt.org/z/zY74KP7K3)
* [float_underflow.cpp](https://godbolt.org/z/E1j76EhW8)
* [float_loop_increment](https://godbolt.org/z/q1T8cTanK)
* [catastrophic_cancellation.cpp](https://godbolt.org/z/54h3xxqYK)
* [benchmark_arithmetic.cpp](https://godbolt.org/z/PhabEKnqd)
* [benchmark_stdfloat_arithmetic.cpp](https://godbolt.org/z/M8cxMae5Y)

## References
* [Catastrophic cancellation](https://en.wikipedia.org/wiki/Catastrophic_cancellation)
* [std::fma](https://en.cppreference.com/w/cpp/numeric/math/fma)
* [CERN openlab Mini-Workshop on Floating-Point Computation](https://indico.cern.ch/event/626147/)
* [Boost.Multiprecision](https://www.boost.org/doc/libs/1_80_0/libs/multiprecision/doc/html/index.html)

