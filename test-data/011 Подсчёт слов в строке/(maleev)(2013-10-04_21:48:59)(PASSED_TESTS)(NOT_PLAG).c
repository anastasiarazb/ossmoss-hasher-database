#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s)
{
        char *tek;
        int len;
        int i = 0, count = 0;
        len = strlen(s);
        while (i < len) {
                if ((!(*(s+i) == ' ')) && ((*(s+i+1) == ' ') || (*(s+i+1) == '\0')))
                        count++; 
                i++;
        } 
        return count;
}

int main(int argc, char *argv)
{
        char r[100], *rez;
        gets(r);
        rez = &r[0];
        printf("%d\n", wcount(rez));
}
