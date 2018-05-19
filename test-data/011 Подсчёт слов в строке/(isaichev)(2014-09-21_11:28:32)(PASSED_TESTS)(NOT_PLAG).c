#include <stdio.h>
#include <string.h>

int wcount (char *s){
    int i, a = 0;
    if ((*(s)!=' ')&&(*s!=NULL)) ++a;
    for (i = 1; i<(strlen(s)); ++i)
        if ((*(s+i-1)==' ')&&(*(s+i)!=' ')) ++a;
    return a;
}

int main (void){
    char s[255];
    gets (s);
    wcount(s);
    printf ("%d\n", wcount(s));
    return 0;
}