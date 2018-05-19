#include <stdio.h>

int wcount(char *s)
{
        short a = 0, b = 0;
	
	if (*s != ' ' && *s != 0) {
		b++;
	}
	while (*(s + a + 1) != 0) {
		((*(s + a + 1) != ' ') && (*(s + a) == ' ')) ? b++, a++: a++;
	}
	return b;
}

int main (int argc, const char * argv[])
{
	char s[40];
	gets(s);
	printf("%d\n", wcount(s));
	return 0;
}