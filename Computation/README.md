# Floating point computation

## Summation

### Traditional
* Prone to errors

### Sorting and Insertion
* Reorder the operands

### Compensated 
* Based on FastTwoSum and TwoSum techniques
* Knowledge of the exact rounding error in a floating-point addition is used to correct the summation
* Developed by William Kahan

### Hints
* If higher precision is available, use it

## Convergence
* Round-off error can affect the convergence
* Example:  Archimedes PI approximation
* Subtraction 1 from a number extremely close to 1 leads to an increasingly problematic loss of significant digits.

## Wrong Convergence
* Section 1.3.2 of “Handbook of Floating-Point Arithmetic”
* Example of an algorithm implemented in finite-precision floating-point arithmetic, actually solves a slightly different problem than from which it was derived algebraically.
* The computed value of fourth iteration is slightly incorrect due to round-off errors.
* Each succeeding iteration is incorrect, and the errors grow as the recursion calculation proceeds.
* Thus the expansion being calculated actually corresponds to a slightly different problem with different convergence value - `100`.
* Using the `Boost.Multiprecision` converges iterations slowly to correct value.

## Online samples
* [summation.cpp](https://godbolt.org/z/8vjavTj89)
* [summation_stdfloat.cpp](https://godbolt.org/z/vM9dTjKab)
* [unstable_convergence.cpp](https://godbolt.org/z/jbTejnWhj)
* [stable_convergence.cpp](https://godbolt.org/z/zzMTc4e13)

## References
* [Machine precision and backward error analysis](https://en.wikipedia.org/wiki/Floating-point_arithmetic)
* [CERN openlab Mini-Workshop on Floating-Point Computation](https://indico.cern.ch/event/626147/)
* [Boost.Multiprecision](https://www.boost.org/doc/libs/1_80_0/libs/multiprecision/doc/html/index.html)
* [Handbook of Floating-Point Arithmetic](http://www.springer.com/us/book/9780817647049)
* [How Futile are Mindless Assessments of Roundoff in Floating-Point Computation?](http://www.eecs.berkeley.edu/~wkahan/Mindless.pdf)
* [Summing an array of floating point numbers](https://www.johndcook.com/blog/2019/11/05/kahan/)
* [Kahan summation algorithm](https://en.wikipedia.org/wiki/Kahan_summation_algorithm)

