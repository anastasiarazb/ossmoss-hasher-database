#include <stdio.h>
#include <string.h>

int wcount(char *s) {
        int words, space, c;
	char carray[128];
	memset(carray, 0, 128);
	words = c = 0;
	space = 1;
	if (gets(carray) && strlen(carray) > 0) {
		for (c = 0; c < strlen(carray); c++) {
			if (isspace(carray[c])) {
				if (!space) {
					words++;
				}
				space = 1;
			} else
				space = 0;
		}
		if (!space)
			words++;
	}

	return words;
}

int main() {
	wcount("1 2 3");
}
