#include <stdio.h>
#include <string.h>

#define DEL " \t\n"

int wcount(char *s)
{
    int count=0, inw=0;
    while(*s){
        const char *p=DEL;
        while (*p != '\0' && *p != *s)
            ++p;
        if (*p != '\0'){
            if (inw==1){
                ++count;
                inw=0;
            }
        }
        else inw=1;
        ++s;
    }
    if (inw==1)
        ++count;
    return count;
}

int main()
{
    char str[255];
    gets(str);
    printf("%d", wcount(str));
}