#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10000

int wcount(char *s) {
        int res = 0;
	char word = 0;
	unsigned int i = 0;
	while (i < MAXLEN) {
		if ((s[i] != 0) && (s[i] != ' ')) {
			if (word == 0) res++;
			word = 1;
		}
		else word = 0;
		
		i++;
	}
	
	return res;
}

int main(int argc, char *argv[]) {
	char* str = (char *)calloc(MAXLEN, 1);
	printf("%d", wcount(gets(str)));
	
        free(str);
        
	return 0;
}