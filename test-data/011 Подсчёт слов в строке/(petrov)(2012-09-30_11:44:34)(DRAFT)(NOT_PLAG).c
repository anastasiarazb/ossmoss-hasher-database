#include <stdio.h>

int main()
{
char s[127];
int i,n,k;
gets(s);
k=0;
n=strnlen(s,127);
for (i=1;i<(n-1);i++)
if ((s[i]==" ")&&(s[i+1]!=" ")) k+=1;
printf("%d",k);
        return 0;