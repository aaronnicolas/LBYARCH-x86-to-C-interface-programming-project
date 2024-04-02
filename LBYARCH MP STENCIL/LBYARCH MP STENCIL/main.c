#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern double asmSolveStencil(double* X, double* Y, int size);

void stencil_Y(double* X, double* Y, int n)
{
    for (int i = 3; i < n - 3; i++)
    {
        Y[i] = X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3];
    }
}

int compareArrays(double* arr1, double* arr2, int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i + 3]) {
            return 0; // Arrays are not the same
        }
    }
    return 1; // Arrays are the same
}

int main()
{
    /* for execution time */
    #define loops 30 // # of times to run
    LARGE_INTEGER frequency;
    long long int start, end;
    double PCFreq, elapse;
    QueryPerformanceFrequency(&frequency);
    PCFreq = (double)(frequency.QuadPart);

    int exponent;
    printf("Enter the exponent for the size of the array (power of 2): ");
    scanf_s("%d", &exponent);

    if (exponent < 3) {
        printf("Exponent must be greater than or equal to 3.\n");
        return 1;
    }

    int n = 1 << exponent; // Equivalent to 2 raised to the power of exponent
    int size = n - 7;

    double* X = (double*)malloc(n * sizeof(double));
    double* Y_asm = (double*)malloc(n * sizeof(double)); // For Assembly
    double* Y_c = (double*)malloc(n * sizeof(double)); // For C

    if (X == NULL || Y_asm == NULL || Y_c == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Populate X array with sequential numbers starting from 1
    for (int i = 0; i < n; i++) {
        X[i] = i + 1.0;
    }

    double assembly_elapse = 0.0;
    for (int i = 0; i < loops; i++) {
        QueryPerformanceCounter(&frequency);
        start = frequency.QuadPart;
        asmSolveStencil(X, Y_asm, size);
        QueryPerformanceCounter(&frequency);
        end = frequency.QuadPart;
        elapse = ((double)(end - start)) * 1000.0 / PCFreq;
        assembly_elapse += elapse;
    }

    double c_elapse = 0.0;
    for (int i = 0; i < loops; i++) {
        QueryPerformanceCounter(&frequency);
        start = frequency.QuadPart;
        stencil_Y(X, Y_c, n);
        QueryPerformanceCounter(&frequency);
        end = frequency.QuadPart;
        elapse = ((double)(end - start)) * 1000.0 / PCFreq;
        c_elapse += elapse;
    }

    printf("x86-64 Assembly \n");
    printf("Output: Y -> ");
    for (int i = 0; i <= size; i++) {
        printf("%.2f ", Y_asm[i]);
    }
    printf("\n\n");

    printf("C version \n");
    printf("Output: Y -> ");
    for (int i = 3; i < n - 3; i++)
    {
        printf("%.2f ", Y_c[i]);
    }
    printf("\n");

    printf("\nERROR CHECKING: \n");
    int result = compareArrays(Y_asm, Y_c, size);
    if (result == 1) {
        printf("Both kernels returned the same results.\n");
    }
    else {
        printf("Not the same.\n");
    }

    printf("\nAVERAGE EXECUTION TIME OF THE KERNEL PORTION IN THE 30 RUNS:\n");
    printf("\t   x86-64: %f ms \n", assembly_elapse / loops);
    printf("\tC version: %f ms \n", c_elapse / loops);

    free(X);
    free(Y_asm);
    free(Y_c);
    return 0;
}