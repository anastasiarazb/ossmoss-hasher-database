#include <stdio.h>
#include <stdlib.h>

int wcount(char *s) {
        char isNewWord = 1;
	int i, res = 0;
	for (i = 0; i < strnlen(s, 1000); i++)
		if (s[i] != ' ') {
			if (isNewWord) {
				res++;
				isNewWord = 0;
			}
		} else
			isNewWord = 1;
	return res;
}

int main() {
	int i, b, num;
	char *mass;
	mass = (char*) malloc(1000 * sizeof(char));
	gets(mass);
	printf("%d", wcount(mass));
	free(mass);
	return 0;
}