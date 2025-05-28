#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long l_num;
    double d_num;
    int ones, i, b;
    printf("Введите число типа long: \n");
    scanf("%ld", &l_num);
    printf("Введите число типа double: \n");
    scanf("%lf", &d_num);
    ones = 0;
    for (i = sizeof(long) * 8 - 1; i > -1; i--) {
        b = (l_num >> i) & 1;
        printf("%d", b);
        if (b == 1) ones++;
    }
    printf("\nКол-во единиц в битах: %d\n", ones);
    ones = 0;
    long long dl_num;
    memcpy(&dl_num, &d_num, sizeof(double));
    for (i = sizeof(double) * 8 - 1; i > -1; i--) {
        b = (dl_num >> i) & 1;
        printf("%d", b);
        if (b == 1) ones++;
    }
    printf("\nКол-во единиц в битах: %d\n", ones);
}
