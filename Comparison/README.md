# Floating Point Comparison

## Operator == has problem
* Does bitwise comparison
* -0 != 0 (negative zero != positive zero)
* NaN != NaN

## Direct comparison
* -0 == 0 (negative zero == positive zero)
* NaN != NaN

## Absoulte margin comparison 
* `std::abs(lhs - rhs) < margin`
* Margin could be `std::numeric_limits<float>::epsilon` (`FLT_EPSILON`)
* The machine epsilon - the difference between 1.0 and the next value representable by the floating-point type
* For values larger than several units, margin may be too small.
* Not suitable for large numbers - same as `operator ==`
* For values closer to zero, margin may be too large.
* `std::abs(lhs - rhs) < std::numeric_limits<float>::min()` - good for values close to zero
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

## References
* [Comparing Floating Point Numbers, 2012 Edition](https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/)
* [Boost: Floating point comparisons](https://www.boost.org/doc/libs/1_34_0/libs/test/doc/components/test_tools/floating_point_comparison.html)
* [Catch2: Floating point comparisons](https://github.com/catchorg/Catch2/blob/devel/docs/comparing-floating-point-numbers.md#top)

