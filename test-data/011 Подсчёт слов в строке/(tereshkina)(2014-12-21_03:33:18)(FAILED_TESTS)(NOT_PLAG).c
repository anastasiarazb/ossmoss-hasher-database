#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
    int i,n,m;
    n=1;
    m=0;
    if ((s[0] == '\n') || (s[0] == ' ')) n = 0;
    for (i = 0; s[i] != '\n'; i++)
    {
        if ((s[i] != ' ') && (s[i + 1] == ' '))
        {
            m++;
        }
        else
        {
            m++;
        }
    }
    return n;
}



int main()
{
    char s[1024];
    fgets(s,1024,stdin);
    printf("%d", wcount(s));
    return 0;
}