#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char*);

int main()
{
        char* str;
        str=(char*)malloc(sizeof(char)*255);
	gets(str);
        printf("%d", wcount(str));
        free(str);
	return 0;
}

int wcount(char* str)
{
        int count=0, i=0;
	int length=strlen(str);
	if(str[0]!=' ') count++;
	if(length==0) count=0; 
	for(i=0; i<(length-1); i++)
	{
		if(str[i]==' ' && str[i+1]!=' ') count++;
	}
	return count;
}