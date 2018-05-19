
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wcount(char *s)
{
        int i,summ=0;
        for(i=0;i<(strlen(s));i++){
            if(s[i]==' ') summ++;
        }
        return summ;
}
int main()
{
        char s[100];
	gets(s);
	return 0;
	printf("%d",wcount(s));
}
