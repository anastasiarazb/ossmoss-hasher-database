#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int wcount(char *s);

int main()
{
    char s[SIZE];
    gets(s);
    printf("%d\n", wcount(s));

    return 0;
    return 0;
}

int wcount(char *s)
{
    int i = 0;
    int k;

    while(s[i] == ' ' ) i++;
    for(k = 0; s[i] != '\0'; k++)
    {
        while(s[i] != ' ' && s[i] != '\0') i++;
        while(s[i] == ' ' ) i++;
    }

    return k;
}
