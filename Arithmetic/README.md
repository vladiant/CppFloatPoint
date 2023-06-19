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

## Binary Fused Multiply-Add (FMA)
* Computes `x * y + z` as if to infinite precision and rounded only once to fit the result type.
* This operation is commonly implemented in hardware as fused multiply-add CPU instruction.
* Infinite intermediate precision like [std::sqrt](https://en.cppreference.com/w/cpp/numeric/math/sqrt)

## References
* [Catastrophic cancellation](https://en.wikipedia.org/wiki/Catastrophic_cancellation)
* [std::fma](https://en.cppreference.com/w/cpp/numeric/math/fma)

