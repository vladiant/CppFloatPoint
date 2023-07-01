# Floating point rounding

## Float point environment

### Affects
* Results of floating-point arithmetic operators outside of constant expressions
* Results of standard library mathematical functions
* Floating-point to floating-point implicit conversion and casts
* String conversions
* The library rounding functions [std::nearbyint](https://en.cppreference.com/w/cpp/numeric/math/nearbyint), [std::rint](https://en.cppreference.com/w/cpp/numeric/math/rint), [std::lrint](https://en.cppreference.com/w/cpp/numeric/math/rint)

### Does NOT affect
* Floating-point to integer implicit conversion and casts (always towards zero)
* Results of floating-point arithmetic operators in expressions executed at compile time (always to nearest)
* The library functions [std::round](https://en.cppreference.com/w/cpp/numeric/math/round), [std::lround](https://en.cppreference.com/w/cpp/numeric/math/round), [std::llround](https://en.cppreference.com/w/cpp/numeric/math/round), [std::ceil](https://en.cppreference.com/w/cpp/numeric/math/ceil), [std::floor](https://en.cppreference.com/w/cpp/numeric/math/floor), [std::trunc](https://en.cppreference.com/w/cpp/numeric/math/trunc)
* [std::from_chars](https://en.cppreference.com/w/cpp/utility/from_chars) (always to nearest)
* [std::to_chars](https://en.cppreference.com/w/cpp/utility/to_chars) (always to nearest)

## Rounding style
* Used by type arithmetic 
* Can not be changed
* Usually round to nearest representable value for float point types, round to zero for integer types

## Online samples
* [float_rounding_style.cpp](https://godbolt.org/z/sTWYbE8z5)
* [float_stof_parse_rounding.cpp](https://godbolt.org/z/Tnb6Eonc1)
* [float_stream_parse_rounding.cpp](https://godbolt.org/z/dKfE59Wqe)
* [float_conversions_rounding.cpp](https://godbolt.org/z/dzexca8j1)
* [float_print_rounding.cpp](https://godbolt.org/z/11GevPcKs)
* [float_stdmath_rounding.cpp](https://godbolt.org/z/r8EjEYoE4)
* [float_arithmetic_rounding.cpp](https://godbolt.org/z/hvbxz3fq1)

## References
* [Rounding fraud](https://en.wikipedia.org/wiki/Rounding_fraud)
* [std::nextafter](https://en.cppreference.com/w/cpp/numeric/math/nextafter)
* [Floating-point environment](https://en.cppreference.com/w/cpp/numeric/fenv)
* [std::float_round_style](https://en.cppreference.com/w/cpp/types/numeric_limits/float_round_style)
* [std::numeric_limits<T>::round_style](https://en.cppreference.com/w/cpp/types/numeric_limits/round_style)
