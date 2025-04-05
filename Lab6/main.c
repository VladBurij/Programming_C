#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");
	char str[50], year[4];
	int i;
	while (fgets(str, 50, input) != NULL) {
		for (i = 4; i > 0; i--) strcat(year, str[strlen(str) - i]);
		printf("%s", year);
	}
	fclose(input);
	fclose(output);
}
