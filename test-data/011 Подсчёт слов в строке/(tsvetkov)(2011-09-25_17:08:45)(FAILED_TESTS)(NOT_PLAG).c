#include <stdio.h>
#include <stdlib.h>
int wcount(char *s)
{
    int i,nc,nw,konets;
    nc=0;
    nw=0;
    while(nc!=strlen(s))
    {
        ++nc;
        if (nc==1) if (s[1]=' ') ++nw;
        if (s[nc]== ' ' || s[nc]=='\n' || s[nc]== '\t')
        konets=0;
        else if (konets==0)
        {
            konets=1;
            ++nw;
        }

    }
    if (s[strlen(s)-1]== ' ') --nw;
    return(nw);
}
int main()
{
    char s2[100];
    gets(s2);
    printf("%d",wcount(s2)-1);
    return 0;
} 