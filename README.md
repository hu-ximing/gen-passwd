# gen-passwd

## Description

Generate true random strings where applicable.

## Specifications

Generate an 18 charater string by default
```
> gen-passwd.exe
ucG8}SrsA!M#6dZGLx
```
Pass string length as an argument. In this case, the program may not be able to generate a string every time. 
```
> gen-passwd.exe 10
N3MTZ9ySX)
```

## Concerns

This program uses C++ `random_device` class to generate random numbers from hardware where available.
As a result, when the program runs on computers without TPM or equivalent hardware, it may use predictable pseudo-random instead.

> std::random_device may be implemented in terms of an implementation-defined pseudo-random number engine if a non-deterministic source (e.g. a hardware device) is not available to the implementation. In this case each std::random_device object may generate the same number sequence.  
[`std::random_device` on cppreference.com](https://en.cppreference.com/w/cpp/numeric/random/random_device)