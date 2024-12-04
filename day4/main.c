#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 140
#define HEIGHT 140


int main() {
    FILE *file_ptr = fopen("../input.txt", "r");
    if (!file_ptr) {
        printf("Failed to open file\n");
        return 1;
    }

    char data[WIDTH][HEIGHT];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            data[x][y] = getc(file_ptr);
        }
        //newline
        getc(file_ptr);
    }

    long long sum = 0;
    // part 1
    /*for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            //horizontal
            if (x < (WIDTH - 3)) {
                if (data[x][y] == 'X' && data[x + 1][y] == 'M' && data[x + 2][y] == 'A' && data[x + 3][y] == 'S') {
                    ++sum;
                }
                if (data[x][y] == 'S' && data[x + 1][y] == 'A' && data[x + 2][y] == 'M' && data[x + 3][y] == 'X') {
                    ++sum;
                }
            }

            //vertical
            if (y < (HEIGHT - 3)) {
                if (data[x][y] == 'X' && data[x][y + 1] == 'M' && data[x][y + 2] == 'A' && data[x][y + 3] == 'S') {
                    ++sum;
                }
                if (data[x][y] == 'S' && data[x][y + 1] == 'A' && data[x][y + 2] == 'M' && data[x][y + 3] == 'X') {
                    ++sum;
                }
            }

            //diagonal top left to bottom right
            if (y < (HEIGHT - 3) && x < (WIDTH - 3)) {
                if (data[x][y] == 'X' && data[x + 1][y + 1] == 'M' && data[x + 2][y + 2] == 'A' && data[x + 3][y + 3] == 'S') {
                    ++sum;
                }
                if (data[x][y] == 'S' && data[x + 1][y + 1] == 'A' && data[x + 2][y + 2] == 'M' && data[x + 3][y + 3] == 'X') {
                    ++sum;
                }
            }

            //diagonal top right to bottom left
            if (x >= 3 && y < (HEIGHT - 3)) {
                if (data[x][y] == 'X' && data[x - 1][y + 1] == 'M' && data[x - 2][y + 2] == 'A' && data[x - 3][y + 3] == 'S') {
                    ++sum;
                }
                if (data[x][y] == 'S' && data[x - 1][y + 1] == 'A' && data[x - 2][y + 2] == 'M' && data[x - 3][y + 3] == 'X') {
                    ++sum;
                }
            }
        }
        printf("\n");
    }
    */

    //part 2
    for (int y = 1; y < HEIGHT - 1; y++) {
        for (int x = 1; x < WIDTH - 1; x++) {
            if (data[x][y] == 'A') {
                int mas_count = 0;
                if (data[x - 1][y - 1] == 'M' && data[x + 1][y + 1] == 'S') {
                    ++mas_count;
                }else if (data[x - 1][y - 1] == 'S' && data[x + 1][y + 1] == 'M') {
                    ++mas_count;
                }

                if (data[x + 1][y - 1] == 'M' && data[x - 1][y + 1] == 'S') {
                    ++mas_count;
                }else if (data[x + 1][y - 1] == 'S' && data[x - 1][y + 1] == 'M') {
                    ++mas_count;
                }

                if (mas_count == 2) {
                    ++sum;
                }
            }
        }
    }
    printf("Sum: %lld\n", sum);
}
