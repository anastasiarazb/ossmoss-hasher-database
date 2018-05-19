
#include <stdio.h>

int wcount(char *s)
{
    char *p = s;
    int count = 0;

    while (1)
    {
        while (*p == ' ')
            p++;
        if (!*p)
            break;
        count++;
        while (*p && (*p != ' '))
            p++;
    }

    return count;
}

int main()
{
    char buf[0x10000];
    gets(buf);
    printf("%d", wcount(buf));
    return 0;
}
