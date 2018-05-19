#include <ctype.h>

int wcount(char *s)
{
    int count = 0;
    int a = 0;

    for (s = 0;*s; s++)
    {
        if (isspace(*s))
        {
            a = 0;
            continue;
        }

        if (!a)
        {
            count++;
            a = 1;
        }
    }

    return count;
}