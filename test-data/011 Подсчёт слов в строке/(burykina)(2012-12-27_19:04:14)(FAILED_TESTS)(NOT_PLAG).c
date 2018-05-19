#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 128

int wcount (char *s, int len)
{
        int k=0,i;
	if (len>0)
	{
		if (s[0]!=' ') k++;
		for (i=1; (i<strlen(s)-1)&&(i<L); i++) 
			if ((s[i]!=' ')&&(s[i-1]==' ')) k++;
	}
	return k;
}

int main () 
{
	int n,i;
        char *str=(char *)malloc(L*sizeof(char));
	for (i=0; i<L; i++) str[i]=0;
	gets(str);
	n=wcount(str,strlen(str));
	printf("%d\n",n);
        free(str);
	return 0;
}
