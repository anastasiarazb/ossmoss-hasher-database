#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s)
{
    int kolvo=0,i,j,k=0;
    for(i=0;i<strlen(s);i++)
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
    return kolvo;
}

int main()
{
    int i;
    char str[128];
    char dopstr[2] = {" "};
    for(i=0;i<128;i++)
    {
                      str[i]=0;
    }
    gets(str);
    strcat(str,dopstr);
    printf("%d", wcount(str));
    return 0;
}
