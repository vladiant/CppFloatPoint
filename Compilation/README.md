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

## Examples

### Simple calculation
[64-bit programs and floating-point calculations](https://pvs-studio.com/en/blog/posts/cpp/0074/)
```
float fConst = 1.4318620f;
float fValue1 = 40.598053f * (1.f - 1.4318620f / 100.f);
float fValue2 = 40.598053f * (1.f - fConst / 100.f);
```

* [GCC](https://godbolt.org/z/Go9ccn6Pd), [Clang](https://godbolt.org/z/8xfq1s9ce) : `fValue1 == fValue2 == 40.016742706298828125`

* [x86-64 icc 2021.6.0](https://godbolt.org/z/8dP5b9dxe) : `fValue1 == 40.01674652099609375` and `fValue2 == 40.016742706298828125`
* [x86-64 icc 2021.6.0 -fp-model strict](https://godbolt.org/z/fssdMsWfa) : `fValue1 == fValue2 == 40.016742706298828125`
* [x86-64 icc 2021.6.0 -fp-model precise](https://godbolt.org/z/aazh6KrcT) : `fValue1 == fValue2 == 40.016742706298828125`
* [x86-64 icc 2021.6.0 -fp-model fast](https://godbolt.org/z/KEnMrqKsv) : `fValue1 == 40.01674652099609375` and `fValue2 == 40.016742706298828125`

* [x86 MSVC v19.latest /fp:strict](https://godbolt.org/z/Gx11e6YP3)  : `fValue1 == fValue2 == 40.016742706298828125`
* [x86 MSVC v19.latest /fp:precise](https://godbolt.org/z/cr96j4374)  : `fValue1 == fValue2 == 40.016742706298828125`
* [x86 MSVC v19.latest /fp:fast](https://godbolt.org/z/v5Yhqz5YM) : `fValue1 == 40.01674652099609375` and `fValue2 == 40.016742706298828125`

### Check for special values and `-ffast-math`
* [GCC](https://godbolt.org/z/va5Wd6KEx) : all true
* [GCC -ffast-math](https://godbolt.org/z/Kn8qca3P7) : all functions checking special values are false
* [Clang](https://godbolt.org/z/9W4xYb93r) : all true
* [Clang -ffast-math](https://godbolt.org/z/h5ndd97qs) : all true

## References
* [GCC - Options That Control Optimization](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)
* [Semantics of Floating Point Math in GCC](https://gcc.gnu.org/wiki/FloatingPointMath)
* [Clang - Controlling Floating Point Behavior](https://clang.llvm.org/docs/UsersManual.html#controlling-floating-point-behavior)
* [MSVC - Specify floating-point behavior](https://learn.microsoft.com/en-us/cpp/build/reference/fp-specify-floating-point-behavior?view=msvc-170)
* [Beware of fast-math](https://simonbyrne.github.io/notes/fastmath/)
* [64-bit programs and floating-point calculations](https://pvs-studio.com/en/blog/posts/cpp/0074/)
* [CERN openlab Mini-Workshop on Floating-Point Computation 2017](https://indico.cern.ch/event/626147/)
