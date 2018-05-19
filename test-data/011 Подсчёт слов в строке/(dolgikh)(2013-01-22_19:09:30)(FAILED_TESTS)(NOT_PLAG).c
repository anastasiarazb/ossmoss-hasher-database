#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char*);

int wcount(char *s);

int main()
{
        char* str;
        str=(char*)malloc(sizeof(char)*255);
	gets(str);
	wcount(str);
        free(str);
	return 0;
}

int wcount(char* str)
{
        int count=0, i=0;
	int length=strlen(str);
	for(i=0; i<(length-1); i++)
	{
		if(str[0]!=' ') count++;
		else if(str[i]==' ' && str[i+1]!=' ') count++;
	}
	printf("%d", count);
	return 0;
}