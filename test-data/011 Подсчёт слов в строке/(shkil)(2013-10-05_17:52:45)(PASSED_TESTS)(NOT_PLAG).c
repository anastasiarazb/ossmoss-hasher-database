#include <stdio.h>
#include <stdlib.h>
int wcount(char *s) { 
        int k=0;
        for (;*s==32;s++);
        if (*s==0) return 0;
	char *p=s;
        for (;;p++) {
                if (*p==32) {
                        k++; 
                        for(;*p==32;p++);
			if (*p==0) return k;
			p--;
                }
	if (*p==0) return (k+1);
	}
}
int main () {
        char s[1000];
        gets(s);
        printf ("%d\n", wcount(s));
return 0;
}