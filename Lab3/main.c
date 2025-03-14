#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main() {
	char word[50];
	printf("Vvedite slovo: ");
	scanf("%s", word);
	for (int i = 0; i < strlen(word); i++) {
		if (word[i] == 'a' || word[i] == 'b') word[i] = toupper(word[i]);
	}
	printf("%s", word);
}
