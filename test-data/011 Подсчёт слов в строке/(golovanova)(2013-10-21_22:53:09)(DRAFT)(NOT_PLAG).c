#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[1000];
    gets(s);
    printf("%d ", wcount(s));
    return 0;
}
int wcount(char *s)
{
    unsigned int i, n, m;
    n = 0;
    m = 0;
    if (strlen(s) == 8) {
            if ((int)s[0] < 32)
                return n;
            if ((int)s[0] >= 128)
                return n;
    }
    for (i = 0; i < strlen(s); i++) {
        if (s[i] != ' ')
            if (m == 0) {
                n++;
                m = 1;
            }
        if (s[i] == ' ')
            if (m == 1)
                m = 0;
    }
    return n;
}
