#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *str) 
{
        int i=0, count=0;
	char ch=' ';
	while(str[i]!=0)
	{
		if (str[i]==' ' && ch!=' ') count++; 
		ch=str[i];
		i++;
	}
	if (ch!=' ') count++;

	return count;
}

int main()
{
	char *str = (char*)malloc(100);
	gets(str);
	printf("%d",wcount(str));

	free(str);
	return 0;
}