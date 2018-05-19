#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int main ()
{
        char *s=(char*)malloc(100*sizeof(char));
	int i;
	for (i=0;i<100; i++)
		s[i]=0;
	gets (s);
	int k = wcount(s);
	printf("%d\n",k);
	free(s);
	return 0;
}

int wcount(char *s) 
{ 
	int i,k=0;
	for (i=1;s[i] != '\0';i++)
		if ((s[i]==' ' && s[i-1]!= ' ') || (s[i] != ' ' && s[i+1] == '\0')) k++;
	return k;
}