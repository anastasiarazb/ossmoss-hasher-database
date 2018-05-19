#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s)
{
    int n = 0, i;
    for(i = 0; i < strlen(s); i++)
        if(s[i] != ' '){
            n++;
            while ((s[i] != ' ') && (s[i] != '\0'))
                i++;
        }
    return n;
}