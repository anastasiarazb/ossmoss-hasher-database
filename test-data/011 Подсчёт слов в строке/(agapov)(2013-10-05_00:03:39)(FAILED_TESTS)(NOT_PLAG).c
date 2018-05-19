#include <stdio.h>
#include <stdlib.h>

int wcount(char *s)
{
    int i, k = 0;
    for (i=0;i<strlen(s)-1;i++){
        if (((int)s[i]!=32) && ((int)s[i+1]==32))
            k++;
    }
    return k;
}

int main()
{
    char s[100];
    gets(s);
    printf("%d", wcount(s));
    return 0;
}
