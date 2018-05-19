#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int wcount(char *s) {
    int count = 0, len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] != ' ') {
            count++;
            while (s[i] != ' ' && i++ < len) {}
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