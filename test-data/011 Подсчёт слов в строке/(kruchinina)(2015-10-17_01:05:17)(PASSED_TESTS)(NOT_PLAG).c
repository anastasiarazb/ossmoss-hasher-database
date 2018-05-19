#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s);

int main(void)
{
    char *str;
    str = malloc(sizeof(*str)*1000);
    gets(str);
    printf("%d \n", wcount(str));
    free(str);
    return 0;
}

int wcount(char *s)
{
    int i;
    int word = 0;
    for (i = 0; i < (strlen(s)); i++)
    {
        if (s[i] != ' ')
        {
            while (s[i] != ' ' && i < (strlen (s)))
                i++;
            word++;
        }
    }
    return word;
}

