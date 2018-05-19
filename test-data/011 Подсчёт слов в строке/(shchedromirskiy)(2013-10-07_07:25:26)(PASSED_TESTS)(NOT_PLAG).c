#include <stdio.h>
#include <string.h>
int wcount(char *s) 
{ 
	unsigned int n=0,i;
	if (strlen(s)>=1) {
		for (i=0;i<strlen(s)-1;i++) {
			if ((s[i]==' ') && (s[i+1]!=' '))
			n+=1;
		}
		if (s[0]!=' ') n=n+1;
	}
	else n=0;
	return n;
}
int main()
{
        char s[256];
	gets(s);
	printf("%d",wcount(s));
	return 0;
}