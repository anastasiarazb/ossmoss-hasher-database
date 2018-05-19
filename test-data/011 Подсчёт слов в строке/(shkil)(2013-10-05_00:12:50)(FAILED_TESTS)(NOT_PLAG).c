#include <stdio.h>
#include <stdlib.h>
int wcount(char *s) { 
        int k=0;
        char *p=s;
        for (;*p==32;p++);
        for (;*p!=0;p++)
                if (*p==32) {
                        k++; 
                        for(;*p==32;p++);
                }
        if (*s!=0 && *(p-1)!=0) k++;
        return k;
}
int main () {
        char s[1000];
        gets(s);
        printf ("%d\n", wcount(s));
return 0;
}