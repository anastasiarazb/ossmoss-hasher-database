#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int wcount(char* s)
{        int k,i,l;
	k=strnlen(s,100);
	for(i=0;i<k-1;i++)
	{	if((strcmp(s[i+1]," ")==0)&&(strcmp(s[i]," ")!=0))
			l++;
	}
	return l;
}

int main()
{	char *s;
	gets(s);
	printf("%d\n",wcount(s));
	return 0;
}