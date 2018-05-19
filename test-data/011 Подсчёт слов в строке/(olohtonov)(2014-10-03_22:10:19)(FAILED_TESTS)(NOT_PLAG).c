#include <stdio.h>

int main() {
        wcount('hello, world!');
	return 0;
}
int wcount(char *s) {
	int words, space, c;
	char carray[128];
	words = c = 0;
	gets(carray);
	for (c = 0; c < 128; c++) {
		while (carray[c] != EOF) {
			if (carray[c] == ' ' || carray[c] == '\t')
				space = 1;
			else if (space == 1) {
				space = 0;
				words++;
			}
		}
	}
	printf("%d", words);
}

