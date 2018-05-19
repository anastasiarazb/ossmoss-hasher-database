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
	printf("%d",k);
	return k;
}

int main()
{
	char str[1000]="";
	gets(str);
	wcount(str);

return 0;
}