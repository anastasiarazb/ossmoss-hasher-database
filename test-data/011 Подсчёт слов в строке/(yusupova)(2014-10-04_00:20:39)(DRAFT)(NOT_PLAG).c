
#include <stdio.h>

int wcount(char *s) 
{ 
        int i=0, j=0, kol=0, z;
        for(;s[i]!=0;i++);
        for(;s[i]==' ';j++);
        for(z=j;z<i;z++) if (s[z]!=' '&&s[z+1]==' ') kol++;
        if (i!=0&&s[i-1]!=' ') kol++;
        return kol;
}
int main()
{
        char s[200];
        int k;
        gets(s);
        k=wcount(s);
        printf("%d",k);
	return 666;
}
