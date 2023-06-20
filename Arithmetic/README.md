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

## Exceptions

* Overflow
* Underflow
* Invalid
* Inexact

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

## References
* [Catastrophic cancellation](https://en.wikipedia.org/wiki/Catastrophic_cancellation)
* [std::fma](https://en.cppreference.com/w/cpp/numeric/math/fma)
* [CERN openlab Mini-Workshop on Floating-Point Computation](https://indico.cern.ch/event/626147/)
* [Boost.Multiprecision](https://www.boost.org/doc/libs/1_80_0/libs/multiprecision/doc/html/index.html)

