#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main() {
    FILE *file_ptr = fopen("../input.txt", "r");
    if (!file_ptr) {
        printf("Failed to open file\n");
        return 1;
    }

    int left[SIZE], right[SIZE];
    for (int i = 0; i < SIZE; i++) {
        fscanf(file_ptr, "%d %d", &left[i], &right[i]);
    }
    fclose(file_ptr);

    //part 1
    /*
    long long sum = 0;
    for (int i = 0; i < SIZE; i++) {
        int l_min = 2000000000, l_i = -1;
        int r_min = 2000000000, r_i = -1;

        for (int l = 0; l < SIZE; l++) {
            if (left[l] != 0 && left[l] < l_min) {
                l_min = left[l];
                l_i = l;
            }
        }
        left[l_i] = 0;

        for (int r = 0; r < SIZE; r++) {
            if (right[r] != 0 && right[r] < r_min) {
                r_min = right[r];
                r_i = r;
            }
        }
        right[r_i] = 0;

        sum += abs(r_min - l_min);
    }

    printf("sum: %lld\n", sum);

    return 0;
     */

    //part 2
    long long sum = 0;
    for (int i = 0; i < SIZE; i++) {
        int l_min = 2000000000, l_i = -1;

        // Find the minimum value in the left array
        for (int l = 0; l < SIZE; l++) {
            if (left[l] != 0 && left[l] < l_min) {
                l_min = left[l];
                l_i = l;
            }
        }
        left[l_i] = 0;  // Mark the element as used

        int count = 0;
        for (int r = 0; r < SIZE; r++) {
            if (right[r] == l_min) {
                ++count;
            }
        }


        sum += abs(count * l_min);  // Add the difference to sum
    }
    printf("sum: %lld\n", sum);
    return 0;
}
