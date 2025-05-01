#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct human {
	char name[20], surname[20], sex[4];
	int year;
	double height;
};

char answ[2];

int sorting_surname(const void* a, const void* b) {
	if (strcmp(((struct human*)a) -> surname, ((struct human*)b) -> surname) == 0) {
		switch (answ[1]) {
			case '2':
				return strcmp(((struct human*)a) -> name, ((struct human*)b) -> name);
				break;
			case '3':
				return ((struct human*)a) -> year - ((struct human*)b) -> year;
				break;
			case '4':
				return strcmp(((struct human*)a) -> sex, ((struct human*)a) -> sex);
				break;
			case '5':
				return ((struct human*)a) -> height - ((struct human*)b) -> height;
				break;
			default:
				break;
		}
	}
	else return strcmp(((struct human*)a) -> surname, ((struct human*)b) -> surname);
};
int sorting_name(const void* a, const void* b) {
	if (strcmp(((struct human*)a) -> name, ((struct human*)b) -> name) == 0) {
		switch (answ[1]) {
			case '1':
				return strcmp(((struct human*)a) -> surname, ((struct human*)b) -> surname);
				break;
			case '3':
				return ((struct human*)a) -> year - ((struct human*)b) -> year;
				break;
			case '4':
				return strcmp(((struct human*)a) -> sex, ((struct human*)a) -> sex);
				break;
			case '5':
				return ((struct human*)a) -> height - ((struct human*)b) -> height;
				break;
			default:
				break;
		}
	}
	else return strcmp(((struct human*)a) -> name, ((struct human*)b) -> name);
}
int sorting_year(const void* a, const void* b) {
	if (((struct human*)a) -> year == ((struct human*)b) -> year) {
		switch (answ[1]) {
			case '1':
				return strcmp(((struct human*)a) -> surname, ((struct human*)b) -> surname);
				break;
			case '2':
				return strcmp(((struct human*)a) -> name, ((struct human*)b) -> name);
				break;
			case '4':
				return strcmp(((struct human*)a) -> sex, ((struct human*)a) -> sex);
				break;
			case '5':
				return ((struct human*)a) -> height - ((struct human*)b) -> height;
				break;
			default:
				break;
		}
	}
	else
	return ((struct human*)a) -> year - ((struct human*)b) -> year;
}
int sorting_sex(const void* a, const void* b) {
	if (strcmp(((struct human*)a) -> sex, ((struct human*)b) -> sex) == 0) {
		switch (answ[1]) {
			case '1':
				return strcmp(((struct human*)a) -> surname, ((struct human*)b) -> surname);
				break;
			case '2':
				return strcmp(((struct human*)a) -> name, ((struct human*)b) -> name);
				break;
			case '3':
				return ((struct human*)a) -> year - ((struct human*)b) -> year;
				break;
			case '5':
				return ((struct human*)a) -> height - ((struct human*)b) -> height;
				break;
			default:
				break;
		}
	}
	else return strcmp(((struct human*)a) -> sex, ((struct human*)a) -> sex);
}
int sorting_height(const void* a, const void* b) {
	if (((struct human*)a) -> height == ((struct human*)b) -> height) {
		switch (answ[1]) {
			case '1':
				return strcmp(((struct human*)a) -> surname, ((struct human*)b) -> surname);
				break;
			case '2':
				return strcmp(((struct human*)a) -> name, ((struct human*)b) -> name);
				break;
			case '3':
				return ((struct human*)a) -> year - ((struct human*)b) -> year;
				break;
			case '4':
				return strcmp(((struct human*)a) -> sex, ((struct human*)a) -> sex);
				break;
			default:
				break;
		}
	}
	else return ((struct human*)a) -> height - ((struct human*)b) -> height;
}

main() {
	FILE *input = fopen("C:/Users/Vlad/Desktop/prog_C/input.txt", "r");
	FILE *output = fopen("C:/Users/Vlad/Desktop/prog_C/output.txt", "w");
	struct human humans[100], s_humans[100];
	int i = 0, k;
	char ans = 'y';
	while ((fscanf(input, "%s %s %s %d %lf\n", humans[i].surname, humans[i].name, humans[i].sex, &humans[i].year, &humans[i].height))!=EOF) {
		s_humans[i] = humans[i];
		i++;
	}
	for (k = 0; k < i; k++) printf("%s %s %d %s %.2lf\n", s_humans[k].surname, s_humans[k].name, s_humans[k].year, s_humans[k].sex, s_humans[k].height);
	while (ans == 'y'){
		printf("Choose sorting: 1) Surname; 2) Name; 3) Birthyear; 4) Sex; 5) Height\n");
		scanf("%s", &answ);
		switch (answ[0]){
			case '1':
				qsort(s_humans, i, sizeof(struct human), sorting_surname);
				break;
			case '2':
				qsort(s_humans, i, sizeof(struct human), sorting_name);
				break;
			case '3':
				qsort(s_humans, i, sizeof(struct human), sorting_year);
				break;
			case '4':
				qsort(s_humans, i, sizeof(struct human), sorting_sex);
				break;
			case '5':
				qsort(s_humans, i, sizeof(struct human), sorting_height);
				break;
			default:
				printf("Error! Write number 1 to 5");
				break;
		}
		for (k = 0; k < i; k++) printf("%s %s %d %s %.2lf\n", s_humans[k].surname, s_humans[k].name, s_humans[k].year, s_humans[k].sex, s_humans[k].height);
		printf("Reset sorting? y/n\n");
		scanf(" %c", &ans);
	}
	for (k = 0; k < i; k++) fprintf(output, "%s %s %d %s %.2lf\n", s_humans[k].surname, s_humans[k].name, s_humans[k].year, s_humans[k].sex, s_humans[k].height);
	fclose(input);
	fclose(output);
}
