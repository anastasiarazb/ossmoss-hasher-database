

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
    char *s=сalloc(100,sizeof(char));
    int p=0;
    gets(s);
    if (s[0] == '\0') {
        printf("0");
        free(s);
        return -1;
    }
    p=wcount(s);
    free(s);
    printf("%d",p);
    return 0;
}