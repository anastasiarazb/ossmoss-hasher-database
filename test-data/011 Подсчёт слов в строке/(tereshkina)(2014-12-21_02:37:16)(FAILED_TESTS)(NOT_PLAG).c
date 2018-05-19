#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
    int n = 0, i, k = strlen(s);
    for (i = 0; i < k - 1; i++)
    {
        if ((s[i] != ' ') && (s[i] != '\0') && s[i] != '\n')
        {
            n++;
        }
    }
    return n;
}



int main()
{
    char s[1024];
    fgets(s,1024,stdin);
    fputs(wcount(s), stdout);
    return 0;
}