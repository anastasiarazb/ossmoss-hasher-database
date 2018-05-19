#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define count 1000

//created by Benji

int wcount(char *s) {
    int len, n, i, k;
    len = strlen(s); n = i = k = 0;
    while(s[n] == ' ' && n < len) { n++; }
        
    while(n < len) {
        while(s[n] != ' ' && n < len) { k = 1; n++; }
        if (k) {
            i++; k = 0;
        }
        n++;
    }
    return i;
}



int main(void) {
    char* string = calloc(count,sizeof(char));
    gets(string);
    printf("%d\n", wcount(string));
    free(string);
    return 0;
}