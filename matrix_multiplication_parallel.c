#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void matrixMultiplicationParallel(int **A, int **B, int **C, int N) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int N = 1000; // Define matrix size
    int **A, **B, **C;

    // Allocate memory for matrices
    A = (int **)malloc(N * sizeof(int *));
    B = (int **)malloc(N * sizeof(int *));
    C = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        A[i] = (int *)malloc(N * sizeof(int));
        B[i] = (int *)malloc(N * sizeof(int));
        C[i] = (int *)malloc(N * sizeof(int));
    }

    // Initialize matrices A and B with random values
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Set number of threads
    omp_set_num_threads(4); // Change this number to test different thread counts

    // Start time
    double start = omp_get_wtime();

    // Perform parallel matrix multiplication
    matrixMultiplicationParallel(A, B, C, N);

    // End time
    double end = omp_get_wtime();
    double time_spent = end - start;
    printf("Time taken by parallel matrix multiplication: %f seconds\n", time_spent);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
