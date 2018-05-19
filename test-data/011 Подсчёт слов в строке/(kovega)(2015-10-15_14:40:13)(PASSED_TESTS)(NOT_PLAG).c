#include <stdio.h>
#define IN 1
#define OUT 0

int wcount(char *s);
char *gets(char *s);

int main (int argc, char **argv)
{
        char s[100];
	gets(s);
	printf ("%d\n", wcount(s));
}

int wcount(char *s) 
{
	int nw, state;
	state = OUT;
	nw = 0;
	while (*s != '\0') {
		if (*s == ' ') state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
		s++;
	}
	return nw;
}
