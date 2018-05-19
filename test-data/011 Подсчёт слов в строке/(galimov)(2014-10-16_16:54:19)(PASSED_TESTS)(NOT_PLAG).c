#include <stdio.h>
int wcount(char *s);
int main()
{
        char tmp[512];
	gets(tmp);
	printf("%d",wcount(tmp));
	return 0;
}
int wcount(char *s)
{
	int i=0,n=0;
	while(s[i])
	{
		for(;s[i]&&s[i]==' ';i++);
		if(s[i])
			for(n++;s[i]&&s[i]!=' ';i++);
	}
	return n;
}