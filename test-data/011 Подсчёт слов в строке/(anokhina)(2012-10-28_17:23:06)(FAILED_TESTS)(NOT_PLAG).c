#include <stdio.h>
#include <stdlib.h>
 
int wcount(char *s)
{
 int k=0, S1=0, l=0;
    while (s[k] != 0)
    {
    if (s[k] != ' ' && s[k + 1] == ' ')
    {
        l =  1;
    }
    ++k;
    if (l != 0 && s[k] == ' ' && s[k + 1] != ' ' && s[k + 1] != 0)
    {
        S1 += 1;
        l = 0;
    }
    }
if (S1 == 0) return(S1);
return(S1 + 1);
}
 
int main() 
{
    char s[1000];
    gets(s);
    printf("%u <-kol-vo slov v stroke", wcount(s));
    return 0;
}
 