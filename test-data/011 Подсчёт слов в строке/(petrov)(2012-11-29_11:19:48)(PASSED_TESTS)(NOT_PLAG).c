#include <stdio.h>
#include <string.h>
int wcount(char *s)
        {
            int i,n,k,h;
            k=0;
            h=0;
            n=strlen(s);
            for (i=0;i<n;i++)
                if (s[i]==' ') h+=1;
            for (i=0;i<(n-1);i++)
                if ((s[i]==' ')&&(s[i+1]!=' ')) k+=1;
            if (s[0]!=' ') k+=1;
            if (h==0) k=1;
            if (strcmp(s,"")==0) k=0;
            return k;
        }
int main()
{
        int a,n,k;
        char *s[255];
        gets(s);
        a=wcount(s);
        printf("%d",a);
        return 0;
}