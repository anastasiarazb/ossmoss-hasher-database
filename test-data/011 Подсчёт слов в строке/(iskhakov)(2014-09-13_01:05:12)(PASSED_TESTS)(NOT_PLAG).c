#include <stdio.h>
#include <stdlib.h>


int wcount(char *s) {
        int c = 0;
	while(*s) {
		if((*s != ' ') && (*s != '\n')) {
			while(*s && (*s != ' ') && (*s != '\n')) s++;
			c++;
		};
		s++;
	};
	return c;
}

int main(void) {
	char t[1024];
	int i;
	for(i = 0; i < 1024; i++) t[i] = '\0';
	fgets(t, 1024, stdin);
	//scanf("%[^\n]s", t); //
	printf("%d", wcount(t));
	return 0;
}
