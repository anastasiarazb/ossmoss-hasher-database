#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main()
{
        char *buff = (char *)calloc(256, sizeof(char));
	gets(buff);
	printf("%d", wcount(buff));
	free(buff);
	return 0;
}

int wcount(char *s) 
{ 
	int count = 0, inw = 0,sp;
	s--;
	while (++s != 0)
	{
		sp = isspace(s);
		if(inw && sp)
			count++;
		inw = sp;		
	}
	if(inw)
		count++;
	return count;
}