#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcs.h"

main() {
	double x, y, z;
	printf("Vvedite storony: ");
	scanf("%lf", &x);
	printf("Vvedite storony: ");
	scanf("%lf", &y);
	printf("Vvedite storony: ");
	scanf("%lf", &z);
	if (trige_perimetr(x, y, z) == -1) printf("Neverniye storoni, nelza vichislit\n");
	else printf("Perimetr = %lf \n", trige_perimetr(x, y, z));
	if (trige_ploschad(x, y, z) == -1) printf("Neverniye storoni, nelza vichislit\n");
	else printf("Ploschad = %lf \n", trige_ploschad(x, y, z));
}
