# Floating point related compilation flags

## Value Safety
The compiler may not make changes such as
* Reassociations: `(x + y) + z ⇔ x + (y + z) `
* Distributions: `x ∗ (y + z) ⇔ x ∗ y + x ∗ z`
* May change under-/overflow behavior: `x ∗ (y ∗ z) <-> (x ∗ y) ∗ z`
* x may be 0, `inf` or a `NaN`: `x/x <-> 1.0`
* x may be `-0`, or a `NaN`:`x + 0 <-> x`
* x may be `-0`, `inf` or a `NaN`: `x ∗ 0 <-> 0`

## Optimizations Affecting Value Safety
* Expression rearrangements
* Flush-to-zero (Replace all generated subnormals with 0)
* Approximate division and square root
* Math library accuracy

## IEEE 754 compliance - Full
* Support infinities, NaNs, gradual underflow, signed zeros, exception flags and traps, setting rounding modes.
* GCC : `-frounding-math` `-fsignaling-nans`
* Clang : `-ffp-model=strict`
* MSVC : `/fp:strict`

## IEEE 754 compliance - Default
* Assumes round to nearest or even and does not care about signalling NaNs.
* GCC : no specific flags
* Clang : `-ffp-model=precise`
* MSVC : `/fp:precise`

## IEEE 754 compliance - Relaxed
* This mode enables optimizations that allow arbitrary reassociations and transformations with no accuracy guarantees. It also does not try to preserve the sign of zeros.
* GCC : `-funsafe-math-optimizations`
* Clang : `-ffp-model=fast`
* MSVC : `/fp:fast`

## Fast math
* Turns on reassociation along with unsafe assumptions such as a lack of NaN and infinite numbers in IEEE 754. 
* Some compilers also offer more granular options to only turn on reassociation. 
* In some compilers (GCC and Clang), turning on "fast" math may cause the program to disable subnormal floats at startup, affecting the floating-point behavior of not only the generated code, but also any program using such code as a library.
* A common problem in "fast" math is that subexpressions may not be optimized identically from place to place, leading to unexpected differences.
* GCC, Clang : `-ffast-math`
* MSVC : `/fp:fast`

## CPU
CPU manufacturer can impact results. Not all floating-point instructions execute exactly the same on AMD and Intel processors

* The rsqrt and rcp instructions differ
* They are not standardized
* Both implementations meet the specification given by Intel

The exact same non-vectorized, non-parallelized, non-threaded application may give different results on systems with similar processors.

## References
* [GCC - Options That Control Optimization](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)
* [Semantics of Floating Point Math in GCC](https://gcc.gnu.org/wiki/FloatingPointMath)
* [Clang - Controlling Floating Point Behavior](https://clang.llvm.org/docs/UsersManual.html#controlling-floating-point-behavior)
* [MSVC - Specify floating-point behavior](https://learn.microsoft.com/en-us/cpp/build/reference/fp-specify-floating-point-behavior?view=msvc-170)
* [Beware of fast-math](https://simonbyrne.github.io/notes/fastmath/)
* [64-bit programs and floating-point calculations](https://pvs-studio.com/en/blog/posts/cpp/0074/)
* [CERN openlab Mini-Workshop on Floating-Point Computation 2017](https://indico.cern.ch/event/626147/)
