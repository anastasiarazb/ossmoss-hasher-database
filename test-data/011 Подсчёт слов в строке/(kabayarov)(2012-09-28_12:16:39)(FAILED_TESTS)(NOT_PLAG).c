#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s) 
{ 
        int a=strnlen(s,8192);
	int i,n=0,m=1;
	for(i=0; i<a; i++)
	{
		switch (m)
		{
		case 0: if(s[i]==' ') m=1; break;
		case 1: if(s[i]!=' ') {m=0; n++;} break;
		}
	}
	return n;
}

int main()
{
	char s[8192];
	gets(s);
	int a=wcount(s);
	printf("%d",a);
	return 0;
}