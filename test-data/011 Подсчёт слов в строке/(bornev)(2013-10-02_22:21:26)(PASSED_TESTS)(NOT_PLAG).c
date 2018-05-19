#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define is_null(ptr) \
{ \
if (ptr == NULL) \
    { \
        printf("[ERROR] Pointer at %s:%i is NULL\n",__FILE__,__LINE__);\
        exit(1); \
    } \
}

typedef unsigned char bool;
#define true 1
#define false 0

int wcount(char *ptr)
{


    int count = 0;
    bool word = false;
    for (;*ptr;ptr++)
    {
        if (isalnum(*ptr))
        {
            if (word == false)
            {
                word = true;
                count++;
            }
        }
        else
        {
            word = false;
        }
    }

    return count;
}


int main()
{
    char string[256];
    gets(string);
    printf("%i\n",wcount(string));
    return 0;
}