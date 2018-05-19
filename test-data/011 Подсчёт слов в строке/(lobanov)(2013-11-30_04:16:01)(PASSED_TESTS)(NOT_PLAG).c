#include <string.h>
#include <stdio.h>

int wcount(char *s) 
{ 
        char *p, ch;
        unsigned long i, n;
        if ((s[0] != 0) && (s[0] != ' ')) n = 1;
        else n = 0;
        for (i = 1; s[i] && s[i + 1]; i++) if (s[i] == ' ' && s[i + 1] != ' ') n++;
        return n;
}

char s[1000];

int main()
{
    gets(&s);
    printf ("%d", wcount(&s));
        return 0;
}