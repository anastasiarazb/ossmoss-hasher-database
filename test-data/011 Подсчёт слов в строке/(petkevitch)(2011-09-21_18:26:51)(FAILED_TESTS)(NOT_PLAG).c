#include <stdio.h>
#include <stdlib.h>
#define MAXIMUM_DLINNA 1000000
int wcount(char *s)
{
        int n, i, k;
        i=0;
        n=0;
        if (s[0]!=' ')
        k=0;
        else
        k=1;
        do
        {
                if (s[i]!=' ')
                k=0;
                if ((s[i]==' ') & (k==0))
                {
                        n++;
                        k=1;
                }
                i++;
        }
        while (i!=strlen(s));
        if (k==0)
        n++;
        return n;
}
int main(int argc , char ** argv)
{       
        char S[MAXIMUM_DLINNA];
        gets(S);
        printf("%d\n",wcount(S));
        return 0;
}
