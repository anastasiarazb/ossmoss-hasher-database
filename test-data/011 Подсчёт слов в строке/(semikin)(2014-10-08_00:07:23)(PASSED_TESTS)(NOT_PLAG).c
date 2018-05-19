#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int wcount(char *s)
{
        int i=0,k=0;
	while (i < strlen (s))
	{
		while (s[i]== ' ')
			i++;
		while ((s[i]!= ' ')&&(i < strlen (s)))
			i++;
		if (s[i-1]!=' ')
			k++;
	}
	return k;
}

int main()
{
	int k1;
	char st[1000] = " ";
	gets(st);
	k1 = wcount(st);
	printf("%d", k1);
	return 0;
}