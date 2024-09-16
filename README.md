# HPC-lab
# Performance Evaluation of Serial vs. Parallel Programs (OpenMP)

# Objective
This project aims to compare the performance of a serial matrix multiplication program with its parallel version using OpenMP. The key concepts include measuring speedup, efficiency, and overhead using OpenMP directives to parallelize the code.

# Key Concepts
- Speedup: The ratio of the time taken by the serial program to the time taken by the parallel program.
- Efficiency: The ratio of speedup to the number of threads.
- Overhead: The difference between the expected and actual speedup.

# Requirements
- GCC compiler with OpenMP support
- C standard library

# Files
- `matrix_multiplication_serial.c`: Serial version of matrix multiplication.
- `matrix_multiplication_parallel.c`: Parallel version of matrix multiplication using OpenMP.
- `README.md`: Project documentation.

# Compilation and Execution
#Serial Version
To compile and run the serial version:
```bash
gcc -o serial matrix_multiplication_serial.c
./serial
#Parallel Version
To compile and run the parallel version:
```bash
gcc -fopenmp -o parallel matrix_multiplication_parallel.c
./parallel
