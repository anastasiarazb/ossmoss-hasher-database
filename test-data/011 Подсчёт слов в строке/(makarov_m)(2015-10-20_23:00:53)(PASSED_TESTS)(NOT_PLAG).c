#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 2000

int wcount(char *s)
{
        int i=0,sum=0,flag=0;
        for (;s[i]!=0;i++) {
                if ((flag == 0) && (s[i]!= ' ') && (s[i]!= '\t')) {
                        ++sum;
                        flag = 1;
                }
                if ((flag == 1) && ((s[i] == ' ') || (s[i] == '\t'))) {
                        flag = 0;
                }
        }
        return sum;
}

int main()
{
        char *s = calloc(MAX_LENGTH, sizeof(char));
        gets(s);
        printf("%d",wcount(s));
        free(s);
        return 0;
}
