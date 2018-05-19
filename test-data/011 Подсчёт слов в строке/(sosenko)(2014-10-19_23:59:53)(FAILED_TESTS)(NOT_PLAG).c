
#include <stdio.h>

int wcount(char *s) 
{ 
        printf("%d", 0);
        return 0;
}

int main()
{
        char s [10000];
        gets(s);
        return wcount(s);
}