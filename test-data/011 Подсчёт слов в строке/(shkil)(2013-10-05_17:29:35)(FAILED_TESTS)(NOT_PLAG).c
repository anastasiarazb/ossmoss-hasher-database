#include <stdio.h>
#include <stdlib.h>
int wcount(char *s) { 
        int k=0;
        for (;*s==32;s++);
        char *p=s;
        for (;*p!=0;p++)
                if (*p==32 || *p==0) {
                        k++; 
                        for(;*p==32;p++);
                        p--;
                }
        return k;
}
int main () {
        char s[1000];
        gets(s);
        printf ("%d\n", wcount(s));
return 0;
}