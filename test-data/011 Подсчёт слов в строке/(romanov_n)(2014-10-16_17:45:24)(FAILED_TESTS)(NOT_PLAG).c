#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int wcount(char *p)
{
        int k=0, i=1, t=1;
	while (p[i] != '\n') {
		if (p[i-1] != ' '  && p[i] == ' ')
			++k;
		i++;
		if (p[i] != ' ')
			t=1
		else 	t=0;
	}
	(if (t==1)
		++k;
	return k;
 }

int main(int argc, char **argv)
{
	char s[100], *p;
	gets(s);
	p=s;
	printf("%d\n", wcount(p));
	return 0;
}