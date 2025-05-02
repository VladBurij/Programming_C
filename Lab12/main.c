#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

main() {
    struct tm *t;
    time_t t_now;
    time(&t_now);
    t = localtime(&t_now);
	char str[10];
    char str1[10];
    int i, k;
    scanf("%s", &str);
    if (str[0] == 'n') {
        t_now = time(NULL);
        t = localtime(&t_now);
        strftime(str1, 50, "%d %B %Y", t);
        printf("Now data is %s", str1);
    }
    else if (str[4] == '.' & str[7] == '.') {
        memset(str1, '\0', sizeof(str1));
        str1[0] = str[0];
        str1[1] = str[1];
        str1[2] = str[2];
        str1[3] = str[3];
        t -> tm_year = atoi(str1) - 1900;
        str1[0] = str[5];
        str1[1] = str[6];
        str1[2] = '\0';
        t -> tm_mon = atoi(str1) - 1;
        str1[0] = str[8];
        str1[1] = str[9];
        t -> tm_mday = atoi(str1);
        mktime(t);
        strftime(str1, 50, "%A", t);
        printf("This day is %s", str1);
    }
    else if (str[4] == '.') {
        int days;
        int week[7] = {0, 0, 0, 0, 0, 0, 0};
        memset(str1, '\0', sizeof(str1));
        str1[0] = str[0];
        str1[1] = str[1];
        str1[2] = str[2];
        str1[3] = str[3];
        t -> tm_year = atoi(str1) - 1900;
        str1[0] = str[5];
        str1[1] = str[6];
        str1[2] = '\0';
        t -> tm_mon = atoi(str1) - 1;
        if (t -> tm_mon + 1 == 1 || t -> tm_mon + 1 == 3 || t -> tm_mon + 1 == 5 || t -> tm_mon + 1 == 7 || t -> tm_mon + 1 == 8 || t -> tm_mon + 1 == 10 || t -> tm_mon + 1 == 12) days = 31;
        else if (t -> tm_mon + 1 == 2 & t -> tm_year % 4 == 0) days = 29;
        else if (t -> tm_mon + 1 == 2) days = 28;
        else days = 30;
        printf("Mn Tu We Th Fr Sa Su\n");
        for (i = 1; i <= days; i++) {
            t -> tm_mday = i;
            mktime(t);
            week[t -> tm_wday] = i;
            if (t -> tm_wday == 6 & i == days) week[0] = 0;
            else if (0 < t -> tm_wday < 6 & i == days) {
                for (k = t -> tm_wday + 1; k <= 6; k++) week[k] = 0;
                week[0] = 0;
            };
            if (t -> tm_wday == 0 || i == days) printf("%d %d %d %d %d %d %d\n", week[1], week[2], week[3], week[4], week[5], week[6], week[0]);
        }
    }
    else {
        int days, mounth;
        memset(str1, '\0', sizeof(str1));
        str1[0] = str[0];
        str1[1] = str[1];
        str1[2] = str[2];
        str1[3] = str[3];
        t -> tm_year = atoi(str1) - 1900;
        for (mounth = 1; mounth <= 12; mounth++) {
            int week[7] = {0, 0, 0, 0, 0, 0, 0};
            t -> tm_mon = mounth - 1;
            if (t -> tm_mon + 1 == 1 || t -> tm_mon + 1 == 3 || t -> tm_mon + 1 == 5 || t -> tm_mon + 1 == 7 || t -> tm_mon + 1 == 8 || t -> tm_mon + 1 == 10 || t -> tm_mon + 1 == 12) days = 31;
            else if (t -> tm_mon + 1 == 2 & t -> tm_year % 4 == 0) days = 29;
            else if (t -> tm_mon + 1 == 2) days = 28;
            else days = 30;
            strftime(str1, 50, "%B", t);
            printf("%s\n", str1);
            printf("Mn Tu We Th Fr Sa Su\n");
            for (i = 1; i <= days; i++) {
                t -> tm_mday = i;
                mktime(t);
                week[t -> tm_wday] = i;
                if (t -> tm_wday == 6 & i == days) week[0] = 0;
                else if (0 < t -> tm_wday < 6 & i == days) {
                    for (k = t -> tm_wday + 1; k <= 6; k++) week[k] = 0;
                    week[0] = 0;
                };
                if (t -> tm_wday == 0 || i == days) printf("%d %d %d %d %d %d %d\n", week[1], week[2], week[3], week[4], week[5], week[6], week[0]);
            }
        }
    }
}
