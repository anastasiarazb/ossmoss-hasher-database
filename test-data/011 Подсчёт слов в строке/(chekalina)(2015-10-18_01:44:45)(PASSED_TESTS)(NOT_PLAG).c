#include <stdio.h>

int wcount(char *s)
{
    char reg, i, c;
    i = reg = c = 0;
    while (s[i]!='\0')
    {
        if (s[i]==' ') reg=0;
        else if (reg==0)
        {
            reg = 1;
            c++;
        };
        i++;
    }
    return c;
}

int main()
{
    char s[255];
    gets(s);
    printf("%d", wcount(s));
    return 0;
}
