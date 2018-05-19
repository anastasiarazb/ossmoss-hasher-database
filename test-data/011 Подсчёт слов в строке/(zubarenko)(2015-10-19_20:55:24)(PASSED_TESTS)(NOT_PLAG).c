
#include <stdio.h>

typedef int bool;
#define true 1;

int wcount(char *s)
{
    int result = 0;
    bool previousCharWasSpace = true;
    while (*s != '\0')
    {
        bool currentCharIsSpace = (*s == ' ');
        if ((!currentCharIsSpace) && (previousCharWasSpace))
            ++result;  
        previousCharWasSpace = currentCharIsSpace;
        ++s;
    }

    return result;
}

int main(void)
{
    char string[256];
    gets(string);
    printf("%i\n", wcount(string));
    return 0;
}