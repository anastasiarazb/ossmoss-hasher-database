#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
    int i,n = 0;
    if ((s[0] == '\n') || (s[0] == ' ')) n = 0;
    for (i = 0; s[i] != '\n'; i++)
        if (((s[i] != ' ') && (s[i + 1] == ' ')) || ((s[i] != ' ') && (s[i + 1] == '\n')))
            n++;
    return n;
}



int main()
{
    char s[1024];
    fgets(s,1024,stdin);
    int m = wcount(s);
    printf("%d", m);
    return 0;
}