# Floating Point Parsing

## Use case
* Feature reads floating point values from file.
* Application was executed in Docker container.
* Unit tests were set and confirmed green.
* Application runs successfully on production for thousand of cases per day.

## Problem
* When application was run on lab machine it is no longer working.

## Root cause
* Ubuntu machine was used instead of Docker container.
* Bulgarian localization pack was applied.
* Unit tests were not executed.
* libQt reads the environment variables and set "bg_BG.UTF-8" for `LC_NUMERIC` flag instead of default `C`.
* `std::stof` fails to parse float point numbers from file. 

## Solution
* Replace `std::stof` with stream parsing with preset `C` locale.
* Consider `std::from_chars` for future use.

## Online samples
* [parse_stof.cpp](https://coliru.stacked-crooked.com/a/e17c28aa4671614c)
* [parse_from_chars.cpp](https://coliru.stacked-crooked.com/a/6c5bc449ddb8d4c4)
* [parse_stream.cpp](https://coliru.stacked-crooked.com/a/de049e3a26882660)
* [parse_quick_benchmark.cpp](parse_quick_benchmark.cpp)
* [parse_benchmark.cpp](https://godbolt.org/z/qb7MEqbfz)

## References
* [std::stof](https://en.cppreference.com/w/cpp/string/basic_string/stof)
* [std::setlocale](https://en.cppreference.com/w/cpp/locale/setlocale)
* [std::localeconv](https://en.cppreference.com/w/cpp/locale/localeconv)
* [std::locale::global](https://en.cppreference.com/w/cpp/locale/locale/global)
* [std::locale](https://en.cppreference.com/w/cpp/locale/locale)
* [std::from_chars](https://en.cppreference.com/w/cpp/utility/from_chars)
