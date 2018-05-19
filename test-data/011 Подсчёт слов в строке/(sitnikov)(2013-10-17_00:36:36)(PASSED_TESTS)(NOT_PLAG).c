#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wcount(char *s)
{
        long k=strlen(s),i,n=0;
	int f=0;
	for (i=0;i<k;i++) {
		if ((s[i]!=' ')&&(n==0)) {
			n=1;
			f+=1;
		}
		if (s[i]==' ') n=0;
	}	
	return f;
}

int main () 
{
	char *s=(char*)malloc(256*sizeof(char));
	gets(s);
	printf("%d",wcount(s));
        free(s);
}	
	