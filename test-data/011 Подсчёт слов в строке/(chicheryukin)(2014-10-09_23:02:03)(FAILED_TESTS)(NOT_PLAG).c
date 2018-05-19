#include <stdio.h>
#include <string.h>

#define max_len 10000

int wcount(char *s) 
{ 
        int i, n, wc=0;
	n= strlen(s);
	for (i=0; i<n; i++)
	{
		while ((s[i] == ' ') && (i<n))
		{
			i++;
		}
		if (i != n)
			wc++;
		while ((s[i] != ' ') && (i<n))
		{
			i++;
		}
	}
	return wc;
}

void main (void)
{
	int n, j;
	scanf("%d", &n);
	char z[max_len];
	gets(z);
	//scanf("\n");
	printf ("%d\n", wcount(z));
}