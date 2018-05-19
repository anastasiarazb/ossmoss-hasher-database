#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount (char *s) {
        int count, help,i;
        help = 1;
        count = 0;
        i=0;
        while (s[i] != '\0') {
                if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t') help = 1;
                else 
                        if (help == 1) {
                                help = 0;
                                count+=1; 
                        }
                i++;
        }
        return count;    
}

int main(int argc, char** argv) {
        long r;
        r = 0;
        char s[200000];
        gets(s);
        if (strlen(s) == 0) {
                printf ("0");
                return 0;
        }  
        r = wcount (s);
        printf("%ld", r);
        return 0;
}