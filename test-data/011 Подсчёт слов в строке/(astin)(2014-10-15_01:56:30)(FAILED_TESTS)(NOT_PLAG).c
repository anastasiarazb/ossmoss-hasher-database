#include <stdio.h>
#define N 239

int wcount(char*);

int main(int argc, char **argv) {
    char *str = NULL;
    str = gets(str);
    printf("%d", wcount(str));
    return 0;
}

int wcount(char *s) {
    int outword, count, i;
    outword = count = i;
    while(s[i] != '\n') {
        while(s[i] == ' ') {
            i++;
            outword++;
        }
    }
    if (outword) {
        count++;
        outword = 0;
    }
    i++;
    return count;
}

