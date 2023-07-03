# Floating point computation example

## Introduction
* Created by Siegfried Rump <https://www.tuhh.de/ti3/rump/>
* See section 1.3.2 of “Handbook of Floating-Point Arithmetic” for more details.
* The expression should evaluate to `-54767 / 66192 = -0.82739605994...` 
* Regardless of the precision of the types used that result is never achieved
* Using the `Boost.Multiprecision` returns correct value.

## Analysis
* [Rump’s Example Revisited](https://link.springer.com/article/10.1023/A:1015569431383)
* [A remarkable example of catastrophic cancellation unraveled](https://link.springer.com/article/10.1007/s006070170028)
* [How Futile are Mindless Assessments of Roundoff in Floating-Point Computation?](http://www.eecs.berkeley.edu/~wkahan/Mindless.pdf)

## Online samples
* [rump.cpp](https://godbolt.org/z/4czT4oM9d)
* [stdfloat_rump.cpp](https://godbolt.org/z/q3bPM8chs)
* [rump_boost_multiprecision.cpp](https://godbolt.org/z/P8MGP5r6b)

## References
* [Machine precision and backward error analysis](https://en.wikipedia.org/wiki/Floating-point_arithmetic)
* [CERN openlab Mini-Workshop on Floating-Point Computation](https://indico.cern.ch/event/626147/)
* [Boost.Multiprecision](https://www.boost.org/doc/libs/1_80_0/libs/multiprecision/doc/html/index.html)
* [Handbook of Floating-Point Arithmetic](http://www.springer.com/us/book/9780817647049)

