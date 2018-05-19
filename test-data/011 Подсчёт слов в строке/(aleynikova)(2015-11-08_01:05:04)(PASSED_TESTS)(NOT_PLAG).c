#include <stdio.h>
#define MAX_STACK 2048
#define Inc i++
#define Incj j++

int wcount(char *s)
{
    int  i = 0, j = 0;

    while(s[i] != '\0')
    {
        while(s[i] == ' ') Inc;
        if(s[i] != '\0' && s[i] != ' ') Incj;
        while(s[i] != '\0' && s[i] != ' ') Inc;
    }
    return j;
}

int main()
{
    char s[MAX_STACK];
    printf("%d\n", wcount(gets(s)));
    return 0;
}