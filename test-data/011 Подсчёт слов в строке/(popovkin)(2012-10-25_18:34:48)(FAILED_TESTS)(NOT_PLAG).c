#include <stdio.h>
#include <string.h>
int wcount(char *string)
{
        int b=0, i, k=0;
	k=strnlen(string, 100);
	for(i=1;i<k;i++)
	{
		if ((string[i]==' ') && (string[i-1]!=' '))
		{
			b++;
		}
	}
	if ((string[k-1]!=' ') && (b!=0))
	{
		b++;
	}
    	return b;
}
int main()
{
	char string[100];
	gets(string);
	printf("%d\n", wcount(string));
	return 0;
}