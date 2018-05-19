
#include <stdio.h>

int wcount(char *s) 
{
        int rv = 0;
        while (*s)
	{
		while (*s && *s == ' ') ++s;
		if (*s) ++rv;
		while (*s && *s != ' ') ++s;
	}
	return rv;
}
int main()
{
	char str [1024];
	if (!gets(str)) //Terrible!
		return 1;
	printf("%d\n", wcount(str));
}