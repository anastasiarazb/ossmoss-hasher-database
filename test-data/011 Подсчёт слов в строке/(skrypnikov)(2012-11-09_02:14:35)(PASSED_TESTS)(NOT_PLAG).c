#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int wcount(char* s)
{       int k,i,l=0;
        k=strnlen(s,100);
	for(i=0;i<k;i++)
	{	if(((s[i+1]-' ')<=0)&&((s[i]-' ')!=0))
		  l++;
	}
	return l;
}

int main()
{	char s[100];
	gets(s);
	printf("%d\n",wcount(s));
	return 0;
}