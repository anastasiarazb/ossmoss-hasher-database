#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int wcount(char *s)
{
        int i=0,k=0;
	while (i < strlen(s))
	{
		while (s[i]== ' ')
			i++;
		if (i >= strlen(s))
			break;
		while (s[i]!=' ')
			i++;
		k++;
	}
	return k;
}

int main()
{
	int k1;
char s[1000] = " ";
	gets(s);
	wcount(s);
	k1 = wcount(s);
	printf("%d", k1);
	return 0;
}