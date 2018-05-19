#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int wcount(char* s)
{       int k,i,l=0;
        char *e;
	e=(char*)malloc(2*sizeof(char));
	k=strnlen(s,100);
	for(i=0;i<k;i++)
	{	e=s+i;
		if(((e[1]-' ')<=0)&&((e[0]-' ')!=0))
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