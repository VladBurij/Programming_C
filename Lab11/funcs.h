#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double sum(int n, ...)
{
    double res = 0;
    va_list list;
    va_start(list, n);
    while (n)
    {
        res += va_arg(list, double);
        --n;
    }
    va_end(list);
	return res;
}

double mid(int n, ...)
{
    double res = 0;
	int k = n;
    va_list list;
    va_start(list, n);
    while (n)
    {
        res += va_arg(list, double);
        --n;
    }
    va_end(list);
	res /= k;
	return res;
}

double max(int n, ...)
{
    double num, res;
    va_list list;
    va_start(list, n);
	res = va_arg(list, double);
	--n;
    while (n)
    {
		num = va_arg(list, double);
		if (num > res) res = num;
        --n;
    }
    va_end(list);
	return res;
}

double min(int n, ...)
{
    double num, res;
    va_list list;
    va_start(list, n);
	res = va_arg(list, double);
	--n;
    while (n)
    {
		num = va_arg(list, double);
		if (num < res) res = num;
        --n;
    }
    va_end(list);
	return res;
}
