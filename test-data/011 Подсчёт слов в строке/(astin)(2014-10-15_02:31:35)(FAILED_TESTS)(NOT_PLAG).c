#include <stdio.h>
#define N 239

int wcount(char*);

int main(int argc, char **argv) {
    char str[N] = { 0 };
    gets(str);
    printf("%d", wcount(str));
    return 0;
}

int wcount(char *s) {
    int in-word, count, i;
    in_word = count = i = 0;
    while(s[i] != '\n') {
        while(s[i] != ' ') {
            i++;
            in_word++;
        }
        count++;
        if (!inword) i++;
    }
    return count;
}

