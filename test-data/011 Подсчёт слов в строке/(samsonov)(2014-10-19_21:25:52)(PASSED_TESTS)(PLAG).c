#include <stdio.h>
#include <ctype.h>

#define limit 1000000

int wcount(char *s)
{
    int count = 0;
    int word = 0;

    for (;*s; s++)
    {
        if (isspace(*s))
        {
            word = 0;
            continue;
        }

        if (!word)
        {
            count++;
            word = 1;
        }
    }

    return count;
}

int main(int argc, char **argv)
{
    int number_of_words;
    char *s = (char *)malloc(limit*sizeof(char));
  
    memset(s, 0, sizeof(char)*limit);
    gets(s);
    number_of_words = wcount(s);
    printf("%d\n", number_of_words);
    free(s);
}