#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {
	double matrix[3][3], diag1, diag2;
	int i, k, j;
	for (i = 0; i < 3; i++) {
		for (k = 0; k < 3; k++){
			printf("Vvedite chislo: ");
			scanf("%lf", &matrix[i][k]);
		}
	}
	for (i = 0; i < 3; i++) {
		printf("[%.2lf] [%.2lf] [%.2lf]\n", matrix[i][0], matrix[i][1], matrix[i][2]);
	}
	for (i = 0; i < 3; i++) {
		diag1 += matrix[i][i];
		diag2 += matrix[i][2-i];
	}
	printf("Sum of main diagonal = %.2lf\n", diag1);
	printf("Sum of another diagonal = %.2lf\n", diag2);
	
	printf("Vvedite razmer matricy: ");
	int r;
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
			for (j = 0; j < r; j++) {
				pow2_matrix[i][k] += min_matrix[i][j] * min_matrix[j][k];
			}
		}
	}
	//pow2_matrix[0][0] = min_matrix[0][0] * min_matrix[0][0] + min_matrix[0][1] * min_matrix[1][0];
	//pow2_matrix[0][1] = min_matrix[0][0] * min_matrix[0][1] + min_matrix[0][1] * min_matrix[1][1];
	//pow2_matrix[1][0] = min_matrix[1][0] * min_matrix[0][0] + min_matrix[1][1] * min_matrix[1][0];
	//pow2_matrix[1][1] = min_matrix[1][0] * min_matrix[0][1] + min_matrix[1][1] * min_matrix[1][1];
	printf("Kvadrat matricy raven: \n");
	for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++){
			printf("[%d] ", pow2_matrix[i][k]);
		}
		printf("\n");
	}
}
