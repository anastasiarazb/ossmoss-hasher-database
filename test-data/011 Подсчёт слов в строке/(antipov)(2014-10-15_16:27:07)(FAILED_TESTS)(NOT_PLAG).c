#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int wcount(char *s)
{
        int i,k=0;
	for (i=0;s[i] != "\0";)
	{
		while(s[i]==' ')
		i++;
			if(s[i]!="\0" && s[i]!=' ')
			k++;
			
			while(s[i]!=' ' && s[i]!="\0")
			i++;
		
	}
	return k;
}
	
int main(void) 
{
	int p;
	char string[100];
	p=wcount(gets(string));
	printf("%d", p);
	return 0;
}