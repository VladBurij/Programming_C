#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main() {
	double matrix[3][3], diag1, diag2;
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++){
			printf("Vvedite chislo: ");
			scanf("%lf", &matrix[i][k]);
		}
	}
	for (int i = 0; i < 3; i++) {
		printf("[%.2lf] [%.2lf] [%.2lf]\n", matrix[i][0], matrix[i][1], matrix[i][2]);
	}
	for (int i = 0; i < 3; i++) {
		diag1 += matrix[i][i];
		diag2 += matrix[i][2-i];
	}
	printf("Sum of main diagonal = %.2lf\n", diag1);
	printf("Sum of another diagonal = %.2lf\n", diag2);

	int min_matrix[2][2];
	int pow2_matrix[2][2];
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < 2; k++){
			printf("Vvedite chislo: ");
			scanf("%d", &min_matrix[i][k]);
		}
	}
	for (int i = 0; i < 2; i++) {
		printf("[%d] [%d]\n", min_matrix[i][0], min_matrix[i][1]);
	}
	pow2_matrix[0][0] = min_matrix[0][0] * min_matrix[0][0] + min_matrix[0][1] * min_matrix[1][0];
	pow2_matrix[0][1] = min_matrix[0][0] * min_matrix[0][1] + min_matrix[0][1] * min_matrix[1][1];
	pow2_matrix[1][0] = min_matrix[1][0] * min_matrix[0][0] + min_matrix[1][1] * min_matrix[1][0];
	pow2_matrix[1][1] = min_matrix[1][0] * min_matrix[0][1] + min_matrix[1][1] * min_matrix[1][1];
	printf("Kvadrat matricy raven: \n");
	for (int i = 0; i < 2; i++) {
		printf("[%d] [%d]\n", pow2_matrix[i][0], pow2_matrix[i][1]);
	}
}
