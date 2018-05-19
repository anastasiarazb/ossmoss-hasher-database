#include <stdio.h>
#include <stdlib.h>

int wcount(const char* s);

int main()
{
    char s[128];

    gets(s);
    printf("%d\n", wcount(s));

    return 0;
}

int wcount(const char* s)
{
    int res = 0, reading;

    reading = *s == ' '? 0: 1;
    for(; *s; ++s)
        if(reading && *s == ' ')
        {
            reading = 0;
            res++;
        }
        else if(!reading && *s != ' ')
            reading = 1;
    if(*(s-1) != ' ')
        res++;

    return res;
}
