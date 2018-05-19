#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int wcount(char *s)
{
    int n=strlen(s), i, t=0, count=0;
    for (i=0;i<n;i++)
        if (s[i]!=' ')
            count=1;
        else
        {
            t+=count;
            count=0;
        }
    if ((s[n-1]!=' ')&&((n)>0))
        t++;
    return t;
}

int main(int argc , char ** argv)
{
    char str[256];
    int a;
    gets(str);
    a=wcount(str);
    printf("%d", a);
    free(str);
    return 0;
}