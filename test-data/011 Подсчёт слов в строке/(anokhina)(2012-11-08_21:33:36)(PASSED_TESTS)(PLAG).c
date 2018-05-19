#include <stdio.h>
#include <stdlib.h>
int wcount (char *s)
{
    int k=0,S1=1,l=0;
    while(s[k]==' '){
        ++k;
    }
    if(s[k]=='\0') return 0;
    while(s[k]!='\0')
    {
        if(s[k]==' '){
            if(S1==0){
                ++l;
                S1=1;
            }
        }
        else
        {
            if(S1==1) S1=0;
        }
        ++k;
    }
    if(S1==1) return l; 
    return l+1;
}
int main()
{
    char s[1000];
    gets(s);
    printf("%d\n",wcount(s));
    return 0;
}