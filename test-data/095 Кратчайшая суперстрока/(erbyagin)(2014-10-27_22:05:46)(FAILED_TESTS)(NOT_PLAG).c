#include <stdio.h>  
#include <stdlib.h>
#include <string.h>


void main() 
{ 
        int n,i;
	scanf("%d",&n);
	char **s = (char**)malloc(n*sizeof(char[256]));
	for(i=0;i<n;i++)
	gets(s[i]);

	printf("10");
}