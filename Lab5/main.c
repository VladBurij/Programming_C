#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

main() {
	int r;
	char operation;
	printf("Vvedite razmer matricy: ");
	scanf("%d", &r);
	double matrix1[r][r];
	for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++){
			printf("Vvedite chislo: ");
			scanf("%lf", &matrix1[i][k]);
		}
	}
	double matrix2[r][r];
	for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++){
			printf("Vvedite chislo: ");
			scanf("%lf", &matrix2[i][k]);
		}
	}
	for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++){
			printf("[%.2lf] ", matrix[i][k]);
		}
		printf("\n");
	}
	printf("----------")
	for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++){
			printf("[%.2lf] ", matrix2[i][k]);
		}
		printf("\n");
	}
	printf("Select operation: +, -, *\n");
	switch(operation) {
		case '+':
			
			break;
		case '-':
			
			break;
		case '*':
			
			break;
		default: 
			printf("Unindentefite operation: +, -, *\n");;
	
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
