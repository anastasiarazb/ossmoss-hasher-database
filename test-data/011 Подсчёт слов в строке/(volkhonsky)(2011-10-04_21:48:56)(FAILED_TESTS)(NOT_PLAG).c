#include <stdio.h>
#include <stdlib.h>

int wcount(char *s)
{
    int f, i, sum,k;
    i=0;
    f=0;
    sum=0;
    k=0;

    while(s[i]!=0)
    {
        k++;
        if (s[i]!=' ' && s[i+1]==' ' && s[i+1]!=0)
        {
            sum++;
        }
        i++;
        if (s[i]==' ' && s[i+1]==0)
            sum-=1;
    }
    if(k==0)return 0;
    if (k!=0)return sum+1;
}

int main(int argc, char **argv)
{
    int a;
    char s[500];
    gets(s);
    printf("%d",wcount(s));

    return 0;
}
