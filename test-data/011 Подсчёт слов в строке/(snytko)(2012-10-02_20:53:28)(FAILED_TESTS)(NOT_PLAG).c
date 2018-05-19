
#include <stdio.h>

int wcount(char *s)
{
        int i=1, counter;
	while (s[i] != 0)
	{
		if ((s[i] == 0x20 && s[i-1] != 0x20) || (s[i] != 0x20 && s[i+1] == 0)) ++counter;
		++i;
	}
	return counter;
}

int main ()
{
	char str[] = {"   hhhhh hhh ee oooo  hhh   "};

	printf("%d\n", wcount(str));
	return 0;
}
