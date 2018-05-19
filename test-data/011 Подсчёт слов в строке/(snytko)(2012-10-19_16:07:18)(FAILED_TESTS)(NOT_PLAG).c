
#include <stdio.h>

int wcount(char *s)
{
        int i = 0, counter = 0;

	while (s[i] != 0)
	{
		if ((i > 0 && s[i] == 0x20 && s[i-1] != 0x20) || (s[i] != 0x20 && s[i+1] == 0)) ++counter;
		++i;
	}
	return counter;
}

int main ()
{
	char str[] = {"a"};

	printf("%d\n", wcount(str));
	return 0;
}
