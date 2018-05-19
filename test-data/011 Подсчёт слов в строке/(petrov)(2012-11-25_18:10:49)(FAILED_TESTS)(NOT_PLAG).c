
#include <stdio.h>
#include <string.h>
int main()
{

        int a,n,k,i,h;
        char *s;
        s=(char *)malloc(n*sizeof(char));
        gets(s);
        k=0;
        h=0;
        n=strlen(s);
        int wcount(char *s)
        {
        for (i=0;i<n;i++)
            if (s[i]==' ') h+=1;
        for (i=0;i<(n-1);i++)
                if ((s[i]==' ')&&(s[i+1]!=' ')) k+=1;
        if (s[0]!=' ') k+=1;
        if (h==0) k=1;
        if (strcmp(s,"")==0) k=0;
        return k;
        }
        a=wcount(s);
        printf("%d",k);
        free(s);
        return 0;
}