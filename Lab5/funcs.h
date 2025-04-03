#include <stdio.h>
#include <stdlib.h>

double** plus(double **m1, double **m2, int r) {
    int i, k, j;
    double **m;
	m = (double**)malloc(r*sizeof(double*));
	for(i = 0; i < r; i++) m[i]= (double*)malloc(r*sizeof(double));
    for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++) m[i][k] = m1[i][k] + m2[i][k];
	}
    return m;
}

double** minus(double **m1, double **m2, int r) {
    int i, k, j;
    double **m;
	m = (double**)malloc(r*sizeof(double*));
	for(i = 0; i < r; i++) m[i]= (double*)malloc(r*sizeof(double));
    for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++) m[i][k] = m1[i][k] - m2[i][k];
	}
    return m;
}

double** multi(double **m1, double **m2, int r) {
    int i, k, j;
    double **m;
	m = (double**)malloc(r*sizeof(double*));
	for(i = 0; i < r; i++) m[i]= (double*)malloc(r*sizeof(double));
    for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++) {
			m[i][k] = 0;
			for (j = 0; j < r; j++) m[i][k] += m1[i][j] * m2[j][k];
		}
	}
    return m;
}
