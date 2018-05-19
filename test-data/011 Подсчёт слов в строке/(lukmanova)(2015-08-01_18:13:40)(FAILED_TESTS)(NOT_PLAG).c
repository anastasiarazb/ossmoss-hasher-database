#include <stdio.h>
#include <string.h>

int wcount(char *s) {
    int count = 0;
    char *p = strtok(s, " ");
    while (p != NULL) {
        count++;
        p = strtok(NULL, " ");
    }
    return count;
}

int main() {
    char *s;
    gets(s);
    int out = wcount(s);
    printf("%d\n", out);
    return 0;
}