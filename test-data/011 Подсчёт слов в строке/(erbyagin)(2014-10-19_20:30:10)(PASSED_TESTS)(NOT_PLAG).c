#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wcount(char *s) 
{ 
        int c = 0, i;
	int size = strlen(s);
	for(i=0;i<size;i++)
	{
		if(s[i]!=' ' && (s[i+1]==' ' || s[i+1]==0))
			c++;
	}
	return c; 
}
void main()
{
	char s[100]; 
	gets(s);
	int count = wcount(s);
	printf("%d",count);
}