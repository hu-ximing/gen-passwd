# gen-passwd

## Description

Generate true random passwords where applicable.

## Specifications

Generate 10 20-charater strings by default.

Run `gen-passwd -h` to show help

```output
Usage: gen-passwd [options] [length] [count]
Options:
  -y  Use symbols. By default only letters and digits are included.
  -h  Print this help message.
```

## Examples

Example 1

```shell
gen-passwd 50 5
```

```output
ezopROXOf3W5zEQLEAlNioGnMlEBzHvnJ5Gh0swjLGfWxcNTli
BPbtrTTrmJpdi8lSpUpMhRBY7xQFCU0zdYnJr1eRjyhhPfvD8k
tOQh3YHYS3NvTGcWQr3FDIN43aHw0R1bztqnBf2a6VLBLtAZSl
BfJDSUw8e5jdxGUzcv2n0NXGUUrKB1R0dwVsPhpAKDqK5FTeyC
dyuKftab1vRzNmVlNToCa3HtO1UAAFpAJpx3EzC3SWlO4pFUTa
```

Example 2

```shell
gen-passwd -y
```

```output
"WDgd*0eG!_Yj,K,>xLB
^2Zcm`l}?Bb4#}S5J8C3
Z`#Qzr01Za?WJdX-Pr\B
Z]5O+=++GTI"up7u}qWN
!PF+0dG$0NOh0RA4m1)m
bur>k|Kv:,)#2k-9DegV
<*;Z7kKxn(8`x}b[vIj2
?b#[{iW#ks7(04DL(tt7
2vSWcr8ihBZbOx%|kY>>
Li4JMAIgByfnJEGQY`2e
```

## Concerns

This program uses C++ `random_device` class to generate random numbers from hardware where available.
As a result, when the program runs on computers without TPM or equivalent hardware, it may use predictable pseudo-random instead.

> std::random_device may be implemented in terms of an implementation-defined pseudo-random number engine if a non-deterministic source (e.g. a hardware device) is not available to the implementation. In this case each std::random_device object may generate the same number sequence.  
> [`std::random_device` on cppreference.com](https://en.cppreference.com/w/cpp/numeric/random/random_device)
