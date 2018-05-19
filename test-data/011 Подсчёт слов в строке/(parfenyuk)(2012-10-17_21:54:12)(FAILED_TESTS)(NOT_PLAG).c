
#include <stdio.h>
#include <stdlib.h>

int wcount(char *s)
{
    int i=1,k,m=0;
    if (s[0] != ' ') {
        k=1;
        m=1;
    }
    else k=0;
    while (s[i] != '\0') {
        if (s[i] == ' ' && k == 1)
            k=0;
        else if (k == 0 && s[i] != ' ') {
            k=1;
            m++;
        }
        i++;
    }
    return m;
}

int main()
{
    char *s=(char*)malloc(100*sizeof(char));
    gets(s);
    if (s[0] != '\0')
        printf("%d",wcount(s));
    else printf("0");
    free(s);
    return 0;
}