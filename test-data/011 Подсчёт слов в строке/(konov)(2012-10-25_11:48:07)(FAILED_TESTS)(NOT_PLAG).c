#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
    int kolvo=0,i,j;
    if(s[i]==0)
    {
            return 0;
    }
    for(i=0;i<128;i++)
    {
                     if(s[i]!=' ')
                     {
                                kolvo++;
                                for(j=i+1;s[j]!=' ';j++)
                                {
                                                i=j;
                                }
                     }
    }                
    return kolvo-1;
}

int main()
{
    int i;
    char str[128];
    for(i=0;i<128;i++)
    {
                      str[i]=0;
    }
    gets(str);
    printf("%d", wcount(str));
    return 0;
}
