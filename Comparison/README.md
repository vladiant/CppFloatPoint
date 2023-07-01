# Floating Point Comparison

## Operator == has problem
* `-0 == 0` is `true` (bitwise not equal)
* `NaN != NaN` is `false` (bitwise equal)
* Other float numbers - bitwise comparison

## Absoulte margin comparison 
* `std::abs(lhs - rhs) < margin`
* Margin could be `std::numeric_limits<float>::epsilon` (`FLT_EPSILON`)
* The machine epsilon - the difference between 1.0 and the next value representable by the floating-point type
* For values larger than several units, margin may be too small.
* Not suitable for large numbers - same as `operator ==`
* For values closer to zero, margin may be too large.
* Does not break down around zero

## Relative epsilon comparison
* `std::abs(lhs - rhs) < eps * std::max(std::abs(lhs), std::abs(rhs))` 
* Suitable for large numbers
* Breaks down around zero

## ULP
* Units in last place
* How many "steps" need to be taken from one number to another
* Should be less than some fixed number
* Handles well large number and values close to zero
* Hard to reason decimally

## Conclusions
* `operator !=` also has problem
* Choose proper comparison algorithm

## Online samples
* [float_wrong_comparison.cpp](https://godbolt.org/z/5zo3hvWGY)
* [float_special_values_comparison.cpp](https://godbolt.org/z/WMhb667Tj)
* [float_relative_comparison_small_numbers.cpp](https://godbolt.org/z/vfWaPW3dj)
* [float_relative_comparison_large_numbers.cpp](https://godbolt.org/z/cosfGc7T3)
* [float_ulp_sample.cpp](https://godbolt.org/z/6sxzf4vYb)
* [stdfloat_types_ulp_sample.cpp](https://godbolt.org/z/x1qK7zE91)
* [float_boost_ulp_sample.cpp](https://godbolt.org/z/49c7E5f3o)

## References
* [Comparing Floating Point Numbers, 2012 Edition](https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/)
* [Boost: Floating point comparisons](https://www.boost.org/doc/libs/1_34_0/libs/test/doc/components/test_tools/floating_point_comparison.html)
* [Catch2: Floating point comparisons](https://github.com/catchorg/Catch2/blob/devel/docs/comparing-floating-point-numbers.md#top)
* [Boost ULP](https://www.boost.org/doc/libs/1_48_0/libs/math/doc/sf_and_dist/html/math_toolkit/utils/next_float/float_distance.html)


