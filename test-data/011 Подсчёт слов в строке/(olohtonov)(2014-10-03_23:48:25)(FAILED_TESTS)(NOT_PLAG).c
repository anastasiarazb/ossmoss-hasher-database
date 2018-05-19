#include <stdio.h>
#include <string.h>

int wcount(char *s) {
        int words, space, c;
	words = c = 0;
	space = 1;
	if (gets(s) && strlen(s) > 0) {
		for (c = 0; c < strlen(s); c++) {
			if (isspace(s[c])) {
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
        char carray[128];
        memset(carray, 0, 128);
	wcount(carray);
}
