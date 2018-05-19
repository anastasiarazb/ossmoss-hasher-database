#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
    int i, len = strlen(s), count = 0;
    for (i = 0; i < len; i++) if (((int)s[i] != 32) && (((int)s[i+1] == 32) || (i == len-1))) count++;
    return count;
}

int main(int argv, char **argc)
{
    char str[300];
    gets(str);
    printf("%d\n", wcount(str));
    return 0;
}
