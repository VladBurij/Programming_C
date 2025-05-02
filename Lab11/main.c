#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

main() {
	double result = sum(3, 4.0, 5.0, 2.0);
    printf("%.2lf\n", result);
    result = mid(3, 4.0, 5.0, 2.0);
    printf("%.2lf\n", result);
    result = max(3, 4.0, 5.0, 2.0);
    printf("%.2lf\n", result);
    result = min(3, 4.0, 5.0, 2.0);
    printf("%.2lf\n", result);
}
