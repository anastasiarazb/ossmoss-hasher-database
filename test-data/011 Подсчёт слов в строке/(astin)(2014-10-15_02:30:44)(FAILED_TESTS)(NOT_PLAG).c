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
    int intword, count, i;
    intword = count = i = 0;
    while(s[i] != '\n') {
        while(s[i] != ' ') {
            i++;
            intword++;
        }
        count++;
        if (!inword) i++;
    }
    return count;
}

