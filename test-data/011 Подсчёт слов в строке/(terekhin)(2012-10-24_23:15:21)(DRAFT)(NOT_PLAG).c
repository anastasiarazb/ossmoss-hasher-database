#include <stdio.h>
#include <stdlib.h>
int wcount (char *s)
{
    int i,spaceflag,wc;
    i=0;
    spaceflag=1;
    wc=0;
    while(s[i]==' ')
    {
        ++i;
    }
    if(s[i]=='\0')
    {
        return 0;
    }
    while(s[i]!='\0')
    {
        if(s[i]==' ')
        {
            if(spaceflag==0)
            {
                wc++;
                spaceflag=1;
            }
        }
        else
        {
            if(spaceflag==1)
                spaceflag=0;
        }
        ++i;
    }
    return wc+1;
}
int main()
{
    char s[1024];
    gets(s);
    printf("%d\n",wcount(s));
    return 0;
}
