#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for the minimum and maximum values in the array
#define MIN_VAL -25
#define MAX_VAL 74

/**
 * Algorithm 2: Efficient implementation of finding the maximum subarray sum.
 * Time complexity: O(n^2)
 *
 * @param array Pointer to the array of integers.
 * @param size The size of the array.
 * @return The maximum sum of any contiguous subarray.
 */
int max_subarray_sum_n2(int *array, int size) {
    int best = 0;
    for (int a = 0; a < size; a++) {
        int sum = 0;
        for (int b = a; b < size; b++) {
            sum += array[b];
            if (sum > best) {
                best = sum;
            }
        }
    }
    return best;
}

int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments are provided
    if (argc != 3) {
        printf("Usage: %s <random_seed> <array_size>\n", argv[0]);
        return 1;
    }

    // Convert command-line arguments to integers
    int seed = atoi(argv[1]);
    int size = atoi(argv[2]);

    // Allocate memory for the array
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize the random number generator with the provided seed
    srand(seed);
    printf("Generated array:\n[");
    for (int i = 0; i < size; i++) {
        // Generate random numbers within the range [MIN_VAL, MAX_VAL]
        array[i] = MIN_VAL + rand() % (MAX_VAL - MIN_VAL + 1);
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Calculate the maximum subarray sum using Algorithm 2
    int result = max_subarray_sum_n2(array, size);
    printf("Max Subarray Sum using Algorithm 2 is: %d\n", result);

    // Free the allocated memory
    free(array);

    return 0;
}
