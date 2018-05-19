#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int wcount(char *s) 
{ 
        int i,k=0;
	if (s[1]=='\0' && s[0]!=' ') k=1;
	for (i=1;s[i] != '\0';i++)
		if ((s[i]==' ' && s[i-1]!= ' ') || (s[i] != ' ' && s[i+1] == '\0')) k++;
	return k;
}

int main ()
{
	char *s=(char*)malloc(100*sizeof(char));
	int i;
	for (i=0;i<100; i++)
		s[i]=0;
	gets (s);
	printf("%d\n",wcount(s));
	free(s);
	return 0;
}