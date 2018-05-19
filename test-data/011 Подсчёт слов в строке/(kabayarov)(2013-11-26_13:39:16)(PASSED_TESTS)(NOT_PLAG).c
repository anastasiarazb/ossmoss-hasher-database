#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s) 
{ 
        int n=0,i,l=strlen(s),m=1;
	for(i=0;i<l;i++) if(s[i]==' ') m=1; else	if(m) {n++;m=0;}
	return n;
}

int main()
{
	char *s=(char*)malloc(100*sizeof(char));
	gets(s);
	printf("%d",wcount(s));
	free(s);	
	return 0;
}