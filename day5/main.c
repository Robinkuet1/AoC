#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define PART1 1176
#define PART2 195

int main() {
    FILE *file_ptr = fopen("../input.txt", "r");
    if (!file_ptr) {
        printf("Failed to open file\n");
        return 1;
    }

    int rules[100][100];

    for (int i = 0; i < PART1; i++) {
        int data[2];
        fscanf(file_ptr, "%d|%d", &data[0], &data[1]);
        printf("%d%d\n", data[0], data[1]);

        for(int x = 0; x < 100; x++) {
            if (rules[data[0]][x] == 0) {
                rules[data[0]][x] = data[1];
            }
        }
    }

    getc(file_ptr);

    for (int i = 0; i < PART2; i++) {
        int list[100];
        fscanf(file_ptr, "%d", &list[0]);
        char c = fgetc(file_ptr);

        int x = 0;
        while (c != '\n') {
            fscanf(file_ptr, "%d", &list[++x]);
            c = fgetc(file_ptr);

            for(int y = 0; y < x; y++) {
                for (int z = 0; z < x; z++) {

                }
            }
        }
    }
}
