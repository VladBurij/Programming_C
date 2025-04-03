#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"

void print_matrix(double **matrix, int r){
	int i, k;
	for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++) printf("[%.2lf] ", matrix[i][k]);
		printf("\n");
	}
}

main() {
	int r, i, k, j;
	double **matrix1, **matrix2, **matrix;

	printf("Vvedite razmer matricy: ");
	scanf("%d", &r);

	matrix1 = (double**)malloc(r*sizeof(double*));
	for(i = 0; i < r; i++) matrix1[i]= (double*)malloc(r*sizeof(double));
	for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++){
			printf("Vvedite chislo: ");
			scanf("%lf", &matrix1[i][k]);
		}
	}
	matrix2 = (double**)malloc(r*sizeof(double*));
	for(i = 0; i < r; i++) matrix2[i]= (double*)malloc(r*sizeof(double));
	for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++){
			printf("Vvedite chislo: ");
			scanf("%lf", &matrix2[i][k]);
		}
	}

	print_matrix(matrix1, r);
	printf("----------\n");
	print_matrix(matrix2, r);

	char operation;
	printf("Select operation: +, -, *:\n");
	scanf(" %c", &operation);
	switch(operation) {
		case '+':
			matrix = plus(matrix1, matrix2, r);
			print_matrix(matrix, r);
			break;
		case '-':
			matrix = minus(matrix1, matrix2, r);
			print_matrix(matrix, r);
			break;
		case '*':
			matrix = multi(matrix1, matrix2, r);
			print_matrix(matrix, r);
			break;
		default: 
			printf("Unidentified operation. Only +, -, *\n");
	}

	for(i = 0; i < r; i++) free(matrix1[i]);
	free(matrix1);
	for(i = 0; i < r; i++) free(matrix2[i]);
	free(matrix2);
	for(i = 0; i < r; i++) free(matrix[i]);
	free(matrix);
}
