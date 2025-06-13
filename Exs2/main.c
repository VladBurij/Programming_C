#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int **matrix, int r){
	int i, k, r_sum;
	for (i = 0; i < r; i++) {
		for (k = 0; k < r; k++) {
            r_sum += matrix[i][k];
            printf("%3d ", matrix[i][k]);
        }
        printf("sum = %d\n", r_sum);
	}
}

int main() {
    // Подсчёт времени
    clock_t timer;
    timer = clock();
    srand(time(NULL));
    // Задание 1
    int N;
    FILE *f = fopen("input.txt", "w");
    printf("Enter random number of count numbers: ");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        fprintf(f, "%d ", rand() % 50 + 1);
    fclose(f);
    // Задание 3 и 4
    f = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");
    int x;
    while (fscanf(f, "%d", &x) == 1) {
        if (x % 5 == 0 && x % 7 == 0) fprintf(f_out, "FIVESEVEN ");
        else if (x % 5 == 0) fprintf(f_out, "FIVE ");
        else if (x % 7 == 0) fprintf(f_out, "SEVEN ");
        else fprintf(f_out, "%d ", x);
    }
    fclose(f);
    fclose(f_out);
    // Задание 5 и 6
    f = fopen("input.txt", "r");
    int i, k, j, c_sum, M = 1;
    while (M * M <= N) M++;
    M--;
    printf("%d", M);
    int **matrix;
    matrix = (int**)malloc(M*sizeof(int*));
	for (i = 0; i < M; i++) matrix[i] = (int*)malloc(M*sizeof(int));
	for (i = 0; i < M; i++) {
		for (k = 0; k < M; k++){
			fscanf(f, "%d", &matrix[i][k]);
		}
	}
    printf("\nMatrix:\n");
    print_matrix(matrix, M);
    for (int i = 0; i < M; i++)
        printf("sum ");
    printf("\n");
    for (k = 0; k < M; k++) {
        c_sum = 0;
		for (i = 0; i < M; i++) c_sum += matrix[i][k];
        printf("%3d ", c_sum);
	}
    // Задание 2
    for (i = 0; i < M; i++) free(matrix[i]);
	free(matrix);
    fclose(f);
    // Задание 7
    timer = clock() - timer;
    printf("\nTime of programm work: %f seconds\n", (float)timer / CLOCKS_PER_SEC);
    return 0;
}
