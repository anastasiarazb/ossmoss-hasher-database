#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s) {
        long n,i;
        n = i = 0;
        n=strlen(s);    
        int count = 1;
        for (i=0;i<n;i++) {
                if (i != 0 && i != n-1 && (*(s + i)) == ' ')
                        count+=1;
        }
        return count;
}

int main(int argc, char** argv) {
        long r;
        r = 0;
        char s[100000];
        gets(s);
        if (strlen(s) == 0) {
                printf ("0");
                return 0;
        }  
        r = wcount (s);
        printf("%ld", r);
        return 0;
} 