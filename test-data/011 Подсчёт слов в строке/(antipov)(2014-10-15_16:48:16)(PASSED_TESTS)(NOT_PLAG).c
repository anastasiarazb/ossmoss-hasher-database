#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int wcount(char *s) 
{ 
        int i=0, k=0;
	while(s[i]!='\0')
	{
		while(s[i]==' ')
		i++;
			if(s[i]!='\0' && s[i]!=' ')
			k++;
		while(s[i]!='\0' && s[i]!=' ')
		i++; 
	}
	return k;
}

int main()
{
	int out;
	char string[1000];
	out=wcount(gets(string));
	printf("%d", out);
	return 0;
}