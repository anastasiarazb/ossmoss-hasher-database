#include <stdio.h>
#include <stdlib.h>

#define bool char
#define true 1
#define false 0



int wcount(char *s) {
    unsigned int idx=0,count=0;
    bool isWord=false;
    while (s[idx]) {
        if (isWord) {
            if (s[idx]=='\n' || s[idx]==' ') {
                isWord=false;
                count++;
            }
        } else {
            if (s[idx]!='\n' && s[idx]!=' ') {
                isWord=true;
            }
        }
        idx++;
    }
    return isWord?count+1:count;
}


int main(int argc, char **argv)
{
    char* str = malloc(sizeof(char)*2048);
    gets(str);
    printf("%d",wcount(str));
    free(str);
    
    return 0;
}