#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
    int n = 1, i, k = strlen(s);
    for (i = 1; i < k - 1; i++)
    {
        if (s[0] == '\n')
        {
            n = 0;
        }
        if ((s[i] != '\n') && (s[i] == ' '))
        {
            if (s[i] == ' ')
            {
                n++;
            }
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