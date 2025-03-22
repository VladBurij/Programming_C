#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {
	double diag1, diag2;
	int i, k, j, r;
	printf("Vvedite razmer matricy: ");
	scanf("%d", &r);
	double matrix[r][r];
	for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++){
			printf("Vvedite chislo: ");
			scanf("%lf", &matrix[i][k]);
		}
	}
	for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++){
			printf("[%.2lf] ", matrix[i][k]);
		}
		printf("\n");
	}
	for (i = 0; i < r; i++) {
		diag1 += matrix[i][i];
		diag2 += matrix[i][r-1-i];
	}
	printf("Sum of main diagonal = %.2lf\n", diag1);
	printf("Sum of another diagonal = %.2lf\n", diag2);
	
	printf("Vvedite razmer matricy: ");
	scanf("%d", &r);
	int min_matrix[r][r];
	int pow2_matrix[r][r];
	for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++){
			printf("Vvedite chislo: ");
			scanf("%d", &min_matrix[i][k]);
		}
	}
	for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++){
			printf("[%d] ", min_matrix[i][k]);
		}
		printf("\n");
	}
	for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++) {
			pow2_matrix[i][k] = 0;
			for (j = 0; j < r; j++) {
				pow2_matrix[i][k] += min_matrix[i][j] * min_matrix[j][k];
			}
		}
	}
	printf("Kvadrat matricy raven: \n");
	for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++){
			printf("[%d] ", pow2_matrix[i][k]);
		}
		printf("\n");
	}
}
