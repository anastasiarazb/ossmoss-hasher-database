#include <stdio.h>

int wcount(char *s)
{
    int i, j = 0, n = 0;
    for (i = 0; i < 256; i++) {
        if ((s[i] == ' ') || (s[i] == 0)) {
            if (j != 0) n++;
            j = 0;
        } else {
            j++;
        }
    }
    return n;
}

int main(int argc, char **argv)
{
    char s[256] = { 0 };
    gets(s);
    printf("%d\n", wcount(s));
    return 0;
}