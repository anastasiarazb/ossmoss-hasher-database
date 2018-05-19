#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
    int len = strlen(s);
    if (len==0) return 0;
    int i=0, numw=0;
    for (i=0;i<len;) {
        while(isspace(s[i])) {
            i++;
        }
        if (i==len) return numw;
        else numw++;
        while(isspace(s[i])==0) {
            i++;
            if (i==len) return numw;
        }
    }
}

int main () {
    char str[100];
    gets(str);
    int n = wcount(str);
    printf("%d",n);
    return 0;
}
