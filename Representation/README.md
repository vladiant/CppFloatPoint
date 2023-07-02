# Floating point representation

## Notes
* Floating point types are not accurate (`std::numeric_limits<T>::is_exact`)
* Accuracy is defined by meaningful digits (`std::numeric_limits<T>::digits10`)
* Limited count of exactly representable values
* Larger type size – Better accuracy, more exactly representable value

## Online samples
* [float_representation.cpp](https://godbolt.org/z/16WYEGEEE)
* [stdfloat_representation_estimation.cpp](print_float_128.cpp)
* [float_siginifcant_digits.cpp](https://godbolt.org/z/nMx7ds113)
* [float_neighbours_representation.cpp](https://godbolt.org/z/q3Ks6Tx4E)

## References
* [Floating-point types](https://en.cppreference.com/w/cpp/language/types)
* [Floating-point literal](https://en.cppreference.com/w/cpp/language/floating_literal)
* [std::numeric_limits<T>::digits10](https://en.cppreference.com/w/cpp/types/numeric_limits/digits10)
* [std::nextafter](https://en.cppreference.com/w/cpp/numeric/math/nextafter)
