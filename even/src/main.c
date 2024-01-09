#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool even(int x) {
    return x % 2 == 0;
}

void process(int *numbers, size_t size, bool (*predicate)(int)) {
    for (size_t i = 0; i < size; ++i) {
        if (predicate(numbers[i])) {
            printf("Even number from the list - %d\n", numbers[i]);
        }
    }
}

int main(void) {
    // VARIABLES
    int xs[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    // PROGRAM
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    size_t xs_len = sizeof(xs) / sizeof(xs[0]);
    int *numbers = (int*)malloc(xs_len * sizeof(int));

    for (size_t i = 0; i < xs_len; ++i) {
        numbers[i] = xs[i];
    }

    process(numbers, xs_len, even);

    clock_gettime(CLOCK_MONOTONIC, &end);

    free(numbers);

    // PROGRAM TIME
    double execution_time = (double)(end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    printf("Time: %f s\n", execution_time);

    return 0;
}
