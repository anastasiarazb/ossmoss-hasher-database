#include <ctype.h>
#include <stdio.h>

int wcount(char *s)
{
    int count = 0;
    int point = 0;

    for (;*s; s++)
    {
        if (isspace(*s))
        {
            point = 0;
            continue;
        }

        if (!point)
        {
            count++;
            point = 1;
        }
    }

    return count;
}

#define n 1000000

int main(int argc, char **argv)
{
    char s[1000000];

    printf("%d\n", wcount(gets(s)));

    return 0;
}