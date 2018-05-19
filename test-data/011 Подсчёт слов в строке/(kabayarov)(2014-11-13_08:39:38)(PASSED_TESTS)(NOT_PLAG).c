#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s)
{
        int i=0,r=0,n=strlen(s);
	for(;i<n;i++)
	{
		if(s[i]==32) continue;
		r++;
		do i++; while(s[i]!=0 && s[i]!=32);
	}
	return r;
}

int main(int argc, char **argv)
{
	char s[256];
	gets(s);
	printf("%d\n",wcount(s));
	return 0;
}
