#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int wcount(char *p)
{
        int k=0, i=0, t=0;
	while (p[i] != '\0') {
		if ((p[i] != ' ')  && (t==0))
			++k;
		if (p[i] == ' ') 
			t=0;
		else 
			t=1;
		++i;
	}
	return k;
 }

int main(int argc, char **argv)
{
	char s[100], *p;
	gets(s);
	int k;
	k=strlen(s);
	p=s;
	p[k]='\0';
	printf("%d\n", wcount(p));
	return 0;
}