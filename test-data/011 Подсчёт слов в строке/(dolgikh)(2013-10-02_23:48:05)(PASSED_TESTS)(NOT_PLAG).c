#include <stdio.h>
#include <string.h>

int wcount(char *);

int main(int argc, char **argv)
{
        char *s;
        s=(char*)malloc(sizeof(char)*1000);
        gets(s);
        printf("\n%d\n", wcount(s));
        free(s);
        return 0;
}

int wcount(char *s)
{
        int i=0, n=0;
        if(strlen(s)==0)
        {
             n=0;
	     return n;
        }
        else if(s[0]!=' ') n++;
        for(i=1; i<strlen(s); i++)
        {
	     if(s[i]!=' ' && s[i-1]==' ') n++;
        }
        return n;
}