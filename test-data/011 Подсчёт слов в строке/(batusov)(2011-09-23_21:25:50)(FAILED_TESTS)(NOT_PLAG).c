#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
    int i = 0, count = 0;
    while (s[i] != 0)
        if (s[i] != ' ')
        {
            count++;
            while ((s[i] != 0) && (s[i] != ' '))
                i++;
        }
        else i++;
    return count;
}

int main()
{
    char *s = malloc(sizeof(char)*100);
    gets(s);
    printf("%d",wcount(s));
    return 0;
}
