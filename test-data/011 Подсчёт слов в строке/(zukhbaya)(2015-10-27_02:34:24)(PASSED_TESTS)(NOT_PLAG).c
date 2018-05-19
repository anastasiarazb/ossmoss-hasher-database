#include <stdio.h>
#include <string.h>

enum { Outside, Inside } state;

int wcount(char *s) {

    char c, state;
    int i, words_num;

    state = Outside;
    words_num = 0;
    i = 0;

    for (i = 0; i < strlen(s); i++) {
        c = s[i];
        if (c == ' ' || c == '\n' || c == '\t' || c == '\0')
            state = Outside;
        else if (state == Outside) {
            state = Inside;
            words_num++;
        }
    }

    return words_num;
}

int main() {

    char s[255];
    gets(s);

    printf("%d", wcount(s));

    return 0;
}