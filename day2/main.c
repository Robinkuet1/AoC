#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1000

int is_valid_sequence(int count, int* data) {
    bool is_increasing = true;
    bool is_decreasing = true;

    for (int i = 1; i < count; ++i) {
        if (data[i] > data[i - 1]) {
            is_decreasing = false;  // Sequence is not decreasing
        }
        if (data[i] < data[i - 1]) {
            is_increasing = false;  // Sequence is not increasing
        }
    }

    // If the sequence is neither increasing nor decreasing, return false
    if (!is_increasing && !is_decreasing) {
        return 0;
    }

    // Check the difference between adjacent levels
    for (int i = 1; i < count; ++i) {
        int diff = abs(data[i] - data[i - 1]);
        if (diff < 1 || diff > 3) {
            return 0;  // Difference is outside the allowed range
        }
    }

    return 1;  // All conditions are met, return true (valid)
}

// Function to check if removing one level can make the sequence valid
int is_valid(int count, int* data) {
    // First, check if the sequence is already valid
    if (is_valid_sequence(count, data)) {
        return 1;
    }

    // Try removing one level and check if the sequence becomes valid
    for (int i = 0; i < count; ++i) {
        // Create a new array without the i-th level
        int new_count = count - 1;
        int* new_data = (int*)malloc(new_count * sizeof(int));

        for (int j = 0, k = 0; j < count; ++j) {
            if (j != i) {
                new_data[k++] = data[j];
            }
        }

        // Check if the new sequence is valid
        if (is_valid_sequence(new_count, new_data)) {
            free(new_data);  // Don't forget to free the allocated memory
            return 1;
        }

        free(new_data);  // Free memory if the sequence is not valid
    }

    return 0;  // If no removal results in a valid sequence, return false
}

int main() {
    FILE *file_ptr = fopen("../input.txt", "r");
    if (!file_ptr) {
        printf("Failed to open file\n");
        return 1;
    }

    int total = 0;
    for (int i = 0; i < SIZE; i++) {
        int buff[100];
        int count = 0;
        char c = 0;
        while (c != 10 && c != EOF) {
            fscanf(file_ptr, "%d", &buff[count++]);
            c = fgetc(file_ptr);
        }
        if (is_valid(count, buff)) {
            total += 1;
        }
    }
    printf("Total valid: %d\n", total);
}
