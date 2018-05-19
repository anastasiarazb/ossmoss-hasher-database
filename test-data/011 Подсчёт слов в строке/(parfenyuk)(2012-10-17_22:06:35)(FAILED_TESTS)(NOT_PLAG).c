
#include <stdio.h>
#include <stdlib.h>

int wcount(char *s)
{
    int i=1,k,m=0;
    if (s[0] == '\0') {
        free(s);
        return m;
    }
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
    free(s);
    return m;
}

int main()
{
    char *s=(char*)malloc(100*sizeof(char));
    int p=0;
    gets(s);
    p=wcount(s);
    printf("%d",p);
    return 0;
}