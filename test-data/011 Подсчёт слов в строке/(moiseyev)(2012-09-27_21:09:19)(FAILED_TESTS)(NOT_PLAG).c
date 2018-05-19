#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s) {
    int words = 0, wordgoes = 0, i;
    char ch;
    for(i = 0; ; i++) {
        ch = s[i];
        if(ch == ' ' || ch == '\n' || ch == '\t' || ch == '\0') {
            if(wordgoes)
                words++;
            if(ch == '\0')
                break;
            wordgoes = 0;
        } else {
            wordgoes = 1;
        }
    }
    return words;
}

int main(int argc, char** argv) {
    char string[256];
    gets(string);
    printf("%d\n", wcount(string));
    return 0;
}
