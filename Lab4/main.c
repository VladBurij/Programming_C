#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

main() {
	double x, y, z;
	printf("Vvedite storony: ");
	scanf("%lf", &x);
	printf("Vvedite storony: ");
	scanf("%lf", &y);
	printf("Vvedite storony: ");
	scanf("%lf", &z);
	if (trige_yes(x, y, z)) {
		printf("Perimetr = %.2lf \n", trige_perimetr(x, y, z));
		printf("Ploschad = %.2lf \n", trige_ploschad(x, y, z));
		printf("Select 1/2/3: ");
		printf("1) %.2lf 2) %.2lf 3) %.2lf\n", x, y, z);
		int n;
		scanf("%d", &n);
		print("%d", n);
		printf("Visota storony = %.2lf\n", trige_heigth(x, y, z, n));
	}
	else printf("Neverniye storoni, nelza vichislit\n");
}
