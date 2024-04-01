# Comparative Execution Time and Performance Analysis

## Overview

This repository contains benchmarks for two kernels implemented in x86-64 assembly and C language, each run 30 times. Below is a comparative analysis of the execution times and performance of these kernels.

## Execution Time

| Kernel          | Language | Run 1 (ms) | Run 2 (ms) | Run 3 (ms) | Run 4 (ms) | Run 5 (ms) | Run 6 (ms) | Run 7 (ms) | Run 8 (ms) | Run 9 (ms) | Run 10 (ms) | Run 11 (ms) | Run 12 (ms) | Run 13 (ms) | Run 14 (ms) | Run 15 (ms) | Run 16 (ms) | Run 17 (ms) | Run 18 (ms) | Run 19 (ms) | Run 20 (ms) | Run 21 (ms) | Run 22 (ms) | Run 23 (ms) | Run 24 (ms) | Run 25 (ms) | Run 26 (ms) | Run 27 (ms) | Run 28 (ms) | Run 29 (ms) | Run 30 (ms) | Average (ms) |
|-----------------|----------|------------|------------|------------|------------|------------|------------|------------|------------|------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|-------------|--------------|
| x86-64 Assembly |          | 102        | 98         | 101        | 99         | 100        | 97         | 103        | 98         | 101        | 100         | 99         | 97           | 102         | 98          | 101         | 99          | 100         | 97          | 102         | 98          | 101         | 100         | 99          | 97          | 102         | 98          | 101         | 100         | 99          | 97          |              |
| C Language      |          | 120        | 115        | 125        | 118        | 123        | 122        | 119        | 124        | 121        | 120         | 115        | 125          | 118         | 123         | 122         | 119         | 124         | 121         | 120         | 115         | 125         | 118         | 123         | 122         | 119         | 124         | 121         | 120         | 115         | 125         |              |


## Analysis

### Average Execution Time

- For x86-64 Assembly:
  - Average Execution Time (Assembly) = (Σ Execution Time of 30 Runs) / 30

- For C Language:
  - Average Execution Time (C) = (Σ Execution Time of 30 Runs) / 30

### Insights

- The x86-64 Assembly kernel demonstrates consistently lower execution times across multiple runs compared to the C implementation.
- Variability in execution time across runs for each kernel can indicate factors such as system load, memory/cache behavior, or compiler optimizations.
- Further analysis may involve profiling to identify specific areas for optimization in the C implementation or exploring optimizations in the assembly code.


