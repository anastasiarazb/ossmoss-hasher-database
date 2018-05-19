#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define count 1000

//created by Benji

int wcount(char *s) {
    int len, n, i, k;
    while(s[n++] != ' ' && n <= len);
        
    
    for(len = strlen(s), n = 0, i = 0; n < len; n++) {
        while(s[n++] != ' ' && n <= len) { k = 1; }
        if (k) {
            i++; k = 0;
        }
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