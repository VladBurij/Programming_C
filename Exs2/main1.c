#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void print_matrix(FILE *f, double **matrix, int r, int c){
	int i, k;
	for (i = 0; i < r; i++) {
		for (k = 0; k < c; k++) {
            fprintf(f, "%.2lf ", matrix[i][k]);
        }
        fprintf(f, "\n");
	}
}

double** plus(double **m1, double **m2, int r, int c) {
    int i, k, j;
    double **m;
	m = (double**)malloc(r*sizeof(double*));
	for (i = 0; i < r; i++) m[i]= (double*)malloc(c*sizeof(double));
    for (i = 0; i < r; i++) {
		for (k = 0; k < c; k++) m[i][k] = m1[i][k] + m2[i][k];
	}
    return m;
}

double** multi(double **m1, double **m2, int r, int c) {
    int i, k, j;
    double **m;
	m = (double**)malloc(r*sizeof(double*));
	for(i = 0; i < r; i++) m[i]= (double*)malloc(r*sizeof(double));
    for (i = 0; i < r; i++) {
		for (k = 0; k < c; k++) {
			m[i][k] = 0;
			for (j = 0; j < r; j++) m[i][k] += m1[i][j] * m2[j][k];
		}
	}
    return m;
}

int main() {
    // Подсчёт времени
    clock_t timer;
    timer = clock();
    srand(time(NULL));
    // Задание 1
    struct tm t;
    time_t time_f, time_now;
    time(&time_now);
    int day, mounth, year;
    double days;
    FILE *f_1 = fopen("C:/Users/Vlad/Desktop/prog_C/input_1.txt", "r");
    fscanf(f_1, "%d.%d.%d", &day, &mounth, &year);
    t.tm_mday = day;
    t.tm_mon = mounth - 1;
    t.tm_year = year - 1900;
    time_f = mktime(&t);
    days = difftime(time_f, time_now) / (60 * 60 * 24);
    printf("Days to %d.%d.%d => %d\n", day, mounth, year, (int)days);
    fclose(f_1);
    // Задание 2
    FILE *f_2 = fopen("C:/Users/Vlad/Desktop/prog_C/input_2.txt", "w");
    int i, k, r1, r2;
    double **matrix1, **matrix2;
    printf("Vvedite razmer matricy: ");
	scanf("%d", &r1);
    matrix1 = (double**)malloc(r1*sizeof(double*));
	for(i = 0; i < r1; i++) matrix1[i]= (double*)malloc(r1*sizeof(double));
	for (i = 0; i < r1; i++) {
		for (k = 0; k < r1; k++){
			printf("Vvedite chislo: ");
            scanf("%lf", &matrix1[i][k]);
			fprintf(f_2, "%.2lf ", matrix1[i][k]);
		}
        fprintf(f_2, "\n");
	}
    fprintf(f_2, "-------------\n");
    printf("Vvedite razmer matricy: ");
	scanf("%d", &r2);
    matrix2 = (double**)malloc(r2*sizeof(double*));
	for(i = 0; i < r2; i++) matrix2[i]= (double*)malloc(r2*sizeof(double));
	for (i = 0; i < r2; i++) {
		for (k = 0; k < r2; k++) {
			printf("Vvedite chislo: ");
            scanf("%lf", &matrix2[i][k]);
			fprintf(f_2, "%.2lf ", matrix2[i][k]);
		}
        fprintf(f_2, "\n");
	}
    // Задание 3
    for (i = 0; i < r1; i++) free(matrix1[i]);
	free(matrix1);
	for (i = 0; i < r2; i++) free(matrix2[i]);
	free(matrix2);
    fclose(f_2);
    // Задание 4
    FILE *f = fopen("C:/Users/Vlad/Desktop/prog_C/input.txt", "r");
    FILE *f_out = fopen("C:/Users/Vlad/Desktop/prog_C/output.txt", "w");
    int c, c1 = 1, c2 = 1, first_string_1 = 1, first_string_2 = 1;
    r1 = 0, r2 = 1;
    char n[10];
    char *number;
    while ((c = fgetc(f)) != '=') {
        if (c == ' ' && first_string_1) c1++;
        else if (c == '\n') {
            r1++;
            first_string_1 = 0;
        }
    }
    fgetc(f);
    while ((c = fgetc(f)) != EOF) {
        if (c == ' ' && first_string_2) c2++;
        else if (c == '\n') {
            r2++;
            first_string_2 = 0;
        }
    }
    fclose(f);
    matrix1 = (double**)malloc(r1*sizeof(double*));
	for(i = 0; i < r1; i++) matrix1[i]= (double*)malloc(c1*sizeof(double));
    matrix2 = (double**)malloc(r2*sizeof(double*));
	for(i = 0; i < r2; i++) matrix2[i]= (double*)malloc(c2*sizeof(double));
    f = fopen("C:/Users/Vlad/Desktop/prog_C/input.txt", "r");
    int another_matrix = 0, j = 0;
    k = i = 0;
    while ((c = fgetc(f)) != EOF) {
        if (c == '=') {
            another_matrix = 1;
            k = i = 0;
            fgetc(f);
        }
        else {
            if (c == ' ') {
                if (!another_matrix) matrix1[i][k] = atof(n);
                else matrix2[i][k] = atof(n);
                k++;
                memset(n, '\0', sizeof(n));
                j = 0;
            }
            else if (c == '\n') {
                if (!another_matrix) matrix1[i][k] = atof(n);
                else matrix2[i][k] = atof(n);
                k = 0;
                i++;
                memset(n, '\0', sizeof(n));
                j = 0;
            }
            else {
                n[j] = c;
                j++;
            }
        }
    }
    matrix2[i][k] = atof(n);
    // Задание 5
    double **matrix_plus, **matrix_multi;
    if (r1 == r2 && c1 == c2) {
        matrix_plus = plus(matrix1, matrix2, r1, c1);
        fprintf(f_out, "Сумма матриц\n");
        print_matrix(f_out, matrix_plus, r2, c2);
    }
    else fprintf(f_out, "Матрицы нельзя сложить, поскольку они разного размера.\n");
    fprintf(f_out, "----\n");
    if (c1 == r2) {
        matrix_multi = multi(matrix1, matrix2, r1, c2);
        fprintf(f_out, "Произведение матриц\n");
        print_matrix(f_out, matrix_multi, r1, c2);
    }
    else fprintf(f_out, "Матрицы нельзя умножить: число столбцов в 1-й не равно кол-ву строк во 2-й\n");
    for (i = 0; i < r1; i++) free(matrix1[i]);
	free(matrix1);
	for (i = 0; i < r2; i++) free(matrix2[i]);
	free(matrix2);
    for (i = 0; i < r1; i++) free(matrix_plus[i]);
	free(matrix_plus);
	for (i = 0; i < r1; i++) free(matrix_multi[i]);
	free(matrix_multi);
    fclose(f);
    fclose(f_out);
    // Задание 6
    timer = clock() - timer;
    printf("\nTime of programm work: %f seconds\n", (float)timer / CLOCKS_PER_SEC);
    return 0;
}
