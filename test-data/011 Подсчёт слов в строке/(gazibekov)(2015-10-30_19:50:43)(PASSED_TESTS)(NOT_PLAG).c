#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int wcount(char *s)
{
    int i, count = 0;
    int len=strlen(s);
    for (i=0; i<len; i++) {
        if (s[i]!=' '){
            count++;
            while (s[i]!=' ' && i < len) {
                i++;
            }
        }
    }
    return count;
}

int main()
{
    char *s=(char*)malloc(100*sizeof(char));
    gets(s);
    int q;
    q=wcount(s);
    printf("%d\n", q);
    free(s);
    return 0;
}