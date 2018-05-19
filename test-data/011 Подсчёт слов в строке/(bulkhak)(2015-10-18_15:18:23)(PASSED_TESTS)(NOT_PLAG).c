#include <stdio.h>
#include <string.h>
#include <stdlib.h>

        int n = 100;
        int wcount(char *s)
{
    int i, j=   0;
    for (i=0; i<strlen(s); i++) {
        if ((s[i] != ' ')&&(s[i+1] == ' ')) {
            j++;
        }
        if ((s[i]!=' ' )&&(s[i+1]==0)) {
            j++;
        }
    }
    return j;
}

int main(){
    
    char s[n];
    gets(s);
    char* a = (char*)malloc(strlen(s));
    int res= wcount(s);
    printf("%d", res);
    free(a);
}