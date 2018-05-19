#include <stdio.h>
#include <string.h>

int wcount( char *s)
{
        int i,n,k=0;
	n=strnlen(s,1000);
	for (i=1; i<n; i++)
		if ((s[i] == ' ') && (s[i-1] != ' ')) k++;
	if (s[n-1] != ' ') k++;
	return k;
}

int main()
{
	char s[50];
	gets(s); if (strnlen(s,50)==0) printf("%d",0);
        else
	printf("%d", wcount(s));
	return 0;
}