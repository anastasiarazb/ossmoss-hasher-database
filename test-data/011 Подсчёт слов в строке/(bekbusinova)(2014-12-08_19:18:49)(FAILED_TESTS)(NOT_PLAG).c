#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wcount(char *s)
{
    int с, nw, nc, state;
    state = OUT;
    nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == " " || c == '\n' || с == '\t') state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw; }
        printf ("%d %d %d\n", nw, nc);
    }

int main(int argc, char** argv) {
        long r,i,j;
        r = i = j = 0;
        char s[100000];
        gets(s);
        for (i=0;i<strlen(s);i++) {
                if (j == 1) 
                        break;
        else { 
                if (s[i] != ' ') {
                        s[j] = s[i];
                        j=j+1;
	        }       
        }
        }
        if (j == 0) 
                s[j]='\0';
        if (strlen(s) == 0) {
                printf ("0");
                return 0;
        }  
        r = wcount (s);
        printf("%ld", r);
        return 0;
} 