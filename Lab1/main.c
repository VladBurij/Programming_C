#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {
	double a, b, c, d, x1, x2;
	int answ = 1;
	while (answ == 1) {
		printf("Vvedite a: ");
		scanf("%lf", &a);
		printf("Vvedite b: ");
		scanf("%lf", &b);
		printf("Vvedite c: ");
		scanf("%lf", &c);
		d = pow(b,2) - 4*a*c;
		printf("d = %.2lf \n", d);
		if (d < 0) printf("No Xs \n");
		else if (d == 0) {
			x1 = -b/(2*a);
			printf("x = %.2lf \n", x1);
		}
		else {
			x1 = (-b + sqrt(d))/(2*a);
			x2 = (-b - sqrt(d))/(2*a);
			printf("x1 = %.2lf \n", x1);
			printf("x2 = %.2lf \n", x2);
		}
		printf("Reset? 1 or 0: ");
		scanf("%d ", &answ);
	}
}
