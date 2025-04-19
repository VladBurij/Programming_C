#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct human {
	char name[20], surname[20];
	int year;
};

int sorting(const void* a, const void* b) {
	return ((struct human*)a) -> year - ((struct human*)b) -> year;
}

main() {
	int i = 0, k;
	char name[20], surname[20];
	int year;
	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");
	struct human humans[100];
	//for (i = 0; i < 4; i++) {
		//printf("Input: surname name birthyear: ");
		//scanf("%s %s %d", &humans[i].surname, &humans[i].name , &humans[i].year);
	//}
	//for (int i = 0; i < 4; i++) printf("%s %s %d\n", humans[i].surname, humans[i].name , humans[i].year);
	while ((fscanf(input, "%s %s %d\n", humans[i].surname, humans[i].name, &humans[i].year))!=EOF) {
		printf("%s %s %d\n", humans[i].surname, humans[i].name, humans[i].year);
		i++;
	}
	qsort(humans, i, sizeof(struct human), sorting);
	for (k = 0; k < i; k++) fprintf(output, "%s %s %d\n", humans[k].surname, humans[k].name, humans[k].year);
}
