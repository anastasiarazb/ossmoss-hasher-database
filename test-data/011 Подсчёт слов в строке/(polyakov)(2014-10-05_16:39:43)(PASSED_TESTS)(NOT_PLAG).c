#include <ctype.h>
#include <stdio.h>

int wcount(char *s)
{
    int count = 0;
    int wflag = 0;

    for (;*s; s++)
    {
        if (isspace(*s))
        {
            wflag = 0;
            continue;
        }

        if (!wflag)
        {
            count++;
            wflag = 1;
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