#include <stdio.h>
#define IN 1
#define OUT 0

int wcount (char *s)
{
        int i, n = 0, flag = OUT;
	for(i = 0; s[i] != '\0'; i++) {
		if(flag == OUT && s[i] != ' ' && s[i] != '\t') n++;
		if(s[i] == ' ' || s[i] == '\t') flag = OUT;
			else flag = IN;
	}
	return n;
}
int main ()
{
	char s[100];
	gets(s);
	printf("%d\n", wcount(s));
	return 0;
}
