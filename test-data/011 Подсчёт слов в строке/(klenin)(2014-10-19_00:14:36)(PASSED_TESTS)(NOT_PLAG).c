//wcount.c
#include <stdio.h>
#define MAX_LEN 512
int wcount(char *s);
int main()
{
        char str[MAX_LEN];
	int i;
	for(i=0; i<MAX_LEN; i++)
	{
		str[i]=0;
	}
	gets(str);
	i=wcount(str);
	printf("%d\n", i);
	return 0;
}
int wcount(char *s)
{
        int i=0, n=0;
	do
	{
		while(s[i]==' ')
		{
			i++;
		}
		if(s[i]=='\0')break;
		n++;
		while(s[i]!=' ' && s[i]!='\0')
		{
			i++;
		}

	}while(s[i]!='\0');

	return n;
}