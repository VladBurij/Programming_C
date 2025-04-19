#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct human {
	char name[20], surname[20], sex[3];
	int year;
	double height;
};

int sorting_surname(const void* a, const void* b) {
	return strcmp((*(struct human**)a) -> surname, (*(struct human**)b) -> surname);
}
int sorting_name(const void* a, const void* b) {
	return strcmp((*(struct human**)a) -> name, (*(struct human**)b) -> name);
}
int sorting_year(const void* a, const void* b) {
	return ((struct human*)a) -> year - ((struct human*)b) -> year;
}
int sorting_sex(const void* a, const void* b) {
	return strcmp((*(struct human**)a) -> sex, (*(struct human**)a) -> sex);
}
int sorting_height(const void* a, const void* b) {
	return ((struct human*)a) -> height - ((struct human*)b) -> height;
}

main() {
	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");
	struct human humans[100], s_humans[100];
	int i = 0, k, answ;
	while ((fscanf(input, "%s %s %d %s %lf\n", humans[i].surname, humans[i].name, &humans[i].year, humans[i].sex, &humans[i].height))!=EOF) {
		printf("%s %s %d %s %lf\n", humans[i].surname, humans[i].name, humans[i].year, humans[i].sex, humans[i].height);
		i++;
	}
	for (k = 0; k < i; k++) s_humans[k] = humans[k];
	printf("Choose sorting: 1) Surname; 2) Name; 3) Birthyear; 4) Sex; 5) Height\n");
	scanf("%d", &answ);
	switch (answ){
		case 1:
			qsort(humans, i, sizeof(struct human), sorting_surname);
			break;
		case 2:
			qsort(humans, i, sizeof(struct human), sorting_name);
			break;
		case 3:
			qsort(humans, i, sizeof(struct human), sorting_year);
			break;
		case 4:
			qsort(humans, i, sizeof(struct human), sorting_sex);
			break;
		case 5:
			qsort(humans, i, sizeof(struct human), sorting_height);
			break;
		default:
			printf("Error! Write number 1 to 5");
			break;
	}
}
	//for (k = 0; k < i; k++) fprintf(output, "%s %s %d %s %.2lf\n", s_humans[k].surname, s_humans[k].name, s_humans[k].year, s_humans[i].sex, s_humans[i].height);
