#include <stdio.h>
#include <string.h>
int main()
{
        char s[256];
	gets(s);
	int wcount(char *s) 
	{ 
		unsigned int n=0,i;
		for (i=0;i<strlen(s)-1;i++) {
			if ((s[i]==' ') && (s[i+1]!=' '))
			n+=1;
		}
		if (s[0]!=' ') n=n+1;
		return n;
	}
	printf("%d",wcount(s));
	return 0;
}
