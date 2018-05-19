
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int wcount(char *s) 
{
        int dlina=0,i=0, count=0;
	dlina = strnlen(s,100);
	for (i=0;i<dlina;i++)
		if(*(s+i)!=' '){
			count++;
			for(;*(s+i)!=' ';i++);
		}else if (*(s+i-1)!=' ') i--;
	return count;
}

int main()
{	
	int kolvo=0,i=0;
	char *s=(char*)calloc(100,sizeof(char));
	gets(s);
	printf("%d", wcount(s));
        free(s);
	return 0;
}