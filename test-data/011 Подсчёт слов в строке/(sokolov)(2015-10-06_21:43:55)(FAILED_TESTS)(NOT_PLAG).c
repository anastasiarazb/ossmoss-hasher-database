#include <stdio.h>

#define IN 1
#define OUT 0

int wcount(char *s);

main()
{
        char c[10000];
	char *d;

	d = get(c);

	return 1; 
}

int wcount(char *s)
{  
	char p =' ';
	int i=0,k=0,state=OUT;

	for (i=0; i<(strlen(s));++i)
	{
		if (s[i] == p)
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++k;
		}
	}

	return k;
}