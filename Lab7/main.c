#include <stdio.h>
#include <stdlib.h>

struct human {
	char name[20], surname[20];
	int year;
};

int sorting(const void* a, const void* b) {
	return ((struct human*)a) -> year - ((struct human*)b) -> year;
}

main() {
	//FILE *input = fopen("C:/Users/Vlad/Desktop/prog_C/input.txt", "r");
	//FILE *output = fopen("C:/Users/Vlad/Desktop/prog_C/output.txt", "w");
	struct human humans[4];
	for (int i = 0; i < 4; i++) {
		printf("Input: surname name birthyear: ");
		scanf("%s %s %d", &humans[i].surname, &humans[i].name , &humans[i].year);
	}
	qsort(humans, 4, sizeof(struct human), sorting);
	for (int i = 0; i < 4; i++) printf("%s %s %d\n", humans[i].surname, humans[i].name , humans[i].year);
	//while ((fscanf(input, "%s %s %d\n", &surname, &name, &year))!=EOF) {
		//fprintf(output, "%s %s %d\n", surname, name, year);
	//}
	//fclose(input);
	//fclose(output);
}
