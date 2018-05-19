
#include <stdio.h>
#include <string.h>


int wcount(char *s);

int main(int argc, char **argv)
{       
        char s[50]={ ' ' };
	gets(s);
	printf("%d\n", wcount(s));
	return 0;
}

int wcount(char *s) 
{
	int dlina=0,i=0, count=0;
	dlina = strnlen(s,50);
	for (i=0;i<dlina;i++)
		if(*(s+i)!=' '){
			count++;
			for(;*(s+i)!=' ';i++);
		}else if (*(s+i-1)!=' ') i--;
	return count;
}