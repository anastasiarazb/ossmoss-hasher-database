#include <stdio.h>
#define N 239

int wcount(char*);

int main(int argc, char **argv) {
    char str[N] = { 0 };
    gets(str);
    int ot = 0;
    ot = wcount(str);
    printf("%d", ot);
    return 0;
}

int wcount(char *s) {
    int flagin, count, i;
    flagin = count = i = 0;
    while(s[i]) {
        flagin = 0;
        while(s[i] && s[i] != ' ') {
            i++;
            if (!flagin) count++;
            flagin++;
        }
        if (!flagin) i++;
    } 
    return count;
}

