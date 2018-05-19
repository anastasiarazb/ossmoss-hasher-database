#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int wcount(char *p)
{
        int k=0, i=0, t=0;
	while (p[i] != '\n') {
		if ((p[i] != ' ')  && (t==0))
			++k;
		if (p[i] == ' ') {
			t=0;
		}
		else {
			t=1;
		}
		++i;
	}
	if (t==0)
		k--;
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