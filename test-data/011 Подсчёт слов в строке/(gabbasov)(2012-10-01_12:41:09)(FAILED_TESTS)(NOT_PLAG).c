#include <stdio.h>

int wcount(char *s) 
{ 
        int t=0,j,i=0,k=0;
        for (i=0;s[i]!=0;i++)
                ;
        if (i==0)
                return 0;
        while (s[k]==' ')
                k++;
        for (j=k;j<i-1;j++)
                if ((s[j]!=' ')&&(s[j+1]==' '))
                        t++;
        if (s[i-1]!=' ')
                t++;
        return t;
}

int main()
{
        char s[100];
        gets(s);
        printf("%d",wcount(s));
        return 0;
}