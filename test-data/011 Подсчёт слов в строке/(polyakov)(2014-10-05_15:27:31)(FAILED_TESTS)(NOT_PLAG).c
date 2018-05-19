
#include <stdio.h>
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


 

#define BUFFER_SIZE     (10 * 1024)



int main()
{
    char s[BUFFER_SIZE];

    printf("%d\n", wcount(gets(s)));

    return 0;
}