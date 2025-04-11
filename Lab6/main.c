#include <stdio.h>
#include <stdlib.h>

main() {
	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");
    int year;
	char surname[50], name[50], patronymic[50];
    if (!input)
    {
        printf("Error! File nothing.\n");
        return 1;
    }
	while ((fscanf(input, "%s %s %s %d\n", &surname, &name, &patronymic, &year))!=EOF) {
		if (year > 1980) fprintf(output, "%s %s %s %d\n", surname, name, patronymic, year);
	}
	fclose(input);
	fclose(output);
}
