#include <stdio.h>

int wcount(char *s) 
{
        int k, i, j;
	k = 0;
	j = 1;
	for (i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] != ' ' && j == 1)
		{
			j = 0;
			++k;
		}
		else if (s[i] == ' ')
			j = 1;
	}
	return k;
			
}

int main(int argc, char **argv)
{
	char str[1000];
	gets (str);
	printf ("%d", wcount (str));
	
	return 0;
}