#include <stdio.h>
#include <stdlib.h>

void digits(int num) {
    if (num == 0) return;
    int digit = num % 10;
    digits(num / 10);
    printf("%d ", digit);
}

void stigid(int num) {
    int num_l = num;
    printf("%d ", num_l % 10);
    if (num_l > 9) stigid(num_l / 10);
}

void zeros(char num[], int i) {
    if (num[i] != '0') return;
    int digit = 0;
    printf("%d ", digit);
    zeros(num, i + 1);
}

main() {
    char *num;
    scanf("%s", num);
    int number = atoi(num);
    if (num[0] == '0') zeros(num, 0);
    if (number != 0) {
        digits(number);
        printf("\n");
        stigid(number);
    }
    if (num[0] == '0') zeros(num, 0);
}
