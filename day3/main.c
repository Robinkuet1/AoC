#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    FILE *file_ptr = fopen("../input.txt", "r");
    if (!file_ptr) {
        printf("Failed to open file\n");
        return 1;
    }

    long long sum = 0;
    char c = 0;
    char last = 0;
    int enabled = 1;
    while (c != EOF) {
        int data[2];
        int ret = fscanf(file_ptr, "mul(%d,%d", &data[0], &data[1]);
        if (ret == 2) {
            if (getc(file_ptr) == ')') {
                sum += data[0] * data[1] * enabled;
                printf("Adding %d * %d * %d\n", data[0], data[1], enabled);
            }
        } else {
            last = c;
            c = getc(file_ptr);
            if (last == 'd' && c == 'o') {
                enabled = 1;
                if (getc(file_ptr) == 'n'){
                    if (getc(file_ptr) == '\'') {
                        if (getc(file_ptr) == 't') {
                            enabled = 0;
                        }else {
                            fseek(file_ptr, -1, SEEK_CUR);
                        }
                    } else {
                        fseek(file_ptr, -1, SEEK_CUR);
                    }
                } else {
                    fseek(file_ptr, -1, SEEK_CUR);
                }
            }
            printf("C: %c\n", c);
        }
    }
    printf("sum: %lld\n", sum);
}
